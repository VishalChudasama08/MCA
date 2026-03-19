import java.util.*;

class ArrayListDemo {
    public static void main(String[] args) {
        ArrayList<String> al = new ArrayList<>(); // store any type of value
        al.add("One");
        al.add("Two");
        al.add("There");
        al.add("Four");

        System.out.println("Array List size :- " + al.size());

        System.out.println("Array List :- " + al);

        al.remove(0); // remove by index
        System.out.println("Array List After remove :- " + al);

        System.out.println("Get value: " + al.get(2));
    }
}