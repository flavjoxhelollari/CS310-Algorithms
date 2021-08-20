# Flavjo Xhelollari
# Implementation of the shellsort algorithm

def shellsort(array):
	
	n = len(array)
	gaps = [5,3,1]
	
	for gap in gaps:
		for i in range(gap, n ):
			temp = array[i]
			j = i;
			while (j >= gap and temp < array[j - gap]) :
				array[j] = array[j - gap]
				j -= gap
			array[j] = temp
			
def main():
	array = [1,5,2,5,3,1,9,129,92134,1293]
	shellsort(array)
	for x in array:
		print(x)
	print
main()	
