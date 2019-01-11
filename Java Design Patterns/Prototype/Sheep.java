
public class Sheep implements Animal {

	public Sheep() {
		System.out.println("Sheep cloned.");
	}
	
	public Animal createClone() {
		
		System.out.println("Sheep is being cloned.");
		
		Sheep sheep = null;
		
		try {
			sheep = (Sheep) super.clone();
		} 
		catch (CloneNotSupportedException e) {
			e.printStackTrace();
		}
		
		return sheep;
	}
	
	public String toString() {
		return "baaaaa baaaaa";
	}

}
