// insertion sort algorithm implemented in java
import java.util.Scanner;
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
         Scanner sc=new Scanner(System.in);
         System.out.println("Enter the number of elements in the array: ");
         int n=sc.nextInt();
         System.out.println("Enter "+n+" elements to be soterd in the array: ");
         for(int i=0;i<n;i++)
            int arr[i] =sc.nextInt();
 
        System.out.println("Given Array");
        System.out.print(Arrays.toString(arr));
        InsertionSort ob = new InsertionSort();
        ob.sort(arr);
 
        System.out.println("\nSorted array");
        System.out.print(Arrays.toString(arr));
    }  
}
