#!/bin/bash

#compile (update) ./ritwc
gcc -o ritwc ritwc.c 

#redirect parameter (text file) into each, writing to txt files
./ritwc < "$1" > out.txt
wc < "$1" > testOut.txt

#run diff comparison
diff -w out.txt testOut.txt
