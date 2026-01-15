class Car {
    public void displayDetails(String brand, String model, String year){
        System.out.println("Car Details: ");
        System.out.println("\tbrand name is " + brand);
        System.out.println("\tmodel name is " + model);
        System.out.println("\tyear " + year);
    }
    public static void main(String arg[]){
        Car c = new Car();
        c.displayDetails("Toyota", "XUV", "07/01/2025");
        c.displayDetails("BMW", "V8", "07/01/2025");
    }
}