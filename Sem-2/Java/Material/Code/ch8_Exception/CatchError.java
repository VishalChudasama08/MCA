class CatchError {

  public static void main(String args[]) {

    try {
    	//int i=1,j=0;
    //	System.out.println(i/j);
      System.out.println("Try Block");
    }
    catch(Exception e) {
    //	System.out.println(e);
      System.out.println("Exception");
    }
    catch(ArithmeticException e) {
      System.out.println("ArithmeticException");
    }
  }
}


