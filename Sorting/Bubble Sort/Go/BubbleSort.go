package main

import "fmt"

func main() {
  //Test Code
	array := []int{1, 6, 2, 4, 9, 0, 5, 3, 7, 8}
	fmt.Println("Unsorted array: ", array)
	sort(array)
	fmt.Println("Sorted array: ", array)
}

func sort(arr []int) {
	for i := 0; i < len(arr); i++ {
		for j := 0; j < i; j++ {
			if arr[j] > arr[i] {
				swap(arr, i, j)
			}
		}
	}
}

func swap(arr []int, x, y int) {
	temp := arr[x]
	arr[x] = arr[y]
	arr[y] = temp
}
