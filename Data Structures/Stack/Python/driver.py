from Stack import Stack

# driver program
s = Stack()
s.push(2.2)
s.push(3.3)
s.push(4.4)
s.push(5.5)
s.push(6.6)

while s.is_empty() is False:
    print(s.pop())

