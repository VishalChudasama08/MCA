interface Drawable {
    public void draw();
}

class Circle implements Drawable {
    public void draw(){
        System.out.println("Drawing a Circle");
    }
} 
class Rectangle implements Drawable {
    public void draw(){
        System.out.println("Drawing a Rectangle");
    }
}

class Interface16A {
    public static void main(String [] arg){
        Circle c = new Circle();
        c.draw();

        Rectangle r = new Rectangle();
        r.draw();
    }
}