import math

# testing
arr = [0, 1, 2, 3, 4, 6, 6, 7, 10, 66, 75, 345, 357, 456, 677, 777, 999]
x = 75
n = len(arr)

i = jumpSearch(arr, x, n)
print("Number ", x, " is at index ", "%.0f"%i)

# function
def jumpSearch (arr, x, n):
  # define block size to jump
  s = math.sqrt(n)
  p = 0
  
  # finding the element
  while arr[int(min(s, n)-1)] < x:
    p = s
    s += math.sqrt(n)
    if p > n:
      return -1
    
  # do a linear search for x in block
  while arr[int(p)] < x:
    p += 1
    if p == min(s, n):
      return -1

  if arr[int(p)] == x:
    return p

  return -1