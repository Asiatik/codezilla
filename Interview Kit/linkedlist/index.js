// --- Directions
// Implement classes Node and Linked Lists
// See 'directions' document
//  const nodeOne = {
//     data: 123
// }
// const nodeTwo = {
//     data: 456
// }
// // Link The Two Nodes
// nodeOne.next = nodeTwo

class Node {
  constructor(data, next) {
    this.data = data
    this.next = next
  }
}

// LinkedList class only knows about the first node 
class LinkedList {
  constructor() {
    this.head = null
  }

  insertFirst(data) {
    this.head = new Node(data, this.head)
  }
  size() {
    let count = 0
    let node = this.head
    while (node) {
      count++
      node = node.next
    }
    return count
  }
  getFirst() {
    return this.head
  }
  getLast() {
    if (!this.head) {
      return null
    }
    let node = this.head
    while (node.next) {
      node = node.next
    }
    return node
  }
  clear() {
    this.head = null
  }
  removeFirst() {
    if (!this.head) {
      return
    }
    this.head = this.head.next
  }
  removeLast() {
    if (!this.head) {
      return
    }
    if (!this.head.next) {
      this.head = null
      return
    }
    let prev = this.head
    let node = this.head.next
    while (node.next) {
      prev = node
      node = node.next
    }
    prev.next = null
  }
  insertLast(data) {
    const last = this.getLast()
    if (last) {
      last.next = new Node(data)
    } else {
      this.head = new Node(data)
    }
  }
  getAt(index) {
    if (!this.head) {
      return null
    }
    let count = 0
    let node = this.head
    while (node) {
      if (index === count) {
        return node
      }
      node = node.next
      count++
    }
    return null
  }
  removeAt(index) {
    if (index >= this.size()) {
      return null
    }
    if (index === 0) {
      this.removeFirst()
    } else if (index === this.size() - 1) {
      this.removeLast()
    } else {
      this.getAt(index - 1).next = this.getAt(index + 1)
    }
  }
  insertAt(data, index) {
    let node
    if (index === 0) {
      node = new Node(data)
      if (this.head !== null) {
        node.next = this.head
      }
      this.head = node
    } else if (index >= this.size()) {
      this.insertLast(data)
    } else {
      node = new Node(data, this.getAt(index))
      this.getAt(index - 1).next = node
    }
  }
  forEach(fn) {
    if (!this.head) {
      return null;
    }

    let node = this.head
    for (let i = 0; i < this.size(); i++) {
      fn(node)
      node = node.next
    }
  }
  // *******************************************************************
  *[Symbol.iterator]() {
    let node = this.head
    while (node) {
      yield node
      node = node.next
    }
  }
  // *******************************************************************
}

module.exports = {
  Node,
  LinkedList
};
