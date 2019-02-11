def larget_prime(number):
	larget_prime = 0
	counter = 2
	while counter * counter <= number:
		if number % counter == 0:
			number = number / counter
			larget_prime = counter
		else:
			counter += 1
	if number > larget_prime:
		larget_prime = number
	print ("{:.0f}".format(larget_prime))

T = int(input())
for i in range(T):
	N = int(input())
	larget_prime(N)
