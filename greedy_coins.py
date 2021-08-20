# Flavjo Xhelollari
# Greedy Coins Implementation


# Method which returns the minimal number of coins 
# needed to get the amount that we specify
# a-> the amount
# d-> denom: An array which contains the values of the 
# available coins ex. 1 cent, 5 cents etc...
# q is an array which will hold the number of times 
# an element from denom is used
def make_amount(a, d, q):
	total_coins = 0
	index = len(d) - 1
	while(a > 0):
		while(a >= d[index]):
			q[index] = q[index] + 1
			a = a - d[index]
			total_coins += 1
		index -= 1
	return total_coins

