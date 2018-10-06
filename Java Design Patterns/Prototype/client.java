
public class client {
	//test the Prototype Design Pattern.
	public static void main(String[] args) {
		CloneFactory factory = new CloneFactory();
		
		Sheep billy = new Sheep();
		
		Sheep clonedSheep = (Sheep) factory.getClone(billy);
		
		Dog rufus = new Dog();
		
		Dog clonedDog = (Dog) factory.getClone(rufus);
		
		System.out.println(clonedSheep + "\n" + clonedDog);
	}
}
