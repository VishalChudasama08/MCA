class CarStatic{
    static int carId = 23;
    int carModelNumber = 34;

    public void displayDetails(){
        System.out.println("Brand: Toyota, model: glanza");
        System.out.println("Car Model Number: " + carModelNumber);
    }
    public static void displayPrice(){ // static method allow static variable only (class scop variable, not inside method variable)
        int carLoop = 12;
        System.out.println("price: 7-8 Lac");
        System.out.println("Car id: " + CarStatic.carId);
    }
    // public static void add(static int a, static int b){ // static perameter not allow in any case (method, constroctor, static method or constroctor)
    //     int c = a+b;
    //     System.out.println(c);
    // }

    public static void main(String arg[]){
        CarStatic c = new CarStatic();
        c.displayDetails();
        displayPrice();

        // static variable access
        System.out.println(CarStatic.carId);
        System.out.println(carId);
        System.out.println(c.carId);
        
        // non-static variable access
        System.out.println(c.carModelNumber);

        // static int a = 2;
        // static int b = 6;
        // c.add(a, b);
    }
}