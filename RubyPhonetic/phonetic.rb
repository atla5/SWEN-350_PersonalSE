# Convert to/from phonetic alphabet
# Aidan Sawyer

class Phonetic


#  attr_accessor :Letters

  Letters = [
             ['A', 'ALPHA'],
             ['B', 'BRAVO'],
             ['C', 'CHARLIE'],
             ['D', 'DELTA'],
             ['E', 'ECHO'],
             ['F', 'FOXTROT'],
             ['G', 'GOLF'],
             ['H', 'HOTEL'],
             ['I', 'INDIA'],
             ['J', 'JULIET'],
             ['K', 'KILO'],
             ['L', 'LIMA'],
             ['M', 'MIKE'],
             ['N', 'NOVEMBER'],
             ['O', 'OSCAR'],
             ['P', 'PAPA'],
             ['Q', 'QUEBEC'],
             ['R', 'ROMEO'],
             ['S', 'SIERRA'],
             ['T', 'TANGO'],
             ['U', 'UNIFORM'],
             ['V', 'VICTOR'],
             ['W', 'WHISKEY'],
             ['X', 'XRAY'],
             ['Y', 'YANKEE'],
             ['Z', 'ZULU'],
            ]

#  attr_accessor :Letters
 
  # Translate a word to its phonetic alphabet equivalent
  def self.to_phonetic(word)
    
    s = "" #return string

    #create a list of all the characters in the word
    ls = word.upcase().split("")

    ls.each { |c|
      Letters.each{ |letter|
        a = letter[0] #alpha character
        p = letter[1] #phonetic word
        
        #if character is an alpha character
        if c == a
          #append relevant phonetic word with a space separator
          s+= p + " "
        end
      }
    } 

    #return the return string without the extra space
    return s.chomp(" ")

  end

  # Translate a sequence of phonetic alphabet code words 
  # to their alphabetic equivalent
  def self.from_phonetic(str)
    
    s = "" #return string
    
    #convert to capital and convert to list
    ls = str.upcase().split(/ +/)
    
    #add each translated character to return string
    ls.each { |w|

      #go through array of arrays looking for word, adding char
      Letters.each { |letter|
        a = letter[0] #alpha 
        p = letter[1] #phonetic

        #if the word is equal to the phonetic
        if w.chomp("\n") == p
          s+=a #append that letter to return string
        end
      }
    }
       
    return s
  end

  # If the line starts with A2P, call to_phonetic on the rest of the substring
  # If the line starts with P2A, call from_phonetic on the rest of the substring
  # Otherwise, return nothing.
  def self.translate(line)
  
    #check that inputs are valid
    if not line.is_a? String
      raise ArgumentError, "invalid input string: non-string input"
    elsif line == ""
      return ""
    end

    #ensure all characters are upcased
    line = line.upcase()+ " "

    #look for 'A2P' or 'P2A' tag.
    tag = line[0..2]

    if tag == "A2P"
      return self.to_phonetic(line[4..-1])
    elsif tag == "P2A"
      return self.from_phonetic(line[4..-1])
    else
      return nil
    end

  end

end

# This is ruby idiom that allows us to use both unit testing and command line processing
# This gets run with ruby phonetic.rb
# Does not get run when we use unit testing, e.g. ruby phonetic_test.rb
if __FILE__ == $PROGRAM_NAME
  $stdin.each do |line|
    puts Phonetic.translate(line)
  end
end
