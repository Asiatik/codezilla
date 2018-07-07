// insertion sort algorithm implemented in java
public class InsertionSort {
    /*
    this function takes an array and assumes the first index as sorted part
    takes element from unsorted part and add to sorted part at appropiate  position untill array is not sorted
    */
    public void sort(int[] arr)
    {
        int size=arr.length; 
        for (int i=1;i<size;i++) // starting from index no 1 because it assumes first index as sorted
        {
            int t=i-1;
            int temp=arr[i];
            for (;t>=0&&arr[t]>temp;t--) 
                {
                    arr[t+1]=arr[t];
                }
            arr[t+1]=temp;
        }
    }
    // driver program
     public static void main(String args[])
    {
        int arr[] = {10,1,0,11,12,20,21};
 
        System.out.println("Given Array");
        System.out.print(Arrays.toString(arr));
        InsertionSort ob = new InsertionSort();
        ob.sort(arr);
 
        System.out.println("\nSorted array");
        System.out.print(Arrays.toString(arr));
    }  
}
