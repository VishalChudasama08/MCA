import java.io.*;

class BinaryFileCopy {
    public static void main(String [] args){
        try {
            String sourceFileName = "SPARROW.jfif";
            String copyFileName = "sparrow_copy.jfif";

            FileInputStream fis = new FileInputStream(sourceFileName);
            FileOutputStream fos = new FileOutputStream(copyFileName);

            int i;
            while((i=fis.read()) != -1){
                fos.write(i);
            }
            
            System.out.println("file copy successfully");
            fis.close();
            fos.close();
        } catch (IOException e){
            System.out.println(e);
        }
    }
}