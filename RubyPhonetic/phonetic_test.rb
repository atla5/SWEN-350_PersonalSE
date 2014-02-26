require_relative 'phonetic'
require 'test/unit'

class PhoneticTest < Test::Unit::TestCase

  def test_rit_to_phonetic
    assert_equal 'ROMEO INDIA TANGO', Phonetic.to_phonetic('RIT')
  end

  def test_line_rit_to_phonetic
    assert_equal 'ROMEO INDIA TANGO', Phonetic.translate('A2P RIT')
  end

  #Remove this line and place more tests here

end
