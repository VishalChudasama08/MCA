 import java.util.*; 
 class ArrayListProg3
 { 
	public static void main(String args[]) 
	{ 
		ArrayList AL = new ArrayList(); 
		System.out.println("\nInitial size of AL:= "  + AL.size()); 
		
		AL.add("Moon"); 
		AL.add("Sun"); 
		AL.add("Stars"); 
		System.out.println("Array List contains \n"+ AL); 
		AL.add(1, "Earth"); 
		System.out.println("Size of AL after additions: "  + AL.size()); 
		System.out.println("Array List after add contains \n"+ AL); 
 
		AL.remove("Sun"); 
		System.out.println("Array List aft remove sun now contains \n"  + AL); 
		AL.remove(1); 
		System.out.println("After removing two elements  size:= " + AL.size()); 
		System.out.println("Array List now contains \n"  + AL); 
	} 
 } 
