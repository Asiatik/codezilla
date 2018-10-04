def merge_sort(array_list, start, end):
    '''Sorts the list from indexe start to end - 1 inclusive.'''
    if end - start > 1:
        mid = (start + end)//2
        merge_sort(array_list, start, mid)
        merge_sort(array_list, mid, end)
        merge_list(array_list, start, mid, end)
     '''Merges each sorted left list and right list'''
def merge_list(array_list, start, mid, end):
    left = array_list[start:mid]
    right = array_list[mid:end]
    k = start
    i = 0
    j = 0
    while (start + i < mid and mid + j < end):
        if (left[i] <= right[j]):
            array_list[k] = left[i]
            i = i + 1
        else:
            array_list[k] = right[j]
            j = j + 1
        k = k + 1
    if start + i < mid:
        while k < end:
            array_list[k] = left[i]
            i = i + 1
            k = k + 1
    else:
        while k < end:
            array_list[k] = right[j]
            j = j + 1
            k = k + 1
 
array_list = [84,29,49,91,17,77,31,10,44,55,20,39]
merge_sort(array_list, 0, len(array_list))
print('Sorted list: ', end='')
print(array_list)
