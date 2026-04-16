class ThreadX implements Runnable
{
	public void run()//override Thread class run method
	{
		System.out.println("Thread 1...");
	}
}
class ThreadY implements Runnable
{
	public void run()//override Thread class run method
	{
		System.out.println("Thread 2...");
	}
}
class RunnableDemo
{
	public static void main(String args[])
	{
		Thread t;
		ThreadX tx=new ThreadX();
		t=new Thread(tx);
		t.start();//call run method of Class ThreadX
		
		
		ThreadY ty=new ThreadY();
		t=new Thread(ty);
		t.start();//call run method of Class ThreadX
	}
}
