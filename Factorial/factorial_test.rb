require_relative 'factorial' #We need to access our code to test
require 'test/unit'          #We need Ruby's unit testing library

class FactorialTest < Test::Unit::TestCase #This is a class. (It's ok if you don't know what those are yet)

  #Test methods MUST start with test_
  def test_normal
    assert_equal 24, factorial(4),"4! should be 24"
  end

  # Add many other test methods here
  
  #Test another known factorial
  def test_another_normal
    assert_equal 120, factorial(5),"5! should be 120"
  end

  #Test that factorial(0) returns 1
  def test_zero
    assert_equal 1, factorial(0), "0! should be 1"
  end

  #Test that negative values don't compute
  def test_negative
    assert_raise ArgumentError factorial(-1),"negative int input should raise error"
  end

  #Test that non-integer input raises error
  def test_string
    assert_raise ArgumentError factorial("helloWorld"),"non-int input should raise error"
  end


end
