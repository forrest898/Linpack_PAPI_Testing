#define ATL_USERMM ATL_supKBmm64_8_1_b0
#define ATL_USERMM_b1 ATL_supKBmm64_8_1_b1
#define ATL_USERMM_bn1 ATL_supKBmm64_8_1_bn1
#define ATL_USERMM_b0 ATL_supKBmm64_8_1_b0
#define ATL_USERMM_bX ATL_supKBmm64_8_1_bX
#define BETA0
#define SREAL

#define MB 80
#define NB 80
#define KB 64

#define MBMB 6400
#define NBNB 6400
#define KBKB 4096

#define MB2 160
#define NB2 160
#define KB2 128


#define MB3 240
#define NB3 240
#define KB3 192


#define MB4 320
#define NB4 320
#define KB4 256


#define MB5 400
#define NB5 400
#define KB5 320


#define MB6 480
#define NB6 480
#define KB6 384


#define MB7 560
#define NB7 560
#define KB7 448


#define MB8 640
#define NB8 640
#define KB8 512

/*
 *             Automatically Tuned Linear Algebra Software v3.10.3
 * Copyright (C) 2011 R. Clint Whaley
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *   1. Redistributions of source code must retain the above copyright
 *      notice, this list of conditions and the following disclaimer.
 *   2. Redistributions in binary form must reproduce the above copyright
 *      notice, this list of conditions, and the following disclaimer in the
 *      documentation and/or other materials provided with the distribution.
 *   3. The name of the ATLAS group or the names of its contributers may
 *      not be used to endorse or promote products derived from this
 *      software without specific written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED
 * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE ATLAS GROUP OR ITS CONTRIBUTORS
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 */
#ifndef ATL_AVX
   #error "This kernel requires AVX"
#endif
#if !defined(KB) || KB < 1
   #error "This kernel requires a constant KB"
#endif
#if defined(NB) && (NB/2)*2 != NB
   #error "NB must be a multiple of 2"
#endif
#if defined(MB) && (MB/4)*4 != MB
   #error "MB must be a multiple of 2"
#endif

#include "atlas_misc.h"
// #include <wmmintrin.h>
// #include <bmmintrin.h>
#include <immintrin.h>

#ifndef ATL_RESTRICT
   #if defined(__STDC_VERSION__) && (__STDC_VERSION__/100 >= 1999)
      #define ATL_RESTRICT restrict
   #else
      #define ATL_RESTRICT
   #endif
#endif
void ATL_USERMM
   (const int M, const int N, const int K, const float alpha,
    const float * ATL_RESTRICT A, const int lda,
    const float * ATL_RESTRICT B, const int ldb, const float beta,
    float * ATL_RESTRICT C, const int ldc)
