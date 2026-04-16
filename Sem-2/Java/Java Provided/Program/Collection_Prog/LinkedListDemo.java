import java.util.*; 
 import java.util.*; 
 class LinkedListDemo
 { 
	static void show(String s) 
	{ 
		System.out.println(s); 
	} 
	public static void main(String args[]) 
	{ 
		LinkedList LL = new LinkedList(); 
		show("\nInitial size of LL: " + LL.size()); 
		
		LL.addFirst(new Integer(1)); 
		LL.addFirst(new Integer(2)); 
		LL.addFirst(new Integer(3)); 
		LL.addFirst(new Integer(4)); 
		LL.addLast(new Float(2.5f)); 
		LL.addLast(new Double(12.5)); 
		LL.addLast(new String("Xyz"));
		
		show("List is " + LL); 
		show("First element:" + LL.getFirst()); 
		show("Last element:" + LL.getLast()); 
		show("Removed First element: "+LL.removeFirst()); 
		show("Removed Last element: " +LL.removeLast()); 
		show("List Now"); 
		
		for (int i = 0; i < LL.size(); i++) 
			System.out.println("Element"+i+":"+LL.get(i)); 
	} 
 } 