class CatchSearch {
  public static void main(String args[]) {
    try {
      System.out.println("Before a");
      a();//call a method
      System.out.println("After a");
    }
    catch(Exception e) {
      System.out.println("main: " + e);
    }
    finally {
      System.out.println("main: finally");
    }
  }

  public static void a() {
    try {
      System.out.println("Before b");
      b();//call b method
      System.out.println("After b");
    }
    catch(ArithmeticException e) {
      System.out.println("a: " + e);
    }
    finally {
      System.out.println("a: finally");
    }
  }

  public static void b() {
    try {
      int array[] = new int[4];
      array[10] = 10; // ArrayIndexOutOfBoundsException
    }
    catch(ClassCastException e) { // we not headle ArrayIndexOutOfBoundsException here
      System.out.println("d: " + e);
    }
    finally {
      System.out.println("d: finally");
    }
  }
}