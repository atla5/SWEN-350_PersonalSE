
def factorial(n)
  raise ArgumentError, "Non-negative numbers only!" unless n.is_a? Numeric and n>=0
  total = 1
  for i in 2..n
    total = total * i
  end
  return total
end
