import java.util.*; 
 class Book 
 { 
		String bname; 
		String author; 
		int price; 
		Book(String bn, String a, int p)
		{ 
			bname = bn; 
			author = a; 
			price =p; 
		} 
		public String toString() 
		{ 
			String s = "Name = " + bname + "\tAuthor=" + author; 
			s = s + "\tPrice=" + price; 
			return s; 
		} 
 } 
 class ITERATING_COLLECTION2{ 
	public static void main(String args[]) 
	{ 
		LinkedList LL = new LinkedList(); 
		
		LL.add(new Book("Sea of C ","Hari Mohan ",295)); 
		LL.add(new Book("Sea of C++ ","Hubbured ",100)); 
		LL.add(new Book("Sea Of Java","H.M.Pandey ",400)); 
		ListIterator itr; 
		System.out.println("\n******Book Details ******\n"); 
		
		for(itr = LL.listIterator();itr.hasNext();) 
			System.out.println(itr.next()+" "); 
	} 
 }