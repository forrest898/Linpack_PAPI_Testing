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

static void ATL_zJIK0x0x35TN1x1x6_a1_bX
   (const int M, const int N, const int K, const double alpha, const double * ATL_RESTRICT A, const int lda, const double * ATL_RESTRICT B, const int ldb, const double beta, double * ATL_RESTRICT C, const int ldc)
/*
 * matmul with TA=T, TB=N, MB=0, NB=0, KB=35, 
 * lda=35, ldb=35, ldc=0, mu=1, nu=1, ku=6, pf=1
 * Generated by ATLAS/tune/blas/gemm/emit_mm.c (3.10.3)
 */
{
   #define Mb M
   #define Nb N
   const double *stM = A + (35*(Mb));
   const double *stN = B + (35*(Nb));
   const double *pfA = stM;
   const int incPFA0 = (((int)(stM - A))*1*1)/(M*N*sizeof(double));
   const int incPFA = (1 > incPFA0) ? 1 : incPFA0;
   #define incAk 6
   const int incAm = 5, incAn = -(35*(Mb));
   #define incBk 6
   const int incBm = -30, incBn = 35;
   #define incCm 2
   const int incCn = (((ldc) << 1)) - (((Mb) << 1));
   double *pC0=C;
   const double *pA0=A;
   const double *pB0=B;
   register int k;
   register double rA0;
   register double rB0;
   register double rC0_0;
   do /* N-loop */
   {
      do /* M-loop */
      {
         ATL_pfl1R(pfA);
         pfA += incPFA;
         rA0 = beta;
         rC0_0 = *pC0;
         rC0_0 *= rA0;
         for (k=0; k < 5; k++) /* easy loop to unroll */
         {
            rA0 = *pA0;
            rB0 = *pB0;
            rC0_0 += rA0 * rB0;
            rA0 = pA0[1];
            rB0 = pB0[1];
            rC0_0 += rA0 * rB0;
            rA0 = pA0[2];
            rB0 = pB0[2];
            rC0_0 += rA0 * rB0;
            rA0 = pA0[3];
            rB0 = pB0[3];
            rC0_0 += rA0 * rB0;
            rA0 = pA0[4];
            rB0 = pB0[4];
            rC0_0 += rA0 * rB0;
            rA0 = pA0[5];
            rB0 = pB0[5];
            rC0_0 += rA0 * rB0;
            pA0 += incAk;
            pB0 += incBk;
         }
         rA0 = *pA0;
         rB0 = *pB0;
         rC0_0 += rA0 * rB0;
         rA0 = pA0[1];
         rB0 = pB0[1];
         rC0_0 += rA0 * rB0;
         rA0 = pA0[2];
         rB0 = pB0[2];
         rC0_0 += rA0 * rB0;
         rA0 = pA0[3];
         rB0 = pB0[3];
         rC0_0 += rA0 * rB0;
         rA0 = pA0[4];
         rB0 = pB0[4];
         rC0_0 += rA0 * rB0;
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
void ATL_zJIK0x0x35TN35x35x0_a1_bX
   (const int M, const int N, const int K, const double alpha, const double * ATL_RESTRICT A, const int lda, const double * ATL_RESTRICT B, const int ldb, const double beta, double * ATL_RESTRICT C, const int ldc)
/*
 * matmul with TA=T, TB=N, MB=0, NB=0, KB=35, 
 * lda=35, ldb=35, ldc=0, mu=12, nu=1, ku=6, pf=1
 * Generated by ATLAS/tune/blas/gemm/emit_mm.c (3.10.3)
 */
{
   const int Mb = (M/12)*12;
   #define Nb N
   const double *ca=A, *cb=B;
   double *cc=C;
   const double *stM = A + (35*(Mb));
   const double *stN = B + (35*(Nb));
   const double *pfA = stM;
   const int incPFA0 = (((int)(stM - A))*12*1)/(M*N*sizeof(double));
   const int incPFA = (1 > incPFA0) ? 1 : incPFA0;
   #define incAk 6
   const int incAm = 390, incAn = -(35*(Mb));
   #define incBk 6
   const int incBm = -30, incBn = 35;
   #define incCm 24
   const int incCn = (((ldc) << 1)) - (((Mb) << 1));
   double *pC0=C;
   const double *pA0=A;
   const double *pB0=B;
   register int k;
   register double rA0, rA1, rA2, rA3, rA4, rA5, rA6, rA7, rA8, rA9, rA10, rA11;
   register double rB0;
   register double rC0_0, rC1_0, rC2_0, rC3_0, rC4_0, rC5_0, rC6_0, rC7_0, rC8_0, rC9_0, rC10_0, rC11_0;
   if (pA0 != stM)
   {
      do /* N-loop */
      {
         do /* M-loop */
         {
            ATL_pfl1R(pfA);
            pfA += incPFA;
            rA0 = beta;
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
            for (k=0; k < 5; k++) /* easy loop to unroll */
            {
               rA0 = *pA0;
               rB0 = *pB0;
               rA1 = pA0[35];
               rA2 = pA0[70];
               rA3 = pA0[105];
               rA4 = pA0[140];
               rC0_0 += rA0 * rB0;
               rA5 = pA0[175];
               rA6 = pA0[210];
               rA7 = pA0[245];
               rA8 = pA0[280];
               rC1_0 += rA1 * rB0;
               rA9 = pA0[315];
               rA10 = pA0[350];
               rA11 = pA0[385];
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
               rA1 = pA0[36];
               rA2 = pA0[71];
               rA3 = pA0[106];
               rA4 = pA0[141];
               rC0_0 += rA0 * rB0;
               rA5 = pA0[176];
               rA6 = pA0[211];
               rA7 = pA0[246];
               rA8 = pA0[281];
               rC1_0 += rA1 * rB0;
               rA9 = pA0[316];
               rA10 = pA0[351];
               rA11 = pA0[386];
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
               rA1 = pA0[37];
               rA2 = pA0[72];
               rA3 = pA0[107];
               rA4 = pA0[142];
               rC0_0 += rA0 * rB0;
               rA5 = pA0[177];
               rA6 = pA0[212];
               rA7 = pA0[247];
               rA8 = pA0[282];
               rC1_0 += rA1 * rB0;
               rA9 = pA0[317];
               rA10 = pA0[352];
               rA11 = pA0[387];
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
               rA1 = pA0[38];
               rA2 = pA0[73];
               rA3 = pA0[108];
               rA4 = pA0[143];
               rC0_0 += rA0 * rB0;
               rA5 = pA0[178];
               rA6 = pA0[213];
               rA7 = pA0[248];
               rA8 = pA0[283];
               rC1_0 += rA1 * rB0;
               rA9 = pA0[318];
               rA10 = pA0[353];
               rA11 = pA0[388];
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
               rA0 = pA0[4];
               rB0 = pB0[4];
               rA1 = pA0[39];
               rA2 = pA0[74];
               rA3 = pA0[109];
               rA4 = pA0[144];
               rC0_0 += rA0 * rB0;
               rA5 = pA0[179];
               rA6 = pA0[214];
               rA7 = pA0[249];
               rA8 = pA0[284];
               rC1_0 += rA1 * rB0;
               rA9 = pA0[319];
               rA10 = pA0[354];
               rA11 = pA0[389];
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
               rA0 = pA0[5];
               rB0 = pB0[5];
               rA1 = pA0[40];
               rA2 = pA0[75];
               rA3 = pA0[110];
               rA4 = pA0[145];
               rC0_0 += rA0 * rB0;
               rA5 = pA0[180];
               rA6 = pA0[215];
               rA7 = pA0[250];
               rA8 = pA0[285];
               rC1_0 += rA1 * rB0;
               rA9 = pA0[320];
               rA10 = pA0[355];
               rA11 = pA0[390];
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
               pB0 += incBk;
            }
            rA0 = *pA0;
            rB0 = *pB0;
            rA1 = pA0[35];
            rA2 = pA0[70];
            rA3 = pA0[105];
            rA4 = pA0[140];
            rC0_0 += rA0 * rB0;
            rA5 = pA0[175];
            rA6 = pA0[210];
            rA7 = pA0[245];
            rA8 = pA0[280];
            rC1_0 += rA1 * rB0;
            rA9 = pA0[315];
            rA10 = pA0[350];
            rA11 = pA0[385];
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
            rA1 = pA0[36];
            rA2 = pA0[71];
            rA3 = pA0[106];
            rA4 = pA0[141];
            rC0_0 += rA0 * rB0;
            rA5 = pA0[176];
            rA6 = pA0[211];
            rA7 = pA0[246];
            rA8 = pA0[281];
            rC1_0 += rA1 * rB0;
            rA9 = pA0[316];
            rA10 = pA0[351];
            rA11 = pA0[386];
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
            rA1 = pA0[37];
            rA2 = pA0[72];
            rA3 = pA0[107];
            rA4 = pA0[142];
            rC0_0 += rA0 * rB0;
            rA5 = pA0[177];
            rA6 = pA0[212];
            rA7 = pA0[247];
            rA8 = pA0[282];
            rC1_0 += rA1 * rB0;
            rA9 = pA0[317];
            rA10 = pA0[352];
            rA11 = pA0[387];
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
            rA1 = pA0[38];
            rA2 = pA0[73];
            rA3 = pA0[108];
            rA4 = pA0[143];
            rC0_0 += rA0 * rB0;
            rA5 = pA0[178];
            rA6 = pA0[213];
            rA7 = pA0[248];
            rA8 = pA0[283];
            rC1_0 += rA1 * rB0;
            rA9 = pA0[318];
            rA10 = pA0[353];
            rA11 = pA0[388];
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
            rA0 = pA0[4];
            rB0 = pB0[4];
            rA1 = pA0[39];
            rA2 = pA0[74];
            rA3 = pA0[109];
            rA4 = pA0[144];
            rC0_0 += rA0 * rB0;
            rA5 = pA0[179];
            rA6 = pA0[214];
            rA7 = pA0[249];
            rA8 = pA0[284];
            rC1_0 += rA1 * rB0;
            rA9 = pA0[319];
            rA10 = pA0[354];
            rA11 = pA0[389];
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
      ATL_zJIK0x0x35TN1x1x6_a1_bX(k, N, 35, alpha, ca + (35*(Mb)), lda, cb, ldb, beta, cc + (((Mb) << 1)), ldc);
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
