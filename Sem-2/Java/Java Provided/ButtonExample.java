import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class ButtonExample extends JFrame implements ActionListener {
    JButton button1, button2;

    public ButtonExample() {
        // Initialize buttons
        button1 = new JButton("Button 1");
        button2 = new JButton("Button 2");

        // Add action listeners to this class
        button1.addActionListener(this);
        button2.addActionListener(this);

        // Layout setup
        this.setLayout(new FlowLayout());
        this.add(button1);
        this.add(button2);
        this.setSize(300, 100);
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        this.setVisible(true);
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        // Use getSource() to find out which button was clicked
        if (e.getSource() == button1) {
            System.out.println("Button 1 was clicked!");
        } else if (e.getSource() == button2) {
            System.out.println("Button 2 was clicked!");
        }
    }

    public static void main(String[] args) {
        new ButtonExample(); //call constructor
    }
}
