class ThisAsArgument{ // IMP
    void show(ThisAsArgument obj){
        // obj.call(); // run time looping error
        // call(); // run time looping error
        call(this);
        System.out.println("Show method called");
    }
    void call(){
        // show(this);
        System.out.println("call method called");
    }
    public static void main(String arg[]){
        ThisAsArgument t = new ThisAsArgument();
        t.call();
    }
}