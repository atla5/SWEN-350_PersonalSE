"""
## filename: ritwc.py
## description: mimics built in wordcount program. 
## author: Aidan Sawyer [aks5238@rit.edu]
## course: Personal SE [SWEN-250-01]
## language: python3
## notes: stresses importance of testing, estimation, scripting, and VCS.
"""

import fileinput

f = fileinput.input() #stores the file fed to it from the command line.

#these will be sums which must have starting values. we represent an empty file
fileText = "" #no text
numLines = 0  #0 lines
numWords = 0  #0 words
numChars = 0  #0 characters

for line in f:     #for every line in the file...
	numLines +=1           #increment the number of lines
	numChars += len(line)  #add the number of characters in that line to sum
	
	lsFromLine=line.split()    #break string into list of strings
	numWords += len(lsFromLine)#add number of items in list to sum

print(" " + str(numLines) + " " + str(numWords) + " " + str(numChars)) #print result
f.close() #close the file to free up memory
