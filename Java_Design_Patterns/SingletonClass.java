public class SingletonClass 
{
	//static instance of SingletonClass
	private static SingletonClass sInstance;
	//unreachable constructor
	private SingletonClass() {
		
	}
	//access method to static instance of SingletonClass
	public static SingletonClass getInstance()
	{
	    if(sInstance == null){
                sInstance = new SingletonClass();
            }
            return sInstance;
	}
}
