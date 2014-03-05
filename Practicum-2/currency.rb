# Currency Calculator
# Aidan Sawyer - aks5238
# Language: ruby
# Assignment: SWEN-250 Practicum-2

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

    #check that currency_code is in RATES [raise error if it is not]
    if not RATES.keys.include?(currency_code)
      raise ArgumentError, "unknown currency_code"
    end

    #check that 'value' is a float [raise error if it's not]
    if not value.is_a? Float
      raise ArgumentError, "value is not a float"
    end

	#use currency code with RATES to get conversion factor.
    k = RATES[currency_code]
    
    #compute and return conversion factor times the number of units of that
    #  currency
	return k*value;
end

# Return the floating point result of the given operation ('+'/'-') 
# using the two floating point value parameters. 
def compute( operator, value_1, value_2 )

    #check the type of values 1 and 2 [if either is not a float, raise error]
    if not value_1.is_a? Float or not value_2.is_a? Float
      raise ArgumentError, "value_1 or value_2 is not a float"
    end

    #check operator and run command. [if not +/- raise error]
    if operator == "+"
      return value_1 + value_2
    elsif operator == "-"
      return value_1 - value_2
    else
      raise ArgumentError, "operator not a +/-"
    end

end

# Given an input string in CSV format, return an array
# of values.
def parse_line( line )

    #chomp newline character and split into list of strings
    line.chomp!("\n")	
	ls = line.split(",")

    #convert both values to floats
    ls[2] = ls[2].to_f()
    ls[4] = ls[4].to_f()
   
    #return the correctly parsed list 
    return ls
	
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
   
    #create a list of the correctly interpreted values from line of stdin 
	ls = parse_line(line)
    
    #calculate result as the computation with op ls[0] with values of the 
    #  conversions of both types
    res = compute( ls[0], convert( ls[1], ls[2] ), convert( ls[3], ls[4] ) )  
  
    #print result for that line in desired format
    printf("Result = %.2f USD\n", res)  
	
  end
end
