require_relative 'grades_util'

# grades.rb Ruby Script
#
# Read the first row (column names) and second row (grade weights).
# If the weights don't sum up to 100, print an error message and exit.
# Otherwise print the column headers with their weights (empty weights simply don't print)
#
# For each student line, print the header and column for each field in the line.
# The field could be identifying information (if the weight is blank) or numeric (if the
# weight is non-negative). Grades can be numeric or letter (with optional +/-)
# Also prints final weighted numeric grade and letter grade.
#
# At end, prints a summary showing the number students for each letter grade and
# the class GPA.


# Create the hash for counting the number of occurrences of each letter grade.
lettercount = Hash.new(0)   # default count is 0.

# Use get_CSV_line() to get the header and weight lines.
# Each line should be "chomped" to eliminate the end of line character(s).
# Create arrays for the headers and weights by splitting on commas.

n = 0 #my way of looking out for the header file by counting numLines
lsHeaders = []   #contains the headers that will be the same for each student
lsWeights = []   #list of weights fed into the second line
lsStudents  = [] #list of lists of grades.

while line = gets

  #lsValues holds the fields for one student
  lsValues = []

  #get csv line
  fields = get_CSV_line(line)

  #edit appropriate list
  if n==0      #header line
    lsHeaders = fields
  elsif n == 1 #weights line
    lsWeights = fields
  else         #student values line
    lsValues = fields
    lsStudents << lsValues
  end

  n+=1
end


#list of digits to check '%' symbol
lsDigits = ["1","2","3","4","5","6","7","8","9","0"]
printf("Summary information for grades file\n\n")

#for every header, print out the header and, if present, its weight
lsHeaders.each_index{|i| 
  
  #print with or without % sign, depending.
  if lsDigits.include?(lsWeights[i][-1])
    printf("%s %s%%\n", lsHeaders[i], lsWeights[i]) 
  else
    printf("%s %s\n", lsHeaders[i], lsWeights[i])
  end
  
}

#print a new line after the header/weight stuff
printf("\n")

# Use sum_weights() to check if the weights do not sum to 100, output the error message:
# "Weights add up to #{sum}, not 100" - where sum is the sum of input weights

sum = sum_weights(lsHeaders,lsWeights)
if sum != 100
  printf("Weights add up to %d, not 100\n",sum)
  exit
end


# Get each of the remaining lines, representing grade information for an individual student.
# Print the header for each column and whatever is in that column on the student grade line.
# Compute contribution of each weighted field to the overall grade using compute_grade(),
# remember to skip fields that do not have weights associated with them.
# Convert the numeric grade to a letter grade using numeric_to_letter().
# Output the final numeric and letter grade for that student and update the 
# lettercount hash that is keeping track of the number of occurrences of each letter grade
# for the class.


# Now print the summary information - the number of students at each 
# letter grade level and the class GPA using print_summary(). 

#for every student entry...
lsStudents.each{|s|

  finNumeric = 0

  #s is a student containing lsValues
  lsHeaders.each_index{|i|

    header = lsHeaders[i]
    value  = s[i]

    #add a percent sign if that value ends in a digit
    if LETTER_TO_NUMERIC.keys.include?(s[i].upcase())
      value = LETTER_TO_NUMERIC[s[i].upcase()]
    end

    #print out "#{header}: #{value}:
    printf("%s: %s\n", header, value)

    #calculate student's final numeric and letter grade
    finNumeric += compute_grade(lsWeights[i],value)
    
  }

  #print out final and letter grade
  finLetter = numeric_to_letter(finNumeric)
  printf("Final Numeric Grade = %d Letter = %s\n",finNumeric,finLetter)

  #print a newline after every student's entry
  printf("\n")
}

