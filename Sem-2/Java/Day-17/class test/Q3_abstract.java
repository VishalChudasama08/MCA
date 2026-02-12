abstract class Vehicle{
    void show(){
        System.out.println("Show method called...");
    }
    abstract void display(String brand);
}

class Car extends Vehicle{
    void display(String brand){
        System.out.println("Brand name: " + brand);
    }
}
public class Q3_abstract {
    public static void main(String[] args) {
        Car c = new Car();
        c.display("Toyota");
    }
}
