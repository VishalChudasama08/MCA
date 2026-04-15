import javax.swing.*;
import java.awt.*;

class StudentDetailsForm {
    public static void main(String[] args) {
        JFrame frame = new JFrame("Student Details Form");

        frame.setLayout(null);
        // frame.setLayout(new FlowLayout());
        // frame.setLayout(new GridLayout(17, 3));
        frame.setSize(610, 510);

        JLabel lblDetail = new JLabel("Student Information Form");
        lblDetail.setBounds(160, 15, 250, 30);
        lblDetail.setFont(new Font("Cooper", Font.BOLD, 20));
        frame.add(lblDetail);

        JLabel lblUserName = new JLabel("Enter Your Name : ");
        lblUserName.setBounds(100, 60, 180, 30); // x,y,width,height
        JTextField txtUserName = new JTextField();
        txtUserName.setBounds(240, 65, 220, 25);
        frame.add(lblUserName);
        frame.add(txtUserName);

        JLabel lblUserNumber = new JLabel("Enter Your Number : ");
        lblUserNumber.setBounds(100, 100, 180, 30);
        JTextField txtUserNumber = new JTextField();
        txtUserNumber.setBounds(240, 105, 220, 25);
        frame.add(lblUserNumber);
        frame.add(txtUserNumber);

        JLabel lblAddress = new JLabel("Enter Your Address : ");
        lblAddress.setBounds(100, 140, 180, 30);
        JTextField txtAddress = new JTextField();
        txtAddress.setBounds(240, 145, 220, 60);
        JScrollPane scrollPanel = new JScrollPane(txtAddress);
        frame.add(lblAddress);
        frame.add(txtAddress);
        frame.add(scrollPanel);

        JLabel lblHobby = new JLabel("Your Hobbes : ");
        lblHobby.setBounds(100, 210, 180, 30);
        JCheckBox chkboxGame = new JCheckBox("Game");
        chkboxGame.setBounds(240, 215, 80, 25);
        JCheckBox chkboxMovie = new JCheckBox("Movie");
        chkboxMovie.setBounds(330, 215, 80, 25);
        JCheckBox chkboxTravel = new JCheckBox("Travel");
        chkboxTravel.setBounds(430, 215, 80, 25);
        frame.add(lblHobby);
        frame.add(chkboxGame);
        frame.add(chkboxMovie);
        frame.add(chkboxTravel);

        JLabel lblGender = new JLabel("Gender : ");
        lblGender.setBounds(100, 250, 180, 30);
        JRadioButton rbtnMale = new JRadioButton("Male");
        rbtnMale.setBounds(240, 255, 80, 25);
        JRadioButton rbtnFemale = new JRadioButton("Female");
        frame.add(lblGender);
        frame.add(rbtnMale);
        frame.add(rbtnFemale);

        rbtnFemale.setBounds(330, 254, 80, 25);
        ButtonGroup bg = new ButtonGroup();
        bg.add(rbtnMale);
        bg.add(rbtnFemale);

        JButton btnSubmit = new JButton("Submit");
        btnSubmit.setBounds(160, 330, 100, 30);
        JButton btnCancel = new JButton("Cancel");
        btnCancel.setBounds(300, 330, 100, 30);
        frame.add(btnSubmit);
        frame.add(btnCancel);

        frame.setVisible(true);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }
}