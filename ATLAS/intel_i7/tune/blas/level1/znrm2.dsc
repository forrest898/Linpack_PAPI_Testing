3
1 0 cnrm2_ssq1_x0.c   "R. Clint Whaley"
2 0 cnrm21_x0.c       "R. Clint Whaley" \
/usr/bin/gcc-5 -fomit-frame-pointer -mfpmath=sse -O2 -mavx2 -mfma -m64 -m64
-fomit-frame-pointer -mfpmath=387 -O2
3 0 cnrm2_x87_x0.c    "R. Clint Whaley" \
/usr/bin/gcc-5 -fomit-frame-pointer -mfpmath=sse -O2 -mavx2 -mfma -m64 -m64
-x assembler-with-cpp
<ID> <incX> <rout> <auth>