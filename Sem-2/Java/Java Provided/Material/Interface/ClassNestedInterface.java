class Vehicle {

    interface Engine {
        void start();
    }
}

class Bike implements Vehicle.Engine {

    public void start() {
        System.out.println("Bike engine started");
    }

    
}
class ClassNestedInterface
{
	public static void main(String[] args) {
        Bike b = new Bike();
        b.start();
    }
}
