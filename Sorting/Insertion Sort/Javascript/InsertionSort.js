function insertionSort (items) {
    for (var i = 0; i < items.length; i++) {
      let value = items[i]
      // store the current item value so it can be placed right
      for (var j = i - 1; j > -1 && items[j] > value; j--) {
        // loop through the items in the sorted array (the items from the current to the beginning)
        // copy each item to the next one
        items[j + 1] = items[j]
      }
      // the last item we've reached should now hold the value of the currently sorted item
      items[j + 1] = value
    }
  
    return list
  }
  
  const list = [54, 26, 93, 17, 77, 31, 44, 55, 20]
  console.log(insertionSort(list)) // [ 17, 20, 26, 31, 44, 54, 55, 77, 93 ]