public class SingletonClass 
{
	//static instance of SingletonClass
	private static SingletonClass instance;
	//unreachable constructor
	private SingletonClass() {
		
	}
	//access method to static instance of SingletonClass
	public static SingletonClass getInstance()
	{
		return instance;
	}
}