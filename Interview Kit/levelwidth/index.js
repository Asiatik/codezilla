// --- Directions
// Given the root node of a tree, return
// an array where each element is the width
// of the tree at each level.
// --- Example
// Given:
//     0
//   / |  \
// 1   2   3
// |       |
// 4       5
// Answer: [1, 3, 2]

function levelWidth(root) {
    const counters = [0]
    const queue = [root, 's']
    while (queue.length > 1) {
        let node = queue.shift()
        if (node === 's') {
            counters.push(0)
            queue.push('s')
        } else {
            queue.push(...node.children)
            counters[counters.length - 1]++
        }
    }
    return counters
}

module.exports = levelWidth;
