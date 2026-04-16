class ThreadX extends Thread
{
	public void run()//override Thread class run method
	{
		while(true)
		{
			try
			{
			System.out.println("Thread 1...");
			Thread.sleep(2000); //2 sec
			}catch(InterruptedException e)
			{
				System.out.print(e);
			}
		}
	}
}
class ThreadY extends Thread
{
	public void run()//override Thread class run method
	{
		try
		{
			while(true)
			{
				System.out.println("Thread 2...");
				Thread.sleep(1000);
			}	
		}
		catch(InterruptedException e)
		{
				System.out.print(e);
		}
	}
}
class ThreadDemo
{
	public static void main(String args[])
	{
		ThreadX tx=new ThreadX();
		tx.start();//call run method of Class ThreadX
		
		
		ThreadY ty=new ThreadY();
		ty.start();//call run method of Class ThreadX
	}
}
