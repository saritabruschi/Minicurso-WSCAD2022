#!/bin/zsh
echo "Diretiva O0"
time -p gcc -O0 mandelbrot.c
time -p ./a.out 1600 1600 -1.5 -1.5 1.5 1.5 50 4 > img.pbm
echo
echo "Diretiva O1"
time -p gcc -O1 mandelbrot.c
time -p ./a.out 1600 1600 -1.5 -1.5 1.5 1.5 50 4 > img.pbm
echo
echo "Diretiva O2"
time -p gcc -O2 mandelbrot.c
time -p ./a.out 1600 1600 -1.5 -1.5 1.5 1.5 50 4 > img.pbm
echo 
echo "Diretiva O3"
time -p gcc -O3 mandelbrot.c
time -p ./a.out 1600 1600 -1.5 -1.5 1.5 1.5 50 4 > img.pbm
