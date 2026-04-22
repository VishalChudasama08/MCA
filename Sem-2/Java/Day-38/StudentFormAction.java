import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

class StudentFormAction {
    public static void main(String[] args) {
        JFrame frame = new JFrame("Student Details Form");

        frame.setLayout(null);
        // frame.setLayout(new FlowLayout());
        // frame.setLayout(new GridLayout(17,3));
        frame.setSize(610, 680);

        JLabel lblDetail = new JLabel("Student Information");
        lblDetail.setBounds(210, 15, 250, 30);
        lblDetail.setFont(new Font("Cooper", Font.BOLD, 20));
        frame.add(lblDetail);

        JLabel lblUserName = new JLabel("Enter Your Name: ");
        lblUserName.setBounds(100, 60, 180, 30); // x,y,width,height
        JTextField txtUserName = new JTextField();
        txtUserName.setBounds(240, 65, 220, 25);
        frame.add(lblUserName);
        frame.add(txtUserName);

        JLabel lblUserNumber = new JLabel("Enter Your Number: ");
        lblUserNumber.setBounds(100, 100, 180, 30);
        JTextField txtUserNumber = new JTextField();
        txtUserNumber.setBounds(240, 105, 220, 25);
        frame.add(lblUserNumber);
        frame.add(txtUserNumber);

        JLabel lblAddress = new JLabel("Enter Your Address: ");
        lblAddress.setBounds(100, 140, 180, 30);
        JTextField txtAddress = new JTextField();
        txtAddress.setBounds(240, 145, 220, 60);
        JScrollPane scrollPanel = new JScrollPane(txtAddress);
        frame.add(lblAddress);
        frame.add(txtAddress);
        frame.add(scrollPanel);

        JLabel lblHobby = new JLabel("Your Hobbes: ");
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

        JLabel lblGender = new JLabel("Gender: ");
        lblGender.setBounds(100, 250, 180, 30);
        JRadioButton rbtnMale = new JRadioButton("Male");
        rbtnMale.setBounds(240, 255, 80, 25);
        JRadioButton rbtnFemale = new JRadioButton("Female");
        rbtnFemale.setBounds(330, 255, 80, 25);
        frame.add(lblGender);
        frame.add(rbtnMale);
        frame.add(rbtnFemale);
        ButtonGroup bg = new ButtonGroup();
        bg.add(rbtnMale);
        bg.add(rbtnFemale);

        JLabel lblCourse = new JLabel("Course: ");
        lblCourse.setBounds(100, 290, 180, 30);
        frame.add(lblCourse);

        String[] Courses = { "select", "BCA", "MCA", "iMCA", "B. Tech", "M. Tech" };
        JComboBox<String> courseBox = new JComboBox<>(Courses);
        courseBox.setBounds(240, 290, 100, 25);
        frame.add(courseBox);

        JButton btnSubmit = new JButton("Submit");
        btnSubmit.setEnabled(false);
        btnSubmit.setBounds(160, 380, 100, 30);
        frame.add(btnSubmit);

        JButton btnRemove = new JButton("Remove");
        btnRemove.setBounds(300, 380, 100, 30);
        frame.add(btnRemove);

        JLabel data = new JLabel();
        data.setBounds(200, 400, 400, 200);
        frame.add(data);

        JCheckBox agreeCheckBox = new JCheckBox("I Am Agree");
        agreeCheckBox.setBounds(120, 340, 100, 40);
        agreeCheckBox.addItemListener(new ItemListener() {
            public void itemStateChanged(ItemEvent e) {
                btnSubmit.setEnabled(agreeCheckBox.isSelected());
            }
        });
        frame.add(agreeCheckBox);

        btnRemove.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                txtUserName.setText("");
                txtUserNumber.setText("");
                txtAddress.setText("");
                chkboxGame.setSelected(false);
                chkboxMovie.setSelected(false);
                chkboxTravel.setSelected(false);
                bg.clearSelection();
                courseBox.setSelectedItem("select");
                agreeCheckBox.setSelected(false);
            }
        });

        btnSubmit.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                String name = txtUserName.getText();
                if (txtUserName.getText().equals("")) {
                    JOptionPane.showMessageDialog(frame, "Please enter your name");
                    txtUserName.requestFocus();
                    return;
                }
                String number = txtUserNumber.getText();
                if (txtUserNumber.getText().equals("")) {
                    JOptionPane.showMessageDialog(frame, "Please enter your number");
                    txtUserNumber.requestFocus();
                    return;
                }
                String address = txtAddress.getText();
                if (txtAddress.getText().equals("")) {
                    JOptionPane.showMessageDialog(frame, "Please enter your address");
                    txtAddress.requestFocus();
                    return;
                }
                String hobbes = "";
                if (chkboxGame.isSelected()) {
                    hobbes += "Game ";
                }
                if (chkboxMovie.isSelected()) {
                    hobbes += "Movie ";
                }
                if (chkboxTravel.isSelected()) {
                    hobbes += "Travel ";
                }
                if (hobbes.equals("")) {
                    JOptionPane.showMessageDialog(frame, "Please select at least one hobby");
                    chkboxGame.requestFocus();
                    return;
                }

                String gender = "";
                if (rbtnMale.isSelected()) {
                    gender = "Male";
                } else if (rbtnFemale.isSelected()) {
                    gender = "Female";
                } else {
                    gender = "";
                }
                if (gender.equals("")) {
                    JOptionPane.showMessageDialog(frame, "Please select your gender");
                    rbtnMale.requestFocus();
                    return;
                }

                String course = (String) courseBox.getSelectedItem();
                if (course.equals("select")) {
                    JOptionPane.showMessageDialog(frame, "Please select your course");
                    courseBox.requestFocus();
                    return;
                }

                data.setText("<html><h3>Student Details</h3><br><b>Name: </b>" + name + "<br><b>Number: </b>" + number
                        + "<br><b>Address: </b>" + address + "<br><b>Hobbes: </b>" + hobbes + "<br><b>Gender: </b>"
                        + gender + "<br><b>Course: </b>" + course + "</html>");

                btnRemove.doClick();
            }
        });

        frame.setVisible(true);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }
}