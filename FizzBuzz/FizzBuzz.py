# Aidan Sawyer
# Personal SE
# python

def main():
	
	#set starting value of integer to 1
	i = 1
	
	#loop through all numbers between 1-100
	while(i<=100):       
		if(i%5 == 0):   
			if(i%7 == 0): 
				#if number is divisible by 5 and 7
				print("FizzBuzz")
			else:
				#if number is divisible by only 5
				print("Fizz")
		else:
			if(i%7 == 0):
				#if number is divisible by only 7
				print("Buzz")
			else:
				#if number is not divisible by either
				print(i) #print the number itself
		
		#increment i.
		i+=1

main()	
