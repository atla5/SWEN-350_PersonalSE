#!/bin/bash

#test printout with no paramater
ruby histogram.rb < jabberwocky.txt > out.txt
ruby histogram.rb < totc.txt >> out.txt

#test printout with parameter of 2 (same as default)
ruby histogram.rb 2 < jabberwocky.txt > outWithPam.txt
ruby histogram.rb 2 < totc.txt >> outWithPam.txt 

diff out.txt outWithPam.txt
