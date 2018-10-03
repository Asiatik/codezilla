def selectionSort(arr):
    l = len(arr) #find the length of the array
    
    for i in range(l): #traverse linearly through the array
        smallest = i #assume smallest is in ith position
        for j in range(i+1, l): #Need to search just from the next element to the smallest 
            if arr[j] < arr[smallest]: #if jth element is less than current smallest, update smallest
                smallest = j
        #Now we have the smallest after the ith iteration. swap it with ith element
        temp = arr[i]
        arr[i] = arr[smallest]
        arr[smallest] = temp

arr = [24, 123, 14, 10, 29]

selectionSort(arr)

print "The sorted array is:", arr
