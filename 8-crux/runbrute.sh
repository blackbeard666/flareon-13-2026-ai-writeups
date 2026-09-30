#!/bin/bash
cd /mnt/c/Users/cavila/Desktop/ctf/flareon13-2026/8-crux
export OMP_NUM_THREADS=12
echo "START $(date)" > brute_full.log
./shabrute2 66777216 4294967296 >> brute_full.log 2>>brute_full.err
echo "END $(date)" >> brute_full.log
