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

static void ATL_dJIK0x0x17TN1x1x4_a1_bX
   (const int M, const int N, const int K, const double alpha, const double * ATL_RESTRICT A, const int lda, const double * ATL_RESTRICT B, const int ldb, const double beta, double * ATL_RESTRICT C, const int ldc)
/*
 * matmul with TA=T, TB=N, MB=0, NB=0, KB=17, 
 * lda=17, ldb=17, ldc=0, mu=1, nu=1, ku=4, pf=1
 * Generated by ATLAS/tune/blas/gemm/emit_mm.c (3.10.3)
 */
{
   #define Mb M
   #define Nb N
   const double *stM = A + (((Mb) << 4)+Mb);
   const double *stN = B + (((Nb) << 4)+Nb);
   const double *pfA = stM;
   const int incPFA0 = (((int)(stM - A))*1*1)/(M*N*sizeof(double));
   const int incPFA = (1 > incPFA0) ? 1 : incPFA0;
   #define incAk 4
   const int incAm = 1, incAn = -(((Mb) << 4)+Mb);
   #define incBk 4
   const int incBm = -16, incBn = 17;
   #define incCm 1
   const int incCn = (ldc) - (Mb);
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
         for (k=0; k < 4; k++) /* easy loop to unroll */
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
            pA0 += incAk;
            pB0 += incBk;
         }
         rA0 = *pA0;
         rB0 = *pB0;
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
void ATL_dJIK0x0x17TN17x17x0_a1_bX
   (const int M, const int N, const int K, const double alpha, const double * ATL_RESTRICT A, const int lda, const double * ATL_RESTRICT B, const int ldb, const double beta, double * ATL_RESTRICT C, const int ldc)
/*
 * matmul with TA=T, TB=N, MB=0, NB=0, KB=17, 
 * lda=17, ldb=17, ldc=0, mu=12, nu=1, ku=4, pf=1
 * Generated by ATLAS/tune/blas/gemm/emit_mm.c (3.10.3)
 */
{
   const int Mb = (M/12)*12;
   #define Nb N
   const double *ca=A, *cb=B;
   double *cc=C;
   const double *stM = A + (((Mb) << 4)+Mb);
   const double *stN = B + (((Nb) << 4)+Nb);
   const double *pfA = stM;
   const int incPFA0 = (((int)(stM - A))*12*1)/(M*N*sizeof(double));
   const int incPFA = (1 > incPFA0) ? 1 : incPFA0;
   #define incAk 4
   const int incAm = 188, incAn = -(((Mb) << 4)+Mb);
   #define incBk 4
   const int incBm = -16, incBn = 17;
   #define incCm 12
   const int incCn = (ldc) - (Mb);
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
            for (k=0; k < 4; k++) /* easy loop to unroll */
            {
               rA0 = *pA0;
               rB0 = *pB0;
               rA1 = pA0[17];
               rA2 = pA0[34];
               rA3 = pA0[51];
               rA4 = pA0[68];
               rA5 = pA0[85];
               rA6 = pA0[102];
               rA7 = pA0[119];
               rA8 = pA0[136];
               rA9 = pA0[153];
               rA10 = pA0[170];
               rC0_0 += rA0 * rB0;
               rA11 = pA0[187];
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
               rA1 = pA0[18];
               rA2 = pA0[35];
               rA3 = pA0[52];
               rA4 = pA0[69];
               rA5 = pA0[86];
               rA6 = pA0[103];
               rA7 = pA0[120];
               rA8 = pA0[137];
               rA9 = pA0[154];
               rA10 = pA0[171];
               rC0_0 += rA0 * rB0;
               rA11 = pA0[188];
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
               rA1 = pA0[19];
               rA2 = pA0[36];
               rA3 = pA0[53];
               rA4 = pA0[70];
               rA5 = pA0[87];
               rA6 = pA0[104];
               rA7 = pA0[121];
               rA8 = pA0[138];
               rA9 = pA0[155];
               rA10 = pA0[172];
               rC0_0 += rA0 * rB0;
               rA11 = pA0[189];
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
               rA1 = pA0[20];
               rA2 = pA0[37];
               rA3 = pA0[54];
               rA4 = pA0[71];
               rA5 = pA0[88];
               rA6 = pA0[105];
               rA7 = pA0[122];
               rA8 = pA0[139];
               rA9 = pA0[156];
               rA10 = pA0[173];
               rC0_0 += rA0 * rB0;
               rA11 = pA0[190];
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
            rA0 = *pA0;
            rB0 = *pB0;
            rA1 = pA0[17];
            rA2 = pA0[34];
            rA3 = pA0[51];
            rA4 = pA0[68];
            rA5 = pA0[85];
            rA6 = pA0[102];
            rA7 = pA0[119];
            rA8 = pA0[136];
            rA9 = pA0[153];
            rA10 = pA0[170];
            rC0_0 += rA0 * rB0;
            rA11 = pA0[187];
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
   }
   if (k=M-Mb)
      ATL_dJIK0x0x17TN1x1x4_a1_bX(k, N, 17, alpha, ca + (((Mb) << 4)+Mb), lda, cb, ldb, beta, cc + (Mb), ldc);
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
