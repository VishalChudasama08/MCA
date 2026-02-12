class Circle {
  public static void main(String args[]) {
    // Get radius
    double radius = Double.valueOf(args[0]).doubleValue();
    // Display Area
    double area = Math.PI * radius * radius;
    System.out.println("Area is " + area);
  }
}