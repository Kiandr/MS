using system;

public class SignleTon{
	private static Singleton Instance;
	 public static Singleton Instance(){
		 if (instance==NULL)
			 instance = new Singleton()
				 return instance;
	 }


}


public sealed class SingleTon{
	
	private static readonly Singleton instance = new Singleton();
	

	public static Single(){
		return instance; 
	}
	
}