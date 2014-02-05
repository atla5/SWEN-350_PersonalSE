#!/bin/bash

python3 palindrome.py < testFile > out.txt
diff out.txt testOut.txt

