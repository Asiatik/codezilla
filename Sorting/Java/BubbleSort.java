//Bubble sort Algorithm
// Java program for implementation of BubbleSort

class BubbleSort
{
	/* Fuction Implementing Bubble Sort Algorithm */
	void sort(int arr[])
 	{
      		int swapped;
      		int length = arr.length;
      		for(int i=0; i<length; i++)
        	{ 
		swapped=0;
			for(int j=0; j<length-i-1; j++)
			{
          		 	if(arr[j]>arr[j+1])
			 	{
            		  	int temp=arr[j+1];
            		  	arr[j+1]=arr[j];
            		  	arr[j]=temp;
	 		  	swapped=1;
          		 	}
			}
		if(swapped==0)
	  	break;
		}
    	}

	/* A utility function to print array of size n */
	static void printArray(int arr[])
	{
		int n = arr.length;
		for (int i=0; i<n; ++i)
			System.out.print(arr[i]+" ");
		System.out.println();
	}

	// Driver program
	public static void main(String args[])
	{
		int arr[] = {10, 7, 8, 9, 1, 5};

		BubbleSort ob = new BubbleSort();
		ob.sort(arr);

		System.out.println("sorted array");
		printArray(arr);
	}
}
/*This code is contributed by Ankush Rodewad */
