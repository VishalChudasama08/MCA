class CatchSearchDemo
{
	public static void main(String args[])
	{
		try
		{
				
				System.out.print("\n\tThis is Main Method");
				
				System.out.print("\n\tB4 a Method..");
				a();//call A method
				System.out.print("\n\tAft4 a Method..");
				
		}
		catch(ArithmeticException e)
		{
			System.out.print("\n\tArithmetic Exception...");
		}
		finally
		{
			System.out.print("\n\tMainMethod finally..");
		}
		
	}
	public void a()
	{
		try
		{
				
				System.out.print("\n\tThis is a() Method");	
				System.out.print("\n\tB4 B Method..");
				b();//call A method
				System.out.print("\n\tAft4 B Method..");
				
		}
		catch(ArrayIndexOutOfBoundsException e)
		{
			System.out.print("\n\tArrayIndexOutOfBoundsException ..");
		}
		finally
		{
			System.out.print("\n\ta Method finally..");
		}
	}
	public void b()
	{
		try
		{
				
				System.out.print("\n\tThis is b() Method");	
				int a=10;
				int b=0;
				int c=a/b;
				
				System.out.print("\n\tDivision is:"+c);
		}
		catch(NegativeArraySizeException e)
		{
			System.out.print("\n\tNegativeArraySizeException ..");
		}
		finally
		{
			System.out.print("\n\tb Method finally..");
		}
	}
}