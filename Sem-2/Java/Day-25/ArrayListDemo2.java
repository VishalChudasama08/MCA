import java.util.*;

public class ArrayListDemo2 {
    public static void main(String[] args) {
        ArrayList<String> list = new ArrayList<>();

        list.add("Ajay");
        list.add("Vishal");
        list.add("Bhavesh");
        list.add("vivek");
        list.add("Aditya");

        System.out.println("Array List: " + list);

        ArrayList<String> list2 = new ArrayList<>();
        for (int i = 0; i < list.size(); i++) {
            if(list.get(i).charAt(0) == 'A'){
                list2.add(list.get(i));
            }
        }
        System.out.println("Name starting from 'A': " + list2);

        // sort ArrayList
        Collections.sort(list);
        System.out.println("After Sort Array List: " + list);
        
        Collections.sort(list, Collections.reverseOrder());
        System.out.println("Reverse Order Sort Array List: " + list);


    }
}
