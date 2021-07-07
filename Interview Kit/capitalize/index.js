// --- Directions
// Write a function that accepts a string.  The function should
// capitalize the first letter of each word in the string then
// return the capitalized string.
// --- Examples
//   capitalize('a short sentence') --> 'A Short Sentence'
//   capitalize('a lazy fox') --> 'A Lazy Fox'
//   capitalize('look, it is working!') --> 'Look, It Is Working!'

function capitalize(str) {
    let arr = str.split(' ')
    let words  = []
    for(let s of arr) {
        words.push(s[0].toUpperCase() + s.slice(1))
    }
    return words.join(' ')
}

module.exports = capitalize;
