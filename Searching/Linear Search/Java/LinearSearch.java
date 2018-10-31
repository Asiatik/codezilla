public class LinearSearch{
    
    /** 
    * Linear search algorithm
    * This is the exact implementation of the pseudocode written in README.
    * Notice that even if the array list contains multiple items,
    * it will return only one index.
    * Thus this algorithm is well suited to find if a item is present.
    * And not for finding the exact index if multiple items are present.
    * 
    * With java you have to be careful of integer overflows.
    * So we must make sure that the length of itemList is below that of int.
    * 
    * @param itemList List of all the sorted items 
    * @param item The item to search for
    * @return Index of the item
    */
    import java.util.Scanner;
    public static int linearSearch(int[] itemList,int item)
    {
        int index=0;
        while ( index < itemList.length )
        {
            if ( itemList[index] == item )
            {
                return index;
            }
            index++;
        }
        return -1;
    }
    
    //Simple desmonstration of the function
    public static void main(String args[])
    {
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter the total number of elements you will be entering for the search: ");
        int nitem=sc.nextInt();
        System.out.println("Enter the integer elements into the element list: ");
        for(int i=0;i<nitem,i++)
            item[i]=sc.nextInt();
        System.out.println("Enter the element to be searched: ");
        int search=sc.nextInt();
        int r=linearSearch(item,search);
        if(r==-1)
            System.out.println("Your search element "+search+" is not found in the elements list.");
        else
            System.out.println("Your search element "+search+" is found in the list at index number "+r);
    }
}
