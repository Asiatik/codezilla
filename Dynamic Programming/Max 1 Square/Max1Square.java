public class Max1Square{
    public static void main(String[] args) {
        // Given array containing only 1 and 0
        int arr[][] = {
            {1,1,1,0,1},
            {1,1,1,1,0},
            {1,1,1,1,0},
            {0,1,1,1,0}
        };
        
        // New Array for finding the max sub square array
        int newArr[][] = new int[arr.length][arr[0].length];

        // Keeping record of the max in
        // the new array
        int omax = Integer.MIN_VALUE;

        int R = arr.length; // Length of the rows
        int C = arr[0].length; // Length of the columns

        // Filling the first row
        for(int i=0;i<R;i++){
            newArr[i][0] = arr[i][0];
        }

        // Filling the first column
        for(int j=0;j<C;j++){
            newArr[0][j] = arr[0][j];
        }

        // Completing the left array
        for(int i=1;i<R;i++){
            for(int j=1;j<C;j++){
                if(arr[i][j]==1){
                    newArr[i][j] = Math.min(newArr[i][j-1],Math.min(newArr[i-1][j], newArr[i-1][j-1])) + 1;
                }
                else{
                    newArr[i][j] = 0;
                }

                // Updating value of omax at every level
                if(omax<newArr[i][j]){
                    omax = newArr[i][j];
                }
            }
        }

        System.out.println("The maximu length of square matrix having 1's are : " + omax);

    }
}