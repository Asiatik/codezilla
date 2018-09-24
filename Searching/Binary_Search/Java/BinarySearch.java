public class BinarySearch{
    
    /** 
    * Binary search algorithm
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
    public static int binarySearch(int itemList[],int item){
        int leftIndex=0;
        int rightIndex=itemList.length-1;
        int middleIndex;
        
        while(leftIndex<=rightIndex){
            middleIndex=(leftIndex+rightIndex)/2;
            
            if(itemList[middleIndex]<item){
                leftIndex=middleIndex+1;
            }
            else if(itemList[middleIndex]>item){
                rightIndex=middleIndex-1;
            }
            else{
                return middleIndex;
            }
        }
        return -1;
    }
    
    //Simple desmonstration of the function
    public static void main(String args[]){
        System.out.println(binarySearch(new int[]{1,2,3,4,5},6));
        System.out.println(binarySearch(new int[]{1,2,3,4,5},3));
    }
}
