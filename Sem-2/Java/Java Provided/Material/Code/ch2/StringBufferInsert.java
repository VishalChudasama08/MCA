class StringBufferInsert {
  public static void main(String args[]) {
    StringBuffer sb = new StringBuffer("abcde");
    sb.insert(0, "012345");
    System.out.println(sb);
  }
}