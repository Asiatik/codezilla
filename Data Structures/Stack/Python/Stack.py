#
# @author rational kunal
#
class Stack():

    # node for stack
    class Node():

        # constructor for node
        def __init__(self, data):
            # data to store in node
            self.data = data
            # next node refrence
            self.next = None


    # constructor for stack
    def __init__(self):
        # initialize head node to null
        self.head_node = None
        # initialize stack size to 0
        self.stack_size = 0

    # create new node with data and return it
    def create_new_node(self, data):
        new_node = self.Node(data=data)
        return new_node

    # returns size of stack
    def size_of_stack(self):
        return stack_size
    
    # to push data to stack
    def push(self, data):
        new_node = self.create_new_node(data=data)
        new_node.next = self.head_node
        self.head_node = new_node
        self.stack_size += 1
    
    # removes top and returns it
    # else returns null
    def pop(self):
        if self.head_node is not None:
            data = self.head_node.data
            self.head_node = self.head_node.next
            self.stack_size -= 1
            return data
        else:
            return None
    
    # to get top element
    # return top of stack if stack is not empty else return null
    def top(self):
        if self.head_node is not None:
            return head_node.data
        else:
            return null

    # chck if stack is empty
    def is_empty(self):
        if self.head_node is None:
            return True
        else:
            return False
    

    # pop all elements
    def pop_all(self):
        while self.head_node is not None:
            self.head_node = self.head_node.next
    

