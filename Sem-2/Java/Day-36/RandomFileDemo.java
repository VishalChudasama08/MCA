import java.io.*;
import java.util.*;

class RandomFileDemo {
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

            raf.seek(0);
            System.out.print("Enter student id to find:- ");
            int find = scan.nextInt();
            boolean found = false;
            System.out.println("Student Details:- ");
            while (raf.getFilePointer() < raf.length()) {
                int id = raf.readInt();
                String name = raf.readUTF();
                double marks = raf.readDouble();
                char grade = raf.readChar();

                if (find == id) {
                    found = true;
                    System.out
                            .println("\tId:- " + id + "\tName:- " + name + "\tMarks:- " + marks + "\tGrade:- " + grade);
                }
            }

            if (!found) {
                System.out.println("Records Not Found..");
            }

        } catch (Exception e) {
            System.out.println(e);
        }
    }

}