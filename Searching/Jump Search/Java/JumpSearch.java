public class JumpSearch {
  // Main function
  public static void main(String [] args) {
    int arr[] = {0, 1, 2, 3, 4, 6, 6, 7, 10, 66, 75, 345, 357, 456, 677, 777, 999};
    int x = 75;

    int i = jumpSearch(arr, x);

    System.out.println("\nNumber " + x + " is at index " + i);
  } 

  // Jump search function
  public static int jumpSearch(int[] arr, int x) {
    int n = arr.length;
    // define block size to be jumped
    int s = (int)Math.floor(Math.sqrt(n));
    int p = 0;

    // finding the block where element is present
    while (arr[Math.min(s, n)-1] < x) {
      p = s;
      s += (int)Math.floor(Math.sqrt(n));
      if (p >= n)
        return -1;
    }

    // doing a linear search for x in block
    while (arr[p] < x) {
      p++;
      if (p == Math.min(s, n))
        return -1;
    }

    if (arr[p] == x)
      return p;
    
    return -1;
  }
}