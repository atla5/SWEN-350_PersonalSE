#!/bin/bash

gcc -o health health.c
./health < input1.txt > out.txt
diff -w out.txt output1.txt
