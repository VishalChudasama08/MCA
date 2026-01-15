import java.io.*;

class FileWriterDemo {

  public static void main(String args[]) {

    try {

      // Create a file writer
	  
	  
      FileWriter fw = new FileWriter("source.txt");

      // Write strings to the file
      for(int i = 0; i < 16; i++) {
        fw.write("Hello " + i + "\n");
      }

      // Close file writer
      fw.close();
    }
    catch(IOException e) {
      System.out.println("Exception: " + e);
    }
  }
}