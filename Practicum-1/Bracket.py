# Transform the 'original' string into the 'bracketed' string by
# surrounding all vowels - a, e, i, o, u in either case - by square
# brackets ([]), any digit by angle brackets (<>), and copying all
# other characters "as is".
#
# When done, return the 'bracketed' string.
#
# Example: bracket("I think February 29, 2024 will be sunny.")
#    returns "[I] th[i]nk F[e]br[u][a]ry <2><9>, <2><0><2><4> w[i]ll b[e] s[u]nny."

#import sys for access to stdin
import sys

def bracket(original):

    # The final bracketed string.
    bracketed = ""

    # List of lowercase vowel characters
    vowels = ["a","e","i","o","u"]

    # List of digit characters
    digits = ["1","2","3","4","5","6","7","8","9","0"]

    # For every character in string
    for char in original:

        # if the character is a vowel, square bracket it, then add.
        if char.lower() in vowels:
            bracketed += "[" + char + "]"

        # if the character is a digit, angle bracket it, then add.
        elif char in digits: 
            bracketed += "<" + char + ">"

        # if the character is neither, add it "as is"
        else:
            bracketed += char

    # return edited string 
    return bracketed


if __name__ == '__main__':
    
    #get standard input from sis. print out bracketed version.
    for line in sys.stdin:
        print(bracket(line))
    
