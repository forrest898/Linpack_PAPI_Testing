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

static void ATL_cJIK0x0x17TN1x1x6_a1_bX
   (const int M, const int N, const int K, const float alpha, const float * ATL_RESTRICT A, const int lda, const float * ATL_RESTRICT B, const int ldb, const float beta, float * ATL_RESTRICT C, const int ldc)
/*
 * matmul with TA=T, TB=N, MB=0, NB=0, KB=17, 
 * lda=17, ldb=17, ldc=0, mu=1, nu=1, ku=6, pf=1
 * Generated by ATLAS/tune/blas/gemm/emit_mm.c (3.10.3)
 */
{
   #define Mb M
   #define Nb N
   const float *stM = A + (((Mb) << 4)+Mb);
   const float *stN = B + (((Nb) << 4)+Nb);
   const float *pfA = stM;
   const int incPFA0 = (((int)(stM - A))*1*1)/(M*N*sizeof(float));
   const int incPFA = (1 > incPFA0) ? 1 : incPFA0;
   #define incAk 6
   const int incAm = 5, incAn = -(((Mb) << 4)+Mb);
   #define incBk 6
   const int incBm = -12, incBn = 17;
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
         rA0 = beta;
         rC0_0 = *pC0;
         rC0_0 *= rA0;
         for (k=0; k < 2; k++) /* easy loop to unroll */
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
void ATL_cJIK0x0x17TN17x17x0_a1_bX
   (const int M, const int N, const int K, const float alpha, const float * ATL_RESTRICT A, const int lda, const float * ATL_RESTRICT B, const int ldb, const float beta, float * ATL_RESTRICT C, const int ldc)
/*
 * matmul with TA=T, TB=N, MB=0, NB=0, KB=17, 
 * lda=17, ldb=17, ldc=0, mu=12, nu=1, ku=6, pf=1
 * Generated by ATLAS/tune/blas/gemm/emit_mm.c (3.10.3)
 */
{
   const int Mb = (M/12)*12;
   #define Nb N
   const float *ca=A, *cb=B;
   float *cc=C;
   const float *stM = A + (((Mb) << 4)+Mb);
   const float *stN = B + (((Nb) << 4)+Nb);
   const float *pfA = stM;
   const int incPFA0 = (((int)(stM - A))*12*1)/(M*N*sizeof(float));
   const int incPFA = (1 > incPFA0) ? 1 : incPFA0;
   #define incAk 6
   const int incAm = 192, incAn = -(((Mb) << 4)+Mb);
   #define incBk 6
   const int incBm = -12, incBn = 17;
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
            for (k=0; k < 2; k++) /* easy loop to unroll */
            {
               rA0 = *pA0;
               rB0 = *pB0;
               rA1 = pA0[17];
               rA2 = pA0[34];
               rA3 = pA0[51];
               rA4 = pA0[68];
               rA5 = pA0[85];
               rC0_0 += rA0 * rB0;
               rA6 = pA0[102];
               rA7 = pA0[119];
               rA8 = pA0[136];
               rA9 = pA0[153];
               rC1_0 += rA1 * rB0;
               rA10 = pA0[170];
               rA11 = pA0[187];
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
               rC0_0 += rA0 * rB0;
               rA6 = pA0[103];
               rA7 = pA0[120];
               rA8 = pA0[137];
               rA9 = pA0[154];
               rC1_0 += rA1 * rB0;
               rA10 = pA0[171];
               rA11 = pA0[188];
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
               rC0_0 += rA0 * rB0;
               rA6 = pA0[104];
               rA7 = pA0[121];
               rA8 = pA0[138];
               rA9 = pA0[155];
               rC1_0 += rA1 * rB0;
               rA10 = pA0[172];
               rA11 = pA0[189];
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
               rC0_0 += rA0 * rB0;
               rA6 = pA0[105];
               rA7 = pA0[122];
               rA8 = pA0[139];
               rA9 = pA0[156];
               rC1_0 += rA1 * rB0;
               rA10 = pA0[173];
               rA11 = pA0[190];
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
               rA1 = pA0[21];
               rA2 = pA0[38];
               rA3 = pA0[55];
               rA4 = pA0[72];
               rA5 = pA0[89];
               rC0_0 += rA0 * rB0;
               rA6 = pA0[106];
               rA7 = pA0[123];
               rA8 = pA0[140];
               rA9 = pA0[157];
               rC1_0 += rA1 * rB0;
               rA10 = pA0[174];
               rA11 = pA0[191];
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
               rA1 = pA0[22];
               rA2 = pA0[39];
               rA3 = pA0[56];
               rA4 = pA0[73];
               rA5 = pA0[90];
               rC0_0 += rA0 * rB0;
               rA6 = pA0[107];
               rA7 = pA0[124];
               rA8 = pA0[141];
               rA9 = pA0[158];
               rC1_0 += rA1 * rB0;
               rA10 = pA0[175];
               rA11 = pA0[192];
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
            rC0_0 += rA0 * rB0;
            rA6 = pA0[102];
            rA7 = pA0[119];
            rA8 = pA0[136];
            rA9 = pA0[153];
            rC1_0 += rA1 * rB0;
            rA10 = pA0[170];
            rA11 = pA0[187];
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
            rC0_0 += rA0 * rB0;
            rA6 = pA0[103];
            rA7 = pA0[120];
            rA8 = pA0[137];
            rA9 = pA0[154];
            rC1_0 += rA1 * rB0;
            rA10 = pA0[171];
            rA11 = pA0[188];
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
            rC0_0 += rA0 * rB0;
            rA6 = pA0[104];
            rA7 = pA0[121];
            rA8 = pA0[138];
            rA9 = pA0[155];
            rC1_0 += rA1 * rB0;
            rA10 = pA0[172];
            rA11 = pA0[189];
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
            rC0_0 += rA0 * rB0;
            rA6 = pA0[105];
            rA7 = pA0[122];
            rA8 = pA0[139];
            rA9 = pA0[156];
            rC1_0 += rA1 * rB0;
            rA10 = pA0[173];
            rA11 = pA0[190];
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
            rA1 = pA0[21];
            rA2 = pA0[38];
            rA3 = pA0[55];
            rA4 = pA0[72];
            rA5 = pA0[89];
            rC0_0 += rA0 * rB0;
            rA6 = pA0[106];
            rA7 = pA0[123];
            rA8 = pA0[140];
            rA9 = pA0[157];
            rC1_0 += rA1 * rB0;
            rA10 = pA0[174];
            rA11 = pA0[191];
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
      ATL_cJIK0x0x17TN1x1x6_a1_bX(k, N, 17, alpha, ca + (((Mb) << 4)+Mb), lda, cb, ldb, beta, cc + (((Mb) << 1)), ldc);
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
