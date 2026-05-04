import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.io.*;

class LoginForm {
	LoginForm(JPanel panel){
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
                    JOptionPane.showMessageDialog(panel, "username and password are wrong");
                    result.setForeground(Color.RED);
                    result.setText("username and password are wrong");
                }
            }
        });
        btnCancel.addActionListener(new ActionListener(){
            public void actionPerformed(ActionEvent e){
                panel.removeAll();
				new HomePage(panel);
				panel.revalidate();
				panel.repaint();
			}
        });

        panel.add(lblLogin);
        panel.add(lblUserName);
        panel.add(txtUserName);
        panel.add(lblUserPassword);
        panel.add(txtUserPassword);
        panel.add(btnSubmit);
        panel.add(btnCancel);
        panel.add(result);
	}
}

class RegisterForm {
	RegisterForm(JPanel panel){
		JLabel lblDetail = new JLabel("Student Information");
        lblDetail.setBounds(210, 15, 250, 30);
        lblDetail.setFont(new Font("Cooper", Font.BOLD, 20));
        panel.add(lblDetail);

        JLabel lblUserName = new JLabel("Enter Your Name: ");
        lblUserName.setBounds(100, 60, 180, 30); // x,y,width,height
        JTextField txtUserName = new JTextField();
        txtUserName.setBounds(240, 65, 220, 25);
        panel.add(lblUserName);
        panel.add(txtUserName);

        JLabel lblUserNumber = new JLabel("Enter Your Number: ");
        lblUserNumber.setBounds(100, 100, 180, 30);
        JTextField txtUserNumber = new JTextField();
        txtUserNumber.setBounds(240, 105, 220, 25);
        panel.add(lblUserNumber);
        panel.add(txtUserNumber);

        JLabel lblAddress = new JLabel("Enter Your Address: ");
        lblAddress.setBounds(100, 140, 180, 30);
        JTextArea txtAddress = new JTextArea();
        JScrollPane scrollPanel = new JScrollPane(txtAddress);
        scrollPanel.setBounds(240, 145, 220, 60);
        panel.add(lblAddress);
        panel.add(scrollPanel);

        JLabel lblHobby = new JLabel("Your Hobbes: ");
        lblHobby.setBounds(100, 210, 180, 30);
        JCheckBox chkboxGame = new JCheckBox("Game");
        chkboxGame.setBounds(240, 215, 80, 25);
        JCheckBox chkboxMovie = new JCheckBox("Movie");
        chkboxMovie.setBounds(330, 215, 80, 25);
        JCheckBox chkboxTravel = new JCheckBox("Travel");
        chkboxTravel.setBounds(430, 215, 80, 25);
        panel.add(lblHobby);
        panel.add(chkboxGame);
        panel.add(chkboxMovie);
        panel.add(chkboxTravel);

        JLabel lblGender = new JLabel("Gender: ");
        lblGender.setBounds(100, 250, 180, 30);
        JRadioButton rbtnMale = new JRadioButton("Male");
        rbtnMale.setBounds(240, 255, 80, 25);
        JRadioButton rbtnFemale = new JRadioButton("Female");
        rbtnFemale.setBounds(330, 255, 80, 25);
        panel.add(lblGender);
        panel.add(rbtnMale);
        panel.add(rbtnFemale);
        ButtonGroup bg = new ButtonGroup();
        bg.add(rbtnMale);
        bg.add(rbtnFemale);

        JLabel lblCourse = new JLabel("Course: ");
        lblCourse.setBounds(100, 290, 180, 30);
        panel.add(lblCourse);

        String[] Courses = { "select", "BCA", "MCA", "iMCA", "B. Tech", "M. Tech" };
        JComboBox<String> courseBox = new JComboBox<>(Courses);
        courseBox.setBounds(240, 290, 100, 25);
        panel.add(courseBox);

        JButton btnSubmit = new JButton("Submit");
        btnSubmit.setEnabled(false);
        btnSubmit.setBounds(160, 380, 100, 30);
        panel.add(btnSubmit);

        JButton btnRemove = new JButton("Remove");
        btnRemove.setBounds(300, 380, 100, 30);
        panel.add(btnRemove);

        JLabel data = new JLabel();
        // JTextArea data = new JTextArea();
        data.setBounds(100, 420, 400, 200);
        panel.add(data);

        JCheckBox agreeCheckBox = new JCheckBox("I Am Agree");
        agreeCheckBox.setBounds(120, 340, 100, 40);
        agreeCheckBox.addItemListener(new ItemListener() {
            public void itemStateChanged(ItemEvent e) {
                btnSubmit.setEnabled(agreeCheckBox.isSelected());
            }
        });
        panel.add(agreeCheckBox);

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
                    JOptionPane.showMessageDialog(panel, "Please enter your name");
                    txtUserName.requestFocus();
                    return;
                }
                long number = 0;
                try {
                    number = Long.parseLong(txtUserNumber.getText());
                } catch (Exception ex){
                    JOptionPane.showMessageDialog(panel, "Please enter a valid number");
                    txtUserNumber.requestFocus();
                    return;
                }
                if (txtUserNumber.getText().equals("")) {
                    JOptionPane.showMessageDialog(panel, "Please enter your number");
                    txtUserNumber.requestFocus();
                    return;
                }
                String address = txtAddress.getText();
                if (txtAddress.getText().equals("")) {
                    JOptionPane.showMessageDialog(panel, "Please enter your address");
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
                    JOptionPane.showMessageDialog(panel, "Please select at least one hobby");
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
                    JOptionPane.showMessageDialog(panel, "Please select your gender");
                    rbtnMale.requestFocus();
                    return;
                }

