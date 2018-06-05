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

static void ATL_cJIK0x0x11TN1x1x11_a1_bX
   (const int M, const int N, const int K, const float alpha, const float * ATL_RESTRICT A, const int lda, const float * ATL_RESTRICT B, const int ldb, const float beta, float * ATL_RESTRICT C, const int ldc)
/*
 * matmul with TA=T, TB=N, MB=0, NB=0, KB=11, 
 * lda=11, ldb=11, ldc=0, mu=1, nu=1, ku=11, pf=1
 * Generated by ATLAS/tune/blas/gemm/emit_mm.c (3.10.3)
 */
{
   #define Mb M
   #define Nb N
   const float *stM = A + (11*(Mb));
   const float *stN = B + (11*(Nb));
   const float *pfA = stM;
   const int incPFA0 = (((int)(stM - A))*1*1)/(M*N*sizeof(float));
   const int incPFA = (1 > incPFA0) ? 1 : incPFA0;
   #define incAk 11
   const int incAm = 0, incAn = -(11*(Mb));
   #define incBk 11
   const int incBm = -11, incBn = 11;
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
         rA0 = pA0[6];
         rB0 = pB0[6];
         rC0_0 += rA0 * rB0;
         rA0 = pA0[7];
         rB0 = pB0[7];
         rC0_0 += rA0 * rB0;
         rA0 = pA0[8];
         rB0 = pB0[8];
         rC0_0 += rA0 * rB0;
         rA0 = pA0[9];
         rB0 = pB0[9];
         rC0_0 += rA0 * rB0;
         rA0 = pA0[10];
         rB0 = pB0[10];
         rC0_0 += rA0 * rB0;
         pA0 += incAk;
         pB0 += incBk;
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
void ATL_cJIK0x0x11TN11x11x0_a1_bX
   (const int M, const int N, const int K, const float alpha, const float * ATL_RESTRICT A, const int lda, const float * ATL_RESTRICT B, const int ldb, const float beta, float * ATL_RESTRICT C, const int ldc)
/*
 * matmul with TA=T, TB=N, MB=0, NB=0, KB=11, 
 * lda=11, ldb=11, ldc=0, mu=12, nu=1, ku=11, pf=1
 * Generated by ATLAS/tune/blas/gemm/emit_mm.c (3.10.3)
 */
{
   const int Mb = (M/12)*12;
   #define Nb N
   const float *ca=A, *cb=B;
   float *cc=C;
   const float *stM = A + (11*(Mb));
   const float *stN = B + (11*(Nb));
   const float *pfA = stM;
   const int incPFA0 = (((int)(stM - A))*12*1)/(M*N*sizeof(float));
   const int incPFA = (1 > incPFA0) ? 1 : incPFA0;
   #define incAk 11
   const int incAm = 121, incAn = -(11*(Mb));
   #define incBk 11
   const int incBm = -11, incBn = 11;
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
            rA0 = *pA0;
            rB0 = *pB0;
            rA1 = pA0[11];
            rA2 = pA0[22];
            rA3 = pA0[33];
            rA4 = pA0[44];
            rA5 = pA0[55];
            rC0_0 += rA0 * rB0;
            rA6 = pA0[66];
            rA7 = pA0[77];
            rA8 = pA0[88];
            rA9 = pA0[99];
            rC1_0 += rA1 * rB0;
            rA10 = pA0[110];
            rA11 = pA0[121];
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
            rA1 = pA0[12];
            rA2 = pA0[23];
            rA3 = pA0[34];
            rA4 = pA0[45];
            rA5 = pA0[56];
            rC0_0 += rA0 * rB0;
            rA6 = pA0[67];
            rA7 = pA0[78];
            rA8 = pA0[89];
            rA9 = pA0[100];
            rC1_0 += rA1 * rB0;
            rA10 = pA0[111];
            rA11 = pA0[122];
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
            rA1 = pA0[13];
            rA2 = pA0[24];
            rA3 = pA0[35];
            rA4 = pA0[46];
            rA5 = pA0[57];
            rC0_0 += rA0 * rB0;
            rA6 = pA0[68];
            rA7 = pA0[79];
            rA8 = pA0[90];
            rA9 = pA0[101];
            rC1_0 += rA1 * rB0;
            rA10 = pA0[112];
            rA11 = pA0[123];
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
            rA1 = pA0[14];
            rA2 = pA0[25];
            rA3 = pA0[36];
            rA4 = pA0[47];
            rA5 = pA0[58];
            rC0_0 += rA0 * rB0;
            rA6 = pA0[69];
            rA7 = pA0[80];
            rA8 = pA0[91];
            rA9 = pA0[102];
            rC1_0 += rA1 * rB0;
            rA10 = pA0[113];
            rA11 = pA0[124];
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
            rA1 = pA0[15];
            rA2 = pA0[26];
            rA3 = pA0[37];
            rA4 = pA0[48];
            rA5 = pA0[59];
            rC0_0 += rA0 * rB0;
            rA6 = pA0[70];
            rA7 = pA0[81];
            rA8 = pA0[92];
            rA9 = pA0[103];
            rC1_0 += rA1 * rB0;
            rA10 = pA0[114];
            rA11 = pA0[125];
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
            rA1 = pA0[16];
            rA2 = pA0[27];
            rA3 = pA0[38];
            rA4 = pA0[49];
            rA5 = pA0[60];
            rC0_0 += rA0 * rB0;
            rA6 = pA0[71];
            rA7 = pA0[82];
            rA8 = pA0[93];
            rA9 = pA0[104];
            rC1_0 += rA1 * rB0;
            rA10 = pA0[115];
            rA11 = pA0[126];
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
            rA0 = pA0[6];
            rB0 = pB0[6];
            rA1 = pA0[17];
            rA2 = pA0[28];
            rA3 = pA0[39];
            rA4 = pA0[50];
            rA5 = pA0[61];
            rC0_0 += rA0 * rB0;
            rA6 = pA0[72];
            rA7 = pA0[83];
            rA8 = pA0[94];
            rA9 = pA0[105];
            rC1_0 += rA1 * rB0;
            rA10 = pA0[116];
            rA11 = pA0[127];
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
            rA0 = pA0[7];
            rB0 = pB0[7];
            rA1 = pA0[18];
            rA2 = pA0[29];
            rA3 = pA0[40];
            rA4 = pA0[51];
            rA5 = pA0[62];
            rC0_0 += rA0 * rB0;
            rA6 = pA0[73];
            rA7 = pA0[84];
            rA8 = pA0[95];
            rA9 = pA0[106];
            rC1_0 += rA1 * rB0;
            rA10 = pA0[117];
            rA11 = pA0[128];
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
            rA0 = pA0[8];
            rB0 = pB0[8];
            rA1 = pA0[19];
            rA2 = pA0[30];
            rA3 = pA0[41];
            rA4 = pA0[52];
            rA5 = pA0[63];
            rC0_0 += rA0 * rB0;
            rA6 = pA0[74];
            rA7 = pA0[85];
            rA8 = pA0[96];
            rA9 = pA0[107];
            rC1_0 += rA1 * rB0;
            rA10 = pA0[118];
            rA11 = pA0[129];
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
            rA0 = pA0[9];
            rB0 = pB0[9];
            rA1 = pA0[20];
            rA2 = pA0[31];
            rA3 = pA0[42];
            rA4 = pA0[53];
            rA5 = pA0[64];
            rC0_0 += rA0 * rB0;
            rA6 = pA0[75];
            rA7 = pA0[86];
            rA8 = pA0[97];
            rA9 = pA0[108];
            rC1_0 += rA1 * rB0;
            rA10 = pA0[119];
            rA11 = pA0[130];
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
            rA0 = pA0[10];
            rB0 = pB0[10];
            rA1 = pA0[21];
            rA2 = pA0[32];
            rA3 = pA0[43];
            rA4 = pA0[54];
            rA5 = pA0[65];
            rC0_0 += rA0 * rB0;
            rA6 = pA0[76];
            rA7 = pA0[87];
            rA8 = pA0[98];
            rA9 = pA0[109];
            rC1_0 += rA1 * rB0;
            rA10 = pA0[120];
            rA11 = pA0[131];
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
      ATL_cJIK0x0x11TN1x1x11_a1_bX(k, N, 11, alpha, ca + (11*(Mb)), lda, cb, ldb, beta, cc + (((Mb) << 1)), ldc);
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