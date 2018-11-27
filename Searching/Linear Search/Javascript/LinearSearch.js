/** Binary search algorithm in Javascript **/

function linearSearch(array, item) {
    for (let i = 0; i < array.length; i++) {
      if(array[i] === item) {
        return i;
      }
    }
    return -1;
  }