"""
This is a simple binary search algorithm for python.
This is the exact implementation of the pseudocode written in README.
"""

def binary_search(item_list,item):
    left_index = 0
    right_index = len(item_list)-1
    
    while left_index <= right_index:
        middle_index = (left_index+right_index) / 2
        if item_list[middle_index] < item:
            left_index=middle_index+1
        elif item_list[middle_index] > item:
            right_index=middle_index-1
        else:
            return middle_index
    return None

#Simple demonstration of the function
if __name__=='__main__':
    print (binary_search([1,3,5,7],3))
    print (binary_search([1,2,5,7,97],0))
