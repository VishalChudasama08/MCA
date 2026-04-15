import java.io.*;
import java.util.*;

class ModifyFile {
    public static void main(String args[]) {
        try {
            Scanner scan = new Scanner(System.in);
            RandomAccessFile raf = new RandomAccessFile("random.dat", "rw");
            System.out.print("Enter Number Of Students:- ");
            int n = scan.nextInt();

            for (int i = 0; i < n; i++) {
                System.out.println("Enter Details Of Students:- " + (i + 1));

                System.out.print("\nStudent Id:- ");
                int id = scan.nextInt();
                raf.writeInt(id);

                System.out.print("\nStudent Name:- ");
                Scanner scan1 = new Scanner(System.in);
                String name = scan1.nextLine();
                raf.writeUTF(name);

                System.out.print("\nStudent Marks:- ");
                double marks = scan.nextDouble();
                raf.writeDouble(marks);

                System.out.print("\nStudent Grade:- ");
                char grade = scan.next().charAt(0);
                raf.writeChar(grade);
            }

            int recordSize = 0;
            raf.seek(0);
            raf.readInt();
            raf.readUTF(); // move cursor where from starting modify
            System.out.print("Enter New Marks:- ");
            double newMarks = scan.nextDouble();
            raf.writeDouble(newMarks); // modify, only next double modify
            raf.seek(0);
            System.out.println("Student Details:- ");

            while (raf.getFilePointer() < raf.length()) {
                int id = raf.readInt();
                String name = raf.readUTF();
                double marks = raf.readDouble();
                char grade = raf.readChar();
                System.out.print("\tId:- " + id + "\tName:- " + name + "\tMarks:- " + marks + "\tGrade:- " + grade);
                recordSize = Integer.BYTES + name.length() + Double.BYTES + Character.BYTES;
                System.out.println("\t=> Record Size:- " + recordSize);
            }

            System.out.println("File Length:- " + raf.length());

            // raf.setLength(0); // clear file

            raf.close();
        } catch (Exception e) {
            System.out.println(e);
        }
    }

}