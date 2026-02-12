class Restaurant{
    void showCuisine(){
        System.out.println("Restaurant class showCuisine method call");
    }
}
class Multicusine extends Restaurant{
    void showDishes(){
        System.out.println("Multicusine class showDishes method call");
    }
}
class Alakarta extends Multicusine{
    void showDishes(){
        System.out.println("Alakarta class showDishes method call");
    }
}
class Buffet extends Multicusine{
    void showDishes(){
        System.out.println("Buffet class showDishes method call");
    }
}
class Italian extends Restaurant{
    void showDishes(){
        System.out.println("Italian class showDishes method call");
    }
}
class Punjabi extends Restaurant{
    void showDishes(){
        System.out.println("Punjabi class showDishes method call");
    }
}
class Platers extends Punjabi{
    void showDishes(){
        System.out.println("Platers class showDishes method call");
    }
}
class Chef extends Restaurant{
    public static void main(String [] arg){
        Alakarta alak = new Alakarta();
        alak.showCuisine();
        alak.showDishes();

        Multicusine mult = new Alakarta();
        mult.showDishes();
        mult.showCuisine();

        Chef c = new Chef();
        c.showCuisine();

        Buffet buff = new Buffet();
        buff.showDishes();

        Punjabi pun = new Platers();
        pun.showCuisine();
        pun.showDishes();
    }    
}