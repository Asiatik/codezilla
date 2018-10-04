arr = list()

abc = int(input("Enter the number of terms"))

for i in range(abc):
    b = int(input())
    arr.append(b)


size = len(arr)
for i in range(size):
    for j in range(0,n-i-1):
        if a[j]>a[j+1]:
            a[j],a[j+1] = a[j+1],a[j]


print(arr)
