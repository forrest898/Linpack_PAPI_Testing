#ifndef ATL_RESTRICT
#if defined(__STDC_VERSION__) && (__STDC_VERSION__/100 >= 1999)
   #define ATL_RESTRICT restrict
#else
   #define ATL_RESTRICT
#endif
#endif
#include "atlas_prefetch.h"

void ATL_dJIK48x48x48TN0x0x0_a1_bX
   (const int M, const int N, const int K, const double alpha, const double * ATL_RESTRICT A, const int lda, const double * ATL_RESTRICT B, const int ldb, const double beta, double * ATL_RESTRICT C, const int ldc)
/*
 * matmul with TA=T, TB=N, MB=48, NB=48, KB=48, 
 * lda=0, ldb=0, ldc=0, mu=12, nu=1, ku=4, pf=1
 * Generated by ATLAS/tune/blas/gemm/emit_mm.c (3.10.3)
 */
{
   const double *stM = A + (((lda) << 5)+((lda) << 4));
   const double *stN = B + (((ldb) << 5)+((ldb) << 4));
   const double *pfA = A + M;
   #define incAk 4
   const int incAm = ((((lda) << 3)+((lda) << 2)) - 48), incAn = -(((lda) << 5)+((lda) << 4));
   #define incBk 4
   const int incBm = -48, incBn = (ldb);
   #define incCm 12
   const int incCn = (ldc) - 48;
   double *pC0=C;
   const double *pA0=A, *pA1=pA0+(lda), *pA2=pA1+(lda), *pA3=pA2+(lda), *pA4=pA3+(lda), *pA5=pA4+(lda), *pA6=pA5+(lda), *pA7=pA6+(lda), *pA8=pA7+(lda), *pA9=pA8+(lda), *pA10=pA9+(lda), *pA11=pA10+(lda);
   const double *pB0=B;
   register int k;
   register double rA0, rA1, rA2, rA3, rA4, rA5, rA6, rA7, rA8, rA9, rA10, rA11;
   register double rB0;
   register double rC0_0, rC1_0, rC2_0, rC3_0, rC4_0, rC5_0, rC6_0, rC7_0, rC8_0, rC9_0, rC10_0, rC11_0;
   do /* N-loop */
   {
      ATL_pfl1R(pfA+0);
      ATL_pfl1R(pfA+8);
      ATL_pfl1R(pfA+16);
      ATL_pfl1R(pfA+24);
      ATL_pfl1R(pfA+32);
      ATL_pfl1R(pfA+40);
      pfA += lda;
      do /* M-loop */
      {
         rA0 = beta;
         rC0_0 = *pC0;
         rC0_0 *= rA0;
         rC1_0 = pC0[1];
         rC1_0 *= rA0;
         rC2_0 = pC0[2];
         rC2_0 *= rA0;
         rC3_0 = pC0[3];
         rC3_0 *= rA0;
         rC4_0 = pC0[4];
         rC4_0 *= rA0;
         rC5_0 = pC0[5];
         rC5_0 *= rA0;
         rC6_0 = pC0[6];
         rC6_0 *= rA0;
         rC7_0 = pC0[7];
         rC7_0 *= rA0;
         rC8_0 = pC0[8];
         rC8_0 *= rA0;
         rC9_0 = pC0[9];
         rC9_0 *= rA0;
         rC10_0 = pC0[10];
         rC10_0 *= rA0;
         rC11_0 = pC0[11];
         rC11_0 *= rA0;
         for (k=0; k < 12; k++) /* easy loop to unroll */
         {
            rA0 = *pA0;
            rB0 = *pB0;
            rA1 = *pA1;
            rA2 = *pA2;
            rA3 = *pA3;
            rA4 = *pA4;
            rA5 = *pA5;
            rA6 = *pA6;
            rC0_0 += rA0 * rB0;
            rA7 = *pA7;
            rA8 = *pA8;
            rA9 = *pA9;
            rA10 = *pA10;
            rA11 = *pA11;
            rC1_0 += rA1 * rB0;
            rC2_0 += rA2 * rB0;
            rC3_0 += rA3 * rB0;
            rC4_0 += rA4 * rB0;
            rC5_0 += rA5 * rB0;
            rC6_0 += rA6 * rB0;
            rC7_0 += rA7 * rB0;
            rC8_0 += rA8 * rB0;
            rC9_0 += rA9 * rB0;
            rC10_0 += rA10 * rB0;
            rC11_0 += rA11 * rB0;
            rA0 = pA0[1];
            rB0 = pB0[1];
            rA1 = pA1[1];
            rA2 = pA2[1];
            rA3 = pA3[1];
            rA4 = pA4[1];
            rA5 = pA5[1];
            rA6 = pA6[1];
            rC0_0 += rA0 * rB0;
            rA7 = pA7[1];
            rA8 = pA8[1];
            rA9 = pA9[1];
            rA10 = pA10[1];
            rA11 = pA11[1];
            rC1_0 += rA1 * rB0;
            rC2_0 += rA2 * rB0;
            rC3_0 += rA3 * rB0;
            rC4_0 += rA4 * rB0;
            rC5_0 += rA5 * rB0;
            rC6_0 += rA6 * rB0;
            rC7_0 += rA7 * rB0;
            rC8_0 += rA8 * rB0;
            rC9_0 += rA9 * rB0;
            rC10_0 += rA10 * rB0;
            rC11_0 += rA11 * rB0;
            rA0 = pA0[2];
            rB0 = pB0[2];
            rA1 = pA1[2];
            rA2 = pA2[2];
            rA3 = pA3[2];
            rA4 = pA4[2];
            rA5 = pA5[2];
            rA6 = pA6[2];
            rC0_0 += rA0 * rB0;
            rA7 = pA7[2];
            rA8 = pA8[2];
            rA9 = pA9[2];
            rA10 = pA10[2];
            rA11 = pA11[2];
            rC1_0 += rA1 * rB0;
            rC2_0 += rA2 * rB0;
            rC3_0 += rA3 * rB0;
            rC4_0 += rA4 * rB0;
            rC5_0 += rA5 * rB0;
            rC6_0 += rA6 * rB0;
            rC7_0 += rA7 * rB0;
            rC8_0 += rA8 * rB0;
            rC9_0 += rA9 * rB0;
            rC10_0 += rA10 * rB0;
            rC11_0 += rA11 * rB0;
            rA0 = pA0[3];
            rB0 = pB0[3];
            rA1 = pA1[3];
            rA2 = pA2[3];
            rA3 = pA3[3];
            rA4 = pA4[3];
            rA5 = pA5[3];
            rA6 = pA6[3];
            rC0_0 += rA0 * rB0;
            rA7 = pA7[3];
            rA8 = pA8[3];
            rA9 = pA9[3];
            rA10 = pA10[3];
            rA11 = pA11[3];
            rC1_0 += rA1 * rB0;
            rC2_0 += rA2 * rB0;
            rC3_0 += rA3 * rB0;
            rC4_0 += rA4 * rB0;
            rC5_0 += rA5 * rB0;
            rC6_0 += rA6 * rB0;
            rC7_0 += rA7 * rB0;
            rC8_0 += rA8 * rB0;
            rC9_0 += rA9 * rB0;
            rC10_0 += rA10 * rB0;
            rC11_0 += rA11 * rB0;
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
            pB0 += incBk;
         }
         *pC0 = rC0_0;
         pC0[1] = rC1_0;
         pC0[2] = rC2_0;
         pC0[3] = rC3_0;
         pC0[4] = rC4_0;
         pC0[5] = rC5_0;
         pC0[6] = rC6_0;
         pC0[7] = rC7_0;
         pC0[8] = rC8_0;
         pC0[9] = rC9_0;
         pC0[10] = rC10_0;
         pC0[11] = rC11_0;
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
