import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.io.*;

public class StudentRegistration {
    public static void main(String[] args) {

        JFrame f = new JFrame("Student Registration Form");
        f.setLayout(new GridLayout(6, 2, 10, 10));

        // Components
        JLabel l1 = new JLabel("Name:");
        JTextField t1 = new JTextField();

        JLabel l2 = new JLabel("Email:");
        JTextField t2 = new JTextField();

        JLabel l3 = new JLabel("Course:");
        JTextField t3 = new JTextField();

        JLabel l4 = new JLabel("Mobile:");
        JTextField t4 = new JTextField();

        JButton b1 = new JButton("Register");
        JButton b2 = new JButton("Clear");

        JLabel l5 = new JLabel("");

        // ========== REGISTER ==========
        b1.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {

                String name = t1.getText();
                String email = t2.getText();
                String course = t3.getText();
                String mobile = t4.getText();

                try {
                    FileWriter fw = new FileWriter("student.txt", true);
                    fw.write(name + ", " + email + ", " + course + ", " + mobile + "\n");
                    fw.close();

                    l5.setText("Registration Successful");

                } catch (Exception ex) {
                    l5.setText("Error Saving Data");
                }
            }
        });

        // ========== CLEAR ==========
        b2.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                t1.setText("");
                t2.setText("");
                t3.setText("");
                t4.setText("");
                l5.setText("");
            }
        });

        // Add components
        f.add(l1); f.add(t1);
        f.add(l2); f.add(t2);
        f.add(l3); f.add(t3);
        f.add(l4); f.add(t4);
        f.add(b1); f.add(b2);
        f.add(l5);

        // Frame settings
        f.setSize(400, 300);
        f.setVisible(true);
        f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }
}