                String course = (String) courseBox.getSelectedItem();
                if (course.equals("select")) {
                    JOptionPane.showMessageDialog(panel, "Please select your course");
                    courseBox.requestFocus();
                    return;
                }

                data.setText("<html><h3>Student Details</h3><br><b>Name: </b>" + name + "<br><b>Number: </b>" + number
                        + "<br><b>Address: </b>" + address + "<br><b>Hobbes: </b>" + hobbes + "<br><b>Gender: </b>"
                        + gender + "<br><b>Course: </b>" + course + "</html>");

                btnRemove.doClick();
            }
        });
	}
}

class HomePage {
	HomePage(JPanel panel){
		JLabel lblDetail = new JLabel("Home Page");
        lblDetail.setBounds(210, 15, 250, 30);
        lblDetail.setFont(new Font("Cooper", Font.BOLD, 20));
        panel.add(lblDetail);
	}
}

public class Login_Register_MenuBar {
	public static void main(String [] args){
		JFrame frame = new JFrame("Login Register with MenuBar");
		frame.setLayout(null);

		JPanel panel = new JPanel();
		panel.setLayout(null);
		panel.setBounds(0, 0, 650, 750);
		new HomePage(panel);

		JMenuBar menubar = new JMenuBar();

		JMenu forms = new JMenu("Forms");
		JMenuItem loginForm = new JMenuItem("Login Form");
		JMenuItem registerForm = new JMenuItem("Register Form");
		
		loginForm.addActionListener(new ActionListener(){
			public void actionPerformed(ActionEvent e){
				panel.removeAll();
				new LoginForm(panel);
				panel.revalidate();
        		panel.repaint();
			}
		});

		registerForm.addActionListener(new ActionListener(){
			public void actionPerformed(ActionEvent e){
				panel.removeAll();
				new RegisterForm(panel);
				panel.revalidate();
        		panel.repaint();
			}
		});

		JMenu options = new JMenu("Options");
		
		JMenuItem home = new JMenuItem("Home");
		JMenuItem logout = new JMenuItem("Logout");
		JMenuItem exit = new JMenuItem("Exit");

		home.addActionListener(new ActionListener(){
			public void actionPerformed(ActionEvent e){
				panel.removeAll();
				new HomePage(panel);
				panel.revalidate();
				panel.repaint();
			}
		});

		logout.addActionListener(new ActionListener(){
			public void actionPerformed(ActionEvent e){
				panel.removeAll();
				new LoginForm(panel);
				panel.revalidate();
        		panel.repaint();
			}
		});

		exit.addActionListener(new ActionListener(){
			public void actionPerformed(ActionEvent e){
				System.exit(0);
			}
		});
		
		forms.add(loginForm);
		forms.add(registerForm);
		options.add(home);
		options.add(logout);
		options.add(exit);
		
		menubar.add(forms);
		menubar.add(options);
		
		frame.add(menubar);
		frame.setJMenuBar(menubar);

		frame.add(panel);
		
		frame.setSize(650, 750);
		frame.setVisible(true);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	}
}
