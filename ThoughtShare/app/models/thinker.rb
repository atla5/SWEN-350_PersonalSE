class Thinker < ActiveRecord::Base

  ## - validations - ##
  
  # - NAME - #
  #ensure 1<=len(name)<=35
  validates :name, length: {minimum:1, maximum:35}
  
  #ensure no other thinker has that name already
  validates :name, uniqueness: true
  
  #ensure formatting of name
  validates :name, :format => { :with => /^[a-zA-Z][a-zA-Z0-9 \-']+$/, \
	message: "contains invalid character"}
  validates :name, :format=> { :with => /^\A[a-zA-Z]/, \
	message: "name must start with a letter"}
  
  # - URL - #
  #ensure the url is unique
  validates :url, uniqueness: true
  
  #ensure len(url)<=120
  validates :url, length: {maximum:120}
  
  #check URL format
  validates :url, :format => { :with=> URI::regexp(%w(http https)) }

  ## - set foreign keys - ##
  has_many :follows, :foreign_key => "follower_id", :class_name => "Follow"
  has_many :followed, :foreign_key => "followee_id", :class_name => "Follow"
  
  ## - set multiplicities - ##
  has_many :thoughts
  has_many :thumbs
  
  # - EMAIL - #
  validates :email, :format => { :with=> /\A[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\.[A-Za-z]+\z/ }

  
end
