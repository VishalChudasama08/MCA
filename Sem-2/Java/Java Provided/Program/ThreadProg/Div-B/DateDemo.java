import java.util.*;
class Date1 extends Thread
{
	public void run()//override Thread class run method
	{
			try
			{
				
				while(true)
				{
								Date d=new Date();
								System.out.println(" "+d);
								Thread.sleep(1000); //1 sec
				}
			}
			catch(InterruptedException e)
			{
				System.out.print(e);
			}
		
	}
}

class DateDemo
{
	public static void main(String args[])
	{
		Date1 dx=new Date1();
		dx.start();//call run method of Class Date1
		
		
	}
}
