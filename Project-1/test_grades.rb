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
   
 ## Test get_CSV_line to ensure the entered input line ##
  # is correctly parsed to an array of string words
  
  #test that get_CSV_line works with the header line + expected input
  def test_getCSV_headerLine
	headers = get_CSV_line("Name,ID,Grade")		#in: input string 
	assert_equal ["Name","ID","Grade"], headers #out: array headerWords
  end

  #test that get_CSV_line works with value line and expected input
  def test_getCSV_valueLines
    values = get_CSV_line("Samantha,25,92")
    assert_equal ["Samantha","25","92"], values
  end

  #test that get_CSV_line works with empty string parts
  def test_getCSV_emptyValue
    
    #empty field at last slot
    emptyAtEnd = get_CSV_line("Samantha,25,")
    assert_equal ["Samantha","25",], emptyAtEnd
    
    #empty field in middle slot
    emptyAtMid = get_CSV_line("Samantha,,92")
    assert_equal ["Samantha","","92"], emptyAtMid
    
    #empty field in first slot (beginning)
    emptyAtBeg = get_CSV_line(",25,92")
    assert_equal ["","25","92"], emptyAtBeg

    #empty field in all slots
    emptyAtAll = get_CSV_line(",,") 
    assert_equal ["","",""], emptyAtAll
  
  end

 ## test numeric_to_letter() to ensure correct letter grade ##
  # from a given number grade [0-100]

  #check invalid arguments are raise errors
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

  #check boundaries and correct output of valid inputs
  def test_numToLet_chkBounds
    assert_equal numeric_to_letter(0), "F"
    assert_equal numeric_to_letter(60), "D"
    assert_equal numeric_to_letter(70), "C"
    assert_equal numeric_to_letter(80), "B"
    assert_equal numeric_to_letter(90), "A"
    assert_equal numeric_to_letter(100), "A"
  end

 ## test sum_weights to see if weights are summed correctly
  
end
  