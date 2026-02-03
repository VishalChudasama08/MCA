class Vehicale{
    public void display(){
        System.out.println("This is a vehicle");
    }
}

class Car extends Vehicale {
    public void display(){
        super.display();
        System.out.println("Thsi is a Car");
    }
}

class SuperKeyword{
    public static void main(String []arg){
        Car c = new Car();
        c.display();
    }
}