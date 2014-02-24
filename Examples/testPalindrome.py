"""
## description: tests whether the input is a palindrome
## author: Aidan Sawyer [aks5238@rit.edu]
## course: Personal SE [SWEN-250-01]
## language: python3

"""
import unittest
import sys

def main():
	"""
	description: gets filename, cleans up and concatenates strings in line, 
      sends it to isPalindrome, and prints out only the lines which 
      are palindromes.
	calls: is_palindrome([concatenated, clean line of file] 
	"""

	#make sure input is insensitive to case and punctuation
	for line in sys.stdin:
		if is_palindrome(line):
			print(line)

#	f.close() #close the file


def is_palindrome(s):
	"""
	description: called by main. sets variables necessary for isPalHelp 
      to run properly. 
	returns: boolean
	"""
	s = "".join(s.strip("\n")).lower()

	sF = "" 		#final, processod string
	for char in s:
		if char >= 'a' and char <= 'z':
			sF+=char
	
	f = 0 	 		#starting index (beginning, zero)
	b = len(sF)-1 	 	#index of last character in string
	m = (len(sF)-1)//2       #midpoint of string
	
	return isPalHelp(f,b,m,sF)	

def isPalHelp(f,b,m,s):
	"""
	description: recursive function for is_palindrome(). checks each index 
      pair from outside-in until it either the pair is mismatched (returns 
      false) or it's gone through the whole string (return true). 
	returns: boolean.
	"""

	#if your start and finishing indexes cross, you've tested the whole 
    #  thing and not gotten an error.
    if f > m or b < m:
		return True
	if s[f] == s[b]:     #the pair is correct and the next pair should be tested
		return  isPalHelp(advance(f),retreat(b),m,s) 
	else:
		return False

def advance(i): 
	"""returns the next index from the left."""
	return i+1

def retreat(i): 
	"""returns the next index from the right"""
	return i-1

##### --- TESTING --- #####

class TestPal(unittest.TestCase):
	def testAdvance(self):
		"""test advance(i) function)"""
		self.assertEqual(advance(2),3)
	def testRetreat(self):
		"""tests retreat(i) function)"""
		self.assertEqual(retreat(5),4)
	def testKnownUnPal(self):
		"""tests is_palindrome(s) with a known non-palindrome"""
		self.assertFalse(is_palindrome("This is not a Palindrome"))
	def testKnownPalOne(self):
		"""ensures that is_palidrome(s) returns true for chars"""
		self.assertTrue(is_palindrome("x"))
	def testKnownPalMultiOdd(self):
		"""ensures is_palindrome(s) returns true for small, all lower 
           case strings"""
		self.assertTrue(is_palindrome("xyx"))
	def testKnownPalMultiEven(self):
		"""ensures is_palindrome(s) returns true for small, even, all lower 
           case strings"""
		self.assertTrue(is_palindrome("xyyx"))
	def testKnownPalCase(self):
		"""ensures that is_palindrome(s) isn't bothered by capitalisation"""
		self.assertTrue(is_palindrome("XYx"))
	def testKnownPalSpaces(self):
		"""ensures that is_palindrome(s) isn't bothered by spacing"""
		self.assertTrue(is_palindrome("x   y x"))
	def testKnownPalPunc(self):
		"""ensures that is_palindrome(s) isn't bothered by punctuation"""
		self.assertTrue(is_palindrome("x,y;@#*!^x"))
		

if __name__ == "__main__": 
	unittest.main()

