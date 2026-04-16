import java.util.*;

class ArrayListProg2 {
    public static void main(String[] args) {

        // Create an ArrayList of Name
        ArrayList<String> list = new ArrayList<>();//declare ArrayList of type String

        list.add("Aarav");
        list.add("Kabir");
        list.add("Vivaan");
        list.add("Ayaan");
        list.add("Aditya");
        System.out.println(list);

        // Create a sublist with string from above ArrayList which
        // start with 'A'.
        ArrayList<String> sublist = new ArrayList<>();
        for (int i = 0; i < list.size(); i++) 
		{
            if (list.get(i).charAt(0) == 'A')//Search element whose data start with 'A'
			{
                sublist.add(list.get(i));
            }
        }
		
		Collections.sort(list);//sort arraylist element ascending order
		System.out.println("Sort Ascending order"+list);
		Collections.sort(list, Collections.reverseOrder()); // Sorts in descending order
		System.out.println("Sort Descending order"+list);
		
		System.out.println("Capacity of list:= "+list.size()); 
		System.out.println("Capacity of sub list := "+sublist.size()); 
        System.out.println("SubList=" + sublist);
		
    }
}