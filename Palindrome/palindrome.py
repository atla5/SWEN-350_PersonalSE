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

	for line in sys.stdin:
		if is_palindrome(line):
			print(line)

def is_palindrome(l):
	"""test a line to see if it is a palindrome. return boolean"""
	l = cleanLine(l) #ensure function is not looking at punctuation or spaces
	startI = 0       #start at 0th index
	endI = len(l)-1  #last index of line

def advance(i):
	return i+1

def retreat(i):
	return i-1

def cleanLine(l):
	"""remove spaces and punctuation from line fed in. return"
	pass
