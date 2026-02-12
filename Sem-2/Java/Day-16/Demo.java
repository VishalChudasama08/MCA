class Demo {
    protected void finalize() { // we override finalize method
        System.out.println("Object destroyed");
    }

    public static void main(String[] args) {
        Demo d = new Demo();
        d = null;

        // System class gc method call finalize() method
        // gc is static method, because we not create it object, compare with println() then println is non-static becasue we call it (ex. System.out.println())
        System.gc(); 
    }
}
