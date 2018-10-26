import java.lang.*; 
import java.util.*;   
public class PG 
{ 
    public static void pigeonhole_sort(int arr[],int n) 
    { 
        int min = arr[0]; 
        int max = arr[0]; 
        int range, i, j, index;    
        for(int a=0; a<n; a++) 
        { 
            if(arr[a] > max) 
                max = arr[a]; 
            if(arr[a] < min) 
                min = arr[a]; 
        }   
        range = max - min + 1; 
        int[] phole = new int[range]; 
        Arrays.fill(phole, 0);   
        for(i = 0; i<n; i++) 
            phole[arr[i] - min]++;             
        index = 0;   
        for(j = 0; j<range; j++) 
            while(phole[j]-->0) 
                arr[index++]=j+min;   
    }   
    public static void main(String[] args) 
    { 
        PG sort = new PG(); 
        int[] arr = {9, 5, 3, 8, 4, 6, 9};   
        sort.pigeonhole_sort(arr,arr.length);           
        for(int i=0 ; i<arr.length ; i++) 
            System.out.print(arr[i] + " "); 
    }   } 
