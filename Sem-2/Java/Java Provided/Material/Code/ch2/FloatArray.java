class FloatArray {
  public static void main(String args[]) {
    Float array[] = new Float[5];
    array[0] = new Float(3.4);
    array[1] = new Float(-7);
    array[2] = Float.valueOf("8.5");
    array[3] = Float.valueOf("6.02e23");
    array[4] = new Float(3.4e38);
    System.out.println(array.length);
    System.out.println(array[0]);
    System.out.println(array[1]);
    System.out.println(array[2]);
    System.out.println(array[3]);
    System.out.println(array[4]);
  }
}