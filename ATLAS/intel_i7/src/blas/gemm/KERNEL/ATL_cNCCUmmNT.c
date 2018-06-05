#ifndef ATL_RESTRICT
#if defined(__STDC_VERSION__) && (__STDC_VERSION__/100 >= 1999)
   #define ATL_RESTRICT restrict
#else
   #define ATL_RESTRICT
#endif
#endif
#include "atlas_prefetch.h"

#ifndef ATL_RESTRICT
#if defined(__STDC_VERSION__) && (__STDC_VERSION__/100 >= 1999)
   #define ATL_RESTRICT restrict
#else
   #define ATL_RESTRICT
#endif
#endif
#include "atlas_prefetch.h"

static void ATL_cJIK0x0x0NT1x1x4_aX_bX
   (const int M, const int N, const int K, const float alpha, const float * ATL_RESTRICT A, const int lda, const float * ATL_RESTRICT B, const int ldb, const float beta, float * ATL_RESTRICT C, const int ldc)
/*
 * matmul with TA=N, TB=T, MB=0, NB=0, KB=0, 
 * lda=0, ldb=0, ldc=0, mu=1, nu=1, ku=4, pf=1
 * Generated by ATLAS/tune/blas/gemm/emit_mm.c (3.10.3)
 */
{
   #define Mb M
   #define Nb N
   const int Kb = (K>>2)<<2;
   const float *stM = A + (((Mb) << 1));
   const float *stN = B + (((Nb) << 1));
   const float *pfA = A + lda*M;
   const float BetaAlpha = beta / alpha;
   const int incAk = (((lda) << 1));
   const int incAm = 2 - (((Kb*lda) << 1)), incAn = -(((Mb) << 1));
   const int incBk = (((ldb) << 1)), incBm = -(((Kb*ldb) << 1));
   #define incBn 2
   #define incCm 2
   const int incCn = (((ldc) << 1)) - (((Mb) << 1));
   float *pC0=C;
   const float *pA0=A;
   const float *pB0=B;
   register int k;
   register float rA0;
   register float rB0;
   register float rC0_0;
   do /* N-loop */
   {
      ATL_pfl1R(pfA+0);
      ATL_pfl1R(pfA+16);
      pfA += lda;
      do /* M-loop */
      {
         rA0 = BetaAlpha;
         rC0_0 = *pC0;
         rC0_0 *= rA0;
         for (k=0; k < Kb; k += 4) /* easy loop to unroll */
         {
            rA0 = *pA0;
            rB0 = *pB0;
            rC0_0 += rA0 * rB0;
            pA0 += incAk;
            pB0 += incBk;
            rA0 = *pA0;
            rB0 = *pB0;
            rC0_0 += rA0 * rB0;
            pA0 += incAk;
            pB0 += incBk;
            rA0 = *pA0;
            rB0 = *pB0;
            rC0_0 += rA0 * rB0;
            pA0 += incAk;
            pB0 += incBk;
            rA0 = *pA0;
            rB0 = *pB0;
            rC0_0 += rA0 * rB0;
            pA0 += incAk;
            pB0 += incBk;
         }
         switch(k = (K-Kb))
         {
         case 1:
            rA0 = *pA0;
            rB0 = *pB0;
            rC0_0 += rA0 * rB0;
            pA0 += incAk;
            pB0 += incBk;
            break;
         case 2:
            rA0 = *pA0;
            rB0 = *pB0;
            rC0_0 += rA0 * rB0;
            pA0 += incAk;
            pB0 += incBk;
            rA0 = *pA0;
            rB0 = *pB0;
            rC0_0 += rA0 * rB0;
            pA0 += incAk;
            pB0 += incBk;
            break;
         case 3:
            rA0 = *pA0;
            rB0 = *pB0;
            rC0_0 += rA0 * rB0;
            pA0 += incAk;
            pB0 += incBk;
            rA0 = *pA0;
            rB0 = *pB0;
            rC0_0 += rA0 * rB0;
            pA0 += incAk;
            pB0 += incBk;
            rA0 = *pA0;
            rB0 = *pB0;
            rC0_0 += rA0 * rB0;
            pA0 += incAk;
            pB0 += incBk;
            break;
         case 0: ;
         }
         pA0 -= k*incAk;
         pB0 -= k*incBk;
         rB0 = alpha;
         rC0_0 *= rB0;
         *pC0 = rC0_0;
         pC0 += incCm;
         pA0 += incAm;
         pB0 += incBm;
      }
      while(pA0 != stM);
      pC0 += incCn;
      pA0 += incAn;
      pB0 += incBn;
   }
   while(pB0 != stN);
}
#ifdef incAm
   #undef incAm
