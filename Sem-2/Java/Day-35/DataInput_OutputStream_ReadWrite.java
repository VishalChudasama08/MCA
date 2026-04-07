import java.io.*;

class DataInput_OutputStream_ReadWrite {
    public static void main(String [] args) throws IOException{
        // write
        DataOutputStream dos = new DataOutputStream(new FileOutputStream("student"));
        
        dos.writeInt(8);
        dos.writeFloat(12.18f);
        dos.writeDouble(18.12d);
        dos.writeChar('V');
        dos.writeUTF("Hey There!");

        dos.close();

        // read
        DataInputStream dis = new DataInputStream(new FileInputStream("student"));

        System.out.println("Read data from file...");
        int id = dis.readInt();
        float f = dis.readFloat();
        double d = dis.readDouble();
        char c = dis.readChar();
        String s = dis.readUTF();

        System.out.println("Int: " + id);
        System.out.println("Float: " + f);
        System.out.println("Double: " + d);
        System.out.println("Character: " + c);
        System.out.println("String: " + s);

        dis.close();
    }
}