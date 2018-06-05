#define ATL_UCPSC ATL_scpsc_xp0yp0aXbX

#include "atlas_misc.h"
void ATL_UCPSC(const int N, const SCALAR alpha, const TYPE *X, const int incX,
               TYPE *Y, const int incY)
{
   int i;
   for (i=N; i; i--, X += incX, Y += incY) *Y = alpha * *X;
}