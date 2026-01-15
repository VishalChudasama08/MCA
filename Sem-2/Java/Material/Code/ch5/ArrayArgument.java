class ArrayArgument {

  public static void main(String args[]) {

    // Initialize variables
    int x[] = { 11, 12, 13, 14, 15 };

    // Display variables
    display(x);

    // Call method
    change(x);

    // Display variables
    display(x);
  }

  public static void change(int x[]) {
    int y[] = { 21, 22, 23, 24, 25 };
    x = y;
    //for(int i = 0; i < x.length; i++) 
    //System.out.print(x[i] + " ");
      x[0]=3453;
      System.out.println(y[0]);

    
  }

  public static void display(int x[]) {
    for(int i = 0; i < x.length; i++) 
      System.out.print(x[i] + " ");
    System.out.println("");
  }
}
    