import javax.swing.*;

public class LoginFrame {
    public static void main(String[] args) {
        JFrame frame = new JFrame("Login Page");
        frame.setLayout(null);
        frame.setSize(600, 400);

        JLabel lblLogin = new JLabel("Login Form");
        lblLogin.setBounds(210, 10, 150, 30);

        JLabel lblUserName = new JLabel("Enter User Name: ");
        lblUserName.setBounds(100, 60, 180, 30); // x,y,width,height
        JTextField txtUserName = new JTextField();
        txtUserName.setBounds(240, 60, 220, 30);

        JLabel lblUserPassword = new JLabel("Enter User Password: ");
        lblUserPassword.setBounds(100, 110, 180, 30);
        JPasswordField txtUserPassword = new JPasswordField();
        txtUserPassword.setBounds(240, 110, 220, 30);

        JButton btnSubmit = new JButton("submit");
        btnSubmit.setBounds(140, 170, 100, 30);
        JButton btnCancel = new JButton("cancel");
        btnCancel.setBounds(290, 170, 100, 30);

        frame.add(lblLogin);
        frame.add(lblUserName);
        frame.add(txtUserName);
        frame.add(lblUserPassword);
        frame.add(txtUserPassword);
        frame.add(btnSubmit);
        frame.add(btnCancel);

        frame.setVisible(true);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }
}