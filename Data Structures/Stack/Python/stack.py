'''
 * This class Implements Stack
 * @author asterisk30
 */
'''
from os import system
class Stack:
    def __init__(self):
        self.items = [] #creates a stack using lists in this program
 
    def is_empty(self):
        return self.items == [] #checks if stack is empty 
    def push(self, data):
        self.items.append(data) #pushes element to the "so called" top
 
    def pop(self):
        return self.items.pop() #pops element from the top
 
    def disp(self):
            print(self.items,end=" ")#displays the stack contents
 
#driver program` 
s = Stack()
while True:
    #system('clear') 
    if s.is_empty():
        print("EMPTY : ",end = " ")
    s.disp()
    print('\npush <value>')
    print('pop')
    print('quit')
    do = input('What would you like to do? ').split()
 
    operation = do[0].strip().lower()
    if operation == 'push':
        s.push((do[1]))
    elif operation == 'pop':
        if s.is_empty():
            print('Stack is empty.')
        else:
            print('Popped value: ', s.pop())
    elif operation == 'quit':
        break