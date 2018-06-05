#ifdef ATL_UCLEANN
#define ATL_dJIK56x0x56TN56x56x0_a1_bX ATL_dgpNBmm_bX
#else
#define ATL_dJIK56x0x56TN56x56x0_a1_bX ATL_dpNBmm_bX
#endif

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

static void ATL_dJIK8x0x56TN8x1x4_a1_bX
   (const int M, const int N, const int K, const double alpha, const double * ATL_RESTRICT A, const int lda, const double * ATL_RESTRICT B, const int ldb, const double beta, double * ATL_RESTRICT C, const int ldc)
/*
 * matmul with TA=T, TB=N, MB=8, NB=0, KB=56, 
 * lda=56, ldb=56, ldc=0, mu=8, nu=1, ku=4, pf=1
 * Generated by ATLAS/tune/blas/gemm/emit_mm.c (3.10.3)
 */
{
   #define Nb N
   const double *stM = A + 448;
   const double *stN = B + (56*(Nb));
   const double *pfA = stM;
   const int incPFA0 = (((int)(stM - A))*8*1)/(8*N*sizeof(double));
   const int incPFA = (1 > incPFA0) ? 1 : incPFA0;
   #define incAk 4
   const int incAm = 392, incAn = -448;
   #define incBk 4
   const int incBm = -56, incBn = 56;
   #define incCm 8
   const int incCn = (ldc) - 8;
   double *pC0=C;
   const double *pA0=A;
   const double *pB0=B;
   register int k;
   register double rA0, rA1, rA2, rA3, rA4, rA5, rA6, rA7;
   register double rB0;
   register double rC0_0, rC1_0, rC2_0, rC3_0, rC4_0, rC5_0, rC6_0, rC7_0;
   do /* N-loop */
   {
      ATL_pfl1R(pfA);
      pfA += incPFA;
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
      for (k=0; k < 14; k++) /* easy loop to unroll */
      {
         rA0 = *pA0;
         rB0 = *pB0;
         rA1 = pA0[56];
         rA2 = pA0[112];
         rA3 = pA0[168];
         rA4 = pA0[224];
         rA5 = pA0[280];
         rA6 = pA0[336];
         rA7 = pA0[392];
         rC0_0 += rA0 * rB0;
         rC1_0 += rA1 * rB0;
         rC2_0 += rA2 * rB0;
         rC3_0 += rA3 * rB0;
         rC4_0 += rA4 * rB0;
         rC5_0 += rA5 * rB0;
         rC6_0 += rA6 * rB0;
         rC7_0 += rA7 * rB0;
         rA0 = pA0[1];
         rB0 = pB0[1];
         rA1 = pA0[57];
         rA2 = pA0[113];
         rA3 = pA0[169];
         rA4 = pA0[225];
         rA5 = pA0[281];
         rA6 = pA0[337];
         rA7 = pA0[393];
         rC0_0 += rA0 * rB0;
         rC1_0 += rA1 * rB0;
         rC2_0 += rA2 * rB0;
         rC3_0 += rA3 * rB0;
         rC4_0 += rA4 * rB0;
         rC5_0 += rA5 * rB0;
         rC6_0 += rA6 * rB0;
         rC7_0 += rA7 * rB0;
         rA0 = pA0[2];
         rB0 = pB0[2];
         rA1 = pA0[58];
         rA2 = pA0[114];
         rA3 = pA0[170];
         rA4 = pA0[226];
         rA5 = pA0[282];
         rA6 = pA0[338];
         rA7 = pA0[394];
         rC0_0 += rA0 * rB0;
         rC1_0 += rA1 * rB0;
         rC2_0 += rA2 * rB0;
         rC3_0 += rA3 * rB0;
         rC4_0 += rA4 * rB0;
         rC5_0 += rA5 * rB0;
         rC6_0 += rA6 * rB0;
         rC7_0 += rA7 * rB0;
         rA0 = pA0[3];
         rB0 = pB0[3];
         rA1 = pA0[59];
         rA2 = pA0[115];
         rA3 = pA0[171];
         rA4 = pA0[227];
         rA5 = pA0[283];
         rA6 = pA0[339];
         rA7 = pA0[395];
         rC0_0 += rA0 * rB0;
         rC1_0 += rA1 * rB0;
         rC2_0 += rA2 * rB0;
         rC3_0 += rA3 * rB0;
         rC4_0 += rA4 * rB0;
         rC5_0 += rA5 * rB0;
         rC6_0 += rA6 * rB0;
         rC7_0 += rA7 * rB0;
         pA0 += incAk;
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
      pC0 += incCm;
      pA0 += incAm;
      pB0 += incBm;
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
void ATL_dJIK56x0x56TN56x56x0_a1_bX
   (const int M, const int N, const int K, const double alpha, const double * ATL_RESTRICT A, const int lda, const double * ATL_RESTRICT B, const int ldb, const double beta, double * ATL_RESTRICT C, const int ldc)
/*
 * matmul with TA=T, TB=N, MB=56, NB=0, KB=56, 
 * lda=56, ldb=56, ldc=0, mu=12, nu=1, ku=4, pf=1
 * Generated by ATLAS/tune/blas/gemm/emit_mm.c (3.10.3)
 */
{
   #define Nb N
   const double *ca=A, *cb=B;
   double *cc=C;
   const double *stM = A + 2688;
   const double *stN = B + (56*(Nb));
   const double *pfA = stM;
   const int incPFA0 = (((int)(stM - A))*12*1)/(56*N*sizeof(double));
   const int incPFA = (1 > incPFA0) ? 1 : incPFA0;
   #define incAk 4
   const int incAm = 616, incAn = -2688;
   #define incBk 4
   const int incBm = -56, incBn = 56;
   #define incCm 12
   const int incCn = (ldc) - 48;
   double *pC0=C;
   const double *pA0=A;
   const double *pB0=B;
   register int k;
   register double rA0, rA1, rA2, rA3, rA4, rA5, rA6, rA7, rA8, rA9, rA10, rA11;
   register double rB0;
   register double rC0_0, rC1_0, rC2_0, rC3_0, rC4_0, rC5_0, rC6_0, rC7_0, rC8_0, rC9_0, rC10_0, rC11_0;
   do /* N-loop */
   {
      do /* M-loop */
      {
         ATL_pfl1R(pfA);
         pfA += incPFA;
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
         for (k=0; k < 14; k++) /* easy loop to unroll */
         {
            rA0 = *pA0;
            rB0 = *pB0;
            rA1 = pA0[56];
            rA2 = pA0[112];
            rA3 = pA0[168];
            rA4 = pA0[224];
            rA5 = pA0[280];
            rA6 = pA0[336];
            rA7 = pA0[392];
            rA8 = pA0[448];
            rA9 = pA0[504];
            rA10 = pA0[560];
            rC0_0 += rA0 * rB0;
            rA11 = pA0[616];
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
            rA1 = pA0[57];
            rA2 = pA0[113];
            rA3 = pA0[169];
            rA4 = pA0[225];
            rA5 = pA0[281];
            rA6 = pA0[337];
            rA7 = pA0[393];
            rA8 = pA0[449];
            rA9 = pA0[505];
            rA10 = pA0[561];
            rC0_0 += rA0 * rB0;
            rA11 = pA0[617];
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
            rA1 = pA0[58];
            rA2 = pA0[114];
            rA3 = pA0[170];
            rA4 = pA0[226];
            rA5 = pA0[282];
            rA6 = pA0[338];
            rA7 = pA0[394];
            rA8 = pA0[450];
            rA9 = pA0[506];
            rA10 = pA0[562];
            rC0_0 += rA0 * rB0;
            rA11 = pA0[618];
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
            rA1 = pA0[59];
            rA2 = pA0[115];
            rA3 = pA0[171];
            rA4 = pA0[227];
            rA5 = pA0[283];
            rA6 = pA0[339];
            rA7 = pA0[395];
            rA8 = pA0[451];
            rA9 = pA0[507];
            rA10 = pA0[563];
            rC0_0 += rA0 * rB0;
            rA11 = pA0[619];
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
         pB0 += incBm;
      }
      while(pA0 != stM);
      pC0 += incCn;
      pA0 += incAn;
      pB0 += incBn;
   }
   while(pB0 != stN);
   ATL_dJIK8x0x56TN8x1x4_a1_bX(8, N, 56, alpha, ca + 2688, lda, cb, ldb, beta, cc + 48, ldc);
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
