/**
 * The 3 general approaches to a very basic dynamic programming problem - the fibonacci sequence
 */
public class Fibonacci {

    /**
     * The very basic fibonacci sequence.
     * Notice the run time is O(n^2) as it has to recalculate the same value numerous times.
     * This is something we try to avoid.
     *
     * E.G) To get fib(4):
     *                   fib(5)
     *                  /     \
     *            fib(3)       fib(4)
     *           /     \      /     \
     *     fib(2)   fib(1)  fib(2)  fib(3)
     *                             /     \
     *                       fib(2)       fib(1)
     *
     * @param n The nth fibonacci number
     * @return The value of the nth fibonacci number
     */
    public int naiveFibonacci(int n) {
        assert n > 0;

        if(n == 1 || n == 2)
            return 1;

        return naiveFibonacci(n-1) + naiveFibonacci(n-2);
    }

    private Map<Integer, Integer> memo = new HashMap<>();

    /**
     * Very similar to above but notice the reference to a map.
     * This is a memo and keeps track of values we have already crossed.
     * Since retrieval from a map is O(1) it improves the runtime of the program by not having to recalculate
     * same values over and over.
     *
     * @param n The nth fibonacci number
     * @return The value of the nth fibonacci number
     */
    public int memoizedFibonacci(int n) {
        assert n > 0;

        if(n == 1 || n == 2)
            return 1;

        //If we already calculated the value before.
        if(memo.containsKey(n))
            return memo.get(n);

        //If not, add it to the memo in case we need to retrieve it again
        int fib = naiveFibonacci(n-1) + naiveFibonacci(n-2);
        memo.put(n, fib);

        return fib;
    }

    /**
     * Now this is very different to the other two. No recursion, just a primitive array.
     * How this works is based of how you look at fibonacci normally:
     * 1,1,2,3,5,... The next number is the sum of the previous two - as can be seen in the for loop.
     * The first two indexes represent the first and second value (hence why the if just returns 1 if you input a value
     * less than 3).
     * The runtime complexity is also easier as it become O(n) since we only pass the loop once and O(n) space as
     * the array increases proportionally to the increase in input value n.
     *
     * @param n The nth fibonacci number
     * @return The value of the nth fibonacci number
     */
    public int tabulatedFibonacci(int n) {
        assert n > 0;

        if(n < 3)
            return 1;

        int[] tab = new int[n];
        tab[0] = 1; tab[1] = 1;

        for(int i=2; i<n; i++) {
            tab[i] = tab[i-1] + tab[i-2];
        }

        return tab[n-1];
    }
}