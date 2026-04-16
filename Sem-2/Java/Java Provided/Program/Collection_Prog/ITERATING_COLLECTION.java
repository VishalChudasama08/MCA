 //DEMO OF ITERATING COLLECTION
 
 import java.util.*; 
 class ITERATING_COLLECTION
 { 
	public static void main(String args[]) 
	{ 
		ArrayList AL = new ArrayList(); 
		for (int i = 0; i < 10; i++) 
			AL.add(new Integer(i + 1)); 
 
		Iterator itr = AL.iterator(); 
		while (itr.hasNext()) 
		{ 
			Object E = itr.next(); 
			System.out.print(E + “ “); 
		} 
		System.out.println(); 
	} 
 } 