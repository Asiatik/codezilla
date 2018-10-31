object BinarySearch {
    /**
     * Binary search algorithm using kotlin
     * @param elements List of all the sorted elements
     * @param data The data to search for
     * @return Index (item location in elements array) of search data item
     * if the item is not found then it will return -1
     */
    fun binarySearch(elements: IntArray, data: Int): Int {
        var leftIndex = 0
        var rightIndex = elements.size - 1
        var midIndex: Int

        while (leftIndex <= rightIndex) {
            midIndex = (leftIndex + rightIndex) / 2

            if (elements[midIndex] < data) {
                leftIndex = midIndex + 1
            } else if (elements[midIndex] > data) {
                rightIndex = midIndex - 1
            } else {
                return midIndex
            }
        }
        return -1
    }

    @JvmStatic
    fun main(args: Array<String>) {
        // sample input with data item which is not in the array of elements
        println(binarySearch(intArrayOf(10, 11, 12, 13, 15, 16), 20))
        // sample input with data item which is present in the array of elements
        println(binarySearch(intArrayOf(100, 102, 103, 105, 106), 105))
    }
}