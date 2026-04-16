import java.io.*;
import java.util.*;

class StudentRAFWithGrade {
    public static void main(String[] args) {
        try {
            Scanner sc = new Scanner(System.in);

            RandomAccessFile file = new RandomAccessFile("student.dat", "rw");

            System.out.print("Enter number of students: ");
            int n = sc.nextInt();

            // -------------------------
            // Writing records
            for (int i = 0; i < n; i++) {
                System.out.println("\nEnter details of student " + (i + 1));

                System.out.print("Enter ID: ");
                int id = sc.nextInt();

                System.out.print("Enter Name: ");
                String name = sc.next();

                System.out.print("Enter Marks: ");
                double marks = sc.nextDouble();

                System.out.print("Enter Grade: ");
                char grade = sc.next().charAt(0);

                file.writeInt(id);
                file.writeUTF(name);
                file.writeDouble(marks);
                file.writeChar(grade);
            }

            // -------------------------
            // Reading records
            file.seek(0);//send file cursor to first byte of file means first char
            System.out.println("\nStudent Records:");

            while (file.getFilePointer() < file.length()) {//read till end of file
                int id = file.readInt();
                String name = file.readUTF();
                double marks = file.readDouble();
                char grade = file.readChar();

                System.out.println(id + " " + name + " " + marks + " " + grade);
            }
			
			
			
			
			
			
			/*
			
			

            // -------------------------
            // Modify marks of 1st student (example)
            file.seek(0);

            file.readInt();
            file.readUTF();

			
			
            System.out.print("\nEnter new marks for first student: ");
            double newMarks = sc.nextDouble();

            file.writeDouble(newMarks);

            // -------------------------
            // Display after modification
            file.seek(0);
            System.out.println("\nAfter Modification:");

            while (file.getFilePointer() < file.length()) {
                int id = file.readInt();
                String name = file.readUTF();
                double marks = file.readDouble();
                char grade = file.readChar();

                System.out.println(id + " " + name + " " + marks + " " + grade);
            }

            file.close();
            sc.close();*/

        } catch (Exception e) {
            System.out.println(e);
        }
    }
}