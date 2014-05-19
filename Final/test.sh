#!/bin/bash

./run.sh > out.txt
diff -w out.txt testOut.txt
