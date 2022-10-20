#!/bin/zsh

for run in {1..10}; do
  time -p python3 mandelbrot.py 1600 1600 -1.5 -1.5 1.5 1.5 50 4 > img.pbm
done

for run in {1..10}; do
  time -p pypy3 mandelbrot.py 1600 1600 -1.5 -1.5 1.5 1.5 50 4 > img.pbm
done
