#include "atlas_asm.h"
/*
 * This file does a 5x2 unrolled r1_sse with these params:
 *    CL=8, ORDER=clmajor
 */
#ifndef ATL_GAS_x8664
   #error "This kernel requires x86-64 assembly!"
#endif
/*
 * Integer register assignment
 */
#define M       %rdi
#define N       %rsi
#define pA0     %r8
#define lda     %rax
#define pX      %rdx
#define pY      %r9
#define II      %rbx
#define pX0     %r11
#define Mr      %rcx
#define incAXm  %r10
#define incII   %r15
#define incAn   %r14
/*
 * SSE register assignment
 */
#define rXr     %xmm0
#define rXi     %xmm1
#define ra0     %xmm2
#define rA0     %xmm3
#define rY0      %xmm4
#define rYh0     %xmm5
#define rY1      %xmm6
#define rYh1     %xmm7
#define NONEPONEOFF -72
#define rneg %xmm15

/*
 * macros
 */
#ifndef MOVA
   #define MOVA movups
#endif
#define movapd movaps
#define movupd movups
#define xorpd xorps
#define addpd addps
#define mulpd mulps
#define addsd addss
#define mulsd mulss
#define movsd movss
#define haddpd haddps
/*
 * Define macros controlling prefetch
 */
#ifndef PFDIST
   #define PFDIST 256
#endif
#ifndef PFADIST
   #define PFADIST PFDIST
#endif
#ifndef PFYDIST
   #define PFYDIST 64
#endif
#ifndef PFXDIST
   #define PFXDIST 64
#endif
#ifndef PFIY
   #define PFIY prefetchnta
#endif
#ifndef PFIA
   #ifdef ATL_3DNow
      #define PFIA prefetchw
   #else
      #define PFIA prefetcht0
   #endif
#endif
#if PFADIST == 0                /* flag for no prefetch */
   #define prefA(mem)
#else
   #define prefA(mem) PFIA mem
#endif
#if PFYDIST == 0                /* flag for no prefetch */
   #define prefY(mem)
#else
   #define prefY(mem) PFIY mem
#endif
#if PFXDIST == 0                /* flag for no prefetch */
   #define prefX(mem)
#else
   #define prefX(mem) PFIX mem
#endif
.text
/*
 *                      %rdi        %rsi           %rdx          %rcx
 * void ATL_UGERK(ATL_CINT M, ATL_CINT N, const TYPE *X, const TYPE *Y,
 *                    %r8      %r9
 *                TYPE *A, ATL_CINT lda)
 */
.text
.global ATL_asmdecor(ATL_UGERK)
ALIGN64
ATL_asmdecor(ATL_UGERK):

/*
 * Save callee-saved iregs
 */
   movq %rbp, -8(%rsp)
   movq %rbx, -16(%rsp)
   movq %r12, -24(%rsp)
   movq %r13, -32(%rsp)
   movq %r14, -40(%rsp)
   movq %r15, -48(%rsp)
/*
 * Compute M = (M/MU)*MU, Mr = M - (M/MU)*MU
 * NOTE: Mr is %rcx reg, so we can use jcx to go to cleanup loop
 */
   mov  %r9, lda        /* move lda to assigned register, rax */
   mov  %rcx, pY        /* move pY to assigned register, r9 */
   movl   $5*8, -56(%rsp)       /* mem = MU */
   fildl  -56(%rsp)                     /* ST = MU */
   movl   %edi, -56(%rsp)               /* mem = M */
   fidivrl -56(%rsp)                    /* ST = M/MU */
   fisttpl -60(%rsp)                    /* mem = TRUNC(M/MU) */
   movl    -60(%rsp), %ebx              /* rbx = TRUNC(M/MU) */
   imul    $5*8, %ebx, %ebx     /* rbx = MU*TRUNC(M/MU) */
   mov     M, Mr                        /* Mr = M */
   sub     %rbx, Mr                     /* Mr = M - MU*TRUNC(M/MU) */
   mov     %rbx, M                      /* M  = MU*TRUNC(M/MU) */
/*
 * Construct nonepone = {1.0,-1.0,1.0,-1.0}
 */
   finit
   fld1                                 /* ST =  1.0 */
   fldz                                 /* ST =  0.0 1.0 */
   fsub %st(1), %st                     /* ST = -1.0 1.0 */
   fsts NONEPONEOFF(%rsp)               /* ST= -1.0 1.0 */
   fstps NONEPONEOFF+8(%rsp)            /* ST=1.0 */
   fsts NONEPONEOFF+4(%rsp)             /* ST=1.0 */
   fstps NONEPONEOFF+12(%rsp)          /* ST=NULL, mem={1.0, -1.0, 1.0, -1.0}*/
   movaps NONEPONEOFF(%rsp), rneg
