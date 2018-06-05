#ifndef ATL_RESTRICT
#if defined(__STDC_VERSION__) && (__STDC_VERSION__/100 >= 1999)
   #define ATL_RESTRICT restrict
#else
   #define ATL_RESTRICT
#endif
#endif
#include "atlas_prefetch.h"

void ATL_cJIK48x48x48TT0x0x0_aX_bX
   (const int M, const int N, const int K, const float alpha, const float * ATL_RESTRICT A, const int lda, const float * ATL_RESTRICT B, const int ldb, const float beta, float * ATL_RESTRICT C, const int ldc)
/*
 * matmul with TA=T, TB=T, MB=48, NB=48, KB=48, 
 * lda=0, ldb=0, ldc=0, mu=12, nu=1, ku=4, pf=1
 * Generated by ATLAS/tune/blas/gemm/emit_mm.c (3.10.3)
 */
{
   const float *stM = A + (((lda) << 6)+((lda) << 5));
   const float *stN = B + 96;
   const float *pfA = A + M;
   const float BetaAlpha = beta / alpha;
   #define incAk 8
   const int incAm = ((((((lda) << 3)+((lda) << 2)) - 48) << 1)), incAn = -(((lda) << 6)+((lda) << 5));
   const int incBk = (((ldb) << 1)), incBm = -(((ldb) << 6)+((ldb) << 5));
   #define incBn 2
   #define incCm 24
   const int incCn = (((ldc) << 1)) - 96;
   float *pC0=C;
   const float *pA0=A, *pA1=pA0+(((lda) << 1)), *pA2=pA1+(((lda) << 1)), *pA3=pA2+(((lda) << 1)), *pA4=pA3+(((lda) << 1)), *pA5=pA4+(((lda) << 1)), *pA6=pA5+(((lda) << 1)), *pA7=pA6+(((lda) << 1)), *pA8=pA7+(((lda) << 1)), *pA9=pA8+(((lda) << 1)), *pA10=pA9+(((lda) << 1)), *pA11=pA10+(((lda) << 1));
   const float *pB0=B;
   register int k;
   register float rA0, rA1, rA2, rA3, rA4, rA5, rA6, rA7, rA8, rA9, rA10, rA11;
   register float rB0;
   register float rC0_0, rC1_0, rC2_0, rC3_0, rC4_0, rC5_0, rC6_0, rC7_0, rC8_0, rC9_0, rC10_0, rC11_0;
   do /* N-loop */
   {
      ATL_pfl1R(pfA+0);
      ATL_pfl1R(pfA+16);
      ATL_pfl1R(pfA+32);
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
         for (k=0; k < 12; k++) /* easy loop to unroll */
         {
            rA0 = *pA0;
            rB0 = *pB0;
            rA1 = *pA1;
            rC0_0 += rA0 * rB0;
            rA2 = *pA2;
            rC1_0 += rA1 * rB0;
            rA3 = *pA3;
            rC2_0 += rA2 * rB0;
            rA4 = *pA4;
            rC3_0 += rA3 * rB0;
            rA5 = *pA5;
            rC4_0 += rA4 * rB0;
            rA6 = *pA6;
            rC5_0 += rA5 * rB0;
            rA7 = *pA7;
            rC6_0 += rA6 * rB0;
            rA8 = *pA8;
            rC7_0 += rA7 * rB0;
            rA9 = *pA9;
            rC8_0 += rA8 * rB0;
            rA10 = *pA10;
            rC9_0 += rA9 * rB0;
            rA11 = *pA11;
            rC10_0 += rA10 * rB0;
            rC11_0 += rA11 * rB0;
            pB0 += incBk;
            rA0 = pA0[2];
            rB0 = *pB0;
            rA1 = pA1[2];
            rC0_0 += rA0 * rB0;
            rA2 = pA2[2];
            rC1_0 += rA1 * rB0;
            rA3 = pA3[2];
            rC2_0 += rA2 * rB0;
            rA4 = pA4[2];
            rC3_0 += rA3 * rB0;
            rA5 = pA5[2];
            rC4_0 += rA4 * rB0;
            rA6 = pA6[2];
            rC5_0 += rA5 * rB0;
            rA7 = pA7[2];
            rC6_0 += rA6 * rB0;
            rA8 = pA8[2];
            rC7_0 += rA7 * rB0;
            rA9 = pA9[2];
            rC8_0 += rA8 * rB0;
            rA10 = pA10[2];
            rC9_0 += rA9 * rB0;
            rA11 = pA11[2];
            rC10_0 += rA10 * rB0;
            rC11_0 += rA11 * rB0;
            pB0 += incBk;
            rA0 = pA0[4];
            rB0 = *pB0;
            rA1 = pA1[4];
            rC0_0 += rA0 * rB0;
            rA2 = pA2[4];
            rC1_0 += rA1 * rB0;
            rA3 = pA3[4];
            rC2_0 += rA2 * rB0;
            rA4 = pA4[4];
            rC3_0 += rA3 * rB0;
            rA5 = pA5[4];
            rC4_0 += rA4 * rB0;
            rA6 = pA6[4];
            rC5_0 += rA5 * rB0;
            rA7 = pA7[4];
            rC6_0 += rA6 * rB0;
            rA8 = pA8[4];
            rC7_0 += rA7 * rB0;
            rA9 = pA9[4];
            rC8_0 += rA8 * rB0;
            rA10 = pA10[4];
            rC9_0 += rA9 * rB0;
            rA11 = pA11[4];
            rC10_0 += rA10 * rB0;
            rC11_0 += rA11 * rB0;
            pB0 += incBk;
            rA0 = pA0[6];
            rB0 = *pB0;
            rA1 = pA1[6];
            rC0_0 += rA0 * rB0;
            rA2 = pA2[6];
            rC1_0 += rA1 * rB0;
            rA3 = pA3[6];
            rC2_0 += rA2 * rB0;
            rA4 = pA4[6];
            rC3_0 += rA3 * rB0;
            rA5 = pA5[6];
            rC4_0 += rA4 * rB0;
            rA6 = pA6[6];
            rC5_0 += rA5 * rB0;
            rA7 = pA7[6];
            rC6_0 += rA6 * rB0;
            rA8 = pA8[6];
            rC7_0 += rA7 * rB0;
            rA9 = pA9[6];
            rC8_0 += rA8 * rB0;
            rA10 = pA10[6];
            rC9_0 += rA9 * rB0;
            rA11 = pA11[6];
            rC10_0 += rA10 * rB0;
            rC11_0 += rA11 * rB0;
            pB0 += incBk;
            pA0 += incAk;
            pA1 += incAk;
            pA2 += incAk;
            pA3 += incAk;
            pA4 += incAk;
            pA5 += incAk;
            pA6 += incAk;
            pA7 += incAk;
            pA8 += incAk;
            pA9 += incAk;
            pA10 += incAk;
            pA11 += incAk;
         }
         pB0 -= 0*incBk;
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
         pA1 += incAm;
         pA2 += incAm;
         pA3 += incAm;
         pA4 += incAm;
         pA5 += incAm;
         pA6 += incAm;
         pA7 += incAm;
         pA8 += incAm;
         pA9 += incAm;
         pA10 += incAm;
         pA11 += incAm;
         pB0 += incBm;
      }
      while(pA0 != stM);
      pC0 += incCn;
      pA0 += incAn;
      pA1 += incAn;
      pA2 += incAn;
      pA3 += incAn;
      pA4 += incAn;
      pA5 += incAn;
      pA6 += incAn;
      pA7 += incAn;
      pA8 += incAn;
      pA9 += incAn;
      pA10 += incAn;
      pA11 += incAn;
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