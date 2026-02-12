class MainOverloadDemo {

    // JVM entry point
    public static void main(String[] args) {
        System.out.println("Inside original main()");
        
        // Calling overloaded main methods
        main(10);
        main("Java");
    }

    // Overloaded main with int parameter
    public static void main(int a) {
        System.out.println("Inside overloaded main(int): " + a);
    }

    // Overloaded main with String parameter
    public static void main(String s) {
        System.out.println("Inside overloaded main(String): " + s);
    }
}
