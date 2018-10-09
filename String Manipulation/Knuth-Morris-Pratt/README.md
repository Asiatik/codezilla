# Knuth-Morris-Pratt (KMP) Algorithm
KMP is a linear time string matching algorithm. The problem involves finding
all occurences where a string pattern matches a substring in a text.
The naive approach to string matching involves
looping over all indicies over a text string and finding the indicies
where the pattern p matches the substring starting at the index.

s.t. pattern[0 ... m - 1] = text[idx ... idx + m - 1], where idx is some offset.

The worst case of this approach is O(m*(n-m+1)), where m is |p| and n is |text|.

The main drawback of the naive appraoch is that it handles overlaps
poorly. Since it will go deep into the second nested loop when checking
whether the substring and the pattern matches. When it hits a mismatch
it will start over from the next increment, thereby redoing some of its
comparisons.

The KMP algorithm solves this problem by relying on some clever preprocessing,
thereby reaching a linear time performance. The clever preprocessing is simply
creating an array that contains information calculated by a prefix function, and this information describes how the pattern matches against shifts of itself. 
We use this array to avoid the worst case situation of the naive approach by reusing previously performed comparisons.

The prefix-function(i) is the longest prefix of p that is also a suffix of p[1 ... i]. The whole idea of finding these substrings in the
pattern which are both prefixes and suffixes, is that they determine from what index in the pattern and text we should start from next, hence
avoiding having to start all the way at the start index of the pattern and only one index further in the text each time we hit a
character miss match.

KMP runs in O(n + m). Note, KMP is only necessary when there are many overlapping parts, since it is only in such
situations where the prefix-suffix array helps. However, the worst case linear time efficiency is guaranteed, meaning
the KMP algorithm is useful in general cases aswell. 

## Pseudocode
Where t is the text string and p is the pattern.

    KMP-Matcher(t, p):
        n = len(t)
        m = len(p)
        prefix-arr = Compute-Prefix-Function(p)
        q = 0
        for i = 0 to n:
            while q > 0 and p[q] != t[i]:
                q = prefix-arr[q]
            if p[q] == t[i]:
                q++
            if q == m:
                patterns occurs at index i - m
                q = prefix-arr[q]

    Compute-Prefix-Function(p)
        m = len(p)
        new arr[0 ... m-1]
        arr[0] = 0
        k = 0
        for i = 1 to m:
            while k > 0 and  p[k] != p[i]:
                k = arr[k]
            if p[k] == p[i]:
                k++
            arr[i] = k
        
        return arr

CLRS[p. 1006].



