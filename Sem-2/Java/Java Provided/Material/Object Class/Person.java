class Person{
    
    String n;  

    // Constructor
    public Person(String n) {
        this.n = n;
    }

    // Override toString() for a 
    // custom string representation
    @Override
    public String toString() {
        return "Person{name:'" + n + "'}";
    }

    public static void main(String[] args) {
      
        Person p = new Person("Geek");
      
        // Custom string representation
        System.out.println(p.toString());
      
        // Default hash code value
        System.out.println(p.hashCode()); 
    }
}