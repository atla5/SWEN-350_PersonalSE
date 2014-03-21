class Thought < ActiveRecord::Base

  ## - validations - ##

  #set character limits to 5 <= numChar <= 154
  validates :thought, length: { minimum: 5, maximum: 154 }

  #ensure no duplicate thoughts
  validates :thought, uniqueness: true

  #set multiplicities  
  belongs_to :thinker #many-to-one thinker->thought.
  has_many :thumbs    #many-to-one thought->thumbs.
  
end
