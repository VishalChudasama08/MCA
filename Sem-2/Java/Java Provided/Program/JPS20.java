class demo 
 { 
  static void show() 
  { 
   System.out.println("Welcome from static show"); 
  } 
 } 
 class JPS20 
 { 
  public static void main(String args[]) 
  { 
   demo d = new demo(); 
   d.show(); 
   demo.show(); 
   (new demo()).show(); 
  } 
 }
 