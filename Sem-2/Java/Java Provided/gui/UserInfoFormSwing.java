import javax.swing.*;
import java.awt.*;
class UserInfo extends JFrame
{
	UserInfo()
	{
		setSize(500,500);//Frame size
		setVisible(true);//make frame visible
		//setLayout(null);
		
		setTitle("User Information Form using Swing");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE); // Exit on close
		
		
		JLabel lblName =new JLabel("Enter Name");
		lblName.setBounds(50, 40, 100, 25);
		JTextField txtName = new JTextField(20);
		txtName.setBounds(160, 40, 200, 25);;
		add(lblName);
		add(txtName);
		
		//chkbox
		JLabel lblHobby = new JLabel("Hobby");
		JCheckBox chkCricket = new JCheckBox("Cricket");
		JCheckBox chkFootball = new JCheckBox("Football");
		JCheckBox chkHockey = new JCheckBox("Hockey");
		
		add(lblHobby);
		add(chkCricket);
		add(chkFootball);
		add(chkHockey);
		
		//CheckboxGroup
		
		JLabel lblGender = new JLabel("Gender");
		
		JRadioButton Male = new JRadioButton("Male",true);
		JRadioButton Female = new JRadioButton("Female",false);
		
		ButtonGroup genderGroup = new ButtonGroup();
        genderGroup.add(Male);
        genderGroup.add(Female);
        
		
		add(lblGender);
		add(Male);
		add(Female);
		
		
		JButton btnOk = new JButton ("OK");
		JButton btnCancel = new JButton ("Cancel");
		
		add(btnOk);
		add(btnCancel);
	}

}

public class UserInfoFormSwing
{
	public static void main(String args[])
	{
	UserInfo ui=new UserInfo();
	}
}