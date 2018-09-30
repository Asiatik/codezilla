# Binary Search

>Worst Case Time Complexity: O(log n)

>Space Complexity: (O(1))

[Wikipedia Entry](https://en.wikipedia.org/wiki/Binary_search_algorithm)

## Pseudocode

A is the array, n is the size of array and T is the item


    function binary_search(A, n, T):
        L := 0
        R := n − 1

        while L <= R:
            m := floor((L + R) / 2)
            if A[m] < T:
                L := m + 1
            else if A[m] > T:
                R := m - 1
            else:
                return m
        return unsuccessful

Notice that even if the array list contains multiple items, it will return only one index.
Thus this algorithm is well suited to find if a item is present. 
And not for finding the exact index if multiple items are present.

Binary search can also be obtain the indexes of the items present. 
And unlike the version here which works on numbers, binary search can work on any sorted array. For example binary search can be used in lexiographically arranged strings.
