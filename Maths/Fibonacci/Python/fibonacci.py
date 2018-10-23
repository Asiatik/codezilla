"""
    A function to calculate fibonacci of x.
    Starting value of fib(0) = 0
    {0, 1, 1, 2, 3, 5, 8, 13, ...}
"""

def fibonacci(x):
    if (x <= 0):
        return 0
    elif (x == 1):
        return 1

    a = 0
    b = 1
    c = 1

    for i in range(2, x):
        a = b
        b = c
        c = a + b
    return c

if __name__ == "__main__":
    assert(fibonacci(-1) == 0)
    assert(fibonacci(0) == 0)
    assert(fibonacci(1) == 1)
    assert(fibonacci(2) == 1)
    assert(fibonacci(3) == 2)
    assert(fibonacci(4) == 3)
    assert(fibonacci(5) == 5)
    assert(fibonacci(46) == 1836311903)
    assert(fibonacci(47) == 2971215073)
    assert(fibonacci(300) == 222232244629420445529739893461909967206666939096499764990979600)
