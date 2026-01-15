class X {
  static int array[];

  static {
  	System.out.println("inside static block");
    array = new int[6];
    for(int i = 0; i < 6; i++) 
      array[i] = i;
  }
}

class StaticInitializationBlock {

  public static void main(String args[]) {
  	System.out.println("inside main block");

    for(int i = 0; i < 6; i++)
    {
    	System.out.println("inside for loop");
      System.out.println("inside loop sop" + X.array[i]);
      }
  }
}