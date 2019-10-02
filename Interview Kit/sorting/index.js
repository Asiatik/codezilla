// --- Directions
// Implement bubbleSort, selectionSort, and mergeSort

function bubbleSort(arr) {
    // Implement bubblesort
    for (let i = 0; i < arr.length; i++) {
        for (let j = 0; j < (arr.length - i - 1); j++) {
            if (arr[j] > arr[j + 1]) {
                const lesser = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = lesser;
            }
        }
    }

    // return the sorted array
    return arr;
}

function selectionSort(arr) {

    for (let i = 0; i < arr.length; i++) {
        let indexOfMin = i
        for (let j = i + 1; j < arr.length; j++) {
            // find index of min value
            if (arr[j] < arr[indexOfMin]) {
                indexOfMin = j
            }
        }

        // swap the min value with current value
        let temp = arr[indexOfMin]
        arr[indexOfMin] = arr[i]
        arr[i] = temp
    }
    return arr
}

function mergeSort(arr) {
    if (arr.length === 1) {
        return arr;
    }

    const center = Math.floor(arr.length / 2);
    const left = arr.slice(0, center);
    const right = arr.slice(center);

    return merge(mergeSort(left), mergeSort(right));
}

function merge(left, right) {
    const results = [];

    while (left.length && right.length) {
      if (left[0] < right[0]) {
        results.push(left.shift());
      } else {
        results.push(right.shift());
      }
    }
  
    return [...results, ...left, ...right];
}

module.exports = { bubbleSort, selectionSort, mergeSort, merge };
