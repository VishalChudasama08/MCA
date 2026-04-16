import javax.swing.*;

public class StudentForm {
    public static void main(String[] args) {
        JFrame f = new JFrame("Student Form");

        JLabel l1 = new JLabel("Name:");
        JTextField t1 = new JTextField();

        JLabel l2 = new JLabel("Course:");
        JTextField t2 = new JTextField();

        JLabel l3 = new JLabel("Marks:");
        JTextField t3 = new JTextField();

        JButton b1 = new JButton("Save");

        l1.setBounds(50, 40, 100, 30);
        t1.setBounds(150, 40, 150, 30);

        l2.setBounds(50, 80, 100, 30);
        t2.setBounds(150, 80, 150, 30);

        l3.setBounds(50, 120, 100, 30);
        t3.setBounds(150, 120, 150, 30);

        

        f.add(l1); f.add(t1);
        f.add(l2); f.add(t2);
        f.add(l3); f.add(t3);
        f.add(b1);

		
		JCheckBox chkCricket=new JCheckBox("Cricket");
		JCheckBox chkFootball=new JCheckBox("Football");
		JCheckBox chkHockey=new JCheckBox("Hockey");
		JLabel lblhobby = new JLabel("Enter Hobby");
		f.add(lblhobby);
		f.add(chkCricket);
		f.add(chkFootball);
		f.add(chkHockey);
		f.add(lblhobby);
		lblhobby.setBounds(50, 180, 100, 30);
		chkCricket.setBounds(120, 180, 100, 30);
		chkFootball.setBounds(250, 180, 100, 30);
		chkHockey.setBounds(350, 180, 100, 30);
		
		
		JLabel lblgender = new JLabel("Select Gender");
		JRadioButton Male=new JRadioButton("Male",true);
		JRadioButton FeMale=new JRadioButton("FeMale",false);
		
		f.add(lblgender);
		f.add(Male);
		f.add(FeMale);
		
		ButtonGroup btngender = new ButtonGroup();
		btngender.add(Male);
		btngender.add(FeMale);
		
		lblgender.setBounds(50, 250, 100, 30);
		Male.setBounds(130, 250, 120, 30);
		FeMale.setBounds(250, 250, 120, 30);
		
		b1.setBounds(120, 400, 100, 30);
        f.setLayout(null);
        f.setSize(500, 500);
        f.setVisible(true);
        f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }
}