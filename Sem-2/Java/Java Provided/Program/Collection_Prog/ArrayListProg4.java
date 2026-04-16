import java.util.*; 
 class ArrayListProg4
 { 
	public static void main(String args[]) 
	{ 
		ArrayList AL = new ArrayList(); 
		System.out.println("\nInitial size of AL: "  + AL.size()); //size of array list
		AL.add(new String("Moon")); 
		AL.add(new Integer(12)); 
		AL.add(new Date()); 
		AL.add(new Double(23.344)); 
		AL.add(new Boolean(true)); 
		AL.add(new Character('P')); 
		System.out.println("Array List contains \n" +AL); //print element of arraylist
 } 
 } 
