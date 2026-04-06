import java.io.*;

class ByteFileReadWrite {
    public static void main(String [] args){
        try {
            FileOutputStream fos = new FileOutputStream("demo.dat");

            // write integer
            fos.write(97);
            fos.write(98);
            fos.write(99);
            fos.write(100);

            // write characters
            fos.write('\n');
            fos.write('H');
            fos.write('e');
            fos.write('y');
            fos.write('\n');

            // write string 
            String name = "Vishal";
            fos.write(name.getBytes());

            fos.close();

            FileInputStream fis = new FileInputStream("demo.dat");

            int i;
            while((i=fis.read()) != -1){
                System.out.print((char)i);
            }

            fis.close();
        } catch (IOException e){
            System.out.println(e);
        }
    } 
}