import java.util.*;
import java.io.*;
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

/*
 * A:-
 * Stack + Multithreading (Thread Class) [20 Marks]
	Write a Java program that simulates a Stack-based Task Manager using Multithreading.
	The program should perform the following:
	• Create a Stack<String> to hold task names.
	• Thread-1 (Producer): Accepts 5 task names from the user and pushes them into the Stack one by one with a 500ms delay between each push. Display a message on each push.
	• Thread-2 (Consumer): After Thread-1 completes, pops all tasks from the Stack one by one with a 700ms delay. Display the popped task name each time.
	• Use Thread class (extend Thread) for both threads.
	• Use thread.join() to ensure Thread-2 starts only after Thread-1 finishes.
	• Display the Stack contents before and after the Consumer thread runs.
 */

import java.util.Scanner;
import java.util.Stack;

class Producer extends Thread {
	private Stack<String> stack;

	public Producer(Stack<String> stack) {
		this.stack = stack;
	}

	public void run() {
		Scanner sc = new Scanner(System.in);

		try {
			for (int i = 1; i <= 5; i++) {
				System.out.print("Enter Task " + i + ": ");
				String task = sc.next();

				stack.push(task);
				System.out.println("Task pushed: " + task);

				Thread.sleep(500); // 500ms delay
			}
		} catch (InterruptedException e) {
			System.out.println(e);
		}
	}
}

class Consumer extends Thread {
	private Stack<String> stack;

	public Consumer(Stack<String> stack) {
		this.stack = stack;
	}

	public void run() {
		try {
			while (!stack.isEmpty()) {
				String task = stack.pop();
				System.out.println("Task popped: " + task);

				Thread.sleep(700); // 700ms delay
			}
		} catch (InterruptedException e) {
			System.out.println(e);
		}
	}
}

class Div_A_Set2_A {
	Div_A_Set2_A() {
		Stack<String> stack = new Stack<>();

		Producer p = new Producer(stack);
		Consumer c = new Consumer(stack);

		p.start();

		try {
			p.join();
		} catch (InterruptedException e) {
			System.out.println(e);
		}

		System.out.println("\nStack before Consumer: " + stack);

		c.start();

		try {
			c.join();
		} catch (InterruptedException e) {
			System.out.println(e);
		}

		System.out.println("\nStack after Consumer: " + stack);
	}
}

/*
 * B:-
 * Swing – Login Form [20 Marks]
 * Design a Student Grade Manager using Java Swing:
 * JTextField — enter student name
 * JTextField — enter marks (out of 100)
 * JButton — "Add Student" → validates input, calculates grade, adds to list
 * JTextArea (scrollable) — displays all students with their marks & grade
 * JButton — "Clear All" → clears the list
 * JLabel — shows class average at the bottom
 * Grade Logic:
 * 
 * 90–100 → A+, 80–89 → A, 70–79 → B, 60–69 → C, below 60 → F
 * Layout: GridLayout for the input form fields + BorderLayout for the overall
 * frame
 */

class Div_A_Set2_B {
	int totalMarks = 0;
	int studentCount = 0;

	Div_A_Set2_B() {
		JFrame frame = new JFrame("Student Grade Manager");
		frame.setSize(600, 500);
		frame.setLayout(new BorderLayout());

		JPanel inputPanel = new JPanel(new GridLayout(3, 2));
		JLabel nameLabel = new JLabel("Student Name:");
		JTextField nameField = new JTextField();
		JLabel marksLabel = new JLabel("Marks (out of 100):");
		JTextField marksField = new JTextField();
		JButton addButton = new JButton("Add Student");
		JButton clearButton = new JButton("Clear All");

		inputPanel.add(nameLabel);
		inputPanel.add(nameField);
		inputPanel.add(marksLabel);
		inputPanel.add(marksField);
		inputPanel.add(addButton);
		inputPanel.add(clearButton);

		JTextArea displayArea = new JTextArea();
		displayArea.setEditable(false);
		JScrollPane scrollPane = new JScrollPane(displayArea);

		JLabel averageLabel = new JLabel("Class Average: N/A");

		frame.add(inputPanel, BorderLayout.NORTH);
		frame.add(scrollPane, BorderLayout.CENTER);
		frame.add(averageLabel, BorderLayout.SOUTH);

		addButton.addActionListener(new ActionListener() {

			public void actionPerformed(ActionEvent e) {
				String name = nameField.getText();
				String marksText = marksField.getText();

				if (name.isEmpty() || marksText.isEmpty()) {
					JOptionPane.showMessageDialog(frame, "Please enter both name and marks.");
					return;
				}

				int marks = Integer.parseInt(marksText);
				if (marks < 0 || marks > 100) {
					JOptionPane.showMessageDialog(frame, "Please enter valid marks between 0 and 100.");
					return;
				}
				// try {
				// marks = Integer.parseInt(marksText);
				// if (marks < 0 || marks > 100) {
				// throw new NumberFormatException();
				// }
				// } catch (NumberFormatException ex) {
				// JOptionPane.showMessageDialog(frame, "Please enter valid marks between 0 and
				// 100.");
				// return;
				// }

				String grade;
				if (marks >= 90)
					grade = "A+";
				else if (marks >= 80)
					grade = "A";
				else if (marks >= 70)
					grade = "B";
				else if (marks >= 60)
					grade = "C";
				else
					grade = "F";

				displayArea.append(name + " - Marks: " + marks + ", Grade: " + grade + "\n");
				totalMarks += marks;
				studentCount++;
				averageLabel.setText("Class Average: " + (totalMarks / studentCount));
				nameField.setText("");
				marksField.setText("");
			}
		});

		clearButton.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				displayArea.setText("");
				totalMarks = 0;
				studentCount = 0;
				averageLabel.setText("Class Average: N/A");
			}
		});

		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.setVisible(true);
	}
}

public class Div_A_Set2_Stack_Multithreading_Swing {
	public static void main(String[] args) {
		// Div_A_Set2_A a = new Div_A_Set2_A();
		Div_A_Set2_B b = new Div_A_Set2_B();
	}
}
