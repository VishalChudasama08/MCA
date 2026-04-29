import java.util.*;
import java.io.*;
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

class Employee {
	private int id;
	private String name;
	private double salary;

	public Employee(int id, String name, double salary) {
		this.id = id;
		this.name = name;
		this.salary = salary;
	}

	public int getId() {
		return id;
	}

	public String getName() {
		return name;
	}

	public double getSalary() {
		return salary;
	}
}

/*
 * A:-
 * Vector + File I/O (Byte Stream) [20 Marks]
 * Write a Java program to build an Employee Record System using Vector
 * (Collection Framework).
 * The program should perform the following:
 * • Accept details of 4 employees (Employee ID, Name, Salary) from the user
 * using Scanner.
 * • Store all employee objects in a Vector.
 * • Use an Iterator to traverse the Vector and write each employee's details
 * into a text file named 'employees.txt' using FileOutputStream and
 * DataOutputStream (Byte Stream).
 * • Read back the file content using FileInputStream and DataInputStream and
 * display it on the console.
 * • Handle FileNotFoundException and IOException using try-catch block.
 */

class Div_A_Set1_A {
	Div_A_Set1_A() {
		Vector<Employee> employees = new Vector<>();
		Scanner scanner = new Scanner(System.in);

		// 4 employee details and store in Vector
		for (int i = 0; i < 4; i++) {
			System.out.print("Enter Employee " + (i + 1) + " ID: ");
			int id = scanner.nextInt();
			System.out.print("Enter Employee " + (i + 1) + " Name: ");
			String name = scanner.next();
			System.out.print("Enter Employee " + (i + 1) + " Salary: ");
			double salary = scanner.nextDouble();

			employees.add(new Employee(id, name, salary));
		}

		// Write employee details to 'employees.txt'
		try (DataOutputStream dos = new DataOutputStream(new FileOutputStream("employees.txt"))) {
			for (Employee emp : employees) {
				dos.writeInt(emp.getId());
				dos.writeUTF(emp.getName());
				dos.writeDouble(emp.getSalary());
			}
		} catch (IOException e) {
			e.printStackTrace();
		}

		// Read file and display
		try (DataInputStream dis = new DataInputStream(new FileInputStream("employees.txt"))) {
			System.out.println("Employee Details:");
			while (dis.available() > 0) {
				int id = dis.readInt();
				String name = dis.readUTF();
				double salary = dis.readDouble();
				System.out.println("ID: " + id + ", Name: " + name + ", Salary: " + salary);
			}
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
}

/*
 * B:-
 * Swing – Student Registration Form [20 Marks]
 * Design a Student Registration Form using Java Swing with the following
 * components:
 * • JTextField for Student Name and Roll Number.
 * • JRadioButton for Gender selection (Male / Female) — use ButtonGroup.
 * • JComboBox for Division selection (A, B, C, D, E).
 * • JButton — 'Register' and 'Clear'.
 * • On clicking Register → display all entered details in a JTextArea below the
 * form.
 * • On clicking Clear → reset all fields to their default/empty state.
 * • Use GridLayout for form fields arrangement inside a JFrame.
 * (Covers: JFrame, JLabel, JTextField, JRadioButton, JComboBox, JTextArea,
 * JButton, GridLayout, ActionListener)
 */

class Div_A_Set1_B {
	Div_A_Set1_B() {
		JFrame frame = new JFrame("Student Registration Form");
		frame.setSize(600, 500);
		frame.setLayout(null);

		JLabel nameLabel = new JLabel("Student Name:");
		nameLabel.setBounds(100, 20, 100, 25);
		JTextField nameField = new JTextField();
		nameField.setBounds(230, 20, 200, 25);
		JLabel rollLabel = new JLabel("Roll Number:");
		rollLabel.setBounds(100, 50, 100, 25);
		JTextField rollField = new JTextField();
		rollField.setBounds(230, 50, 200, 25);

		JLabel genderLabel = new JLabel("Gender:");
		genderLabel.setBounds(100, 80, 100, 25);
		JRadioButton maleButton = new JRadioButton("Male");
		maleButton.setBounds(230, 80, 80, 25);
		JRadioButton femaleButton = new JRadioButton("Female");
		femaleButton.setBounds(310, 80, 80, 25);
		ButtonGroup genderGroup = new ButtonGroup();
		genderGroup.add(maleButton);
		genderGroup.add(femaleButton);

		JLabel divisionLabel = new JLabel("Division:");
		divisionLabel.setBounds(100, 110, 100, 25);
		String[] divisions = { "select", "A", "B", "C", "D", "E" };
		JComboBox<String> divisionCombo = new JComboBox<>(divisions);
		divisionCombo.setBounds(230, 110, 200, 25);

		JButton registerButton = new JButton("Register");
		registerButton.setBounds(200, 160, 100, 25);
		JButton clearButton = new JButton("Clear");
		clearButton.setBounds(310, 160, 100, 25);

		JTextArea outputArea = new JTextArea();
		outputArea.setBounds(100, 200, 360, 100);

		registerButton.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				String name = nameField.getText();
				String roll = rollField.getText();
				String gender = maleButton.isSelected() ? "Male"
						: (femaleButton.isSelected() ? "Female" : "Not Selected");
				String division = (String) divisionCombo.getSelectedItem();

				outputArea.setText(
						"Name: " + name + "\nRoll Number: " + roll + "\nGender: " + gender + "\nDivision: " + division);
			}
		});

		clearButton.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				nameField.setText("");
				rollField.setText("");
				genderGroup.clearSelection();
				divisionCombo.setSelectedIndex(0);
				outputArea.setText("");
			}
		});

		frame.add(nameLabel);
		frame.add(nameField);
		frame.add(rollLabel);
		frame.add(rollField);
		frame.add(genderLabel);
		frame.add(maleButton);
		frame.add(femaleButton);
		frame.add(divisionLabel);
		frame.add(divisionCombo);
		frame.add(registerButton);
		frame.add(clearButton);
		frame.add(outputArea);

		frame.setVisible(true);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	}
}

class Div_A_Set1_Vector_File_Swing {
	public static void main(String[] args) {
		Div_A_Set1_A a = new Div_A_Set1_A();
		Div_A_Set1_B b = new Div_A_Set1_B();
	}
}