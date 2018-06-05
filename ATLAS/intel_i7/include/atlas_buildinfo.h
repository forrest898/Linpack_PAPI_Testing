#ifndef ATL_INSTINFO_H
   #define ATL_INSTINFO_H

#define ATL_ARCH "Corei464AVXMAC"
#define ATL_INSTFLAGS "-1 0 -a 1 -l 1"
#define ATL_F2CDEFS "-DAdd_ -DF77_INTEGER=int -DStringSunStyle"
#define ATL_ARCHDEFS "-DATL_OS_Linux -DATL_ARCH_Corei4 -DATL_CPUMHZ=2712 -DATL_AVXMAC -DATL_AVX -DATL_SSE3 -DATL_SSE2 -DATL_SSE1 -DATL_USE64BITS -DATL_GAS_x8664"
#define ATL_DKCFLAGS "-fomit-frame-pointer -mfpmath=sse -O2 -mavx2 -mfma -m64"
#define ATL_DKC "/usr/bin/gcc-5"
#define ATL_SKCFLAGS "-fomit-frame-pointer -mfpmath=sse -O2 -mavx2 -mfma -m64"
#define ATL_SKC "/usr/bin/gcc-5"
#define ATL_DMCFLAGS "-fomit-frame-pointer -mfpmath=sse -O2 -fschedule-insns -mavx2 -mfma -m64"
#define ATL_DMC "/usr/bin/gcc-5"
#define ATL_SMCFLAGS "-fomit-frame-pointer -mfpmath=sse -O2 -fschedule-insns -mavx2 -mfma -m64"
#define ATL_SMC "/usr/bin/gcc-5"
#define ATL_ICCFLAGS "-DL2SIZE=33554432 -I/home/forrest/Documents/linpack/ATLAS/intel_i7/include -I/home/forrest/Documents/linpack/ATLAS/intel_i7/..//include -I/home/forrest/Documents/linpack/ATLAS/intel_i7/..//include/contrib -DAdd_ -DF77_INTEGER=int -DStringSunStyle -DATL_OS_Linux -DATL_ARCH_Corei4 -DATL_CPUMHZ=2712 -DATL_AVXMAC -DATL_AVX -DATL_SSE3 -DATL_SSE2 -DATL_SSE1 -DATL_USE64BITS -DATL_GAS_x8664 -m64 -DPentiumCPS=2400 -DATL_FULL_LAPACK -DATL_NCPU=8 -fomit-frame-pointer -mfpmath=sse -O2 -mavx2 -mfma -m64"
#define ATL_ICC "/usr/bin/gcc-5"
#define ATL_F77FLAGS "-O -mavx2 -mfma -m64"
#define ATL_F77 "/usr/bin/x86_64-linux-gnu-gfortran"
#define ATL_DKCVERS "gcc-5 (Ubuntu 5.4.0-6ubuntu1 16.04.9) 5.4.0 20160609"
#define ATL_SKCVERS "gcc-5 (Ubuntu 5.4.0-6ubuntu1 16.04.9) 5.4.0 20160609"
#define ATL_DMCVERS "gcc-5 (Ubuntu 5.4.0-6ubuntu1 16.04.9) 5.4.0 20160609"
#define ATL_SMCVERS "gcc-5 (Ubuntu 5.4.0-6ubuntu1 16.04.9) 5.4.0 20160609"
#define ATL_ICCVERS "gcc-5 (Ubuntu 5.4.0-6ubuntu1 16.04.9) 5.4.0 20160609"
#define ATL_F77VERS "GNU Fortran (Ubuntu 5.4.0-6ubuntu1 16.04.9) 5.4.0 20160609"
#define ATL_SYSINFO "Linux forrest-ThinkPad-T460p 4.4.0-127-generic #153-Ubuntu SMP Sat May 19 10:58:46 UTC 2018 x86_64 x86_64 x86_64 GNU/Linux"
#define ATL_DATE    "Mon Jun  4 08:52:27 EDT 2018"
#define ATL_UNAM    "forrest"
#define ATL_VERS    "3.10.3"

#endif