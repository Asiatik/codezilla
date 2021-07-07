// --- Directions
// Given a string, return the character that is most
// commonly used in the string.
// --- Examples
// maxChar("abcccccccd") === "c"
// maxChar("apple 1231111") === "1"

function maxChar(str) {
    let map = {}
    let max = 0, maxCh = ''
    for (let char of str) {
        map[char] = map[char] + 1 || 1;
    }
    for (let char in map) {
        if(map[char] > max) {
            max = map[char]
            maxCh = char
        }
    }
    return maxCh

}
function maxChar3(str) {
    let arr = new Array(256)
    arr.fill(0)
    for(let char of str) {
        arr[char.charCodeAt(0)]++
    }
    let char = '', max = 0
    for (let x of arr) {
        max = max > x ? max : x
    }
    return String.fromCharCode(arr.indexOf(max))
}

function maxChar2(str) {
    let map = new Map()
    for (let char of str) {
        map.set(char, map.get(char) + 1 || 1)
    }
    let max = 0, char = ''
    map.forEach((x, y) => {
        max = max > x ? max : x
        char = max === x ? y : char
    })
    return char
}

module.exports = maxChar;
