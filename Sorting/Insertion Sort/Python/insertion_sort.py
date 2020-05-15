def insertion_sort(arr):
	'''
		Args: Input list
		Returns: Sorted list
	'''
	for i in range(1, len(arr)):
		key = arr[i]
		j = i-1
		# finding element greater than current value
		while(j>=0 and arr[j]>key):
			arr[j+1] = arr[j]
			j -= 1
		arr[j+1] = key

	return arr

# Driver Program
if __name__ == '__main__':
	arr = [5,3,9,6,1,8]
	arr = insertion_sort(arr)
	print(arr)