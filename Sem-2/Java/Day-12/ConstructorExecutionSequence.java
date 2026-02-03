class Vehicle{
    Vehicle(){
        System.out.println("Vehicle Constructor Called");
    }
}
class Car extends Vehicle {
    Car(){
        System.out.println("Car Constructor Called");
    }
}
class ElectricCar extends Car{
    ElectricCar(){
        System.out.println("ElectricCar Constructor Called");
    }
}

class ConstructorExecutionSequence{
    public static void main(String [] arg){
        ElectricCar ec = new ElectricCar();
    }
} 