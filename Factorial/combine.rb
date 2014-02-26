require_relative 'factorial'

if ARGV.length != 2
  puts "invalid number of arguments"
end

n = ARGV[0].to_i()
r = ARGV[1].to_i()

num = factorial(n).to_i() * factorial(0) 
denom = factorial(r).to_i() * factorial(n-r).to_i()
ans = num/denom

#printf("num = %d \n",num)
#printf("denom = %d \n",denom)

puts( ans )