#endif
#ifdef incAn
   #undef incAn
#endif
#ifdef incAk
   #undef incAk
#endif
#ifdef incBm
   #undef incBm
#endif
#ifdef incBn
   #undef incBn
#endif
#ifdef incBk
   #undef incBk
#endif
#ifdef incCm
   #undef incCm
#endif
#ifdef incCn
   #undef incCn
#endif
#ifdef incCk
   #undef incCk
#endif
#ifdef Mb
   #undef Mb
#endif
#ifdef Nb
   #undef Nb
#endif
#ifdef Kb
   #undef Kb
#endif
void ATL_cJIK0x0x0NT0x0x0_aX_bX
   (const int M, const int N, const int K, const float alpha, const float * ATL_RESTRICT A, const int lda, const float * ATL_RESTRICT B, const int ldb, const float beta, float * ATL_RESTRICT C, const int ldc)
/*
 * matmul with TA=N, TB=T, MB=0, NB=0, KB=0, 
 * lda=0, ldb=0, ldc=0, mu=12, nu=1, ku=4, pf=1
 * Generated by ATLAS/tune/blas/gemm/emit_mm.c (3.10.3)
 */
{
   const int Mb = (M/12)*12;
   #define Nb N
   const int Kb = (K>>2)<<2;
   const float *ca=A, *cb=B;
   float *cc=C;
   const float *stM = A + (((Mb) << 1));
   const float *stN = B + (((Nb) << 1));
   const float *pfA = A + lda*M;
   const float BetaAlpha = beta / alpha;
   const int incAk = (((lda) << 1));
   const int incAm = 24 - (((Kb*lda) << 1)), incAn = -(((Mb) << 1));
   const int incBk = (((ldb) << 1)), incBm = -(((Kb*ldb) << 1));
   #define incBn 2
   #define incCm 24
   const int incCn = (((ldc) << 1)) - (((Mb) << 1));
   float *pC0=C;
   const float *pA0=A;
   const float *pB0=B;
   register int k;
   register float rA0, rA1, rA2, rA3, rA4, rA5, rA6, rA7, rA8, rA9, rA10, rA11;
   register float rB0;
   register float rC0_0, rC1_0, rC2_0, rC3_0, rC4_0, rC5_0, rC6_0, rC7_0, rC8_0, rC9_0, rC10_0, rC11_0;
   if (pA0 != stM)
   {
      do /* N-loop */
      {
         ATL_pfl1R(pfA+0);
         ATL_pfl1R(pfA+16);
         pfA += lda;
         do /* M-loop */
         {
            rA0 = BetaAlpha;
            rC0_0 = *pC0;
            rC0_0 *= rA0;
            rC1_0 = pC0[2];
            rC1_0 *= rA0;
            rC2_0 = pC0[4];
            rC2_0 *= rA0;
            rC3_0 = pC0[6];
            rC3_0 *= rA0;
            rC4_0 = pC0[8];
            rC4_0 *= rA0;
            rC5_0 = pC0[10];
            rC5_0 *= rA0;
            rC6_0 = pC0[12];
            rC6_0 *= rA0;
            rC7_0 = pC0[14];
            rC7_0 *= rA0;
            rC8_0 = pC0[16];
            rC8_0 *= rA0;
            rC9_0 = pC0[18];
            rC9_0 *= rA0;
            rC10_0 = pC0[20];
            rC10_0 *= rA0;
            rC11_0 = pC0[22];
            rC11_0 *= rA0;
            for (k=0; k < Kb; k += 4) /* easy loop to unroll */
            {
               rA0 = *pA0;
               rB0 = *pB0;
               rA1 = pA0[2];
               rC0_0 += rA0 * rB0;
               rA2 = pA0[4];
               rC1_0 += rA1 * rB0;
               rA3 = pA0[6];
               rC2_0 += rA2 * rB0;
               rA4 = pA0[8];
               rC3_0 += rA3 * rB0;
               rA5 = pA0[10];
               rC4_0 += rA4 * rB0;
               rA6 = pA0[12];
               rC5_0 += rA5 * rB0;
               rA7 = pA0[14];
               rC6_0 += rA6 * rB0;
               rA8 = pA0[16];
               rC7_0 += rA7 * rB0;
               rA9 = pA0[18];
               rC8_0 += rA8 * rB0;
               rA10 = pA0[20];
               rC9_0 += rA9 * rB0;
               rA11 = pA0[22];
               rC10_0 += rA10 * rB0;
               rC11_0 += rA11 * rB0;
               pA0 += incAk;
               pB0 += incBk;
               rA0 = *pA0;
               rB0 = *pB0;
               rA1 = pA0[2];
               rC0_0 += rA0 * rB0;
               rA2 = pA0[4];
               rC1_0 += rA1 * rB0;
               rA3 = pA0[6];
               rC2_0 += rA2 * rB0;
               rA4 = pA0[8];
               rC3_0 += rA3 * rB0;
               rA5 = pA0[10];
               rC4_0 += rA4 * rB0;
               rA6 = pA0[12];
               rC5_0 += rA5 * rB0;
               rA7 = pA0[14];
               rC6_0 += rA6 * rB0;
               rA8 = pA0[16];
               rC7_0 += rA7 * rB0;
               rA9 = pA0[18];
               rC8_0 += rA8 * rB0;
               rA10 = pA0[20];
               rC9_0 += rA9 * rB0;
               rA11 = pA0[22];
               rC10_0 += rA10 * rB0;
               rC11_0 += rA11 * rB0;
               pA0 += incAk;
               pB0 += incBk;
               rA0 = *pA0;
               rB0 = *pB0;
               rA1 = pA0[2];
               rC0_0 += rA0 * rB0;
               rA2 = pA0[4];
               rC1_0 += rA1 * rB0;
               rA3 = pA0[6];
               rC2_0 += rA2 * rB0;
               rA4 = pA0[8];
               rC3_0 += rA3 * rB0;
               rA5 = pA0[10];
               rC4_0 += rA4 * rB0;
               rA6 = pA0[12];
               rC5_0 += rA5 * rB0;
               rA7 = pA0[14];
               rC6_0 += rA6 * rB0;
               rA8 = pA0[16];
               rC7_0 += rA7 * rB0;
               rA9 = pA0[18];
               rC8_0 += rA8 * rB0;
               rA10 = pA0[20];
               rC9_0 += rA9 * rB0;
               rA11 = pA0[22];
               rC10_0 += rA10 * rB0;
               rC11_0 += rA11 * rB0;
               pA0 += incAk;
               pB0 += incBk;
               rA0 = *pA0;
               rB0 = *pB0;
               rA1 = pA0[2];
               rC0_0 += rA0 * rB0;
               rA2 = pA0[4];
               rC1_0 += rA1 * rB0;
               rA3 = pA0[6];
               rC2_0 += rA2 * rB0;
               rA4 = pA0[8];
               rC3_0 += rA3 * rB0;
               rA5 = pA0[10];
               rC4_0 += rA4 * rB0;
               rA6 = pA0[12];
               rC5_0 += rA5 * rB0;
               rA7 = pA0[14];
               rC6_0 += rA6 * rB0;
               rA8 = pA0[16];
               rC7_0 += rA7 * rB0;
               rA9 = pA0[18];
               rC8_0 += rA8 * rB0;
               rA10 = pA0[20];
               rC9_0 += rA9 * rB0;
               rA11 = pA0[22];
               rC10_0 += rA10 * rB0;
               rC11_0 += rA11 * rB0;
               pA0 += incAk;
               pB0 += incBk;
            }
            switch(k = (K-Kb))
            {
            case 1:
               rA0 = *pA0;
               rB0 = *pB0;
               rA1 = pA0[2];
               rC0_0 += rA0 * rB0;
               rA2 = pA0[4];
               rC1_0 += rA1 * rB0;
               rA3 = pA0[6];
               rC2_0 += rA2 * rB0;
               rA4 = pA0[8];
               rC3_0 += rA3 * rB0;
               rA5 = pA0[10];
               rC4_0 += rA4 * rB0;
               rA6 = pA0[12];
               rC5_0 += rA5 * rB0;
               rA7 = pA0[14];
               rC6_0 += rA6 * rB0;
               rA8 = pA0[16];
               rC7_0 += rA7 * rB0;
               rA9 = pA0[18];
               rC8_0 += rA8 * rB0;
               rA10 = pA0[20];
               rC9_0 += rA9 * rB0;
               rA11 = pA0[22];
               rC10_0 += rA10 * rB0;
               rC11_0 += rA11 * rB0;
               pA0 += incAk;
               pB0 += incBk;
               break;
            case 2:
               rA0 = *pA0;
               rB0 = *pB0;
               rA1 = pA0[2];
               rC0_0 += rA0 * rB0;
               rA2 = pA0[4];
               rC1_0 += rA1 * rB0;
               rA3 = pA0[6];
               rC2_0 += rA2 * rB0;
               rA4 = pA0[8];
               rC3_0 += rA3 * rB0;
               rA5 = pA0[10];
               rC4_0 += rA4 * rB0;
               rA6 = pA0[12];
               rC5_0 += rA5 * rB0;
               rA7 = pA0[14];
               rC6_0 += rA6 * rB0;
               rA8 = pA0[16];
               rC7_0 += rA7 * rB0;
               rA9 = pA0[18];
               rC8_0 += rA8 * rB0;
               rA10 = pA0[20];
               rC9_0 += rA9 * rB0;
               rA11 = pA0[22];
               rC10_0 += rA10 * rB0;
               rC11_0 += rA11 * rB0;
               pA0 += incAk;
               pB0 += incBk;
               rA0 = *pA0;
               rB0 = *pB0;
               rA1 = pA0[2];
               rC0_0 += rA0 * rB0;
               rA2 = pA0[4];
               rC1_0 += rA1 * rB0;
               rA3 = pA0[6];
               rC2_0 += rA2 * rB0;
               rA4 = pA0[8];
               rC3_0 += rA3 * rB0;
               rA5 = pA0[10];
               rC4_0 += rA4 * rB0;
               rA6 = pA0[12];
               rC5_0 += rA5 * rB0;
               rA7 = pA0[14];
               rC6_0 += rA6 * rB0;
               rA8 = pA0[16];
               rC7_0 += rA7 * rB0;
               rA9 = pA0[18];
               rC8_0 += rA8 * rB0;
               rA10 = pA0[20];
               rC9_0 += rA9 * rB0;
               rA11 = pA0[22];
               rC10_0 += rA10 * rB0;
               rC11_0 += rA11 * rB0;
               pA0 += incAk;
               pB0 += incBk;
               break;
            case 3:
               rA0 = *pA0;
               rB0 = *pB0;
               rA1 = pA0[2];
               rC0_0 += rA0 * rB0;
               rA2 = pA0[4];
               rC1_0 += rA1 * rB0;
               rA3 = pA0[6];
               rC2_0 += rA2 * rB0;
               rA4 = pA0[8];
               rC3_0 += rA3 * rB0;
               rA5 = pA0[10];
               rC4_0 += rA4 * rB0;
               rA6 = pA0[12];
               rC5_0 += rA5 * rB0;
               rA7 = pA0[14];
               rC6_0 += rA6 * rB0;
               rA8 = pA0[16];
               rC7_0 += rA7 * rB0;
               rA9 = pA0[18];
               rC8_0 += rA8 * rB0;
               rA10 = pA0[20];
               rC9_0 += rA9 * rB0;
               rA11 = pA0[22];
               rC10_0 += rA10 * rB0;
               rC11_0 += rA11 * rB0;
               pA0 += incAk;
               pB0 += incBk;
               rA0 = *pA0;
               rB0 = *pB0;
               rA1 = pA0[2];
               rC0_0 += rA0 * rB0;
               rA2 = pA0[4];
               rC1_0 += rA1 * rB0;
               rA3 = pA0[6];
               rC2_0 += rA2 * rB0;
               rA4 = pA0[8];
               rC3_0 += rA3 * rB0;
               rA5 = pA0[10];
               rC4_0 += rA4 * rB0;
               rA6 = pA0[12];
               rC5_0 += rA5 * rB0;
               rA7 = pA0[14];
               rC6_0 += rA6 * rB0;
               rA8 = pA0[16];
               rC7_0 += rA7 * rB0;
               rA9 = pA0[18];
               rC8_0 += rA8 * rB0;
               rA10 = pA0[20];
               rC9_0 += rA9 * rB0;
               rA11 = pA0[22];
               rC10_0 += rA10 * rB0;
               rC11_0 += rA11 * rB0;
               pA0 += incAk;
               pB0 += incBk;
               rA0 = *pA0;
               rB0 = *pB0;
               rA1 = pA0[2];
               rC0_0 += rA0 * rB0;
               rA2 = pA0[4];
               rC1_0 += rA1 * rB0;
               rA3 = pA0[6];
               rC2_0 += rA2 * rB0;
               rA4 = pA0[8];
               rC3_0 += rA3 * rB0;
               rA5 = pA0[10];
               rC4_0 += rA4 * rB0;
               rA6 = pA0[12];
               rC5_0 += rA5 * rB0;
               rA7 = pA0[14];
               rC6_0 += rA6 * rB0;
               rA8 = pA0[16];
               rC7_0 += rA7 * rB0;
               rA9 = pA0[18];
               rC8_0 += rA8 * rB0;
               rA10 = pA0[20];
               rC9_0 += rA9 * rB0;
               rA11 = pA0[22];
               rC10_0 += rA10 * rB0;
               rC11_0 += rA11 * rB0;
               pA0 += incAk;
               pB0 += incBk;
               break;
            case 0: ;
            }
            pA0 -= k*incAk;
            pB0 -= k*incBk;
            rB0 = alpha;
            rC0_0 *= rB0;
            rC1_0 *= rB0;
            rC2_0 *= rB0;
            rC3_0 *= rB0;
            rC4_0 *= rB0;
            rC5_0 *= rB0;
            rC6_0 *= rB0;
            rC7_0 *= rB0;
            rC8_0 *= rB0;
            rC9_0 *= rB0;
            rC10_0 *= rB0;
            rC11_0 *= rB0;
            *pC0 = rC0_0;
            pC0[2] = rC1_0;
            pC0[4] = rC2_0;
            pC0[6] = rC3_0;
            pC0[8] = rC4_0;
            pC0[10] = rC5_0;
            pC0[12] = rC6_0;
            pC0[14] = rC7_0;
            pC0[16] = rC8_0;
            pC0[18] = rC9_0;
            pC0[20] = rC10_0;
            pC0[22] = rC11_0;
            pC0 += incCm;
            pA0 += incAm;
            pB0 += incBm;
         }
         while(pA0 != stM);
         pC0 += incCn;
         pA0 += incAn;
         pB0 += incBn;
      }
      while(pB0 != stN);
   }
   if (k=M-Mb)
      ATL_cJIK0x0x0NT1x1x4_aX_bX(k, N, K, alpha, ca + (((Mb) << 1)), lda, cb, ldb, beta, cc + (((Mb) << 1)), ldc);
}
#ifdef incAm
   #undef incAm
#endif
#ifdef incAn
   #undef incAn
#endif
#ifdef incAk
   #undef incAk
#endif
#ifdef incBm
   #undef incBm
#endif
#ifdef incBn
   #undef incBn
#endif
#ifdef incBk
   #undef incBk
#endif
#ifdef incCm
   #undef incCm
#endif
#ifdef incCn
   #undef incCn
#endif
#ifdef incCk
   #undef incCk
#endif
#ifdef Mb
   #undef Mb
#endif
#ifdef Nb
   #undef Nb
#endif
#ifdef Kb
   #undef Kb
#endif
