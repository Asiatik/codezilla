num = int(input("Please enter size of array :"))
arr_str = list(input().split(" "))
if len(arr_str)!=num:
	print("Please enter only "+str(num)+" elements.")
	exit()
arr = list(map(int, arr_str))

def heapify(arr, n, i):
	largest = i
	left = 2*i + 1
	right = 2*i + 2

	if left < n and arr[left] > arr[i]:
		largest = left

	if right < n and arr[right] > arr[largest]:
		largest = right

	if largest != i:
		arr[i] = arr[largest] + arr[i]
		arr[largest] = arr[i] - arr[largest]
		arr[i] = arr[i] - arr[largest]
		heapify(arr, n, largest)

def heap_sort(arr):

	n = len(arr)
	for i in range(n//2, -1, -1):
		# creating max heap
		heapify(arr, n, i)

	for i in range(n-1, 0, -1):
		# swapping largest num with last one
		arr[0], arr[i] = arr[i], arr[0]
		# again creating max heap
		heapify(arr, i, 0)

heap_sort(arr)
print(arr)