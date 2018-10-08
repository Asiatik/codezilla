# Knuth-Morris-Pratt (KMP) Algorithm
KMP is a linear time string matching algorithm. The naive approach to string matching involves
looping over all indicies over a text string and finding the indicies
where the pattern p matches the substring starting at the index.
s.t. pattern[1 ... m] = text[idx + 1 ... idx + m].

The worst case of this approach is O(m*(n-m+1)), where m is the |p| and
n is |text|.

The main drawback of the naive appraoch is that it handles almost matches
poorly. Since it will go deep into the second nested loop when checking
whether the substring and the pattern matches. For example if we have
pattern "asdqweX" and string "asdqweY" the we check almost the entire
pattern before realising that there are no matches.

The KMP algorithm solves this problem by relying on some clever preprocessing,
thereby reaching a linear time performance. The clever preprocessing is simply
creating an array that contains information calculated by a prefix function, and this information describes how the pattern matches against shifts of itself. We use this array to avoid the worst case situation of the naive approach.  

## Pseudocode
KMP-Matcher(t, p)
    n = |t|
    m = |p|

Compute-Prefix-Function(p)
    m = |p|


## Example