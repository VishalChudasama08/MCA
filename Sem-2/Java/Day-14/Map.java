class Country{
    void showState(){
        System.out.println("Country class showState method call");
    }
    void showPM(){
        System.out.println("Country class showPM method call");
    }
    int showCurrency(){
        int currency = 800;
        System.out.println("Country class showCurrency method call");
        return currency;
    }
    int showCurrency(int c){
        int currency = c;
        System.out.println("Country class showCurrency method with one parameater call");
        return currency;
    }
}

class State extends Country{
    void showState(){
        System.out.println("State class showState method call");
    }
    void showCM(){
        System.out.println("State class showCM method call");
    }
    int showStateCode(){
        int code = 777;
        System.out.println("State class showStateCode method call");
        return code;
    }
    int showStateCode(int sc){
        int code = sc;
        System.out.println("State class showStateCode method with one parameater call");
        return code;
    }
}

class City extends State{
    void showCollector(){
        System.out.println("City class showCollector method call");
    }
    final int showCityCode(){
        int code = 222;
        System.out.println("City class showCityCode final method call");
        return code;
    }
}

class Map{
    public static void main(String [] arg){
        City c = new City();
        c.showState();
        c.showPM();
        System.out.println(c.showCurrency());
        System.out.println(c.showCurrency(123));

        c.showState();
        c.showCM();
        System.out.println(c.showStateCode());
        System.out.println(c.showStateCode(321));

        c.showCollector();
        System.out.println(c.showCityCode());
    }
}