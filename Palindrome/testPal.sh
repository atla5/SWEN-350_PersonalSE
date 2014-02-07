#!/bin/bash

python3 palindrome.py < testFile.txt > out.txt
diff -b out.txt testOut.txt

