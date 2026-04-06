import java.io.*;

class MergedByteFile {
    public static void main(String [] args){
        try {
            FileInputStream fis1 = new FileInputStream("demo.dat");
            FileInputStream fis2 = new FileInputStream("demo2.dat");
            String mergedFileName = "marge.dat";
            FileOutputStream fos = new FileOutputStream(mergedFileName);

            int i;
            while((i=fis1.read()) != -1){
                fos.write((char)i);
            }
            fos.write('\n');
            while((i=fis2.read()) != -1){
                fos.write((char)i);
            }
            
            System.out.println("\tMerged in " + mergedFileName + " file successfully");
            fis1.close();
            fis2.close();
            fos.close();
        } catch (IOException e){
            System.out.println(e);
        }
    }
}