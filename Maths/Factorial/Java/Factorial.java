import java.util.Scanner;
public class Factorial 
{
	public static long factorial(int n) {
		if(n == 1) {
			return 1;
		}
		else {
			return n * factorial(n-1);
		}
	}
	public static void main(String [] argv) 
	{
		Scanner sc=new Scanner(System.in);
		int n;
		System.out.println("Enter the number to get its factorial: ");
		n=sc.nextInt();
		double fact=factorial(n));
		System.out.println("Factorial of "+n+" = "+fact);
	}
}
