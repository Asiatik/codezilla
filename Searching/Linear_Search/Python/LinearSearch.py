"""
This is a simple Linear search algorithm for python.
This is the exact implementation of the pseudocode written in README.
"""
def linear_search(item_list,item):
    index=0
    while index < len(item_list):
        if item_list[index] == item:
            return index
        index+=1
    return None

#Simple demonstration of the function
if __name__=='__main__':
    print (linear_search([1,3,5,7],3))
    print (linear_search([1,2,5,7,97],0))
