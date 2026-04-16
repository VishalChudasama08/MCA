class demo extends Thread 
{ 
	public void run() 
	{ 
		for (int i = 0; i < 5; i++) 
			System.out.println(getName() + " i = " + i); 
	} 
	demo() 
		{ 
			start(); //call run method of Thread class
		} 
} 
class GetNameDemo 
{ 
		public static void main(String[] args) 
		{ 
			demo d1 = new demo(); 
			demo d2 = new demo();
		}
}