#!/usr/bin/env bash

#ignore non-codon strings
echo "line without any codons in it" | python3 amino_acids.py > out.txt

#reading/interpreting/translating correct codons
echo "AUG UUU" | python3 amino_acids.py >> out.txt

#correctly identifies and uses start codon.
echo "UUU AUG" | python3 amino_acids.py >> out.txt

#correctly hangles start/stop/end of line
echo "AUG UUU UAA AUG UUU UUU" | python3 amino_acids.py >> out.txt


#compare real output with expected output
diff out.txt testOut.txt
