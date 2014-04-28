#!/bin/bash

#$fName = input + "$1" + .txt

rm health
make
./health < "$1"
