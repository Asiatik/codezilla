
public class Singleton {
	// The single instance that will exist
	private static Singleton instance = null;
	private static boolean existsInstance = false;
	
	private int someVariable1;
	private char someVariable2;
	
	// Private constructor so that it can't be called directly
	private Singleton(int someVariable1, char someVariable2) {
		this.someVariable1 = someVariable1;
		this.someVariable2 = someVariable2;
	}
	
	// To create the instance / get the instance we will call getInstance()
	public static Singleton getInstance() {
		if (!existsInstance) {
			instance = new Singleton(0,'0');
		}
		return instance;
	}
	
	// Some other methods:
	
	public void setVar1(int someVariable1) {
		this.someVariable1 = someVariable1;
	}
	public void setVar2(char someVariable2) {
		this.someVariable2 = someVariable2;
	}
	
	public int getVar1() {
		return someVariable1;
	}
	public char getVar2() {
		return someVariable2;
	}
	
	public static void main(String args[]) {
		Singleton obj = getInstance();
		obj.setVar1(10);
		obj.setVar2('S');
		System.out.println("Instance created with var1 = " + obj.getVar1() + " and var2 = " + obj.getVar2());
	}
	
}