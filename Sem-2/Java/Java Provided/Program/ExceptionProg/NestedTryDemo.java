public class NestedTryDemo {
  
  public static void main(String[] args) {

        try {
            int arr[] = {10, 20, 30}; //3 size
			int result = 10 / 0;//ArithmeticException
            try {
                System.out.println(arr[5]);//ArrayIndexOutOfBoundsException
            }
            catch (ArithmeticException e) {
			//
                System.out.println("Inner Catch: Arithmetic");
            }
			
            
        }
       
		catch (ArrayIndexOutOfBoundsException e) {
		//
            System.out.println("Outer Catch: ArrayIndexOutOfBounds");
        }
		finally
		{
			System.out.println("Program End");
		}
    }
}