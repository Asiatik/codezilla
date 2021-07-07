// --- Directions
// Print out the n-th entry in the fibonacci series.
// The fibonacci series is an ordering of numbers where
// each number is the sum of the preceeding two.
// For example, the sequence
//  [0, 1, 1, 2, 3, 5, 8, 13, 21, 34]
// forms the first ten entries of the fibonacci series.
// Example:
//   fib(4) === 3

// 1.  Recursive Solution
function fib2(n) {
    if (n < 2) {
        return n
    }
    return (fib(n - 1) + fib(n - 2))
}

// 2. Iterative Solution
function fib1(n) {
    let curr = 1, prev = 0
    for (i = 0; i < n; i++) {
        curr = curr + prev
        prev = curr - prev
    }
    return prev
}

// 3. Dynamic Programming Time 0.569 s
let store = new Map()
function fib3(n) {

    if (n < 2) {
        return n
    } else if (store.has(n)) {
        return store.get(n)
    } else {
        let res = fib(n - 1) + fib(n - 2)
        store.set(n, res)
        return res
    }

}

// ES 6  Time 0.274 s
function memoize(fn) {
    const cache = {}
    // I dont know how many arguments are there so I used ...args
    return function (...args) {
        if (cache[args]) {
            return cache[args]
        }
        //The apply() method calls a function with a given this value, and arguments provided as an array (or an array-like object).
        const res = fn.apply(this, args)
        cache[args] = res
        return res
    }
}

const fib = memoize(fib2)
module.exports = fib;


// fn.apply() example
// var numbers = [5, 6, 2, 3, 7];

// var max = Math.max.apply(null, numbers);

// console.log(max);
// // expected output: 7

// var min = Math.min.apply(null, numbers);

// console.log(min);