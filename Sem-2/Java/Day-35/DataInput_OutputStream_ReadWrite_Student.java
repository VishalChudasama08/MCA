import java.io.*;
import java.util.*;

class DataInput_OutputStream_ReadWrite_Student {
    public static void main(String [] args) throws IOException{
        Scanner scan = new Scanner(System.in);

        System.out.print("How many student: ");
        int n = scan.nextInt();

        // write
        DataOutputStream dos = new DataOutputStream(new FileOutputStream("student"));
        for(int i=0; i<n; i++){
            System.out.println("Fill Student " + (i+1) + " Details");

            System.out.print("Enter Student id: ");
            dos.writeInt(scan.nextInt());
            System.out.print("\nEnter Student name: ");
            dos.writeUTF(scan.next());
            System.out.print("\nEnter Student marks: ");
            dos.writeFloat(scan.nextFloat());
            System.out.print("\nenter Student gander[m/f, M/F]: ");
            dos.writeChar(scan.next().charAt(0));
        }
        dos.close();

        // read
        DataInputStream dis = new DataInputStream(new FileInputStream("student"));
        System.out.println("Here are file data:- ");
        for(int i=0; i<n; i++){
            System.out.print("Student " + (i+1) + " id: " + dis.readInt());
            System.out.print("\tname: " + dis.readUTF());
            System.out.print("\tmarks: " + dis.readFloat());
            System.out.print("\tgander: " + dis.readChar() + "\n");
        }
        dis.close();
    }
}