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

static void ATL_cJIK0x80x80TN1x1x6_a1_b0
   (const int M, const int N, const int K, const float alpha, const float * ATL_RESTRICT A, const int lda, const float * ATL_RESTRICT B, const int ldb, const float beta, float * ATL_RESTRICT C, const int ldc)
/*
 * matmul with TA=T, TB=N, MB=0, NB=80, KB=80, 
 * lda=80, ldb=80, ldc=0, mu=1, nu=1, ku=6, pf=1
 * Generated by ATLAS/tune/blas/gemm/emit_mm.c (3.10.3)
 */
{
   #define Mb M
   const float *stM = A + (((Mb) << 6)+((Mb) << 4));
   const float *stN = B + 6400;
   const float *pfA = stM;
   const int incPFA0 = (((int)(stM - A))*1*1)/(M*N*sizeof(float));
   const int incPFA = (1 > incPFA0) ? 1 : incPFA0;
   #define incAk 6
   const int incAm = 2, incAn = -(((Mb) << 6)+((Mb) << 4));
   #define incBk 6
   const int incBm = -78, incBn = 80;
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
      do /* M-loop */
      {
         ATL_pfl1R(pfA);
         pfA += incPFA;
/*
 *       Feeble prefetch of C
 */
         rC0_0 = *pC0;
         rC0_0 = 0.0;
         for (k=0; k < 13; k++) /* easy loop to unroll */
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
void ATL_cJIK0x80x80TN80x80x0_a1_b0
   (const int M, const int N, const int K, const float alpha, const float * ATL_RESTRICT A, const int lda, const float * ATL_RESTRICT B, const int ldb, const float beta, float * ATL_RESTRICT C, const int ldc)
/*
 * matmul with TA=T, TB=N, MB=0, NB=80, KB=80, 
 * lda=80, ldb=80, ldc=0, mu=12, nu=1, ku=6, pf=1
 * Generated by ATLAS/tune/blas/gemm/emit_mm.c (3.10.3)
 */
{
   const int Mb = (M/12)*12;
   const float *ca=A, *cb=B;
   float *cc=C;
   const float *stM = A + (((Mb) << 6)+((Mb) << 4));
   const float *stN = B + 6400;
   const float *pfA = stM;
   const int incPFA0 = (((int)(stM - A))*12*1)/(M*N*sizeof(float));
   const int incPFA = (1 > incPFA0) ? 1 : incPFA0;
   #define incAk 6
   const int incAm = 882, incAn = -(((Mb) << 6)+((Mb) << 4));
   #define incBk 6
   const int incBm = -78, incBn = 80;
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
         do /* M-loop */
         {
            ATL_pfl1R(pfA);
            pfA += incPFA;
/*
 *          Feeble prefetch of C
 */
            rC0_0 = *pC0;
            rC0_0 = rC1_0 = rC2_0 = rC3_0 = rC4_0 = rC5_0 = rC6_0 = rC7_0 = rC8_0 = rC9_0 = rC10_0 = rC11_0 = 0.0;
            for (k=0; k < 13; k++) /* easy loop to unroll */
            {
               rA0 = *pA0;
               rB0 = *pB0;
               rA1 = pA0[80];
               rA2 = pA0[160];
               rA3 = pA0[240];
               rA4 = pA0[320];
               rA5 = pA0[400];
               rC0_0 += rA0 * rB0;
               rA6 = pA0[480];
               rA7 = pA0[560];
               rA8 = pA0[640];
               rA9 = pA0[720];
               rC1_0 += rA1 * rB0;
               rA10 = pA0[800];
               rA11 = pA0[880];
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
               rA1 = pA0[81];
               rA2 = pA0[161];
               rA3 = pA0[241];
               rA4 = pA0[321];
               rA5 = pA0[401];
               rC0_0 += rA0 * rB0;
               rA6 = pA0[481];
               rA7 = pA0[561];
               rA8 = pA0[641];
               rA9 = pA0[721];
               rC1_0 += rA1 * rB0;
               rA10 = pA0[801];
               rA11 = pA0[881];
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
               rA1 = pA0[82];
               rA2 = pA0[162];
               rA3 = pA0[242];
               rA4 = pA0[322];
               rA5 = pA0[402];
               rC0_0 += rA0 * rB0;
               rA6 = pA0[482];
               rA7 = pA0[562];
               rA8 = pA0[642];
               rA9 = pA0[722];
               rC1_0 += rA1 * rB0;
               rA10 = pA0[802];
               rA11 = pA0[882];
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
               rA1 = pA0[83];
               rA2 = pA0[163];
               rA3 = pA0[243];
               rA4 = pA0[323];
               rA5 = pA0[403];
               rC0_0 += rA0 * rB0;
               rA6 = pA0[483];
               rA7 = pA0[563];
               rA8 = pA0[643];
               rA9 = pA0[723];
               rC1_0 += rA1 * rB0;
               rA10 = pA0[803];
               rA11 = pA0[883];
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
               rA1 = pA0[84];
               rA2 = pA0[164];
               rA3 = pA0[244];
               rA4 = pA0[324];
               rA5 = pA0[404];
               rC0_0 += rA0 * rB0;
               rA6 = pA0[484];
               rA7 = pA0[564];
               rA8 = pA0[644];
               rA9 = pA0[724];
               rC1_0 += rA1 * rB0;
               rA10 = pA0[804];
               rA11 = pA0[884];
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
               rA1 = pA0[85];
               rA2 = pA0[165];
               rA3 = pA0[245];
               rA4 = pA0[325];
               rA5 = pA0[405];
               rC0_0 += rA0 * rB0;
               rA6 = pA0[485];
               rA7 = pA0[565];
               rA8 = pA0[645];
               rA9 = pA0[725];
               rC1_0 += rA1 * rB0;
               rA10 = pA0[805];
               rA11 = pA0[885];
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
            rA1 = pA0[80];
            rA2 = pA0[160];
            rA3 = pA0[240];
            rA4 = pA0[320];
            rA5 = pA0[400];
            rC0_0 += rA0 * rB0;
            rA6 = pA0[480];
            rA7 = pA0[560];
            rA8 = pA0[640];
            rA9 = pA0[720];
            rC1_0 += rA1 * rB0;
            rA10 = pA0[800];
            rA11 = pA0[880];
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
            rA1 = pA0[81];
            rA2 = pA0[161];
            rA3 = pA0[241];
            rA4 = pA0[321];
            rA5 = pA0[401];
            rC0_0 += rA0 * rB0;
            rA6 = pA0[481];
            rA7 = pA0[561];
            rA8 = pA0[641];
            rA9 = pA0[721];
            rC1_0 += rA1 * rB0;
            rA10 = pA0[801];
            rA11 = pA0[881];
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
      ATL_cJIK0x80x80TN1x1x6_a1_b0(k, 80, 80, alpha, ca + (((Mb) << 6)+((Mb) << 4)), lda, cb, ldb, beta, cc + (((Mb) << 1)), ldc);
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
#ifdef ATL_UCLEANM
#define ATL_cpMBmm_b0 ATL_cgpMBmm_b0
#endif

void ATL_cJIK0x80x80TN80x80x0_a1_b0(const int M, const int N, const int K, const float alpha, const float *A, const int lda, const float *B, const int ldb, const float beta, float *C, const int ldc);
void ATL_cJIK0x80x80TN80x80x0_a1_bX(const int M, const int N, const int K, const float alpha, const float *A, const int lda, const float *B, const int ldb, const float beta, float *C, const int ldc);
void ATL_cJIK0x80x80TN80x80x0_a1_b1(const int M, const int N, const int K, const float alpha, const float *A, const int lda, const float *B, const int ldb, const float beta, float *C, const int ldc);

void ATL_cpMBmm_b0(const int M, const int N, const int K, const float alpha, const float *A, const int lda, const float *B, const int ldb, const float beta, float *C, const int ldc)
{
   ATL_cJIK0x80x80TN80x80x0_a1_b0(M, N, K, alpha, A, lda, B, ldb, -beta, C, ldc);
   ATL_cJIK0x80x80TN80x80x0_a1_b0(M, N, K, alpha, A, lda, B+N*ldb, ldb, beta, C+1, ldc);
   ATL_cJIK0x80x80TN80x80x0_a1_bX(M, N, K, alpha, A+M*lda, lda, B+N*ldb, ldb, -1.0, C, ldc);
   ATL_cJIK0x80x80TN80x80x0_a1_b1(M, N, K, alpha, A+M*lda, lda, B, ldb, 1.0, C+1, ldc);
}
