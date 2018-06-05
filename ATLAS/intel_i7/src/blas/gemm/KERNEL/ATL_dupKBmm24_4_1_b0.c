#define ATL_USERMM ATL_dupKBmm24_4_1_b0
#define ATL_USERMM_b1 ATL_dupKBmm24_4_1_b1
#define ATL_USERMM_bn1 ATL_dupKBmm24_4_1_bn1
#define ATL_USERMM_b0 ATL_dupKBmm24_4_1_b0
#define ATL_USERMM_bX ATL_dupKBmm24_4_1_bX
#define BETA0
#define DREAL

#define MB 56
#define NB 56
#define KB 24

#define MBMB 3136
#define NBNB 3136
#define KBKB 576

#define MB2 112
#define NB2 112
#define KB2 48


#define MB3 168
#define NB3 168
#define KB3 72


#define MB4 224
#define NB4 224
#define KB4 96


#define MB5 280
#define NB5 280
#define KB5 120


#define MB6 336
#define NB6 336
#define KB6 144


#define MB7 392
#define NB7 392
#define KB7 168


#define MB8 448
#define NB8 448
#define KB8 192

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

#include <atlas_misc.h>
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
   (const int M, const int N, const int K, const double alpha,
    const double * ATL_RESTRICT A, const int lda,
    const double * ATL_RESTRICT B, const int ldb, const double beta,
    double * ATL_RESTRICT C, const int ldc)
