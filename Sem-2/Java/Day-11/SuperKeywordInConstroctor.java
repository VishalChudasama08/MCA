class Vehicale2{
    Vehicale2(String brand){
        System.out.println("Vehicle Brand: " + brand);
    }
}

class Car2 extends Vehicale2 {
    Car2(String brand, String model){
        super(brand); // call Vehicale2 class constroctor
        System.out.println("Car model: " + model);
    }
}

class SuperKeywordInConstroctor{
    public static void main(String []arg){
        Car2 c = new Car2("Toyota", "XUV");
    }
}
/*

thurday (29/01/2026) test =>

loop, if-else leader, array (1d,2d,..), class object concept,
methodoverloading, constroctor (default, para), constroctor overloading, this key word (for all),
static keyword (for all), 
inner, outer, nested class

*/