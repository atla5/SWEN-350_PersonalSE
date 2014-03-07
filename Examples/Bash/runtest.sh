#!/bin/bash
python3 ritwc.py < "$1" > myoutput.txt
wc < "$1" > wcoutput.txt
diff -b myoutput.txt wcoutput.txt
