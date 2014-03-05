# Currency Calculator

  # Currency conversion rates for one USD
  RATES = Hash[
             'GBP' => 1.674,
			 'CAN' => 0.861,
			 'CHF' => 1.137,
			 'EUR' => 1.38,
			 'SEK' => 0.156,		
			 'USD' => 1.0
             ]

# Given a currency code and floating point units of that currency,
# return the equivalent USD as a floating point value.
def convert( currency_code, value )

	## FILL IN ##
	return 0.0    # place holder
end

# Return the floating point result of the given operation ('+'/'-') 
# using the two floating point value parameters. 
def compute( operator, value_1, value_2 )

	## FILL IN ##
	return 0.0	 # place holder
end

# Given an input string in CSV format, return an array
# of values.
def parse_line( line )

    line.chomp!("\n")	
	return line.split(",")
	
end


# This is a Ruby idiom that allows us to use both unit testing and command line processing
# This gets run with ruby currency.rb
# Does not get run when we use unit testing, e.g. ruby currency_test.rb

# For each line of CSV input:
#	- parse the input line into appropriate fields
#	- convert the currencies to USD
#   - perform the computation requested
#   - output the result as "Result = xx.xx USD"
#		where xx.xx is USD rounded to the nearest cent

if __FILE__ == $PROGRAM_NAME
  $stdin.each do |line|
    
	## FILL IN ##
	
  end
end
