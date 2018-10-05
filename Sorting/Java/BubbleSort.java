//BubbleSort
// Java Program for BubbleSort
class BubbleSort{
  //this funtion takes an array and BubbleSort it in ascending order
  public  static void  sortAscending (int [ ] arr)
  {
      int size=arr.length;
     for (int i=0;i<size;i++)
     {
        for (int j=i+1;j<size;j++)
        {
          if(arr[i]>arr[j])
           {
             int temp=arr[i];
              arr[i]=arr[j];  
              arr[j]=temp;
           }
        }
     }
    }
  //this funtion takes an array and BubbleSort it in ascending order
  public  static void  sortDescending (int [ ] arr)
  {
      int size=arr.length;
     for (int i=0;i<size;i++)
     {
        for (int j=i+1;j<size;j++)
        {
          if(arr[i]<arr[j])
           {
             int temp=arr[i];
              arr[i]=arr[j];  
              arr[j]=temp;
           }
        }
     }
    }  
  //this funtion takes an array and Prints it
  static void printArray(int[] arr)
	{
		int n = arr.length;
		for (int i=0; i<n; ++i)
			System.out.print(arr[i]+" ");
		System.out.println();
	}
}
// Driver program
class Main{
  public static void main(String args[])
	{
		int[] arr = {10, 20, 8, 4, 6, 2};
		int n = arr.length;
    BubbleSort ob=new BubbleSort();
    ob.sortAscending(arr);
		System.out.println("Ascending order sorted array");
		ob.printArray(arr);
		ob.sortDescending(arr);
		System.out.println("Descending order sorted array");
		ob.printArray(arr);
	}
}
