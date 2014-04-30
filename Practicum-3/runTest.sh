#!/bin/bash

./book_list < input1.txt > out.txt
diff testOut.txt out.txt
