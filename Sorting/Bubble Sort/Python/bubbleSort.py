def bubbleSort(arr): 
    lengthArr = len(arr)  
    for i in range(lengthArr): 
        for j in range(0, lengthArr-i-1): 
            if(arr[j] > arr[j+1]): 
                arr[j], arr[j+1] = arr[j+1], arr[j] 
  
