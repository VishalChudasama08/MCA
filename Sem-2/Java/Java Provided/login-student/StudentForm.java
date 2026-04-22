import javax.swing.*;
import java.awt.event.*;

public class StudentForm extends JFrame implements ActionListener, ItemListener {
    JLabel nameLabel, genderLabel, hobbyLabel, courseLabel, outputLabel;
    JTextField nameField;
    JRadioButton maleButton, femaleButton;
    ButtonGroup genderGroup;
    JCheckBox hobbyReading, hobbySports, hobbyMusic, agreeCheckBox;
    JComboBox<String> courseBox;
    JButton submitButton;

    public StudentForm() {
        setTitle("Student Registration");
        setSize(400, 400);
        setLayout(null);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        // Initialize and position all components like you already have
        // Example:
        nameLabel = new JLabel("Name:");
        nameLabel.setBounds(20, 20, 100, 25);
        add(nameLabel);

        nameField = new JTextField();
        nameField.setBounds(120, 20, 200, 25);
        add(nameField);

        genderLabel = new JLabel("Gender:");
        genderLabel.setBounds(20, 60, 100, 25);
        add(genderLabel);

        maleButton = new JRadioButton("Male");
        maleButton.setBounds(120, 60, 80, 25);
        femaleButton = new JRadioButton("Female");
        femaleButton.setBounds(200, 60, 100, 25);

        genderGroup = new ButtonGroup();
        genderGroup.add(maleButton);
        genderGroup.add(femaleButton);

        add(maleButton);
        add(femaleButton);

        hobbyLabel = new JLabel("Hobbies:");
        hobbyLabel.setBounds(20, 100, 100, 25);
        add(hobbyLabel);

        hobbyReading = new JCheckBox("Reading");
        hobbyReading.setBounds(120, 100, 80, 25);
        hobbySports = new JCheckBox("Sports");
        hobbySports.setBounds(200, 100, 80, 25);
        hobbyMusic = new JCheckBox("Music");
        hobbyMusic.setBounds(280, 100, 80, 25);

        add(hobbyReading);
        add(hobbySports);
        add(hobbyMusic);

        courseLabel = new JLabel("Course:");
        courseLabel.setBounds(20, 140, 100, 25);
        add(courseLabel);

        String[] courses = {"Select", "BCA", "MCA", "B.Tech", "M.Tech"};
        courseBox = new JComboBox<>(courses);
        courseBox.setBounds(120, 140, 200, 25);
        add(courseBox);

        agreeCheckBox = new JCheckBox("I agree");
        agreeCheckBox.setBounds(120, 180, 100, 25);
        agreeCheckBox.addItemListener(this);
        add(agreeCheckBox);

        submitButton = new JButton("Submit");
        submitButton.setBounds(120, 220, 100, 30);
        submitButton.setEnabled(false);
        submitButton.addActionListener(this);
        add(submitButton);

        outputLabel = new JLabel();
        outputLabel.setBounds(20, 270, 350, 100);
        add(outputLabel);

        setVisible(true);
    }

    public void itemStateChanged(ItemEvent e) {
        submitButton.setEnabled(agreeCheckBox.isSelected());
    }

    public void actionPerformed(ActionEvent e) {
        String name = nameField.getText();
        String gender = maleButton.isSelected() ? "Male" : (femaleButton.isSelected() ? "Female" : "");
        String hobbies = "";
        if (hobbyReading.isSelected()) hobbies += "Reading ";
        if (hobbySports.isSelected()) hobbies += "Sports ";
        if (hobbyMusic.isSelected()) hobbies += "Music ";
        String course = (String) courseBox.getSelectedItem();

        outputLabel.setText("<html>Name: " + name + "<br>Gender: " + gender + "<br>Hobbies: " + hobbies + "<br>Course: " + course + "</html>");
    }
}
