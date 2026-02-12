class MainAllDemo {

    // JVM ENTRY POINT (only this is called automatically)
    public static void main(String[] args) {
        System.out.println("JVM started execution from main(String[] args)");

        // Explicit calls to overloaded main methods
        main(10);
        main(10.5f);
        main('A');
        main(true);
        main("Java");
        main(new int[]{1,2,3});
    }

    // Overloaded main methods (compiler accepts all)
    public static void main(int a) {
        System.out.println("main(int) called with value: " + a);
    }

    public static void main(float f) {
        System.out.println("main(float) called with value: " + f);
    }

    public static void main(char c) {
        System.out.println("main(char) called with value: " + c);
    }

    public static void main(boolean b) {
        System.out.println("main(boolean) called with value: " + b);
    }

    public static void main(String s) {
        System.out.println("main(String) called with value: " + s);
    }

    public static void main(int[] arr) {
        System.out.println("main(int[]) called with length: " + arr.length);
    }
}
