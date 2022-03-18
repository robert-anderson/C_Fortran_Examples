#!/usr/bin/bash

FC=gfortran
CC=gcc

$FC -c -fPIC my_fortran_lib.f90 -o my_fortran_lib.o
$FC my_fortran_lib.o -shared -o my_fortran_lib.so
$CC -c main.c -o main.o
$CC main.o my_fortran_lib.o -o a.out
./a.out
