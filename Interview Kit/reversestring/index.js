// --- Directions
// Given a string, return a new string with the reversed
// order of characters
// --- Examples
//   reverse('apple') === 'leppa'
//   reverse('hello') === 'olleh'
//   reverse('Greetings!') === '!sgniteerG'

function reverse (str) {
	return str.split("").reverse().join("");
}
function reverse2 (str) {
	return str === '' ? '' : reverse2(str.substr(1)) + str.charAt(0)
}
function reverse3 (str) {
	let res = ''
	// for (i = 0; i < str.length; i++) {
	// 	res = str.charAt(i) + res
	// }
	for (let char of str) {
		res = char + res
	}
	return res
}
module.exports = {
	reverse,
	reverse2,
	reverse3
};
