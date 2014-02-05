"""
#description: looks through a file and prints out the palindromes
#author: Aidan Sawyer [aks5238@rit.edu]
#language: python3
"""

#import sys to enable access to stdin
import sys 

def main():
	"""loop through stdin, call is_palindrome() on each line. 
	if it is a palindrome, prints it out. """

	#print( is_palindrome("dad") )
	#print( is_palindrome("daddy") )
	#print( is_palindrome("Dad") )
	#print( is_palindrome("madam, i'm Adam") )

	for line in sys.stdin:
		if is_palindrome(line):
			print( line.strip("\n") )
		else:
			pass

def is_palindrome(l):
	"""test a line to see if it is a palindrome. return boolean"""
	l = cleanLine(l) #ensure function ignores punctuation or spaces
	fd = 0           #start at 0th index
	bk = len(l)-1    #last index of line

	while(fd<=bk): #loop through until back and forward indexes cross
		if(l[fd] == l[bk]):
			fd = advance(fd)
			bk = retreat(bk)
		else: 
			return False
		
	return True

def advance(i):
	return i+1

def retreat(i):
	return i-1

def cleanLine(l):
	"""remove spaces and punctuation from line fed in. return"""
	line = ""
	lsPunct = [".",",","'",'"',"!"," ","@","#","$","%","^","&","*","(", \
		")","{","}","+","?","/","=","-","_","\\","|","`","~",";",":"]

	#remove any punctuation
	for c in l:
		if c in lsPunct:
			pass
		else:
			line += c

	#make lowercase
	line = line.lower()
	line = "".join(line.strip("\n"))

	#return
	return line

main()	
