require_relative 'currency' 
require 'test/unit'          

class CurrencyTest < Test::Unit::TestCase 

  # assert_in_delta() is used to compare two floating point
  # values within a tolerance, or delta, to account for potential
  # rounding errors when performing floating point computations.
  
  def test_convert

    #check for invalid currency code
    assert_raise ArgumentError do
      convert( 'ZZZ',2.0)
    end

    #check for invalid value
    assert_raise ArgumentError do
      convert('CAN', "two")
    end

    #test normal input
    assert_in_delta 58.59, convert( 'GBP', 35.0 ), 0.01
	assert_in_delta 1.722, convert( 'CAN', 2.0 ), 0.01
  
  end

  def test_parse_line
    ls = ["op","type1",12.0,"type2",15.0]
    assert_equal ls, parse_line("op,type1,12,type2,15\n")
    assert_equal ls, parse_line("op,type1,12,type2,15")
  end

  def test_compute
    
   ##check incorrect arguments
    
    #operator not +/-
    assert_raise ArgumentError do
      compute("4",2.0,2.0)
    end

    #val1 not a float
    assert_raise ArgumentError do
      compute("+","two",2.0)
    end

    #val2 not a float
    assert_raise ArgumentError do
      compute("+",2.0,"two")
    end

   ##check valid input
    
    #2.0+2.0=4
    assert_equal 4.0, compute("+",2.0,2.0)
    
    #4.0-2.0=2.0
    assert_equal 2.0, compute("-",4.0,2.0)

  end 
 
end
