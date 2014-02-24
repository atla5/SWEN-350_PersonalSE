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
  
 ## test numeric_to_letter()

  #check invalid arguments are handled correctly
  def test_numToLet_invalidArgs
    
    #string arguments raise errors
    assert_raise ArgumentError do
      numeric_to_letter("helloWorld")
    end

    #negative input raises error
    assert_raise ArgumentError do
      numeric_to_letter(-12)
    end

    #numbers exceeding 100 raise error
    assert_raise ArgumentError do
      numeric_to_letter(102)
    end

  end

  #check boundaries and correct output of valid args
  def test_numToLet_chkBounds
    assert_equal "F-", numeric_to_letter(0)
    assert_equal "A", numeric_to_letter(96)
    assert_equal "A+", numeric_to_letter(100)
  end
  
end
  
