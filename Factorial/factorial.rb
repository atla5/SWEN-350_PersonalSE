# factorial(n) is defined as n*n-1*n-2..1 for n > 0
# factorial(n) is 1 for n=0
# Let's raise an exception if factorial is negative
# Let's raise an exception if factorial is anything but an integer

def factorial(n)
  # Write the factorial code here per the activity
  if n==0
    return 1
  elsif n == 1
    return 1
  else
    return n*factorial(n-1)
  end

end
