# grades_util.rb Ruby Script
#
# Support methods used by grades.rb for reading CSV gradebook files
# and producing reports
#

##### TRANSLATION HASH FOR LETTER GRADES TO NUMERIC #####

LETTER_TO_NUMERIC = {
  "A+" => 98, "A" => 95, "A-" => 92,
  "B+" => 88, "B" => 85, "B-" => 82,
  "C+" => 78, "C" => 75, "C-" => 72,
  "D+" => 68, "D" => 65, "D-" => 62,
  "F+" => 55, "F" => 40, "F-" => 25,
}

##### TRANSLATION OF LETTER GRADES TO QUALITY POINTS #####

QUALITY_POINTS = { 'A' => 4, 'B' => 3, 'C' => 2, 'D' => 1, 'F' => 0 }


# sum_weights( headers, weights)
#	headers = array of header strings (1st line of input)
#	weights = array of weights strings (2nd line of input)
# returns integer value equal to the sum of all weights
#
# Method to sum up the weights in the weight line. 
# Skips over empty fields.

def sum_weights(headers, weights)
  
  ### YOUR CODE HERE ###
  
end

# numeric_to_letter(numeric)
#	numeric =  integer value to convert to a letter grade
# return letter grade as a string
#
# Method to convert a raw numeric grade to a letter A - F.

def numeric_to_letter(numeric)

  #catch incorrect arguments
  if not numeric.is_a? Integer or numeric.is_a? Float
    raise ArgumentError, "Argument must be a number"
  elsif numeric > 100 or numeric < 0
    raise ArgumentError, "cannot have grade > 100 or < 0"

  #return the correct Letter grade based on range.
  elsif numeric >= 0 and numeric < 60
    return "F"
  elsif numeric >= 60 and numeric < 70
    return "D"
  elsif numeric >= 70 and numeric < 80
    return "C"
  elsif numeric >= 80 and numeric < 90
    return "B"
  elsif numeric >= 90 and numeric <= 100
    return "A"
  else
    raise "a number 0<=n<=100 was not caught"
  end
end

  
# get_CSV_line( line)
#	line = string of one line of input
# returns array of strings representing fields in that line
#
# Get a CSV line for the header line, weight lines or field line
# Each line should be "chomped" to eliminate the end of line character(s).
# Create arrays for the headers, weights and fields by splitting on commas.

def get_CSV_line( line )
   
  ls = line.chomp().split(",")
  return ls
   
end

# compute_grade( weight, field )
# 	weight = string value representing weight of the graded item
#   field = string value representing value of graded item in numeric or letter grade format
# returns floating point grade value
#
# Compute a numeric grade given the weight of the grade and either a numeric 
# score or letter score in the field. 

def compute_grade( weight, field)
   
  if field.is_a? String
    if field (LETTER_TO_NUMERIC.keys).include?
      field = LETTER_TO_NUMERIC[field]
    else
      raise ArgumentError, "field string not in dictionary"
    end
  end

  return weight*field
   
end

# print_summary(lettercount)  - !!! DO NOT MODIFY !!!
#	lettercount = hash of letter grades => count of number of students
#
# Prints summary information. First the count of the number of students for each
# letter grade and then the class GPA.

def print_summary(lettercount)
  qualty_points = 0
  grade_count = 0

  ['A', 'B', 'C', 'D', 'F'].each do | letter |
    puts "#{letter} = #{lettercount[letter]}"
    qualty_points += QUALITY_POINTS[letter] * lettercount[letter]
    grade_count += lettercount[letter]
  end

  printf "Class GPA = %1.2f", qualty_points.to_f / grade_count.to_f
  puts " "
end
