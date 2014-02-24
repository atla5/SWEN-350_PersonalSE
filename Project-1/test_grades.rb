require_relative 'grades_util'
require 'test/unit'

# TetsGrades
#
# Unit test suite for testing grades_util.rb support methods:
#	compute_grade()
#	get_CSV_line()
#	numeric_to_letter()
#	sum_weights()

class TestGrades < Test::Unit::TestCase
   
  # Tests get_CSV_line to insure the entered input line
  # is correctly be parsed to an array of string words
  #
  def test_header_line
	headers = get_CSV_line("Name,ID,Grade")		# pass in an input string 
	assert_equal headers, ["Name","ID","Grade"] # return an array of header words
  end
  
  ####  YOUR ADDITIONAL UNIT TESTS START HERE  ####
  
end
  
