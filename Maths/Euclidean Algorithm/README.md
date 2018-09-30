# Euclidean Algorithm

[Wikipedia Entry](https://en.wikipedia.org/wiki/Euclidean_algorithm)

This is one of the fastest method for finding the greatest common divisior between two numbers.


## Pseudocode

    function gcd(a, b)
        while b ≠ 0
           t := b; 
           b := a mod b; 
           a := t; 
        return a;
