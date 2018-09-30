# Linear Search

>Worst Case Time Complexity: O(n)

>Space Complexity: O(1)

[Wikipedia Entry](https://en.wikipedia.org/wiki/Linear_search)

## Pseudocode

A is the array, n is the size of array and T is the item


    function linear_search(A, n, T):
        i=0
        while i < n:
            if A[i] == T:
                return i
            i=i+1
        return unsuccessful

Notice that even if the array list contains multiple items, it will return only one index.
Thus this algorithm is well suited to find if a item is present. 
And not for finding the exact index if multiple items are present.

This algorithm is rarely used since there are always better options like binary search or hash tables.
