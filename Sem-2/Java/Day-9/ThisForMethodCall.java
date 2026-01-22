class ThisForMethodCall{
    void display(){
        System.out.println("Display");
    }
    void show(){
        this.display();
        display();
        System.out.println("Show");
    }
    public static void main(String arg[]){
        ThisForMethodCall t = new ThisForMethodCall();
        // t.display();
        t.show();
    }
}