// --- Directions
// Write a function that accepts a positive number N.
// The function should console log a step shape
// with N levels using the # character.  Make sure the
// step has spaces on the right hand side!
// --- Examples
//   steps(2)
//       '# '
//       '##'
//   steps(3)
//       '#  '
//       '## '
//       '###'
//   steps(4)
//       '#   '
//       '##  '
//       '### '
//       '####'

function steps(n) {
	for (i = 1; i <= n; i++) {
		let step = ''
		for (j = 1; j <= n; j++) {
			if (j <= i) {
				step += '#'
			} else {
				step += " "
			}
		}
		console.log(step)
	}
}
function steps2(n, row = 0, stair = '') {
	if (n === row) {
		return
	}

	if (n === stair.length) {
		console.log(stair)
		return steps2(n, row + 1)
	}
	if (stair.length <= row) {
		stair += '#'
	} else {
		stair += ' '
	}
	steps2(n, row, stair)
}

module.exports = steps;
