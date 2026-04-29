import java.util.*;
import java.io.*;

import javax.script.ScriptEngineManager;
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

/*
 * A:-
 * ArrayList + Iterator + Character Stream [20 Marks]
	Write a Java program to manage a Student Marks System using ArrayList (List Interface).
	The program should perform the following:
	• Accept details of 5 students (Name, Roll No, Marks out of 100) using Scanner.
	• Store them in an ArrayList<Student> (create a Student class with constructor).
	• Use an Iterator to traverse the list and write each student's record into 'marks.txt' using FileWriter and BufferedWriter (Character Stream).
	• Read the file back using FileReader and BufferedReader, display all records line by line.
	• Also display the count of students who scored above 70 while reading.
 */

class Student {
	private String name;
	private int rollNo;
	private int marks;

	public Student(String name, int rollNo, int marks) {
		this.name = name;
		this.rollNo = rollNo;
		this.marks = marks;
	}

	public String getName() {
		return name;
	}

	public int getRollNo() {
		return rollNo;
	}

	public int getMarks() {
		return marks;
	}
}

class Div_B_Set1_A {
	Div_B_Set1_A() {
		ArrayList<Student> students = new ArrayList<>();
		Scanner scanner = new Scanner(System.in);

		// 5 student details and store in ArrayList
		for (int i = 0; i < 5; i++) {
			System.out.print("Enter Student " + (i + 1) + " Name: ");
			String name = scanner.next();
			System.out.print("Enter Student " + (i + 1) + " Roll No: ");
			int rollNo = scanner.nextInt();
			System.out.print("Enter Student " + (i + 1) + " Marks: ");
			int marks = scanner.nextInt();

			students.add(new Student(name, rollNo, marks));
		}

		// Write to file using BufferedWriter
		try (BufferedWriter writer = new BufferedWriter(new FileWriter("marks.txt"))) {
			for (Student student : students) {
				writer.write(student.getName() + "\t" + student.getRollNo() + "\t" + student.getMarks());
				writer.newLine();
			}
		} catch (IOException e) {
			System.out.println(e);
		}

		// Read from file using BufferedReader
		int countAbove70 = 0;
		try (BufferedReader reader = new BufferedReader(new FileReader("marks.txt"))) {
			String line;
			while ((line = reader.readLine()) != null) {
				System.out.println(line);
				String[] parts = line.split("\t");
				int marks = Integer.parseInt(parts[2]);
				if (marks > 70) {
					countAbove70++;
				}
			}
			System.out.println("Number of students scoring above 70: " + countAbove70);
		} catch (IOException e) {
			System.out.println(e);
		}
	}
}

/*
 * B:-
 * Swing – Simple Calculator [20 Marks]
 * Design a Simple Calculator application using Java Swing:
 * • JTextField (non-editable) at the top to display input and result.
 * • Buttons arranged using GridLayout (4 rows x 4 columns): Digits 0–9,
 * Operators (+, -, *, /), '=' button to compute result, 'C' button to clear.
 * • Implement ActionListener on all buttons.
 * • On pressing '=' → evaluate the expression and show result in JTextField.
 * • On pressing 'C' → clear the JTextField.
 * • Handle division by zero with an appropriate error message.
 */

class Div_B_Set1_B {
	Div_B_Set1_B() {
		JFrame frame = new JFrame("Simple Calculator");
		frame.setSize(400, 500);
		frame.setLayout(new BorderLayout());

		JTextField displayField = new JTextField();
		displayField.setEditable(false);
		displayField.setFont(new Font("Arial", Font.BOLD, 24));
		frame.add(displayField, BorderLayout.NORTH);

		JPanel buttonPanel = new JPanel(new GridLayout(4, 4));
		String[] buttons = { "7", "8", "9", "/",
				"4", "5", "6", "*",
				"1", "2", "3", "-",
				"C", "0", "=", "+" };

		for (String text : buttons) {
			JButton button = new JButton(text);
			button.setFont(new Font("Arial", Font.BOLD, 20));
			buttonPanel.add(button);
			button.addActionListener(new ActionListener() {
				public void actionPerformed(ActionEvent e) {
					String command = e.getActionCommand();
					// displayField.setText(command);
					if (command.equals("C")) {
						displayField.setText("");
					} else if (command.equals("=")) {
						try {
							double result = ExpressionEvaluator.evaluate(displayField.getText());
							displayField.setText(String.valueOf(result));
						} catch (ArithmeticException ex) {
							displayField.setText("Error: Division by zero");
						} catch (Exception ex) {
							displayField.setText("Invalid Expression");
						}
					} else {
						displayField.setText(displayField.getText() + command);
					}
				}
			});
		}

		frame.add(buttonPanel, BorderLayout.CENTER);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.setVisible(true);
	}
}

class Div_B_Set1_ArrayList_File_Swing {
	public static void main(String[] args) {
		// new Div_B_Set1_A();
		new Div_B_Set1_B();
	}
}

class ExpressionEvaluator {

	// Method to evaluate full expression
	public static double evaluate(String expression) {
		Stack<Double> numbers = new Stack<>();
		Stack<Character> operators = new Stack<>();

		int i = 0;
		while (i < expression.length()) {
			char ch = expression.charAt(i);

			// Skip spaces
			if (ch == ' ') {
				i++;
				continue;
			}

			// If digit, read full number
			if (Character.isDigit(ch)) {
				StringBuilder sb = new StringBuilder();
				while (i < expression.length() &&
						(Character.isDigit(expression.charAt(i)) || expression.charAt(i) == '.')) {
					sb.append(expression.charAt(i));
					i++;
				}
				numbers.push(Double.parseDouble(sb.toString()));
				continue;
			}

			// If operator
			if (isOperator(ch)) {
				while (!operators.isEmpty() &&
						precedence(operators.peek()) >= precedence(ch)) {
					double b = numbers.pop();
					double a = numbers.pop();
					char op = operators.pop();
					numbers.push(applyOp(a, b, op));
				}
				operators.push(ch);
			}

			i++;
		}

		// Process remaining operators
		while (!operators.isEmpty()) {
			double b = numbers.pop();
			double a = numbers.pop();
			char op = operators.pop();
			numbers.push(applyOp(a, b, op));
		}

		return numbers.pop();
	}

	// Check operator
	private static boolean isOperator(char ch) {
		return ch == '+' || ch == '-' || ch == '*' || ch == '/';
	}

	// Operator precedence
	private static int precedence(char op) {
		if (op == '+' || op == '-')
			return 1;
		if (op == '*' || op == '/')
			return 2;
		return 0;
	}

	// Apply operation
	private static double applyOp(double a, double b, char op) {
		switch (op) {
			case '+':
				return a + b;
			case '-':
				return a - b;
			case '*':
				return a * b;
			case '/':
				if (b == 0)
					throw new ArithmeticException();
				return a / b;
		}
		return 0;
	}
}