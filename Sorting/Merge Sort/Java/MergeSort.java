public class MergeSort {
    /*
    This function takes an array to be sorted,
    divide the array in two sub arrays i.e leftSubArray and RightSubarray if size of array is greater than 1
    then recursivelly call sort for subarrays
    and then call the merge function
    */
 
    public void sort(int[] arr)
    {
     if (arr.length>1)
     {
         int mid=(arr.length)/2;
         int sizel=mid; // size for left sub array
         int sizer=arr.length-mid; // size for right sub array
         int[] larr=new int[sizel]; // left sub array
         int[] rarr=new int[sizer]; // right sub array
         int t=0;
         for (int i=0;i<mid;i++,t++) // copies elements in left sub array
         {
             larr[i]=arr[t];
         }
         for (int i=0;i<sizer;i++,t++) // copies elements in right sub array
         {
             rarr[i]=arr[t];
         }
         sort(larr); // recursively call sort funtion for left sub array
         sort(rarr); // recursively call sort function for right sub array
         merge(larr,rarr,arr); // call merge funtion to merge the sub arrays in array
     }
    }
    /*
    this function takes three arrays two subarray to be merged in third array in sorted form
    */
    private void merge(int[] larr,int[] rarr,int[] arr)
    {
        int lsize=larr.length; // size of left sub array
        int rsize=rarr.length; // size of right sub array
        int l=0,r=0,a=0; // l for left sub array index, r for right sub array index, a for array index 
        while (l<lsize && r<rsize) // coping elements in array 
        {
            if (larr[l]<rarr[r])
            {
                arr[a]=larr[l];
                l++;a++;
            }
            else
            {
                arr[a]=rarr[r];
                r++;a++;
            }
        }
        while (l<lsize) // coping remaing elements of left sub array in array
        {
            arr[a]=larr[l];
                l++;a++;
        }
        while (r<rsize) // coping remaining elements of right sub array in array
        {
            arr[a]=rarr[r];
                r++;a++;
        }
    }
       // driver function
    public static void main(String args[])
    {
        int arr[] = {10,2,4,9,100,80,70};
 
        System.out.println("Given Array");
        System.out.print(Arrays.toString(arr));
        MergeSort ob = new MergeSort();
        ob.sort(arr);
 
        System.out.println("\nSorted array");
        System.out.print(Arrays.toString(arr));
    }  
}
