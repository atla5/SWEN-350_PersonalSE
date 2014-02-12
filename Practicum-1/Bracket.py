# Transform the 'original' string into the 'bracketed' string by
# surrounding all vowels - a, e, i, o, u in either case - by square
# brackets ([]), any digit by angle brackets (<>), and copying all
# other characters "as is".
#
# When done, return the 'bracketed' string.
#
# Example: bracket("I think February 29, 2024 will be sunny.")
#    returns "[I] th[i]nk F[e]br[u][a]ry <2><9>, <2><0><2><4> w[i]ll b[e] s[u]nny."

import fileinput
import sys

def bracket(original):
    # The final bracketed string.
    bracketed = ''
    vowels = ["a","e","i","o","u"]
    digits = ["1","2","3","4","5","6","7","8","9","0"]

    for c in original:
        if c in vowels:
            bracketed += "[" + c + "]"
        if c in digits: 
            bracketed += "<" + c + ">"
        else:
            bracketed += c

    return bracketed


if __name__ == '__main__':
    # Replace this next line with your own implementation. Do not include tests here.
    
   
    for line in sys.stdin:
        print(bracket(line))
    
	#print(bracket("I think February 29, 2024 will be sunny."))
