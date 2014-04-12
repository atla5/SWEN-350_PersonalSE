#!/bin/bash

./ritwc < DarkAndStormyNight.txt > out.txt
wc < DarkAndStormyNight.txt > testOut.txt

./ritwc < GaltSpeech.txt >> out.txt
wc < GaltSpeech.txt >> testOut.txt

diff -w out.txt testOut.txt
