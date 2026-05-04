import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

class ButtonAction {
    public static void main(String [] args){
        JFrame frame = new JFrame("Button action");
        frame.setSize(500,400);
        frame.setLayout(new GridLayout(2,1));
        // frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        JPanel panel = new JPanel();
        panel.setBorder(BorderFactory.createTitledBorder("Action"));
        panel.setLayout(null);

        JLabel lblName = new JLabel("Enter your name : ");
        lblName.setBounds(90, 30, 150, 30);
        panel.add(lblName);

        JTextField txtName = new JTextField();
        txtName.setBounds(260, 35, 150, 25);
        panel.add(txtName);
        
        JLabel lblColor = new JLabel("Enter color name : ");
        lblColor.setBounds(90, 70, 150, 30);
        panel.add(lblColor);

        JTextField txtColor = new JTextField();
        txtColor.setBounds(260, 70, 150, 25);
        panel.add(txtColor);

        JButton btn = new JButton("Ok");
        btn.setBounds(180, 120, 100, 30);
        btn.setForeground(Color.BLACK);
        btn.setBackground(Color.CYAN);
        panel.add(btn);

        JPanel panel2 = new JPanel();
        panel2.setBorder(BorderFactory.createTitledBorder("Result"));
        panel2.setLayout(new FlowLayout());

        JLabel lblWel = new JLabel("");
        lblWel.setFont(new Font("Cooper", Font.BOLD, 20));
        panel2.add(lblWel);


        btn.addActionListener(new ActionListener(){
            public void actionPerformed(ActionEvent e){
                String color = txtColor.getText();
                if(color.equalsIgnoreCase("red")) lblWel.setForeground(Color.RED);
                if(color.equalsIgnoreCase("black")) lblWel.setForeground(Color.BLACK);
                if(color.equalsIgnoreCase("cyan")) lblWel.setForeground(Color.CYAN);
                if(color.equalsIgnoreCase("gray")) lblWel.setForeground(Color.GRAY);
                if(color.equalsIgnoreCase("green")) lblWel.setForeground(Color.GREEN);
                if(color.equalsIgnoreCase("orange")) lblWel.setForeground(Color.ORANGE);
                if(color.equalsIgnoreCase("blue")) lblWel.setForeground(Color.BLUE);
                String name = txtName.getText();
                lblWel.setText("Welcome " + name);
            }
        });

        frame.add(panel);
        frame.add(panel2);
        frame.setVisible(true);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }

}