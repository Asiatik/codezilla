## Fibonacci

More on the history and explanation [here](https://en.wikipedia.org/wiki/Fibonacci_number).
In short, the fibonacci sequence is a list of ascending numbers in such a way that the
number at index n is the sum of n-1 and n-2.

### Example
the number at the _sixth_ index is __8__.<br>
This is because it is the sum of the 5th and 4th elements which are __5__ and __3__.
The full sequence leading up to it is:
```
1,1,2,3,5,8
```

A reminder that this is an infinite sequence therefore there is no end, but in programming
terms, end will be reached when it reaches max value (which in Java is 2^31 since int is 32 bit).

One question that may also be asked (along with the examples provided) is to get n-step fibonacci.
This refers to n numbers added to create the next digit.

### Example
3 step fibonacci (also called tribonacci) will look as follows:
```
1,1,2,4,7,13,24
```
As it is adding the 3 previous values before it. Note the _1,1,2_ as the third index only has two numbers
to use, it will only be able to add them.

