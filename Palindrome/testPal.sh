#!/bin/bash

python3 palindrome.py < testFile.txt > out.txt
diff out.txt testOut.txt

