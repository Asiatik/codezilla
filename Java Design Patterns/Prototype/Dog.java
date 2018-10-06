
public class Dog implements Animal {
 
	public Dog() {
		System.out.println("Dog Cloned.");
	}
	
	public Animal createClone() {
		
		System.out.println("Dog is being cloned.");
		
		Dog dog = null;
		try {
			dog = (Dog) super.clone();
		}
		catch(CloneNotSupportedException e) {
			e.printStackTrace();
		}
		
		return dog;
	}

	public String toString() {
		return "wuuuuf wuuuuuf";
	}
	
}
