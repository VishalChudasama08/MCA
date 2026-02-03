class Vehicle{
    String brand = "Toyota";
    String year = "27, Jan 2026";
    public void displayVehicle(){
        System.out.println("Brand: " + brand + ", Year: " + year);
    }
}

class Car extends Vehicle{
    String model = "Glanza";
    public void displayCar(){
        System.out.println("Model: " + model);
    }
}

class ElectricCar extends Car {
    String batteryCapacity = "800km in one Full charge";
    public void displayElectricCar(){
        System.out.println("Battery Capacity: " + batteryCapacity);
    }

    public static void main(String [] arg){
        ElectricCar ec = new ElectricCar();
        ec.displayVehicle();
        ec.displayCar();
        ec.displayElectricCar();
    }
}