class X {
  void f() 
  {
  	int j,k=100;
    for( j = 0; j < 5; j++)
     {
       k = 100;
      System.out.println("j = " + j + "; k = " + k);
    }
      System.out.println("j = " + j + "; k = " + k);
  }
}

class VariableScope {
  public static void main(String args[]) {
    X x = new X();
    x.f();
  }
}