/*
 * matmul with TA=T, TB=N, MB=0, NB=0, KB=56,
 * lda=56, ldb=56, ldc=0, mu=4, nu=2, ku=1, pf=0
 * Generated by ATLAS/tune/blas/gemm/emit_mm.c (3.9.39)
 */
{
   const int Mb = (M>>2)<<2;
   const int Nb = (N>>1)<<1;
   const float *stM = A + (KB*(Mb));
   const float *stN = B + (KB*(Nb));
   const float *pfA = stM;
   const int incAm = 3*KB, incAn = -(KB*(Mb));
   const int incBm = -KB, incBn = 2*KB;
   const int incCn = ((((ldc) << 1)) - (Mb))SHIFT;
   float *pC0=C, *pC1=pC0+(ldc SHIFT);
   const float *pA0=A;
   const float *pB0=B;
   register int k;
   register __m256 rA0, rA1, rA2, rA3;
   register __m256 rB0, rB1, t0;
   register __m256 rC0_0, rC1_0, rC2_0, rC3_0, rC0_1, rC1_1, rC2_1, rC3_1;
   #if defined(TCPLX)
      float V[24], *v, *z;
      v = ATL_AlignPtr(V);
/*      v[0] = v[2] = v[4] = v[6] = beta;
      v[1] = v[3] = v[5] = v[7] = ATL_rone; */
   #endif
   do /* N-loop */
   {
      do /* M-loop */
      {
         rC0_0 = _mm256_setzero_ps();
         rC1_0 = _mm256_setzero_ps();
         rC2_0 = _mm256_setzero_ps();
         rC3_0 = _mm256_setzero_ps();

         rC0_1 = _mm256_setzero_ps();
         rC1_1 = _mm256_setzero_ps();
         rC2_1 = _mm256_setzero_ps();
         rC3_1 = _mm256_setzero_ps();
         for (k=0; k < KB; k += 8) /* easy loop to unroll */
         {
            rA0 = _mm256_load_ps(pA0);
            rB0 = _mm256_load_ps(pB0);
            rA1 = _mm256_load_ps(pA0+KB);
            rA2 = _mm256_load_ps(pA0+2*KB);
            rA3 = _mm256_load_ps(pA0+3*KB);
            rB1 = _mm256_load_ps(pB0+KB);

            t0 = _mm256_mul_ps(rA0, rB0);
            rC0_0 = _mm256_add_ps(rC0_0, t0);
            pA0 += 8;
            t0 = _mm256_mul_ps(rA1, rB0);
            rC1_0 = _mm256_add_ps(rC1_0, t0);
            pB0 += 8;
            t0 = _mm256_mul_ps(rA2, rB0);
            rC2_0 = _mm256_add_ps(rC2_0, t0);
            t0 = _mm256_mul_ps(rA3, rB0);
            rC3_0 = _mm256_add_ps(rC3_0, t0);
            t0 = _mm256_mul_ps(rA0, rB1);
            rC0_1 = _mm256_add_ps(rC0_1, t0);
            t0 = _mm256_mul_ps(rA1, rB1);
            rC1_1 = _mm256_add_ps(rC1_1, t0);
            t0 = _mm256_mul_ps(rA2, rB1);
            rC2_1 = _mm256_add_ps(rC2_1, t0);
            t0 = _mm256_mul_ps(rA3, rB1);
            rC3_1 = _mm256_add_ps(rC3_1, t0);

         }
         pA0 += incAm;
         #if !defined(BETA0) && !defined(TCPLX)
            t0 = _mm256_loadu_ps(pC1);
         #endif
         rC0_0 = _mm256_hadd_ps(rC0_0, rC1_0);
         rC0_1 = _mm256_hadd_ps(rC0_1, rC1_1);
         pB0 += incBm;
         /* c10gh c10ef c00gh c00ef c10cd c10ab c00cd c00ab */
         rC2_0 = _mm256_hadd_ps(rC2_0, rC3_0);
         rC2_1 = _mm256_hadd_ps(rC2_1, rC3_1);
         _mm_prefetch(pfA, 1);
         /* c30gh c30ef c20gh c20ef c30cd c30ab c20cd c20ab */
         rC0_0 = _mm256_hadd_ps(rC0_0, rC2_0);
         rC0_1 = _mm256_hadd_ps(rC0_1, rC2_1);
         pfA += 8;
         /* c30efgh c20efgh c10efgh c00efgh c30abcd c20abcd c10abcd c00abcd */
         #ifdef TCPLX
            rC2_0 = _mm256_castps128_ps256(_mm256_extractf128_ps(rC0_0, 1));
                    /* xx xx xx xx c30efgh c20efgh c10efgh c00efgh */

            rC0_0 = _mm256_add_ps(rC0_0, rC2_0);
                /* xx xx xx xx c30a-h c20a-h c10a-h c00a-h */
            rC2_1 = _mm256_castps128_ps256(_mm256_extractf128_ps(rC0_1, 1));
                    /* xx xx xx xx c31efgh c21efgh c11efgh c01efgh */

            rC0_1 = _mm256_add_ps(rC0_1, rC2_1);
                /* xx xx xx xx c31a-h c21a-h c11a-h c01a-h */
            #if 1 /* bogus thru-mem workaround to buggy code below */
               _mm256_store_ps(v, rC0_0);
               _mm256_store_ps(v+8, rC0_1);
               #ifdef BETA0
                  *pC0 = v[0];
                  pC0[2] = v[1];
                  pC0[4] = v[2];
                  pC0[6] = v[3];
                  *pC1 = v[8];
                  pC1[2] = v[9];
                  pC1[4] = v[10];
                  pC1[6] = v[11];
               #elif defined(BETAX)
                  *pC0   = beta*(*pC0) + v[0];
                  pC0[2] = beta*pC0[2] + v[1];
                  pC0[4] = beta*pC0[4] + v[2];
                  pC0[6] = beta*pC0[6] + v[3];
                  *pC1   = beta*(*pC1) + v[8];
                  pC1[2] = beta*pC1[2] + v[9];
                  pC1[4] = beta*pC1[4] + v[10];
                  pC1[6] = beta*pC1[6] + v[11];
               #else
                  *pC0   += v[0];
                  pC0[2] += v[1];
                  pC0[4] += v[2];
                  pC0[6] += v[3];
                  *pC1   += v[8];
                  pC1[2] += v[9];
                  pC1[4] += v[10];
                  pC1[6] += v[11];
               #endif
            pC0 += 8; pC1 += 8;
            #else /* this code seems right, but does not work */
      v[0] = v[2] = v[4] = v[6] = beta;
      v[1] = v[3] = v[5] = v[7] = ATL_rone;
            rC1_0 = _mm256_loadu_ps(pC0); /* zz C30 yy C20 xx C10 rr C00 */
            t0 = _mm256_setzero_ps();     /*  0   0  0   0  0   0  0   0 */
            rC1_1 = _mm256_loadu_ps(pC1); /* zz C31 yy C21 xx C11 rr C01 */
            #ifdef BETA0
               rC1_0 = _mm256_blend_ps(rC1_0, t0, 0x55/*0b0101 0101*/);
               rC1_1 = _mm256_blend_ps(rC1_1, t0, 0x55/*0b0101 0101*/);
                       /* zz 0 yy 0 xx 0 rr 0 */
            #elif defined(BETAX)
               rC3_0 = _mm256_load_ps(v);  /* 1 beta 1 beta 1 beta 1 beta */
               rC1_0 = _mm256_mul_ps(rC1_0, rC3_0);
               rC1_1 = _mm256_mul_ps(rC1_1, rC3_0);
                     /* zz b*C3 yy b*C20 xx b*C10 rr b*c00 */
            #endif
            rC0_0 = _mm256_unpacklo_ps(rC0_0, t0);
                    /* 0 c3a-h 0 c2a-h 0 c1a-h 0 c0a-h */
            rC0_0 = _mm256_add_ps(rC0_0, rC1_0);
                    /* zz c3a-h yy c2a-h xx c1a-h rr c0a-h */
            _mm256_storeu_ps(pC0, rC0_0);
            pC0 += 8;

            rC0_1 = _mm256_unpacklo_ps(rC0_1, t0);
            rC0_1 = _mm256_add_ps(rC0_1, rC1_1);
            _mm256_storeu_ps(pC1, rC0_1);
            pC1 += 8;
            #endif
         #else
         {
            __m128 a, b;
            #ifdef BETAX
               __m128 bet;
            #endif
            a = _mm256_castps256_ps128(rC0_0);
                /* c30abcd c20abcd c10abcd c00abcd */
            b = _mm256_extractf128_ps(rC0_0, 1);
                /* c30efgh c20efgh c10efgh c00efgh */
            a = _mm_add_ps(a, b); /* c30a-h c20a-h c10a-h c00a-h */
            #if !defined(BETA0)
               b = _mm_loadu_ps(pC0);
               #ifdef BETAX
                  bet = _mm_load1_ps(&beta);
                  b = _mm_mul_ps(b, bet);
               #endif
               a = _mm_add_ps(a, b);
            #endif
            _mm_storeu_ps(pC0, a);
            pC0 += 4;
            a = _mm256_castps256_ps128(rC0_1);
            b = _mm256_extractf128_ps(rC0_1, 1);
            a = _mm_add_ps(a, b);
            #if !defined(BETA0)
               b = _mm_loadu_ps(pC1);
               #ifdef BETAX
                  b = _mm_mul_ps(b, bet);
               #endif
               a = _mm_add_ps(a, b);
            #endif
            _mm_storeu_ps(pC1, a);
            pC1 += 4;
         }
         #endif

      }
      while(pA0 != stM);
      pC0 += incCn;
      pC1 += incCn;
      pA0 += incAn;
      pB0 += incBn;
   }
   while(pB0 != stN);
}