/*
 * Setup constants
 */
   mov lda, incAn       /* incAn = lda */
   sub M, incAn         /* incAn = lda - (M/MU)*MU */
   sub Mr, incAn        /* incAn = lda - M */
   shl $3, incAn        /* incAn = (lda-M)*sizeof */
   shl $3, lda          /* lda *= sizeof */
   sub $-128, pA0       /* code compaction by using signed 1-byte offsets */
   sub $-128, pX        /* code compaction by using signed 1-byte offsets */
   mov pX, pX0          /* save for restore after M loops */
   mov $-320, incAXm     /* code comp: use reg rather than constant */
   add lda, incAn               /* incAn = (2*lda-M)*sizeof */
   mov $8*5, incII      /* code comp: use reg rather than constant */
   mov M, II

   ALIGN32
   LOOPN:
      movlps 0*8(pY), rY0   /* rY0 = {xx,xx, Y0i, Y0r} */
      movlhps rY0, rY0      /* rY0 = {Y0i, Y0r, Y0i, Y0r} */
      pshufd $0x11, rY0, rYh0 /* rYh0 = {Y0r, Y0i, Y0r, Y0i} */
      mulps rneg, rYh0  /* rYh0 = {Y0r,-Y0i, Y0r,-Y0i} */
      movlps 1*8(pY), rY1   /* rY1 = {xx,xx, Y1i, Y1r} */
      movlhps rY1, rY1      /* rY1 = {Y1i, Y1r, Y1i, Y1r} */
      pshufd $0x11, rY1, rYh1 /* rYh1 = {Y1r, Y1i, Y1r, Y1i} */
      mulps rneg, rYh1  /* rYh1 = {Y1r,-Y1i, Y1r,-Y1i} */

      LOOPM:
         movsldup 0-128(pX), rXr /* rXr = { X1r, X1r, X0r, X0r} */
         movaps rY0, rA0   /* rA0 = {Y0i, Y0r,Y0i, Y0r} */
         mulps  rXr, rA0   /* rA0 = {X1r*Y0i,X1r*Y0r,X0r*Y0i,X0r*Y0r} */
         MOVA   0-128(pA0), ra0
         addps ra0, rA0
         movshdup 0-128(pX), rXi /* rXi = {X1i, X1i, X0i, X0i} */
         movaps rYh0, ra0  /* ra0 = {Y0r,-Y0i,Y0r,-Y0i} */
         mulps  rXi, ra0   /* ra0 = {X1i*Y0r,-X1i*Y0i,X0i*Y0r,-X0i*Y0i} */
         addps  ra0, rA0
         MOVA   rA0, 0-128(pA0)
         prefA(PFADIST+0(pA0))
         prefA(PFADIST+0(pA0,lda))
         movaps rY1, rA0   /* rA0 = {Y1i, Y1r,Y1i, Y1r} */
         mulps  rXr, rA0   /* rA0 = {X1r*Y1i,X1r*Y1r,X0r*Y1i,X0r*Y1r} */
         MOVA   0-128(pA0,lda), ra0
         addps ra0, rA0
         movaps rYh1, ra0  /* ra0 = {Y1r,-Y1i,Y1r,-Y1i} */
         mulps  rXi, ra0   /* ra0 = {X1i*Y0r,-X1i*Y0i,X0i*Y0r,-X0i*Y0i} */
         addps  ra0, rA0
         MOVA   rA0, 0-128(pA0,lda)

         movsldup 64-128(pX), rXr /* rXr = { X1r, X1r, X0r, X0r} */
         movaps rY0, rA0   /* rA0 = {Y0i, Y0r,Y0i, Y0r} */
         mulps  rXr, rA0   /* rA0 = {X1r*Y0i,X1r*Y0r,X0r*Y0i,X0r*Y0r} */
         MOVA   64-128(pA0), ra0
         addps ra0, rA0
         movshdup 64-128(pX), rXi /* rXi = {X1i, X1i, X0i, X0i} */
         movaps rYh0, ra0  /* ra0 = {Y0r,-Y0i,Y0r,-Y0i} */
         mulps  rXi, ra0   /* ra0 = {X1i*Y0r,-X1i*Y0i,X0i*Y0r,-X0i*Y0i} */
         addps  ra0, rA0
         MOVA   rA0, 64-128(pA0)
         prefA(PFADIST+64(pA0))
         prefA(PFADIST+64(pA0,lda))
         movaps rY1, rA0   /* rA0 = {Y1i, Y1r,Y1i, Y1r} */
         mulps  rXr, rA0   /* rA0 = {X1r*Y1i,X1r*Y1r,X0r*Y1i,X0r*Y1r} */
         MOVA   64-128(pA0,lda), ra0
         addps ra0, rA0
         movaps rYh1, ra0  /* ra0 = {Y1r,-Y1i,Y1r,-Y1i} */
         mulps  rXi, ra0   /* ra0 = {X1i*Y0r,-X1i*Y0i,X0i*Y0r,-X0i*Y0i} */
         addps  ra0, rA0
         MOVA   rA0, 64-128(pA0,lda)

         movsldup 128-128(pX), rXr /* rXr = { X1r, X1r, X0r, X0r} */
         movaps rY0, rA0   /* rA0 = {Y0i, Y0r,Y0i, Y0r} */
         mulps  rXr, rA0   /* rA0 = {X1r*Y0i,X1r*Y0r,X0r*Y0i,X0r*Y0r} */
         MOVA   128-128(pA0), ra0
         addps ra0, rA0
         movshdup 128-128(pX), rXi /* rXi = {X1i, X1i, X0i, X0i} */
         movaps rYh0, ra0  /* ra0 = {Y0r,-Y0i,Y0r,-Y0i} */
         mulps  rXi, ra0   /* ra0 = {X1i*Y0r,-X1i*Y0i,X0i*Y0r,-X0i*Y0i} */
         addps  ra0, rA0
         MOVA   rA0, 128-128(pA0)
         prefA(PFADIST+128(pA0))
         prefA(PFADIST+128(pA0,lda))
         movaps rY1, rA0   /* rA0 = {Y1i, Y1r,Y1i, Y1r} */
         mulps  rXr, rA0   /* rA0 = {X1r*Y1i,X1r*Y1r,X0r*Y1i,X0r*Y1r} */
         MOVA   128-128(pA0,lda), ra0
         addps ra0, rA0
         movaps rYh1, ra0  /* ra0 = {Y1r,-Y1i,Y1r,-Y1i} */
         mulps  rXi, ra0   /* ra0 = {X1i*Y0r,-X1i*Y0i,X0i*Y0r,-X0i*Y0i} */
         addps  ra0, rA0
         MOVA   rA0, 128-128(pA0,lda)

         movsldup 192-128(pX), rXr /* rXr = { X1r, X1r, X0r, X0r} */
         movaps rY0, rA0   /* rA0 = {Y0i, Y0r,Y0i, Y0r} */
         mulps  rXr, rA0   /* rA0 = {X1r*Y0i,X1r*Y0r,X0r*Y0i,X0r*Y0r} */
         MOVA   192-128(pA0), ra0
         addps ra0, rA0
         movshdup 192-128(pX), rXi /* rXi = {X1i, X1i, X0i, X0i} */
         movaps rYh0, ra0  /* ra0 = {Y0r,-Y0i,Y0r,-Y0i} */
         mulps  rXi, ra0   /* ra0 = {X1i*Y0r,-X1i*Y0i,X0i*Y0r,-X0i*Y0i} */
         addps  ra0, rA0
         MOVA   rA0, 192-128(pA0)
         prefA(PFADIST+192(pA0))
         prefA(PFADIST+192(pA0,lda))
         movaps rY1, rA0   /* rA0 = {Y1i, Y1r,Y1i, Y1r} */
         mulps  rXr, rA0   /* rA0 = {X1r*Y1i,X1r*Y1r,X0r*Y1i,X0r*Y1r} */
         MOVA   192-128(pA0,lda), ra0
         addps ra0, rA0
         movaps rYh1, ra0  /* ra0 = {Y1r,-Y1i,Y1r,-Y1i} */
         mulps  rXi, ra0   /* ra0 = {X1i*Y0r,-X1i*Y0i,X0i*Y0r,-X0i*Y0i} */
         addps  ra0, rA0
         MOVA   rA0, 192-128(pA0,lda)

         movsldup 256-128(pX), rXr /* rXr = { X1r, X1r, X0r, X0r} */
         movaps rY0, rA0   /* rA0 = {Y0i, Y0r,Y0i, Y0r} */
         mulps  rXr, rA0   /* rA0 = {X1r*Y0i,X1r*Y0r,X0r*Y0i,X0r*Y0r} */
         MOVA   256-128(pA0), ra0
         addps ra0, rA0
         movshdup 256-128(pX), rXi /* rXi = {X1i, X1i, X0i, X0i} */
         movaps rYh0, ra0  /* ra0 = {Y0r,-Y0i,Y0r,-Y0i} */
         mulps  rXi, ra0   /* ra0 = {X1i*Y0r,-X1i*Y0i,X0i*Y0r,-X0i*Y0i} */
         addps  ra0, rA0
         MOVA   rA0, 256-128(pA0)
         prefA(PFADIST+256(pA0))
         prefA(PFADIST+256(pA0,lda))
         movaps rY1, rA0   /* rA0 = {Y1i, Y1r,Y1i, Y1r} */
         mulps  rXr, rA0   /* rA0 = {X1r*Y1i,X1r*Y1r,X0r*Y1i,X0r*Y1r} */
         MOVA   256-128(pA0,lda), ra0
         addps ra0, rA0
         movaps rYh1, ra0  /* ra0 = {Y1r,-Y1i,Y1r,-Y1i} */
         mulps  rXi, ra0   /* ra0 = {X1i*Y0r,-X1i*Y0i,X0i*Y0r,-X0i*Y0i} */
         addps  ra0, rA0
         MOVA   rA0, 256-128(pA0,lda)

         movsldup 16-128(pX), rXr /* rXr = { X1r, X1r, X0r, X0r} */
         movaps rY0, rA0   /* rA0 = {Y0i, Y0r,Y0i, Y0r} */
         mulps  rXr, rA0   /* rA0 = {X1r*Y0i,X1r*Y0r,X0r*Y0i,X0r*Y0r} */
         MOVA   16-128(pA0), ra0
         addps ra0, rA0
         movshdup 16-128(pX), rXi /* rXi = {X1i, X1i, X0i, X0i} */
         movaps rYh0, ra0  /* ra0 = {Y0r,-Y0i,Y0r,-Y0i} */
         mulps  rXi, ra0   /* ra0 = {X1i*Y0r,-X1i*Y0i,X0i*Y0r,-X0i*Y0i} */
         addps  ra0, rA0
         MOVA   rA0, 16-128(pA0)
         movaps rY1, rA0   /* rA0 = {Y1i, Y1r,Y1i, Y1r} */
         mulps  rXr, rA0   /* rA0 = {X1r*Y1i,X1r*Y1r,X0r*Y1i,X0r*Y1r} */
         MOVA   16-128(pA0,lda), ra0
         addps ra0, rA0
         movaps rYh1, ra0  /* ra0 = {Y1r,-Y1i,Y1r,-Y1i} */
         mulps  rXi, ra0   /* ra0 = {X1i*Y0r,-X1i*Y0i,X0i*Y0r,-X0i*Y0i} */
         addps  ra0, rA0
         MOVA   rA0, 16-128(pA0,lda)

         movsldup 32-128(pX), rXr /* rXr = { X1r, X1r, X0r, X0r} */
         movaps rY0, rA0   /* rA0 = {Y0i, Y0r,Y0i, Y0r} */
         mulps  rXr, rA0   /* rA0 = {X1r*Y0i,X1r*Y0r,X0r*Y0i,X0r*Y0r} */
         MOVA   32-128(pA0), ra0
         addps ra0, rA0
         movshdup 32-128(pX), rXi /* rXi = {X1i, X1i, X0i, X0i} */
         movaps rYh0, ra0  /* ra0 = {Y0r,-Y0i,Y0r,-Y0i} */
         mulps  rXi, ra0   /* ra0 = {X1i*Y0r,-X1i*Y0i,X0i*Y0r,-X0i*Y0i} */
         addps  ra0, rA0
         MOVA   rA0, 32-128(pA0)
         movaps rY1, rA0   /* rA0 = {Y1i, Y1r,Y1i, Y1r} */
         mulps  rXr, rA0   /* rA0 = {X1r*Y1i,X1r*Y1r,X0r*Y1i,X0r*Y1r} */
         MOVA   32-128(pA0,lda), ra0
         addps ra0, rA0
         movaps rYh1, ra0  /* ra0 = {Y1r,-Y1i,Y1r,-Y1i} */
         mulps  rXi, ra0   /* ra0 = {X1i*Y0r,-X1i*Y0i,X0i*Y0r,-X0i*Y0i} */
         addps  ra0, rA0
         MOVA   rA0, 32-128(pA0,lda)

         movsldup 48-128(pX), rXr /* rXr = { X1r, X1r, X0r, X0r} */
         movaps rY0, rA0   /* rA0 = {Y0i, Y0r,Y0i, Y0r} */
         mulps  rXr, rA0   /* rA0 = {X1r*Y0i,X1r*Y0r,X0r*Y0i,X0r*Y0r} */
         MOVA   48-128(pA0), ra0
         addps ra0, rA0
         movshdup 48-128(pX), rXi /* rXi = {X1i, X1i, X0i, X0i} */
         movaps rYh0, ra0  /* ra0 = {Y0r,-Y0i,Y0r,-Y0i} */
         mulps  rXi, ra0   /* ra0 = {X1i*Y0r,-X1i*Y0i,X0i*Y0r,-X0i*Y0i} */
         addps  ra0, rA0
         MOVA   rA0, 48-128(pA0)
         movaps rY1, rA0   /* rA0 = {Y1i, Y1r,Y1i, Y1r} */
         mulps  rXr, rA0   /* rA0 = {X1r*Y1i,X1r*Y1r,X0r*Y1i,X0r*Y1r} */
         MOVA   48-128(pA0,lda), ra0
         addps ra0, rA0
         movaps rYh1, ra0  /* ra0 = {Y1r,-Y1i,Y1r,-Y1i} */
         mulps  rXi, ra0   /* ra0 = {X1i*Y0r,-X1i*Y0i,X0i*Y0r,-X0i*Y0i} */
         addps  ra0, rA0
         MOVA   rA0, 48-128(pA0,lda)

         movsldup 80-128(pX), rXr /* rXr = { X1r, X1r, X0r, X0r} */
         movaps rY0, rA0   /* rA0 = {Y0i, Y0r,Y0i, Y0r} */
         mulps  rXr, rA0   /* rA0 = {X1r*Y0i,X1r*Y0r,X0r*Y0i,X0r*Y0r} */
         MOVA   80-128(pA0), ra0
         addps ra0, rA0
         movshdup 80-128(pX), rXi /* rXi = {X1i, X1i, X0i, X0i} */
         movaps rYh0, ra0  /* ra0 = {Y0r,-Y0i,Y0r,-Y0i} */
         mulps  rXi, ra0   /* ra0 = {X1i*Y0r,-X1i*Y0i,X0i*Y0r,-X0i*Y0i} */
         addps  ra0, rA0
         MOVA   rA0, 80-128(pA0)
         movaps rY1, rA0   /* rA0 = {Y1i, Y1r,Y1i, Y1r} */
         mulps  rXr, rA0   /* rA0 = {X1r*Y1i,X1r*Y1r,X0r*Y1i,X0r*Y1r} */
         MOVA   80-128(pA0,lda), ra0
         addps ra0, rA0
         movaps rYh1, ra0  /* ra0 = {Y1r,-Y1i,Y1r,-Y1i} */
         mulps  rXi, ra0   /* ra0 = {X1i*Y0r,-X1i*Y0i,X0i*Y0r,-X0i*Y0i} */
         addps  ra0, rA0
         MOVA   rA0, 80-128(pA0,lda)

         movsldup 96-128(pX), rXr /* rXr = { X1r, X1r, X0r, X0r} */
         movaps rY0, rA0   /* rA0 = {Y0i, Y0r,Y0i, Y0r} */
         mulps  rXr, rA0   /* rA0 = {X1r*Y0i,X1r*Y0r,X0r*Y0i,X0r*Y0r} */
         MOVA   96-128(pA0), ra0
         addps ra0, rA0
         movshdup 96-128(pX), rXi /* rXi = {X1i, X1i, X0i, X0i} */
         movaps rYh0, ra0  /* ra0 = {Y0r,-Y0i,Y0r,-Y0i} */
         mulps  rXi, ra0   /* ra0 = {X1i*Y0r,-X1i*Y0i,X0i*Y0r,-X0i*Y0i} */
         addps  ra0, rA0
         MOVA   rA0, 96-128(pA0)
         movaps rY1, rA0   /* rA0 = {Y1i, Y1r,Y1i, Y1r} */
         mulps  rXr, rA0   /* rA0 = {X1r*Y1i,X1r*Y1r,X0r*Y1i,X0r*Y1r} */
         MOVA   96-128(pA0,lda), ra0
         addps ra0, rA0
         movaps rYh1, ra0  /* ra0 = {Y1r,-Y1i,Y1r,-Y1i} */
         mulps  rXi, ra0   /* ra0 = {X1i*Y0r,-X1i*Y0i,X0i*Y0r,-X0i*Y0i} */
         addps  ra0, rA0
         MOVA   rA0, 96-128(pA0,lda)

         movsldup 112-128(pX), rXr /* rXr = { X1r, X1r, X0r, X0r} */
         movaps rY0, rA0   /* rA0 = {Y0i, Y0r,Y0i, Y0r} */
         mulps  rXr, rA0   /* rA0 = {X1r*Y0i,X1r*Y0r,X0r*Y0i,X0r*Y0r} */
         MOVA   112-128(pA0), ra0
         addps ra0, rA0
         movshdup 112-128(pX), rXi /* rXi = {X1i, X1i, X0i, X0i} */
         movaps rYh0, ra0  /* ra0 = {Y0r,-Y0i,Y0r,-Y0i} */
         mulps  rXi, ra0   /* ra0 = {X1i*Y0r,-X1i*Y0i,X0i*Y0r,-X0i*Y0i} */
         addps  ra0, rA0
         MOVA   rA0, 112-128(pA0)
         movaps rY1, rA0   /* rA0 = {Y1i, Y1r,Y1i, Y1r} */
         mulps  rXr, rA0   /* rA0 = {X1r*Y1i,X1r*Y1r,X0r*Y1i,X0r*Y1r} */
         MOVA   112-128(pA0,lda), ra0
         addps ra0, rA0
         movaps rYh1, ra0  /* ra0 = {Y1r,-Y1i,Y1r,-Y1i} */
         mulps  rXi, ra0   /* ra0 = {X1i*Y0r,-X1i*Y0i,X0i*Y0r,-X0i*Y0i} */
         addps  ra0, rA0
         MOVA   rA0, 112-128(pA0,lda)

         movsldup 144-128(pX), rXr /* rXr = { X1r, X1r, X0r, X0r} */
         movaps rY0, rA0   /* rA0 = {Y0i, Y0r,Y0i, Y0r} */
         mulps  rXr, rA0   /* rA0 = {X1r*Y0i,X1r*Y0r,X0r*Y0i,X0r*Y0r} */
         MOVA   144-128(pA0), ra0
         addps ra0, rA0
         movshdup 144-128(pX), rXi /* rXi = {X1i, X1i, X0i, X0i} */
         movaps rYh0, ra0  /* ra0 = {Y0r,-Y0i,Y0r,-Y0i} */
         mulps  rXi, ra0   /* ra0 = {X1i*Y0r,-X1i*Y0i,X0i*Y0r,-X0i*Y0i} */
         addps  ra0, rA0
         MOVA   rA0, 144-128(pA0)
         movaps rY1, rA0   /* rA0 = {Y1i, Y1r,Y1i, Y1r} */
         mulps  rXr, rA0   /* rA0 = {X1r*Y1i,X1r*Y1r,X0r*Y1i,X0r*Y1r} */
         MOVA   144-128(pA0,lda), ra0
         addps ra0, rA0
         movaps rYh1, ra0  /* ra0 = {Y1r,-Y1i,Y1r,-Y1i} */
         mulps  rXi, ra0   /* ra0 = {X1i*Y0r,-X1i*Y0i,X0i*Y0r,-X0i*Y0i} */
         addps  ra0, rA0
         MOVA   rA0, 144-128(pA0,lda)

         movsldup 160-128(pX), rXr /* rXr = { X1r, X1r, X0r, X0r} */
         movaps rY0, rA0   /* rA0 = {Y0i, Y0r,Y0i, Y0r} */
         mulps  rXr, rA0   /* rA0 = {X1r*Y0i,X1r*Y0r,X0r*Y0i,X0r*Y0r} */
         MOVA   160-128(pA0), ra0
         addps ra0, rA0
         movshdup 160-128(pX), rXi /* rXi = {X1i, X1i, X0i, X0i} */
         movaps rYh0, ra0  /* ra0 = {Y0r,-Y0i,Y0r,-Y0i} */
         mulps  rXi, ra0   /* ra0 = {X1i*Y0r,-X1i*Y0i,X0i*Y0r,-X0i*Y0i} */
         addps  ra0, rA0
         MOVA   rA0, 160-128(pA0)
         movaps rY1, rA0   /* rA0 = {Y1i, Y1r,Y1i, Y1r} */
         mulps  rXr, rA0   /* rA0 = {X1r*Y1i,X1r*Y1r,X0r*Y1i,X0r*Y1r} */
         MOVA   160-128(pA0,lda), ra0
         addps ra0, rA0
         movaps rYh1, ra0  /* ra0 = {Y1r,-Y1i,Y1r,-Y1i} */
         mulps  rXi, ra0   /* ra0 = {X1i*Y0r,-X1i*Y0i,X0i*Y0r,-X0i*Y0i} */
         addps  ra0, rA0
         MOVA   rA0, 160-128(pA0,lda)

         movsldup 176-128(pX), rXr /* rXr = { X1r, X1r, X0r, X0r} */
         movaps rY0, rA0   /* rA0 = {Y0i, Y0r,Y0i, Y0r} */
         mulps  rXr, rA0   /* rA0 = {X1r*Y0i,X1r*Y0r,X0r*Y0i,X0r*Y0r} */
         MOVA   176-128(pA0), ra0
         addps ra0, rA0
         movshdup 176-128(pX), rXi /* rXi = {X1i, X1i, X0i, X0i} */
         movaps rYh0, ra0  /* ra0 = {Y0r,-Y0i,Y0r,-Y0i} */
         mulps  rXi, ra0   /* ra0 = {X1i*Y0r,-X1i*Y0i,X0i*Y0r,-X0i*Y0i} */
         addps  ra0, rA0
         MOVA   rA0, 176-128(pA0)
         movaps rY1, rA0   /* rA0 = {Y1i, Y1r,Y1i, Y1r} */
         mulps  rXr, rA0   /* rA0 = {X1r*Y1i,X1r*Y1r,X0r*Y1i,X0r*Y1r} */
         MOVA   176-128(pA0,lda), ra0
         addps ra0, rA0
         movaps rYh1, ra0  /* ra0 = {Y1r,-Y1i,Y1r,-Y1i} */
         mulps  rXi, ra0   /* ra0 = {X1i*Y0r,-X1i*Y0i,X0i*Y0r,-X0i*Y0i} */
         addps  ra0, rA0
         MOVA   rA0, 176-128(pA0,lda)

         movsldup 208-128(pX), rXr /* rXr = { X1r, X1r, X0r, X0r} */
         movaps rY0, rA0   /* rA0 = {Y0i, Y0r,Y0i, Y0r} */
         mulps  rXr, rA0   /* rA0 = {X1r*Y0i,X1r*Y0r,X0r*Y0i,X0r*Y0r} */
         MOVA   208-128(pA0), ra0
         addps ra0, rA0
         movshdup 208-128(pX), rXi /* rXi = {X1i, X1i, X0i, X0i} */
         movaps rYh0, ra0  /* ra0 = {Y0r,-Y0i,Y0r,-Y0i} */
         mulps  rXi, ra0   /* ra0 = {X1i*Y0r,-X1i*Y0i,X0i*Y0r,-X0i*Y0i} */
         addps  ra0, rA0
         MOVA   rA0, 208-128(pA0)
         movaps rY1, rA0   /* rA0 = {Y1i, Y1r,Y1i, Y1r} */
         mulps  rXr, rA0   /* rA0 = {X1r*Y1i,X1r*Y1r,X0r*Y1i,X0r*Y1r} */
         MOVA   208-128(pA0,lda), ra0
         addps ra0, rA0
         movaps rYh1, ra0  /* ra0 = {Y1r,-Y1i,Y1r,-Y1i} */
         mulps  rXi, ra0   /* ra0 = {X1i*Y0r,-X1i*Y0i,X0i*Y0r,-X0i*Y0i} */
         addps  ra0, rA0
         MOVA   rA0, 208-128(pA0,lda)

         movsldup 224-128(pX), rXr /* rXr = { X1r, X1r, X0r, X0r} */
         movaps rY0, rA0   /* rA0 = {Y0i, Y0r,Y0i, Y0r} */
         mulps  rXr, rA0   /* rA0 = {X1r*Y0i,X1r*Y0r,X0r*Y0i,X0r*Y0r} */
         MOVA   224-128(pA0), ra0
         addps ra0, rA0
         movshdup 224-128(pX), rXi /* rXi = {X1i, X1i, X0i, X0i} */
         movaps rYh0, ra0  /* ra0 = {Y0r,-Y0i,Y0r,-Y0i} */
         mulps  rXi, ra0   /* ra0 = {X1i*Y0r,-X1i*Y0i,X0i*Y0r,-X0i*Y0i} */
         addps  ra0, rA0
         MOVA   rA0, 224-128(pA0)
         movaps rY1, rA0   /* rA0 = {Y1i, Y1r,Y1i, Y1r} */
         mulps  rXr, rA0   /* rA0 = {X1r*Y1i,X1r*Y1r,X0r*Y1i,X0r*Y1r} */
         MOVA   224-128(pA0,lda), ra0
         addps ra0, rA0
         movaps rYh1, ra0  /* ra0 = {Y1r,-Y1i,Y1r,-Y1i} */
         mulps  rXi, ra0   /* ra0 = {X1i*Y0r,-X1i*Y0i,X0i*Y0r,-X0i*Y0i} */
         addps  ra0, rA0
         MOVA   rA0, 224-128(pA0,lda)

         movsldup 240-128(pX), rXr /* rXr = { X1r, X1r, X0r, X0r} */
         movaps rY0, rA0   /* rA0 = {Y0i, Y0r,Y0i, Y0r} */
         mulps  rXr, rA0   /* rA0 = {X1r*Y0i,X1r*Y0r,X0r*Y0i,X0r*Y0r} */
         MOVA   240-128(pA0), ra0
         addps ra0, rA0
         movshdup 240-128(pX), rXi /* rXi = {X1i, X1i, X0i, X0i} */
         movaps rYh0, ra0  /* ra0 = {Y0r,-Y0i,Y0r,-Y0i} */
         mulps  rXi, ra0   /* ra0 = {X1i*Y0r,-X1i*Y0i,X0i*Y0r,-X0i*Y0i} */
         addps  ra0, rA0
         MOVA   rA0, 240-128(pA0)
         movaps rY1, rA0   /* rA0 = {Y1i, Y1r,Y1i, Y1r} */
         mulps  rXr, rA0   /* rA0 = {X1r*Y1i,X1r*Y1r,X0r*Y1i,X0r*Y1r} */
         MOVA   240-128(pA0,lda), ra0
         addps ra0, rA0
         movaps rYh1, ra0  /* ra0 = {Y1r,-Y1i,Y1r,-Y1i} */
         mulps  rXi, ra0   /* ra0 = {X1i*Y0r,-X1i*Y0i,X0i*Y0r,-X0i*Y0i} */
         addps  ra0, rA0
         MOVA   rA0, 240-128(pA0,lda)

         movsldup 272-128(pX), rXr /* rXr = { X1r, X1r, X0r, X0r} */
         movaps rY0, rA0   /* rA0 = {Y0i, Y0r,Y0i, Y0r} */
         mulps  rXr, rA0   /* rA0 = {X1r*Y0i,X1r*Y0r,X0r*Y0i,X0r*Y0r} */
         MOVA   272-128(pA0), ra0
         addps ra0, rA0
         movshdup 272-128(pX), rXi /* rXi = {X1i, X1i, X0i, X0i} */
         movaps rYh0, ra0  /* ra0 = {Y0r,-Y0i,Y0r,-Y0i} */
         mulps  rXi, ra0   /* ra0 = {X1i*Y0r,-X1i*Y0i,X0i*Y0r,-X0i*Y0i} */
         addps  ra0, rA0
         MOVA   rA0, 272-128(pA0)
         movaps rY1, rA0   /* rA0 = {Y1i, Y1r,Y1i, Y1r} */
         mulps  rXr, rA0   /* rA0 = {X1r*Y1i,X1r*Y1r,X0r*Y1i,X0r*Y1r} */
         MOVA   272-128(pA0,lda), ra0
         addps ra0, rA0
         movaps rYh1, ra0  /* ra0 = {Y1r,-Y1i,Y1r,-Y1i} */
         mulps  rXi, ra0   /* ra0 = {X1i*Y0r,-X1i*Y0i,X0i*Y0r,-X0i*Y0i} */
         addps  ra0, rA0
         MOVA   rA0, 272-128(pA0,lda)

         movsldup 288-128(pX), rXr /* rXr = { X1r, X1r, X0r, X0r} */
         movaps rY0, rA0   /* rA0 = {Y0i, Y0r,Y0i, Y0r} */
         mulps  rXr, rA0   /* rA0 = {X1r*Y0i,X1r*Y0r,X0r*Y0i,X0r*Y0r} */
         MOVA   288-128(pA0), ra0
         addps ra0, rA0
         movshdup 288-128(pX), rXi /* rXi = {X1i, X1i, X0i, X0i} */
         movaps rYh0, ra0  /* ra0 = {Y0r,-Y0i,Y0r,-Y0i} */
         mulps  rXi, ra0   /* ra0 = {X1i*Y0r,-X1i*Y0i,X0i*Y0r,-X0i*Y0i} */
         addps  ra0, rA0
         MOVA   rA0, 288-128(pA0)
         movaps rY1, rA0   /* rA0 = {Y1i, Y1r,Y1i, Y1r} */
         mulps  rXr, rA0   /* rA0 = {X1r*Y1i,X1r*Y1r,X0r*Y1i,X0r*Y1r} */
         MOVA   288-128(pA0,lda), ra0
         addps ra0, rA0
         movaps rYh1, ra0  /* ra0 = {Y1r,-Y1i,Y1r,-Y1i} */
         mulps  rXi, ra0   /* ra0 = {X1i*Y0r,-X1i*Y0i,X0i*Y0r,-X0i*Y0i} */
         addps  ra0, rA0
         MOVA   rA0, 288-128(pA0,lda)

         movsldup 304-128(pX), rXr /* rXr = { X1r, X1r, X0r, X0r} */
         movaps rY0, rA0   /* rA0 = {Y0i, Y0r,Y0i, Y0r} */
         mulps  rXr, rA0   /* rA0 = {X1r*Y0i,X1r*Y0r,X0r*Y0i,X0r*Y0r} */
         MOVA   304-128(pA0), ra0
         addps ra0, rA0
         movshdup 304-128(pX), rXi /* rXi = {X1i, X1i, X0i, X0i} */
         movaps rYh0, ra0  /* ra0 = {Y0r,-Y0i,Y0r,-Y0i} */
         mulps  rXi, ra0   /* ra0 = {X1i*Y0r,-X1i*Y0i,X0i*Y0r,-X0i*Y0i} */
         addps  ra0, rA0
         MOVA   rA0, 304-128(pA0)
         movaps rY1, rA0   /* rA0 = {Y1i, Y1r,Y1i, Y1r} */
         mulps  rXr, rA0   /* rA0 = {X1r*Y1i,X1r*Y1r,X0r*Y1i,X0r*Y1r} */
         MOVA   304-128(pA0,lda), ra0
         addps ra0, rA0
         movaps rYh1, ra0  /* ra0 = {Y1r,-Y1i,Y1r,-Y1i} */
         mulps  rXi, ra0   /* ra0 = {X1i*Y0r,-X1i*Y0i,X0i*Y0r,-X0i*Y0i} */
         addps  ra0, rA0
         MOVA   rA0, 304-128(pA0,lda)

         sub incAXm, pX
         sub incAXm, pA0
      sub incII, II
      jnz LOOPM

      cmp $0, Mr
      jz  MCLEANED

      mov Mr, II
      xorps rXr, rXr
      movaps rXr, rXi
      xorps ra0, ra0
      LOOPMCU:
         movlps -128(pX), rXi           /* rXr = {0, 0, X0i, X0r} */
         pshufd $0xE0, rXi, rXr         /* rXr = {0, 0, X0r, X0r} */
         movaps rY0, rA0                /* rA0 = {Y0i, Y0r, Y0i, Y0r} */
         mulps  rXr, rA0                /* rA0 = {0, 0, X0r*Y0i, X0r*Y0r} */
         movlps -128(pA0), ra0
         addps ra0, rA0
         shufps $0xE5, rXi, rXi         /* rXi = {0, 0, X0i, X0i} */
         movaps rYh0, ra0               /* ra0 = {Y0r, -Y0i, Y0r,-Y0i} */
         mulps  rXi, ra0                /* ra0 = {0, 0, X0i*Y0r,-X0i*Y0i} */
         addps  ra0, rA0
         movlps rA0, -128(pA0)
         movlps -128(pX), rXi           /* rXr = {0, 0, X0i, X0r} */
         pshufd $0xE0, rXi, rXr         /* rXr = {0, 0, X0r, X0r} */
         movaps rY1, rA0                /* rA0 = {Y1i, Y1r, Y1i, Y1r} */
         mulps  rXr, rA0                /* rA0 = {0, 0, X0r*Y1i, X0r*Y1r} */
         movlps -128(pA0,lda), ra0
         addps ra0, rA0
         shufps $0xE5, rXi, rXi         /* rXi = {0, 0, X0i, X0i} */
         movaps rYh1, ra0               /* ra0 = {Y1r, -Y1i, Y1r,-Y1i} */
         mulps  rXi, ra0                /* ra0 = {0, 0, X0i*Y0r,-X0i*Y0i} */
         addps  ra0, rA0
         movlps rA0, -128(pA0,lda)
         add $8, pX
         add $8, pA0
      dec II
      jnz LOOPMCU

MCLEANED:
      prefY(2*8+PFYDIST(pY))
      add $2*8, pY
      add incAn, pA0
      mov pX0, pX
      mov M, II
   sub $2, N
   jnz LOOPN
/*
 * EPILOGUE: restore registers and return
 */
   movq -8(%rsp), %rbp
   movq -16(%rsp), %rbx
   movq -24(%rsp), %r12
   movq -32(%rsp), %r13
   movq -40(%rsp), %r14
   movq -48(%rsp), %r15
   ret
