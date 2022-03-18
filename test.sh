#!/usr/bin/bash

gfortran -c -fPIC my_fortran_lib.f90 -o my_fortran_lib.o
gfortran my_fortran_lib.o -shared -o my_fortran_lib.so
gcc -c main.c -o main.o
gcc main.o my_fortran_lib.o -o a.out
./a.out