/*
 * matmul with TA=T, TB=N, MB=0, NB=0, KB=56,
 * lda=56, ldb=56, ldc=0, mu=4, nu=2, ku=1, pf=0
 * Generated by ATLAS/tune/blas/gemm/emit_mm.c (3.9.39)
 */
{
   const int Mb = (M>>2)<<2;
   const int Nb = (N>>1)<<1;
   const double *stM = A + (KB*(Mb));
   const double *stN = B + (KB*(Nb));
   const double *pfA = stM;
   const int incAm = 3*KB, incAn = -(KB*(Mb));
   const int incBm = -KB, incBn = 2*KB;
   const int incCn = ((((ldc) << 1)) - (Mb))SHIFT;
   double *pC0=C, *pC1=pC0+(ldc SHIFT);
   const double *pA0=A;
   const double *pB0=B;
   register int k;
   register __m256d rA0, rA1, rA2, rA3;
   register __m256d rB0, rB1, t0;
   register __m256d rC0_0, rC1_0, rC2_0, rC3_0, rC0_1, rC1_1, rC2_1, rC3_1;
   #ifndef BETA0
      register __m256d rc00;
   #endif
   #ifdef TCPLX
      TYPE V[8], *v;
      v = ATL_AlignPtr(V);
   #endif
   do /* N-loop */
   {
      do /* M-loop */
      {
         rC0_0 = _mm256_setzero_pd();
         rC1_0 = _mm256_setzero_pd();
         rC2_0 = _mm256_setzero_pd();
         rC3_0 = _mm256_setzero_pd();
         #if !defined(BETA0) && !defined(TCPLX)
            rc00 = _mm256_loadu_pd(pC0);
            #ifdef BETAX
               t0 = _mm256_broadcast_sd(&beta);
               rc00 =  _mm256_mul_pd(rc00, t0);
            #endif
         #endif
         rC0_1 = _mm256_setzero_pd();
         rC1_1 = _mm256_setzero_pd();
         rC2_1 = _mm256_setzero_pd();
         rC3_1 = _mm256_setzero_pd();
         for (k=0; k < KB; k += 4) /* easy loop to unroll */
         {
            rA0 = _mm256_load_pd(pA0);
            rB0 = _mm256_load_pd(pB0);
            rA1 = _mm256_load_pd(pA0+KB);
            rA2 = _mm256_load_pd(pA0+2*KB);
            rA3 = _mm256_load_pd(pA0+3*KB);
            rB1 = _mm256_load_pd(pB0+KB);

            t0 = _mm256_mul_pd(rA0, rB0);
            rC0_0 = _mm256_add_pd(rC0_0, t0);
            t0 = _mm256_mul_pd(rA1, rB0);
            rC1_0 = _mm256_add_pd(rC1_0, t0);
            t0 = _mm256_mul_pd(rA2, rB0);
            rC2_0 = _mm256_add_pd(rC2_0, t0);
            t0 = _mm256_mul_pd(rA3, rB0);
            rC3_0 = _mm256_add_pd(rC3_0, t0);
            t0 = _mm256_mul_pd(rA0, rB1);
            rC0_1 = _mm256_add_pd(rC0_1, t0);
            t0 = _mm256_mul_pd(rA1, rB1);
            rC1_1 = _mm256_add_pd(rC1_1, t0);
            t0 = _mm256_mul_pd(rA2, rB1);
            rC2_1 = _mm256_add_pd(rC2_1, t0);
            t0 = _mm256_mul_pd(rA3, rB1);
            rC3_1 = _mm256_add_pd(rC3_1, t0);

            pA0 += 4;
            pB0 += 4;
         }
         #if !defined(BETA0) && !defined(TCPLX)
            t0 = _mm256_loadu_pd(pC1);
         #endif
         rC0_0 = _mm256_hadd_pd(rC0_0, rC1_0);  /* c10cd c00cd c10ab c00ab */
         rC2_0 = _mm256_hadd_pd(rC2_0, rC3_0);  /* c30cd c20cd c30ab c20ab */
         #if defined(BETAX) && !defined(TCPLX)
            rC3_0 = _mm256_broadcast_sd(&beta);
            t0 =  _mm256_mul_pd(t0, rC3_0);
         #endif

         rC1_0 = _mm256_permute2f128_pd(rC0_0, rC2_0, 32);
             /* 0b 0 10 00 00 = 32 */           /* c30ab c20ab c10ab c00ab */
         rC0_0 = _mm256_permute2f128_pd(rC0_0, rC2_0, 49);
         _mm_prefetch(pfA, 1);
             /* 0b 0 11 00 01 = 1+16+32=97*/    /* c30cd c20cd c10cd c00cd */
         rC0_0 = _mm256_add_pd(rC0_0, rC1_0);
                                        /* c30abcd c20abcd c10abcd c00abcd */
         #ifdef TCPLX
            _mm256_store_pd(v, rC0_0);
            #ifdef BETA0
               *pC0 = v[0]; pC0[2] = v[1]; pC0[4] = v[2]; pC0[6] = v[3];
            #elif defined(BETA1)
               *pC0 += v[0]; pC0[2] += v[1]; pC0[4] += v[2]; pC0[6] += v[3];
            #else
               *pC0   = beta*(*pC0) + v[0];
               pC0[2] = beta*pC0[2] + v[1];
               pC0[4] = beta*pC0[4] + v[2];
               pC0[6] = beta*pC0[6] + v[3];
            #endif
         #else
            #if !defined(BETA0) && !defined(TCPLX)
               rC0_0 = _mm256_add_pd(rC0_0, rc00);
            #endif
            _mm256_storeu_pd(pC0, rC0_0);
         #endif

         rC0_1 = _mm256_hadd_pd(rC0_1, rC1_1);  /* c11cd c01cd c11ab c01ab */
         rC2_1 = _mm256_hadd_pd(rC2_1, rC3_1);  /* c31cd c21cd c31ab c21ab */
         rC1_1 = _mm256_permute2f128_pd(rC0_1, rC2_1, 32);
             /* 0b 0 10 00 00 = 32 */           /* c31ab c21ab c11ab c01ab */
         rC0_1 = _mm256_permute2f128_pd(rC0_1, rC2_1, 49);
             /* 0b 0 11 00 01 = 1+16+32=97*/    /* c31cd c21cd c11cd c01cd */
         rC0_1 = _mm256_add_pd(rC0_1, rC1_1);
                                        /* c31abcd c21abcd c11abcd c01abcd */
         #ifdef TCPLX
            _mm256_store_pd(v, rC0_1);
            pfA += 8;
            #ifdef BETA0
               *pC1 = v[0]; pC1[2] = v[1]; pC1[4] = v[2]; pC1[6] = v[3];
            #elif defined(BETA1)
               *pC1 += v[0]; pC1[2] += v[1]; pC1[4] += v[2]; pC1[6] += v[3];
            #else
               *pC1   = beta*(*pC1) + v[0];
               pC1[2] = beta*pC1[2] + v[1];
               pC1[4] = beta*pC1[4] + v[2];
               pC1[6] = beta*pC1[6] + v[3];
            #endif
         #else
            #ifndef BETA0
               rC0_1 = _mm256_add_pd(rC0_1, t0);
            #endif
            pfA += 8;
            _mm256_storeu_pd(pC1, rC0_1);
         #endif

         pC0 += 4 SHIFT;
         pC1 += 4 SHIFT;
         pA0 += incAm;
         pB0 += incBm;
      }
      while(pA0 != stM);
      pC0 += incCn;
      pC1 += incCn;
      pA0 += incAn;
      pB0 += incBn;
   }
   while(pB0 != stN);
}
