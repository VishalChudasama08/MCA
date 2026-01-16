class CarThisKeyword{
    String brand="hyndai";
    String model="exter";
    String price="12 lac";

    public void displayDetails(String brand, String model, String price){
        brand="hyndai";
        model="exter";
        price="12 lac";

        // this.brand = brand;
        // this.model = model;
        // this.price = price;

        System.out.println("Car Details: ");
        System.out.println("\tbrand name is " + brand);
        System.out.println("\tmodel name is " + model);
        System.out.println("\tprice " + price);
        // System.out.println("\tbrand name is " + this.brand);
        // System.out.println("\tmodel name is " + this.model);
        // System.out.println("\tprice " + this.price);
    }
    public static void main(String arg[]){
        CarThisKeyword c = new CarThisKeyword();
        c.displayDetails("Toyota", "XUV", "8");
        c.displayDetails("BMW", "V8", "8");
    }
}