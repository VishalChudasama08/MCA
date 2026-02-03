class Vehicle{
    void start(){
        System.out.println("Vehicle is starting");
    }
}
class Car extends Vehicle {
    void start(){
        System.out.println("Car is starting");
    }
    void displayCar(){
        System.out.println("This is a car");
    }
}

class SuperclassReferenceSubclassObject{
    public static void main(String [] arg){
        Vehicle v = new Car(); // Polymorphism
        v.start();
        // v.displayCar();
    }
}