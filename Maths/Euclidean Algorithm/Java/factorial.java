import java.util.*;
public class fact{
	static int factorial(int n) {
		if(n==0)	return 1;
		return (n*factorial(n-1));
	}

	public static void main(String args[]) {
		int a;
		a = factorial(4);
		System.out.println(a);
	}
}
