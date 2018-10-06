
public class CloneFactory {
	//clone factory not needed but can be useful when different super classes to clone from. 
	//eg. mammal, insect, etc...
	public Animal getClone(Animal animalSample) {
		//make copy of any animal subclass
		
		return animalSample.createClone();
	}
}
