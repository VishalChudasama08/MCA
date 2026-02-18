interface Vehicle{
    static void start(){
        System.out.println("Vehicle is starting");
    }
}
interface Electric {
    static void charge(){
        System.out.println("Vehicle is charging");
    }
}
class ElectricCar implements Vehicle, Electric {
    public void start(){
        System.out.println("ElectricCar is starting...");
    }
    public void charge(){
        System.out.println("ElectricCar is charging...");
    }
}
class Interface16B{
    public static void main(String [] arg){
        ElectricCar ec = new ElectricCar();
        Vehicle.start();
        ec.start();

        System.out.println();

        Electric.charge();
        ec.charge();
    }
}