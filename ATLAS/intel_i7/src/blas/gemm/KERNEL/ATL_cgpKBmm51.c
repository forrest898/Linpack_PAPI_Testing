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

static void ATL_cJIK0x0x51TN1x1x6_a1_bX
   (const int M, const int N, const int K, const float alpha, const float * ATL_RESTRICT A, const int lda, const float * ATL_RESTRICT B, const int ldb, const float beta, float * ATL_RESTRICT C, const int ldc)
/*
 * matmul with TA=T, TB=N, MB=0, NB=0, KB=51, 
 * lda=51, ldb=51, ldc=0, mu=1, nu=1, ku=6, pf=1
 * Generated by ATLAS/tune/blas/gemm/emit_mm.c (3.10.3)
 */
{
   #define Mb M
   #define Nb N
   const float *stM = A + (51*(Mb));
   const float *stN = B + (51*(Nb));
   const float *pfA = stM;
   const int incPFA0 = (((int)(stM - A))*1*1)/(M*N*sizeof(float));
   const int incPFA = (1 > incPFA0) ? 1 : incPFA0;
   #define incAk 6
   const int incAm = 3, incAn = -(51*(Mb));
   #define incBk 6
   const int incBm = -48, incBn = 51;
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
         for (k=0; k < 8; k++) /* easy loop to unroll */
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
void ATL_cJIK0x0x51TN51x51x0_a1_bX
   (const int M, const int N, const int K, const float alpha, const float * ATL_RESTRICT A, const int lda, const float * ATL_RESTRICT B, const int ldb, const float beta, float * ATL_RESTRICT C, const int ldc)
/*
 * matmul with TA=T, TB=N, MB=0, NB=0, KB=51, 
 * lda=51, ldb=51, ldc=0, mu=12, nu=1, ku=6, pf=1
 * Generated by ATLAS/tune/blas/gemm/emit_mm.c (3.10.3)
 */
{
   const int Mb = (M/12)*12;
   #define Nb N
   const float *ca=A, *cb=B;
   float *cc=C;
   const float *stM = A + (51*(Mb));
   const float *stN = B + (51*(Nb));
   const float *pfA = stM;
   const int incPFA0 = (((int)(stM - A))*12*1)/(M*N*sizeof(float));
   const int incPFA = (1 > incPFA0) ? 1 : incPFA0;
   #define incAk 6
   const int incAm = 564, incAn = -(51*(Mb));
   #define incBk 6
   const int incBm = -48, incBn = 51;
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
            for (k=0; k < 8; k++) /* easy loop to unroll */
            {
               rA0 = *pA0;
               rB0 = *pB0;
               rA1 = pA0[51];
               rA2 = pA0[102];
               rA3 = pA0[153];
               rA4 = pA0[204];
               rA5 = pA0[255];
               rC0_0 += rA0 * rB0;
               rA6 = pA0[306];
               rA7 = pA0[357];
               rA8 = pA0[408];
               rA9 = pA0[459];
               rC1_0 += rA1 * rB0;
               rA10 = pA0[510];
               rA11 = pA0[561];
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
               rA1 = pA0[52];
               rA2 = pA0[103];
               rA3 = pA0[154];
               rA4 = pA0[205];
               rA5 = pA0[256];
               rC0_0 += rA0 * rB0;
               rA6 = pA0[307];
               rA7 = pA0[358];
               rA8 = pA0[409];
               rA9 = pA0[460];
               rC1_0 += rA1 * rB0;
               rA10 = pA0[511];
               rA11 = pA0[562];
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
               rA1 = pA0[53];
               rA2 = pA0[104];
               rA3 = pA0[155];
               rA4 = pA0[206];
               rA5 = pA0[257];
               rC0_0 += rA0 * rB0;
               rA6 = pA0[308];
               rA7 = pA0[359];
               rA8 = pA0[410];
               rA9 = pA0[461];
               rC1_0 += rA1 * rB0;
               rA10 = pA0[512];
               rA11 = pA0[563];
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
               rA1 = pA0[54];
               rA2 = pA0[105];
               rA3 = pA0[156];
               rA4 = pA0[207];
               rA5 = pA0[258];
               rC0_0 += rA0 * rB0;
               rA6 = pA0[309];
               rA7 = pA0[360];
               rA8 = pA0[411];
               rA9 = pA0[462];
               rC1_0 += rA1 * rB0;
               rA10 = pA0[513];
               rA11 = pA0[564];
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
               rA1 = pA0[55];
               rA2 = pA0[106];
               rA3 = pA0[157];
               rA4 = pA0[208];
               rA5 = pA0[259];
               rC0_0 += rA0 * rB0;
               rA6 = pA0[310];
               rA7 = pA0[361];
               rA8 = pA0[412];
               rA9 = pA0[463];
               rC1_0 += rA1 * rB0;
               rA10 = pA0[514];
               rA11 = pA0[565];
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
               rA1 = pA0[56];
               rA2 = pA0[107];
               rA3 = pA0[158];
               rA4 = pA0[209];
               rA5 = pA0[260];
               rC0_0 += rA0 * rB0;
               rA6 = pA0[311];
               rA7 = pA0[362];
               rA8 = pA0[413];
               rA9 = pA0[464];
               rC1_0 += rA1 * rB0;
               rA10 = pA0[515];
               rA11 = pA0[566];
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
            rA1 = pA0[51];
            rA2 = pA0[102];
            rA3 = pA0[153];
            rA4 = pA0[204];
            rA5 = pA0[255];
            rC0_0 += rA0 * rB0;
            rA6 = pA0[306];
            rA7 = pA0[357];
            rA8 = pA0[408];
            rA9 = pA0[459];
            rC1_0 += rA1 * rB0;
            rA10 = pA0[510];
            rA11 = pA0[561];
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
            rA1 = pA0[52];
            rA2 = pA0[103];
            rA3 = pA0[154];
            rA4 = pA0[205];
            rA5 = pA0[256];
            rC0_0 += rA0 * rB0;
            rA6 = pA0[307];
            rA7 = pA0[358];
            rA8 = pA0[409];
            rA9 = pA0[460];
            rC1_0 += rA1 * rB0;
            rA10 = pA0[511];
            rA11 = pA0[562];
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
            rA1 = pA0[53];
            rA2 = pA0[104];
            rA3 = pA0[155];
            rA4 = pA0[206];
            rA5 = pA0[257];
            rC0_0 += rA0 * rB0;
            rA6 = pA0[308];
            rA7 = pA0[359];
            rA8 = pA0[410];
            rA9 = pA0[461];
            rC1_0 += rA1 * rB0;
            rA10 = pA0[512];
            rA11 = pA0[563];
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
      ATL_cJIK0x0x51TN1x1x6_a1_bX(k, N, 51, alpha, ca + (51*(Mb)), lda, cb, ldb, beta, cc + (((Mb) << 1)), ldc);
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
