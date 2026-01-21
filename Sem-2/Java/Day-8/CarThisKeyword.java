class CarThisKeyword{
    int price=8000;

    CarThisKeyword(int price){
        this.price = price;

        // System.out.println("Car Details: ");
        // System.out.println("\tprice " + this.price);
    }
    public static void main(String arg[]){
        CarThisKeyword c = new CarThisKeyword(9000);
        
        System.out.println("\tprice " + c.price);
    }
}