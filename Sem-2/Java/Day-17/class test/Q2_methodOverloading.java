// ODD: Q2. demonstrate method overloading

public class Q2_methodOverloading {
    void show(){
        System.out.println("I am void show()");
    }
    int show(int b){
        System.out.println("I am int show(int b)");
        return b;
    }
    float show(int a, int b){
        System.out.println("I am float show(int a, int b)");
        return (a/b);
    }
    public static void main(String[] args) {
        Q2_methodOverloading obj = new Q2_methodOverloading();
        obj.show();
        System.out.println("show(int b) return: "+obj.show(8));
        System.out.println("show(int a, int b) return: "+obj.show(8, 5));
    }
}


