a = []

abc = int(input("Enter the number of terms"))

for i in range(abc):
    b = int(input())
    a.append(b)


n = len(a)
for i in range(n):
    for j in range(0,n-i-1):
        if(a[j]>a[j+1]):
            a[j],a[j+1] = a[j+1],a[j]


print(a)
