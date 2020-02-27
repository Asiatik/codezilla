def merge(arr,left,mid,right):
    n1 = (mid-left)  + 1
    n2 = right-mid

    Left_arr = [0]*(n1)
    Right_arr = [0]*(n2)

    for i in range(0,n1):
        Left_arr[i] = arr[left + i]

    for j in range(0, n2):
        Right_arr[j] = arr[mid + 1 +j]

    i = 0
    j = 0
    k = left

    while(i < n1 and j < n2):
        if(Left_arr[i]<=Right_arr[j]):
            arr[k] = Left_arr[i]
            i = i+1
        else:
            arr[k] = Right_arr[j]
            j = j+1
        k = k+1

    while(i<n1):
        arr[k] = Left_arr[i]
        i = i+1
        k = k+1

    while(j<n2):
        arr[k] = Right_arr[j]
        j = j+1
        k = k+1

def mergeSort(arr,left,right):
    if(left<right):
        mid = int((left+(right-1))/2)

        mergeSort(arr,left,mid)
        mergeSort(arr,mid+1,right)
        merge(arr,left,mid,right)


arr = []
size = int(input("Enter the size"))

for i in range(0,size):
    a = int(input())
    arr.append(a)

n = len(arr)
print("List before sorting")
print(arr)

mergeSort(arr,0,n-1)
print("sorted list ")
print(arr)
