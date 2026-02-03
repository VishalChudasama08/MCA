class Vehicle{
    String brand = "Toyota";
    String year = "23 jan 2026";
    public void displayVehical(){
        System.out.println("Vehicale details => brand: " + brand + ", year: " + year);
    }
}
class Car extends Vehicle {
    String model = "Toyota";
    public void displayCar(){
        System.out.println("Car details => model: " + model);
    }
}
class Bike extends Vehicle{
    String type = "Sports, Cruiser";
    public void displayBike(){
        System.out.println("Bike details => type: " + type);
    }
}
class HierarchicalInheritance{
    public static void main(String [] arg){
        System.out.println("\n");
        Car c = new Car();
        c.displayVehical();
        c.displayCar();

        System.out.println("\n");
        Bike b = new Bike();
        b.displayVehical();
        b.displayBike();

        System.out.println("\n");
    }
}