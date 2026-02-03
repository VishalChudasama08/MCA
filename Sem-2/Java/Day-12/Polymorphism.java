class Country{
    void display(){
        System.out.println("This is Country class");
    }
}
class State extends Country{
    void display(){
        System.out.println("This is State class");
    }
}
class City extends State {
    void display(){
        System.out.println("This is City class");
    }
}

class Polymorphism{
    public static void main(String [] arg){
        Country c = new State();
        c.display();
    }
}