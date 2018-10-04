
'''
 * This class Implements Stack
 * @author asterisk30
 */
'''
class Stack:
    def __init__(self):
        self.items = [] 
 
    def is_empty(self):
        return self.items == [] 
    def push(self, data):
        self.items.append(data) 
 
    def pop(self):
        return self.items.pop() 
 
    def disp(self):
            print(self.items,end=" ")
 
#driver program
if __name__=='__main__':
    s = Stack()
    while True:
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




