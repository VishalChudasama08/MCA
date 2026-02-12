public class FinalizeDemo {
    public static void main(String[] args) {
      
        FinalizeDemo t = new FinalizeDemo();
        System.out.println(t.hashCode());

        t = null;

        // calling garbage collector
        System.gc();

        System.out.println("end");
    }

    @Override protected void finalize()
    {
        System.out.println("finalize method called");
    }
}