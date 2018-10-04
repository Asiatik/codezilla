

class Stack:

	def __init__(self, size = 1000000):
		self.stack = []
		self.stack_size = size

	# Add element to stack
	def push(self, element):
		# Checking stack is full or not
		if len(self.stack) <= self.stack_size:
			self.stack.append(element)
		else:
			print('Stack Full. Overflow')

	# Delete element from stack
	def pop(self):
		if len(self.stack) == 0:
			print('Empty Stack. Underflow')
		else:
			self.stack.pop()

	# Returns top element of stack
	def top(self):
		return self.stack[-1]


# Driver Program
if __name__ == '__main__':
	stack = Stack()
	stack.pop()
	stack.push(1)
	stack.push(2)
	stack.push(3)
	print(stack.top())
	stack.pop()
	print(stack.top())
