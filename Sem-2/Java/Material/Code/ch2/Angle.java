class Angle {
  public static void main(String args[]) {
    // Get angle in degrees
    double degrees = Double.valueOf(args[0]).doubleValue();
    // Convert to radians
    double radians = degrees * Math.PI/180;
    // Display trig values
    System.out.println("cos = " + Math.cos(radians));
    System.out.println("sin = " + Math.sin(radians));
    System.out.println("tan = " + Math.tan(radians));
  }
}