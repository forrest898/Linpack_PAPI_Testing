#include "atlas_misc.h"
#ifndef PFYDIST
   #define PFYDIST 4
#endif

#if !defined(ATL_3DNow) && !defined(ATL_SSE1) && \
    (PFADIST != 0 || PFXDIST != 0 || PFYDIST != 0)
   #include "atlas_prefetch.h"
#endif

#if defined(ATL_3DNow) || defined(ATL_SSE1)
   #ifndef PFIY
      #define PFIY prefetchnta
   #endif
   #ifndef PFIX
      #define PFIX prefetchnta
   #endif
   #ifndef PFIA
      #ifdef ATL_3DNow
         #define PFIA prefetchw
      #else
         #define PFIA prefetcht0
      #endif
   #endif
#endif
/*
 * X & A are prefetched in M loop PF[A,X]DIST (in bytes) ahead
 */
#if PFADIST == 0                /* flag for no prefetch */
   #define prefA(mem)
#else
   #if defined(ATL_3DNow) || defined(ATL_SSE1)
      #define prefA(mem) __asm__ __volatile__ \
         (Mstr(PFIA) " %0" : : "m" (*(((char *)(mem))+PFADIST)))
   #else
      #if PFLVL == 2
         #define prefA(mem) ATL_pfl2W(((char*)mem)+PFADIST)
      #else
         #define prefA(mem) ATL_pfl1W(((char*)mem)+PFADIST)
      #endif
   #endif
#endif
#if PFXDIST == 0                /* flag for no prefetch */
   #define prefX(mem)
#else
   #if defined(ATL_3DNow) || defined(ATL_SSE1)
      #define prefX(mem) __asm__ __volatile__ \
         (Mstr(PFIX) " %0" : : "m" (*(((char *)(mem))+PFXDIST)))
   #else
      #if PFLVL == 2
         #define prefX(mem) ATL_pfl2R(((char*)mem)+PFXDIST)
      #else
         #define prefX(mem) ATL_pfl1R(((char*)mem)+PFXDIST)
      #endif
   #endif
#endif
/*
 * Y is prefetched in N-loop, and always fetches next NU piece
 */
#if PFYDIST == 0                /* flag for no prefetch */
   #define prefY(mem)
#else
   #if defined(ATL_3DNow) || defined(ATL_SSE1)
      #define prefY(mem) \
         __asm__ __volatile__ (Mstr(PFIY) " %0" : : "m" (*(((char *)(mem)))))
   #else
      #if PFLVL == 2
         #define prefY(mem) ATL_pfl2R(mem)
      #else
         #define prefY(mem) ATL_pfl1R(mem)
      #endif
   #endif
#endif
#ifndef ATL_CINT
   #define ATL_CINT const int
#endif
#ifndef ATL_INT
   #define ATL_INT int
#endif
void ATL_UGEMV(ATL_CINT M0, ATL_CINT N, const TYPE *A, ATL_CINT lda0,
               const TYPE *X, TYPE *Y)
/*
 * 1x4 unrolled mvt_c.
 * Extracted from ATLAS/tune/blas/gemv/atlas-l2g.base
 */
{
   ATL_CINT N4=(N/4)*4, M=M0+M0, M1=((M0/1)*1)<<1,
            lda=lda0+lda0, lda4=lda*4;
   ATL_INT j;

   for (j=N4; j; j -= 4, A += lda4, Y += 8)
   {
      const double *A0=A, *A1=A0+lda, *A2=A1+lda, *A3=A2+lda;
      register double ry0=ATL_rzero, iy0=ATL_rzero, ry1=ATL_rzero,
                      iy1=ATL_rzero, ry2=ATL_rzero, iy2=ATL_rzero,
                      ry3=ATL_rzero, iy3=ATL_rzero;
      ATL_INT i;
      prefY(Y+8+8-1);
      for (i=0; i < M1; i += 2)
      {
         const register double ra0_0=A0[i+0], ia0_0=A0[i+1], ra0_1=A1[i+0],
                               ia0_1=A1[i+1], ra0_2=A2[i+0], ia0_2=A2[i+1],
                               ra0_3=A3[i+0], ia0_3=A3[i+1];
         const register double rx0=X[i+0], ix0=X[i+1];

         prefX(X);
         ry0 += ra0_0 * rx0;
         iy0 += ra0_0 * ix0;
         ry1 += ra0_1 * rx0;
         iy1 += ra0_1 * ix0;
         ry2 += ra0_2 * rx0;
         iy2 += ra0_2 * ix0;
         ry3 += ra0_3 * rx0;
         iy3 += ra0_3 * ix0;

         ry0 -= ia0_0 * ix0;
         iy0 += ia0_0 * rx0;
         prefA(A0);
         ry1 -= ia0_1 * ix0;
         iy1 += ia0_1 * rx0;
         prefA(A1);
         ry2 -= ia0_2 * ix0;
         iy2 += ia0_2 * rx0;
         prefA(A2);
         ry3 -= ia0_3 * ix0;
         iy3 += ia0_3 * rx0;
         prefA(A3);
      }
      #ifdef BETA0
         Y[0] = ry0;
         Y[1] = iy0;
         Y[2] = ry1;
         Y[3] = iy1;
         Y[4] = ry2;
         Y[5] = iy2;
         Y[6] = ry3;
         Y[7] = iy3;
      #else
         Y[0] += ry0;
         Y[1] += iy0;
         Y[2] += ry1;
         Y[3] += iy1;
         Y[4] += ry2;
         Y[5] += iy2;
         Y[6] += ry3;
         Y[7] += iy3;
      #endif
   }
/*
 * Do remaining columns with NU=1 cleanup
 */
   for (j=N-N4; j; j--, A += lda, Y += 2)
   {
      const double *A0=A;
      register double ry0=ATL_rzero, iy0=ATL_rzero;
      ATL_INT i;
      prefY(Y+8+8-1);
      for (i=0; i < M1; i += 2)
      {
         const register double ra0_0=A0[i+0], ia0_0=A0[i+1];
         const register double rx0=X[i+0], ix0=X[i+1];

         prefX(X);
         ry0 += ra0_0 * rx0;
         iy0 += ra0_0 * ix0;

         ry0 -= ia0_0 * ix0;
         iy0 += ia0_0 * rx0;
         prefA(A0);
      }
      #ifdef BETA0
         Y[0] = ry0;
         Y[1] = iy0;
      #else
         Y[0] += ry0;
         Y[1] += iy0;
      #endif
   }
}
