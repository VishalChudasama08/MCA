class Complex {

    // Class data members
    private double re, im;

    
    public Complex(double re, double im)// Constructor 1-// Parameterized constructor
    {
        // this keyword refers to current instance itself
        this.re = re;
        this.im = im;
    }
  
    Complex(Complex c)// Constructor 2 - // Copy constructor    
    {
        System.out.println("Copy constructor called");
        re = c.re;
        im = c.im;
    }
    
	public String toString()// Overriding the toString() of Object class
    {
       return "(" + re + " + " + im + "i)";
    }
}

public class CopyConstructorDemo {

    public static void main(String[] args)
    {
        // Creating object of above class
        Complex c1 = new Complex(10, 15);

        // Following involves a copy constructor call
        Complex c2 = new Complex(c1);
		System.out.println(c2);
        // Note: Following doesn't involve a copy
        // constructor call
        // as non-primitive variables are just references.
        Complex c3 = c2;

        // toString() of c2 is called here
        System.out.println(c3);
    }
}