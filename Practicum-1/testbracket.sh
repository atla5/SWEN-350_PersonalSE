#!/usr/bin/env bash

#Testing original sample
echo "I think February 29, 2024 will be sunny." | python3 Bracket.py > out.txt
# Output should be: [I] th[i]nk F[e]br[u][a]ry <2><9>, <2><0><2><4> w[i]ll b[e] s[u]nny.

#Test Lowercase Vowels Only
echo "aeiou" |  python3 Bracket.py >> out.txt
# Output should be: [a][e][i][o][u]

#Add others here:

#Test Uppercase Vowels
echo "AEIOU" | python3 Bracket.py >> out.txt
#output should be: [A][E][I][O][U]

#Tets String Digits only
echo "1234567890" | python3 Bracket.py >> out.txt
#output should be: <1><2><3><4><5><6><7><8><9><0>

#Test empty string
echo "" | python3 Bracket.py >> out.txt
#output should be: ""

## -- end writing to out.txt -- ##

#look at difference between actual and desired output
diff out.txt testOut.txt
#test is successful when diff outputs nothing
