#ifdef ATL_UCLEANN
#define ATL_sJIK80x0x80TN80x80x0_a1_bX ATL_sgpNBmm_bX
#else
#define ATL_sJIK80x0x80TN80x80x0_a1_bX ATL_spNBmm_bX
#endif

#ifndef ATL_RESTRICT
#if defined(__STDC_VERSION__) && (__STDC_VERSION__/100 >= 1999)
   #define ATL_RESTRICT restrict
#else
   #define ATL_RESTRICT
#endif
#endif
#ifndef ATL_RESTRICT
#if defined(__STDC_VERSION__) && (__STDC_VERSION__/100 >= 1999)
   #define ATL_RESTRICT restrict
#else
   #define ATL_RESTRICT
#endif
#endif
static void ATL_sJIK80x0x80TN2x1x1_a1_bX
   (const int M, const int N, const int K, const float alpha, const float * ATL_RESTRICT A, const int lda, const float * ATL_RESTRICT B, const int ldb, const float beta, float * ATL_RESTRICT C, const int ldc)
/*
 * matmul with TA=T, TB=N, MB=80, NB=0, KB=80, 
 * lda=80, ldb=80, ldc=0, mu=2, nu=1, ku=1, pf=0
 * Generated by ATLAS/tune/blas/gemm/emit_mm.c (3.10.3)
 */
{
   #define Nb N
   const float *stM = A + 6400;
   const float *stN = B + (((Nb) << 6)+((Nb) << 4));
   #define incAk 1
   const int incAm = 80, incAn = -6400;
   #define incBk 1
   const int incBm = -80, incBn = 80;
   #define incCm 2
   const int incCn = (ldc) - 80;
   float *pC0=C;
   const float *pA0=A;
   const float *pB0=B;
   register int k;
   register float rA0, rA1;
   register float rB0;
   register float rC0_0, rC1_0;
   do /* N-loop */
   {
      do /* M-loop */
      {
         rA0 = beta;
         rC0_0 = *pC0;
         rC0_0 *= rA0;
         rC1_0 = pC0[1];
         rC1_0 *= rA0;
         for (k=0; k < 80; k++) /* easy loop to unroll */
         {
            rA0 = *pA0;
            rB0 = *pB0;
            rA1 = pA0[80];
            rC0_0 += rA0 * rB0;
            rC1_0 += rA1 * rB0;
            pA0 += incAk;
            pB0 += incBk;
         }
         *pC0 = rC0_0;
         pC0[1] = rC1_0;
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
void ATL_sJIK80x0x80TN80x80x0_a1_bX
   (const int M, const int N, const int K, const float alpha, const float * ATL_RESTRICT A, const int lda, const float * ATL_RESTRICT B, const int ldb, const float beta, float * ATL_RESTRICT C, const int ldc)
/*
 * matmul with TA=T, TB=N, MB=80, NB=0, KB=80, 
 * lda=80, ldb=80, ldc=0, mu=2, nu=5, ku=1, pf=0
 * Generated by ATLAS/tune/blas/gemm/emit_mm.c (3.10.3)
 */
{
   const int Nb = (N/5)*5;
   const float *ca=A, *cb=B;
   float *cc=C;
   const float *stM = A + 6400;
   const float *stN = B + (((Nb) << 6)+((Nb) << 4));
   #define incAk 1
   const int incAm = 80, incAn = -6400;
   #define incBk 1
   const int incBm = -80, incBn = 400;
   #define incCm 2
   const int incCn = (((ldc) << 2)+ldc) - 80;
   float *pC0=C, *pC1=pC0+(ldc), *pC2=pC1+(ldc), *pC3=pC2+(ldc), *pC4=pC3+(ldc);
   const float *pA0=A;
   const float *pB0=B;
   register int k;
   register float rA0, rA1;
   register float rB0, rB1, rB2, rB3, rB4;
   register float rC0_0, rC1_0, rC0_1, rC1_1, rC0_2, rC1_2, rC0_3, rC1_3, rC0_4, rC1_4;
   if (pB0 != stN)
   {
      do /* N-loop */
      {
         do /* M-loop */
         {
            rA0 = beta;
            rC0_0 = *pC0;
            rC0_0 *= rA0;
            rC1_0 = pC0[1];
            rC1_0 *= rA0;
            rC0_1 = *pC1;
            rC0_1 *= rA0;
            rC1_1 = pC1[1];
            rC1_1 *= rA0;
            rC0_2 = *pC2;
            rC0_2 *= rA0;
            rC1_2 = pC2[1];
            rC1_2 *= rA0;
            rC0_3 = *pC3;
            rC0_3 *= rA0;
            rC1_3 = pC3[1];
            rC1_3 *= rA0;
            rC0_4 = *pC4;
            rC0_4 *= rA0;
            rC1_4 = pC4[1];
            rC1_4 *= rA0;
            for (k=0; k < 80; k++) /* easy loop to unroll */
            {
               rA0 = *pA0;
               rB0 = *pB0;
               rA1 = pA0[80];
               rC0_0 += rA0 * rB0;
               rB1 = pB0[80];
               rB2 = pB0[160];
               rC1_0 += rA1 * rB0;
               rB3 = pB0[240];
               rB4 = pB0[320];
               rC0_1 += rA0 * rB1;
               rC1_1 += rA1 * rB1;
               rC0_2 += rA0 * rB2;
               rC1_2 += rA1 * rB2;
               rC0_3 += rA0 * rB3;
               rC1_3 += rA1 * rB3;
               rC0_4 += rA0 * rB4;
               rC1_4 += rA1 * rB4;
               pA0 += incAk;
               pB0 += incBk;
            }
            *pC0 = rC0_0;
            pC0[1] = rC1_0;
            *pC1 = rC0_1;
            pC1[1] = rC1_1;
            *pC2 = rC0_2;
            pC2[1] = rC1_2;
            *pC3 = rC0_3;
            pC3[1] = rC1_3;
            *pC4 = rC0_4;
            pC4[1] = rC1_4;
            pC0 += incCm;
            pC1 += incCm;
            pC2 += incCm;
            pC3 += incCm;
            pC4 += incCm;
            pA0 += incAm;
            pB0 += incBm;
         }
         while(pA0 != stM);
         pC0 += incCn;
         pC1 += incCn;
         pC2 += incCn;
         pC3 += incCn;
         pC4 += incCn;
         pA0 += incAn;
         pB0 += incBn;
      }
      while(pB0 != stN);
   }
   if (k=N-Nb)
      ATL_sJIK80x0x80TN2x1x1_a1_bX(80, k, 80, alpha, ca, lda, cb + (((Nb) << 6)+((Nb) << 4)), ldb, beta, cc + (Nb*ldc), ldc);
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
