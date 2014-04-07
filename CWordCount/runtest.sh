#!/bin/bash

./ritwc < DarkAndStormyNight.txt > out.txt
wc < DarkAndStormyNight.txt > testOut.txt

diff out.txt testOut.txt
