class FinalKeyword{
    final static int b=12;
    static final int c=13;

    // public static final void main(String [] arg){
    //     // in main method, final work
    // }
    public static void main(String [] arg){
        final int a=8;
        // a=5; // not allow
        System.out.println(a);

        System.out.println(b);

        System.out.println(c);
    }
}

class D extends FinalKeyword{
    public static final void main(String [] arg){ // wen do "java D" it run
        System.out.println("I am D class");
    }
} 

// nptel