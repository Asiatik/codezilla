# Knuth-Morris-Pratt (KMP) Algorithm
KMP is a linear time string matching algorithm. The naive approach to string matching involves
looping over all indicies over a text string and finding the indicies
where the pattern p matches the substring starting at the index.
s.t. pattern[0 ... m-1] = text[idx ... idx + m - 1].

The worst case of this approach is O(m*(n-m+1)), where m is the |p| and
n is |text|.

The main drawback of the naive appraoch is that it handles almost matches
poorly. Since it will go deep into the second nested loop when checking
whether the substring and the pattern matches. For example if we have
pattern "asdqweX" and string "asdqweY" we then check almost the entire
pattern before realising that there are no matches.

The KMP algorithm solves this problem by relying on some clever preprocessing,
thereby reaching a linear time performance. The clever preprocessing is simply
creating an array that contains information calculated by a prefix function, and this information describes how the pattern matches against shifts of itself. 
We use this array to avoid the worst case situation of the naive approach.

## Pseudocode
t is the text string and p is the pattern.

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
            if p[k + 1] == p[i]:
                k++
            arr[i] = k
        
        return arr


## Example
text = "Hello world!";
pattern = "world";

