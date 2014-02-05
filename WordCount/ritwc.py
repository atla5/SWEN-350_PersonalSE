"""
## description: mimics built in wordcount program. 
## author: Aidan Sawyer [aks5238@rit.edu]
"""

import fileinput

f = fileinput.input() #stores the file fed to it from the command line.

#sums for each variable to be stored initialized to 0
numLines = 0  #lines in file
numWords = 0  #words in file
numChars = 0  #characters in file

for line in f:     #for every line in the file...
	numLines +=1           #increment the number of lines
	numChars += len(line)  #add the number of characters in that line to sum
	
	lsFromLine=line.split()    #break string into list of strings
	numWords += len(lsFromLine)#add number of items in list to sum

#print result in 'wc' format:
print(" " + str(numLines) + "  " + str(numWords) + " " + str(numChars))

#close the file to free up memory
f.close()
