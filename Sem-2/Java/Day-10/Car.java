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
        System.out.println("Car details => model: " + model + ", Vehicale details => brand: " + brand + ", year: " + year);
    }
    public static void main(String [] arg){
        Car c = new Car();
        c.displayCar();
        c.displayVehical();
    }
}