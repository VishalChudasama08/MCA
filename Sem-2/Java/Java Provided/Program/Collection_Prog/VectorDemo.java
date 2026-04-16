import java.util.*; 
 class VectorDemo
 { 
			static void show(String s){ 
						System.out.println(s); 
			} 
 public static void main(String args[]) 
 { 
		Vector V = new Vector(); 
		show("\nVector size := " + V.size()); 
		show("Vector capacity := " + V.capacity()); 
		
		V.addElement(new Integer(12)); 
		V.addElement("Vector_Demo"); 
		V.addElement(new Double(14.54)); 
		V.addElement(new Boolean(true)); 
		V.addElement("Element"); 
		V.addElement(new Character(‘V’)); 
		
		show("\nFirst Element := " + V.fi rstElement()); 
		show("Last Element := " + V.lastElement()); 
		show("Vector size now := " + V.size()); 
		show("Vector Capacity now := " + V.capacity()); 
		
		Enumeration E; 
		show("\nElements of Vector V"); 
		for (E = V.elements(); E.hasMoreElements(); ) 
			show(E.nextElement() + " "); 
			show(" "); 
		} 
 }