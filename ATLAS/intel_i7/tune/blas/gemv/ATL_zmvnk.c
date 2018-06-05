#include "atlas_misc.h"
#ifndef PFYDIST
   #define PFYDIST 4
#endif

#if !defined(ATL_3DNow) && !defined(ATL_SSE1) && \
    (PFADIST != 0 || PFXDIST != 0 || PFYDIST != 0)
   #include "atlas_prefetch.h"
#endif

#if defined(ATL_3DNow) || defined(ATL_SSE1)
   #ifndef PFIY
      #define PFIY prefetchnta
   #endif
   #ifndef PFIX
      #define PFIX prefetchnta
   #endif
   #ifndef PFIA
      #ifdef ATL_3DNow
         #define PFIA prefetchw
      #else
         #define PFIA prefetcht0
      #endif
   #endif
#endif
/*
 * X & A are prefetched in M loop PF[A,X]DIST (in bytes) ahead
 */
#if PFADIST == 0                /* flag for no prefetch */
   #define prefA(mem)
#else
   #if defined(ATL_3DNow) || defined(ATL_SSE1)
      #define prefA(mem) __asm__ __volatile__ \
         (Mstr(PFIA) " %0" : : "m" (*(((char *)(mem))+PFADIST)))
   #else
      #if PFLVL == 2
         #define prefA(mem) ATL_pfl2W(((char*)mem)+PFADIST)
      #else
         #define prefA(mem) ATL_pfl1W(((char*)mem)+PFADIST)
      #endif
   #endif
#endif
#if PFXDIST == 0                /* flag for no prefetch */
   #define prefX(mem)
#else
   #if defined(ATL_3DNow) || defined(ATL_SSE1)
      #define prefX(mem) __asm__ __volatile__ \
         (Mstr(PFIX) " %0" : : "m" (*(((char *)(mem))+PFXDIST)))
   #else
      #if PFLVL == 2
         #define prefX(mem) ATL_pfl2R(((char*)mem)+PFXDIST)
      #else
         #define prefX(mem) ATL_pfl1R(((char*)mem)+PFXDIST)
      #endif
   #endif
#endif
/*
 * Y is prefetched in N-loop, and always fetches next NU piece
 */
#if PFYDIST == 0                /* flag for no prefetch */
   #define prefY(mem)
#else
   #if defined(ATL_3DNow) || defined(ATL_SSE1)
      #define prefY(mem) \
         __asm__ __volatile__ (Mstr(PFIY) " %0" : : "m" (*(((char *)(mem)))))
   #else
      #if PFLVL == 2
         #define prefY(mem) ATL_pfl2R(mem)
      #else
         #define prefY(mem) ATL_pfl1R(mem)
      #endif
   #endif
#endif
#ifndef ATL_CINT
   #define ATL_CINT const int
#endif
#ifndef ATL_INT
   #define ATL_INT int
#endif
/* Need to handle BETA=0 case by assigning y to zero outside of loop */
void ATL_UGEMV(ATL_CINT M0, ATL_CINT N, const TYPE *A, ATL_CINT lda0,
               const TYPE *X, TYPE *Y)
/*
 * 1x4 unrolled mvn_c.
 * Extracted from ATLAS/tune/blas/gemv/atlas-l2g.base
 */
{
   ATL_CINT N4=(N/4)*4, M=M0+M0, M1=((M0/1)*1)<<1,
            lda=lda0+lda0, lda4=lda*4;
   ATL_INT j;

   #ifdef BETA0
      for (j=0; j < M; j++)
         Y[j] = ATL_rzero;
   #endif
   for (j=N4; j; j -= 4, A += lda4, X += 8)
   {
      const double *A0=A, *A1=A0+lda, *A2=A1+lda, *A3=A2+lda;
      register double rx0=X[0], ix0=X[1], rx1=X[2], ix1=X[3], rx2=X[4],
                      ix2=X[5], rx3=X[6], ix3=X[7];
      ATL_INT i;
      prefY(X+8+8-1);
      for (i=0; i < M1; i += 2)
      {
         const double ra0_0=A0[i+0], ia0_0=A0[i+1], ra0_1=A1[i+0],
                      ia0_1=A1[i+1], ra0_2=A2[i+0], ia0_2=A2[i+1],
                      ra0_3=A3[i+0], ia0_3=A3[i+1];
         register double ry0=Y[i+0], iy0=Y[i+1];

         prefY(Y);
         ry0 += ra0_0 * rx0;
         iy0 += ra0_0 * ix0;
         ry0 -= ia0_0 * ix0;
         iy0 += ia0_0 * rx0;
         prefA(A0);

         ry0 += ra0_1 * rx1;
         iy0 += ra0_1 * ix1;
         ry0 -= ia0_1 * ix1;
         iy0 += ia0_1 * rx1;
         prefA(A1);

         ry0 += ra0_2 * rx2;
         iy0 += ra0_2 * ix2;
         ry0 -= ia0_2 * ix2;
         iy0 += ia0_2 * rx2;
         prefA(A2);

         ry0 += ra0_3 * rx3;
         iy0 += ra0_3 * ix3;
         ry0 -= ia0_3 * ix3;
         iy0 += ia0_3 * rx3;
         prefA(A3);


         Y[i+0] = ry0;
         Y[i+1] = iy0;
      }
   }
/*
 * Do remaining columns with NU=1 cleanup
 */
   for (j=N-N4; j; j--, A += lda, X += 2)
   {
      const double *A0=A;
      register double rx0=X[0], ix0=X[1];
      ATL_INT i;
      prefY(X+8+8-1);
      for (i=0; i < M1; i += 2)
      {
         const double ra0_0=A0[i+0], ia0_0=A0[i+1];
         register double ry0=Y[i+0], iy0=Y[i+1];

         prefY(Y);
         ry0 += ra0_0 * rx0;
         iy0 += ra0_0 * ix0;
         ry0 -= ia0_0 * ix0;
         iy0 += ia0_0 * rx0;
         prefA(A0);


         Y[i+0] = ry0;
         Y[i+1] = iy0;
      }
   }
}
