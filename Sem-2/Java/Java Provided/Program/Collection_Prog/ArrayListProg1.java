/*PROG 18.1 DEMO OF ARRAYLIST CLASS VER 1*/ 

 import java.util.*; 
 class ArrayListProg1
 { 
	public static void main(String args[]) 
	{ 
		//int a[]=new int[5];//static array a[6]=11
		ArrayList AL1 = new ArrayList(); //class Al1->obj
		System.out.println("\nInitial capacity of AL1:=  "+AL1.size()); //0
		AL1.add("one"); 
		AL1.add("two"); 
		AL1.add("three");
		AL1.add("four");		
				
		System.out.println("Elements of Array LIst: "+AL1);//display arraylist element
		AL1.remove("one");
		AL1.remove(2); //0		
		System.out.println("Aft remove Elements of Array LIst: "+AL1);//display arraylist element
		AL1.add(1,"ZERO");
		System.out.println("Aft add Elements of Array LIst: "+AL1);//display arraylist element
		
		
		
		ArrayList AL2 = new ArrayList(AL1); //copy arraylist 
	
		ArrayList AL3 = new ArrayList(50); 
		System.out.println("Capacity of AL1:= "+AL1.size()); 
		System.out.println("Capacity of AL2:= "+AL2.size()); 
		System.out.println("Capacity of AL3:= "+AL3.size()); 
		
		System.out.println("Element of ArrayList1:= "+AL1); //print arraylist element
		
		//display elements of array
		for (int i = 0; i < AL1.size(); i++) 
		{
            System.out.println(AL1.get(i));
		}
	} 
 } 