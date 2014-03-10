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
    assert_equal [], emptyAtAll
  
  end

 ## test numeric_to_letter() to ensure correct letter grade ##
  # from a given number grade [0-100]

  #check arguments to see if they raise errors
  def test_numToLet_Args
    
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
    assert_equal "F", numeric_to_letter(0)
    assert_equal "D", numeric_to_letter(60)
    assert_equal "C", numeric_to_letter(70)
    assert_equal "B", numeric_to_letter(80)
    assert_equal "A", numeric_to_letter(90)
    assert_equal "A", numeric_to_letter(100)
  end

 ## test sum_weights to see if weights are summed correctly
  def test_sum_weight_input 
    
    lsHead   = ["these","are","headers"]
    lsString = [20,30,"twelve"] #string in weights list
    lsEmpty  = [20,30,]         #empty field in weights list
    lsNorm   = [20,30]    

    #test that errors are skipped with string field in weights
    assert_equal( sum_weights(lsHead, lsNorm), sum_weights(lsHead, lsString) )

    #ensure that method skips over empty fields
    assert_equal sum_weights(lsHead,lsNorm), sum_weights(lsHead,lsEmpty)

  end

  def test_sum_weight_output

    lsHead   = ["these","are","headers"] #list of headers
    ls100    = [20,30,50] 
    ls110    = [20,30,50,10] 
    ls0      = [0,0,0,0]

    assert_equal 100, sum_weights(lsHead,ls100)
    assert_equal 110, sum_weights(lsHead,ls110)
    assert_equal   0, sum_weights(lsHead,ls0)

  end


 ## test compute_grade
  def test_compute_inputs

    #incorrect string (letter grade) for field results in return of 0
    assert_equal 0, compute_grade(20,"Zed")

    #non-float input for weight results in return of zero
    assert_equal 0, compute_grade("twenty","A")

    #out-of-bounds float value for weight
    assert_raise ArgumentError do
      compute_grade(120,82)
    end
    assert_raise ArgumentError do
      compute_grade(-20,82)
    end

    #out-of-bounds int value for grade
    assert_raise ArgumentError do
      compute_grade(20,130)
    end
    assert_raise ArgumentError do
      compute_grade(20,-12)
    end
  end 

  def test_compute_output
    assert_equal 20, compute_grade(20,100)
    assert_equal 10, compute_grade(10,100)
    assert_equal 10, compute_grade(20,50)
    assert_equal 10, compute_grade(40,25)
  end
   
end
