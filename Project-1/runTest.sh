#!/bin/bash

ruby grades.rb < input.txt > out.txt
diff -w out.txt output.txt
