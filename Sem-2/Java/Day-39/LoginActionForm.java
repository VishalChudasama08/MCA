
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.io.*;

public class LoginActionForm {
    public static void main(String [] args){
        JFrame frame = new JFrame("Login Page");
        // frame.setLayout(new FlowLayout());
        frame.setLayout(null);
        frame.setSize(600,400);

        JPanel panel = new JPanel();
        panel.setBorder(BorderFactory.createTitledBorder("Login Form"));
        panel.setLayout(null);
        
        JLabel lblLogin = new JLabel("Login Form");
        lblLogin.setBounds(210,10,150,30);

        JLabel lblUserName = new JLabel("Enter User Name: ");
        lblUserName.setBounds(100,60,180,30); // x,y,width,height
        JTextField txtUserName = new JTextField();
        txtUserName.setBounds(240,60,220,30);

        JLabel lblUserPassword = new JLabel("Enter User Passwrod: ");
        lblUserPassword.setBounds(100,110,180,30);
        JPasswordField txtUserPassword = new JPasswordField();
        txtUserPassword.setBounds(240,110,220,30); 

        JButton btnSubmit = new JButton("submit");
        btnSubmit.setBounds(140,170,100,30);
        JButton btnCancel = new JButton("cancel");
        btnCancel.setBounds(290,170,100,30);

        JLabel result = new JLabel("");
        result.setFont(new Font("Cooper", Font.BOLD, 15));
        result.setBounds(80, 230, 350, 30);

        btnSubmit.addActionListener(new ActionListener(){
            public void actionPerformed(ActionEvent e){
                String userName = txtUserName.getText();
                String userPassword = txtUserPassword.getText();

                if(userName.equals("Admin") && userPassword.equals("12345")){
                    result.setForeground(Color.GREEN);
                    result.setText("Welcome " + userName);

                    try {
                        FileWriter fw = new FileWriter("loginData.txt");
                        fw.write("User Name:\t" + userName + "\n");
                        fw.write("User Password:\t" + userPassword + "\n");
                        fw.close();
                    } catch(IOException fe){
                        System.out.println(fe);
                    }
                } else {
                    JOptionPane.showMessageDialog(frame, "username and password are wrong");
                    result.setForeground(Color.RED);
                    result.setText("username and password are wrong");
                }
            }
        });
        btnCancel.addActionListener(new ActionListener(){
            public void actionPerformed(ActionEvent e){
                System.exit(0);
            }
        });

        frame.add(lblLogin);
        frame.add(lblUserName);
        frame.add(txtUserName);
        frame.add(lblUserPassword);
        frame.add(txtUserPassword);
        frame.add(btnSubmit);
        frame.add(btnCancel);
        frame.add(result);

        // frame.add(panel);

        frame.setVisible(true);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        
    }
}