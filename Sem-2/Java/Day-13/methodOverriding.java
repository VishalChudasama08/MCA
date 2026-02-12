class Vehicle{
    void fuelType(){
        System.out.println("Vehicles can use different types of fuel");
    }
}
class Car extends Vehicle {
    void fuelType(){
        System.out.println("Cars use petrol or diesel");
    }
}

class methodOverriding{
    public static void main(String [] arg){
        Vehicle v = new Vehicle();
        v.fuelType();

        Car c = new Car();
        c.fuelType();

        Vehicle v1 = new Car();
        v1.fuelType();
    }
}