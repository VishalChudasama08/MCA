abstract class Shape{
    void display(){
        System.out.println("This is abstract class shape");
    }
    public abstract double area(double r);
    public abstract double area(double l, double w);
}
// class Circle extends Shape{
//     // @Override
//     public double area(double r){
//         System.out.print("Area of Circle: pi*r*r");
//         return (3.14*r*r);
//     }
// }
// class Rectangle extends Shape{
//     // @Override
//     public double area(double l, double w){
//         System.out.print("Area of Rectangle: length*width");
//         return (l*w);
//     }
// }

class FindArea extends Shape{
    public double area(double r){
        System.out.print("Area of Circle: pi*r*r");
        return (3.14*r*r);
    }
    public double area(double l, double w){
        System.out.print("Area of Rectangle: length*width");
        return (l*w);
    }
}
class AbstractTopic{
    public static void main(String [] arg){
        // Circle c = new Circle();
        // System.out.println(" = "+c.area(12));

        // Rectangle r = new Rectangle();
        // System.out.println(" = "+r.area(10, 20));

        FindArea f = new FindArea();
        System.out.println(" = "+f.area(12));
        System.out.println(" = "+f.area(10, 20));
    }
}