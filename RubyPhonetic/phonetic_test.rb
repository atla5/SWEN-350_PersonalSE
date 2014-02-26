require_relative 'phonetic'
require 'test/unit'

class PhoneticTest < Test::Unit::TestCase

 ## - TEST PHONETIC.TRANSLATE - ##

  #test inputs
  def test_translate_bad_inputs
    
    #non-string input raises error
    assert_raise ArgumentError do
      Phonetic.translate(123)
    end 

    #check that empty string is returned
    assert_equal Phonetic.translate(""), ""

    #check that it is case insensitive
    allCapsOut = Phonetic.translate("A2P A")
    noCapsOut  = Phonetic.translate("a2p a")
    assert_equal allCapsOut, noCapsOut

    #check that it can handle numbers
    withDigitsOut = "ALPHA 12 ALPHA"
    assert_equal Phonetic.translate("A2P a12a"), withDigitsOut

  end

  #test that translate correctly filters with tag
  def test_translate_tags
    
    #test that no tag returns nil
    assert_equal Phonetic.translate("RIT"), nil

    #test that correctly handles A2P tag
    a2Pout = Phonetic.to_phonetic("RIT")
    assert_equal Phonetic.translate("A2P RIT"), a2Pout

    #test that correctly handles P2A tag
    p2Aout = Phonetic.from_phonetic("ALPHA")
    assert_equal Phonetic.translate("P2A ALPHA"), p2Aout

  end

 ## - TEST P2A functionality - ##
 
  #test with good input
  def test_rit_to_phonetic
    assert_equal 'ALPHA BRAVO CHARLIE', Phonetic.to_phonetic("ABC")
    assert_equal 'ROMEO INDIA TANGO', Phonetic.to_phonetic('RIT')
  end

  #ensure case insensitive
  def test_P2A_case
    assert_equal Phonetic.to_phonetic("RIT"), Phonetic.to_phonetic("rit")
  end

end
