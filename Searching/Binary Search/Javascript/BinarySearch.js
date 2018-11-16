/** Binary search algorithm in Javascript **/
/** Follows the README.md **/

function binarySearch(array, target) {
    let leftIndex = 0;
    let rightIndex = array.length - 1;
    let middleIndex;

    while (leftIndex <= rightIndex) {
        middleIndex = leftIndex + Math.floor((rightIndex - leftIndex) / 2);
        if (array[middleIndex] === target) {
            return middleIndex;
        }
        if (arr[middleIndex] < target) {
            leftIndex = middleIndex + 1;
        } else {
            rightIndex = middleIndex - 1;
        }
    }
    return -1;
}