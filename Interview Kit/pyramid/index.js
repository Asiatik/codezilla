// --- Directions
// Write a function that accepts a positive number N.
// The function should console log a pyramid shape
// with N levels using the # character.  Make sure the
// pyramid has spaces on both the left *and* right hand sides
// --- Examples
//   pyramid(1)
//       '#'
//   pyramid(2)
//       ' # '
//       '###'
//   pyramid(3)
//       '  #  '
//       ' ### '
//       '#####'

function pyramid2(n) {
    for (i = 1, k = 1; i <= n; i++ , k += 2) {
        let steps = ''
        for (j = 0; j < n - i; j++) {
            steps += ' '
        }
        for (j = 0; j < k; j++) {
            steps += '#'
        }
        for (j = 0; j < n - i; j++) {
            steps += ' '
        }
        console.log(steps)
    }
}

function pyramid(n, row = 0, str = '') {
    if (row === n) {
        return
    }

    if (str.length === 2 * n - 1 ) {
        console.log(str)
        return pyramid(n, row + 1)
    }
    const midpoint = Math.floor((2*n -1)/2)
    let add
    if( midpoint - row <= str.length && midpoint + row >= str.length){
        add = '#'
    } else {
        add = ' '
    }
    pyramid(n, row, str + add)
}


module.exports = pyramid;
