public class fact{
	static long factorial(int n) {
		if(n==0)	return 1;
		return (n*factorial(n-1));
	}

	public static void main(String args[]) {
		long a;
		a = factorial(4);
		System.out.println(a);
	}
}
