class OuterClass{
    static class InnerClass1{
        public void show(){
            System.out.println("This is Inner Class 1 Show Method");
        }
    }
    class InnerClass2{
        public void show(){
            System.out.println("This is Inner Class 2 Show Method");
        }
    }
    public void show(){
        System.out.println("This is Outer Class Show Method");
    }
    public static void main(String arg[]){
        OuterClass outer = new OuterClass();
        
        // here 2 way to create object of static inner class (here InnerClass1)
        InnerClass1 inner1 = new InnerClass1();
        OuterClass.InnerClass1 inner11 = new InnerClass1();

        // here 1 way to create object of non-static inner class (here InnerClass2)
        InnerClass2 inner2 = outer.new InnerClass2();

        outer.show();
        inner1.show();
        inner11.show();
        inner2.show();
    }
}