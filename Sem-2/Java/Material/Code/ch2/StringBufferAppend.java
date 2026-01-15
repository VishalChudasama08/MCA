class StringBufferAppend {
  public static void main(String args[]) {
    StringBuffer sb = new StringBuffer("abcde");
    sb.append("fgh");
    sb.append("ijklmnop");
    System.out.println(sb);
    System.out.println("sb.capacity = " + sb.capacity());
    System.out.println("sb.length = " + sb.length());
  }
}