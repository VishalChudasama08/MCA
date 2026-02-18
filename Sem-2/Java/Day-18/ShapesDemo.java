// Unit-3 program-1
import java.lang.Math;

interface Shape2D {
    public double getArea();
}
interface Shape3D {
    public double getVolume();
}
abstract class Shape {
    abstract public void display();
}

class Circle extends Shape implements Shape2D{
    int radius;
    Circle(int radius){
        this.radius = radius;
    }
    public void display(){
        System.out.println("Circle");
    }
    public double getArea(){
        return (Math.PI*radius*radius);
    }
} 

class Sphere extends Shape implements Shape3D{
    double radius;
    Sphere(int radius){
        this.radius = radius;
    }
    public void display(){
        System.out.println("Sphere");
    }
    public double getVolume(){
        return ((4/3)*Math.PI*radius*radius*radius);
    }
}

class ShapesDemo {
    public static void main(String [] arg){
        Circle c = new Circle(2);
        c.display();
        System.out.println("Circle area: " + c.getArea());

        System.out.println();

        Sphere s = new Sphere(12);
        s.display();
        System.out.println("Sphere volume: " + s.getVolume());
    }
}