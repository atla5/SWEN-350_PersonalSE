require_relative 'phonetic'
require 'test/unit'

class PhoneticTest < Test::Unit::TestCase

  #test with incorrect input
  def test_bad_inputs
    
    #non-string input
    assert_raise ArgumentError do
      Phonetic.translate(123)
    end 

    #string input without A2P
    assert_raise ArgumentError do
      Phonetic.translate('RIT')
    end
  end

  #test P2A 
  def test_rit_to_phonetic
    assert_equal 'ROMEO INDIA TANGO', Phonetic.to_phonetic('RIT')
  end

  def test_line_rit_to_phonetic
    assert_equal 'ROMEO INDIA TANGO', Phonetic.translate('A2P RIT')
  end

  #Remove this line and place more tests here

end
