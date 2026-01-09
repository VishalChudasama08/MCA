class task2{
    int add(int a, int b){
        System.out.println("int add(int a, int b)");
        return 0;
    }
    // double add(int a, int b){
    //     System.out.println("int add(int a, int b)");
    //     return 0.0d;
    // }
    int add(double a, double b){
        System.out.println("int add(int a, int b)");
        return 0;
    }
    public static void main(String arg[]){
        task2 t = new task2();
        t.add(1, 2);
        t.add(1.1d, 2.2d);
    }
}