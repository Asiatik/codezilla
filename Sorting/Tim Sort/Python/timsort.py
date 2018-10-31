"""
An implementation of Timsort.

More details on https://hackernoon.com/timsort-the-fastest-sorting-algorithm-youve-never-heard-of-36b28417f399
"""


def binary_search(arr, item, start, end):
    if start == end:
        if arr[start] > item:
            return start
        else:
            return start + 1
    if start > end:
        return start

    mid = (start + end) // 2

    if arr[mid] < item:
        return binary_search(arr, item, mid + 1, end)

    elif arr[mid] > item:
        return binary_search(arr, item, start, mid - 1)

    else:
        return mid


def insertion_sort(the_array):
    """Insertion sort that timsort uses if the array size is small or if
    the size of the "run" is small
    """
    l = len(the_array)
    for index in range(1, l):
        value = the_array[index]
        pos = binary_search(the_array, value, 0, index - 1)
        the_array = the_array[:pos] + [value] + the_array[pos:index] + the_array[index+1:]
    return the_array


def merge(left, right):
    """Takes two sorted lists and returns a single sorted list by comparing the
    elements one at a time.
    [1, 2, 3, 4, 5, 6]
    """
    if not left:
        return right
    if not right:
        return left
    if left[0] < right[0]:
        return [left[0]] + merge(left[1:], right)
    return [right[0]] + merge(left, right[1:])


def timsort(arr):
    runs, sorted_runs = [], []
    length = len(arr)
    new_run = [arr[0]]

    # for every i in the range of 1 to length of array
    for i in range(1, length):
        # if i is at the end of the list
        if i == length - 1:
            new_run.append(arr[i])
            runs.append(new_run)
            break
        # if the i'th element of the array is less than the one before it
        if arr[i] < arr[i-1]:
            # if new_run is set to None (NULL)
            if not new_run:
                runs.append([arr[i]])
                new_run.append(arr[i])
            else:
                runs.append(new_run)
                new_run = []
        # else if its equal to or more than
        else:
            new_run.append(arr[i])

    # for every item in runs, append it using insertion sort
    for item in runs:
        sorted_runs.append(insertion_sort(item))

    # for every run in sorted_runs, merge them
    sorted_array = []
    for run in sorted_runs:
        sorted_array = merge(sorted_array, run)

    print(sorted_array)


timsort([2, 3, 1, 5, 6, 7])
