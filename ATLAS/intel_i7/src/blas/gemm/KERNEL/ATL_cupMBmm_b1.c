#define SCPLX
#include "atlas_misc.h"
void ATL_cupMBmm0_2_0_b0
   (const int M, const int N, const int K, const float alpha,
    const float *A, const int lda, const float *B, const int ldb,
    const float beta, float *C, const int ldc);
void ATL_cupMBmm0_4_0_b0
   (const int M, const int N, const int K, const float alpha,
    const float *A, const int lda, const float *B, const int ldb,
    const float beta, float *C, const int ldc);
void ATL_cgpMBmm_b0
   (const int M, const int N, const int K, const float alpha,
    const float *A, const int lda, const float *B, const int ldb,
    const float beta, float *C, const int ldc);
void ATL_cupMBmm0_2_0_b1
   (const int M, const int N, const int K, const float alpha,
    const float *A, const int lda, const float *B, const int ldb,
    const float beta, float *C, const int ldc);
void ATL_cupMBmm0_4_0_b1
   (const int M, const int N, const int K, const float alpha,
    const float *A, const int lda, const float *B, const int ldb,
    const float beta, float *C, const int ldc);
void ATL_cgpMBmm_b1
   (const int M, const int N, const int K, const float alpha,
    const float *A, const int lda, const float *B, const int ldb,
    const float beta, float *C, const int ldc);
void ATL_cupMBmm0_2_0_bX
   (const int M, const int N, const int K, const float alpha,
    const float *A, const int lda, const float *B, const int ldb,
    const float beta, float *C, const int ldc);
void ATL_cupMBmm0_4_0_bX
   (const int M, const int N, const int K, const float alpha,
    const float *A, const int lda, const float *B, const int ldb,
    const float beta, float *C, const int ldc);
void ATL_cgpMBmm_bX
   (const int M, const int N, const int K, const float alpha,
    const float *A, const int lda, const float *B, const int ldb,
    const float beta, float *C, const int ldc);

#define ATL_CupMBmm0_2_0_b1(M_, N_, K_, al_, A_, lda_, B_, ldb_, be_, C_, ldc_) \
{ \
   ATL_cupMBmm0_2_0_bX(M_, N_, K_, al_, A_, lda_, B_, ldb_, ATL_rnone, C_, ldc_); \
   ATL_cupMBmm0_2_0_b1(M_, N_, K_, al_, A_, lda_, (B_)+(ldb_)*(N_), ldb_, be_, (C_)+1, ldc_); \
   ATL_cupMBmm0_2_0_bX(M_, N_, K_, al_, (A_)+(lda_)*(M_), lda_, (B_)+(ldb_)*(N_), ldb_, ATL_rnone, C_, ldc); \
   ATL_cupMBmm0_2_0_b1(M_, N_, K_, al_, (A_)+(lda_)*(M_), lda_, B_, ldb_, ATL_rone, (C_)+1, ldc_); \
}
#define ATL_CupMBmm0_4_0_b1(M_, N_, K_, al_, A_, lda_, B_, ldb_, be_, C_, ldc_) \
{ \
   ATL_cupMBmm0_4_0_bX(M_, N_, K_, al_, A_, lda_, B_, ldb_, ATL_rnone, C_, ldc_); \
   ATL_cupMBmm0_4_0_b1(M_, N_, K_, al_, A_, lda_, (B_)+(ldb_)*(N_), ldb_, be_, (C_)+1, ldc_); \
   ATL_cupMBmm0_4_0_bX(M_, N_, K_, al_, (A_)+(lda_)*(M_), lda_, (B_)+(ldb_)*(N_), ldb_, ATL_rnone, C_, ldc); \
   ATL_cupMBmm0_4_0_b1(M_, N_, K_, al_, (A_)+(lda_)*(M_), lda_, B_, ldb_, ATL_rone, (C_)+1, ldc_); \
}

void ATL_cpMBmm_b1
   (const int M, const int N, const int K, const float alpha,
    const float *A, const int lda, const float *B, const int ldb,
    const float beta, float *C, const int ldc)
{

   if (M == (((((M) >> 2)) << 2)))
   {
      ATL_CupMBmm0_4_0_b1(M, N, K, alpha, A, lda, B, ldb, beta, C, ldc);
   }
   else if (M == (((((M) >> 1)) << 1)))
   {
      ATL_CupMBmm0_2_0_b1(M, N, K, alpha, A, lda, B, ldb, beta, C, ldc);
   }
   else ATL_cgpMBmm_b1(M, N, K, alpha, A, lda, B, ldb, beta, C, ldc);
}
