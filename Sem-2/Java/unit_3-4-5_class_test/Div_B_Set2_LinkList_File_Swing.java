/*
 * A	LinkedList + File Class Operations [20 Marks]
Write a Java program to perform File and Folder Management using LinkedList (List Interface) and the File class.
The program should perform the following:
  • Accept 4 file names from the user and store them in a LinkedList<String>.
  • Use an Iterator to traverse and perform the following for each file name:
      – Create a folder named 'LJMCA_Records' (if not already present).
      – Create a new file inside that folder with the stored file name.
      – Display whether creation was successful or the file already exists.
  • After all files are created, rename the folder to 'MCA_Files'.
  • Delete the first file from the renamed folder and display remaining files using list().
 */

 /*
  * B	Swing – Employee Payroll Form [20 Marks]
Design an Employee Payroll Form using Java Swing:
  • JTextField for Employee Name and Basic Salary.
  • JComboBox for Department (HR, IT, Finance, Admin).
  • JComboBox for Designation (Manager, Developer, Analyst, Clerk).
  • JButton — 'Calculate Salary' and 'Reset'.
  • JTextArea (non-editable, with JScrollPane) to display the salary slip.
  • On Calculate: compute HRA = 20% of Basic, DA = 10% of Basic, Total = Basic + HRA + DA. Display all in JTextArea.
  • On Reset → clear all fields.
  • Use BorderLayout: form fields in CENTER, buttons in SOUTH.
  */

import java.util.*;
import java.io.*;
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

class Div_B_Set2_A {
    Div_B_Set2_A() {
        Scanner sc = new Scanner(System.in);
        LinkedList<String> files = new LinkedList<>();

        for (int i = 1; i <= 4; i++) {
            System.out.print("Enter file name " + i + ": ");
            files.add(sc.next());
        }

        File folder = new File("LJMCA_Records");
        if (!folder.exists()) folder.mkdir();

        for (String fname : files) {
            try {
                File f = new File(folder, fname);
                if (f.createNewFile())
                    System.out.println(fname + " created");
                else
                    System.out.println(fname + " already exists");
            } catch (IOException e) {
                System.out.println(e);
            }
        }

        File newFolder = new File("MCA_Files");
        folder.renameTo(newFolder);

        // delete first file
        File firstFile = new File(newFolder, files.getFirst());
        firstFile.delete();

        System.out.println("Remaining files:");
        for (String f : newFolder.list()) {
            System.out.println(f);
        }
    }
}

class Div_B_Set2_B {
    Div_B_Set2_B() {
        JFrame frame = new JFrame("Payroll Form");
        frame.setSize(500, 400);
        frame.setLayout(new BorderLayout());

        JPanel panel = new JPanel(new GridLayout(4,2));

        JTextField name = new JTextField();
        JTextField salary = new JTextField();

        JComboBox<String> dept = new JComboBox<>(new String[]{"HR","IT","Finance","Admin"});
        JComboBox<String> desig = new JComboBox<>(new String[]{"Manager","Developer","Analyst","Clerk"});

        panel.add(new JLabel("Name")); panel.add(name);
        panel.add(new JLabel("Basic Salary")); panel.add(salary);
        panel.add(new JLabel("Department")); panel.add(dept);
        panel.add(new JLabel("Designation")); panel.add(desig);

        JTextArea area = new JTextArea();
        area.setEditable(false);
        JScrollPane sp = new JScrollPane(area);

        JButton calc = new JButton("Calculate");
        JButton reset = new JButton("Reset");

        JPanel btnPanel = new JPanel();
        btnPanel.add(calc); btnPanel.add(reset);

        calc.addActionListener(e -> {
            double basic = Double.parseDouble(salary.getText());
            double hra = basic * 0.2;
            double da = basic * 0.1;
            double total = basic + hra + da;

            area.setText("Name: "+name.getText()
                    +"\nDept: "+dept.getSelectedItem()
                    +"\nDesignation: "+desig.getSelectedItem()
                    +"\nBasic: "+basic
                    +"\nHRA: "+hra
                    +"\nDA: "+da
                    +"\nTotal: "+total);
        });

        reset.addActionListener(e -> {
            name.setText("");
            salary.setText("");
            area.setText("");
        });

        frame.add(panel, BorderLayout.CENTER);
        frame.add(btnPanel, BorderLayout.SOUTH);
        frame.add(sp, BorderLayout.NORTH);

        frame.setVisible(true);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }
}

public class Div_B_Set2_LinkList_File_Swing {
    public static void main(String[] args) {
        new Div_B_Set2_A();
        // new Div_B_Set2_B();
    }
}
