def bubble_sort(arr):
    size = len(arr)
    for i in range(size):
        for j in range(0,size-i-1):
            if arr[j]>arr[j+1]:
                arr[j],arr[j+1] = arr[j+1],arr[j]


test_arr = [ 12, 11, 13, 5, 6, 7]
print("List before sorting")
print(test_arr)
bubble_sort(test_arr)
print("List After Sorting")
print(test_arr)

#Bubble Sorting by Prakhar Varshney
