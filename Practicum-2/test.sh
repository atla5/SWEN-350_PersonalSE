#!/bin/bash

ruby currency.rb < input.txt > out.txt
diff output.txt out.txt
