class Thought < ActiveRecord::Base

  ## - validations - ##

  #set character limits to 5 <= numChar <= 154
  validates :thought, length: { minimum: 5, maximum: 154 , \
	message: "thought must be between 5 and 154 characters long"}

  #ensure no duplicate thoughts
  validates :thought, uniqueness: {true \
	message: "thoughts must be unique"}

  #set multiplicities  
  belongs_to :thinker #many-to-one thinker->thought.
  has_many :thumbs    #many-to-one thought->thumbs.
  
end
