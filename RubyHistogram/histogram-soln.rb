# Require Ruby's "Pretty Print"
#   (for printf)
require 'pp'

# Default cutoff is 2, but we'll take ARGV if it's non-nil
cutoff = 2
cutoff = ARGV[0].to_i if ARGV[0]

# Create an empty hash
bag = Hash.new(0)

#Iterate over stdin
$stdin.each do |line|
  line.chomp!    # Remove newlines (! means modifying line)
  line.downcase! # Lowercase
  line.gsub!(/[^a-zA-Z ]/,"") # Remove non-letters and non-spaces
  line.sub!(/^ +/,"")         # Remove consecutive spaces
  # Increment the frequency over the line's split tokens
  line.split(/ +/).each do | word | 
    bag[word] += 1
  end 
end

# Sort, using a given custom sorting comparator
pairs = bag.sort do | pair1, pair2 | 
  if pair1[1] == pair2[1]
    pair1[0] <=> pair2[0]
  else
    pair2[1] <=> pair1[1]
  end
end

# Cull using the cutoff
pairs = pairs.select { | v | v[1] >= cutoff }

# Find the maximum
#   (return value of the block goes back into l)
longest = pairs.inject(0) do | l, v |
  v[0].length > l ? v[0].length : l 
end

# Print it out
pairs.each do | apair |
  printf "%-*.*s ", longest, longest, apair[0]
  puts "*" * apair[1]
end
