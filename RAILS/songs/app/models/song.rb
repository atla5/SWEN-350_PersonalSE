class Song < ActiveRecord::Base


  #validations for year field
  
	#ensure the year field is not empty
	validates :year, :presence => true
	
	#ensure the year field is a number
	validates :year, :numericality => true
	
	#ensure year is less than or equal to the current year and greater than 0
	#validates :year, :numericality { 
	#	:greater_than => 0, 
	#	:less_than_or_equal_to => Date.today.year 
	#	}
	
	#establish multiplicity/cardinality (one to many author->song)
	belongs_to :author
end
