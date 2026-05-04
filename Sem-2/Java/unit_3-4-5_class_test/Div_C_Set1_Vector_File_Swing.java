/*
 * A	Vector + Collection Interface Methods + FileWriter [20 Marks]
Write a Java program to demonstrate Collection Interface methods using Vector combined with file writing.
The program should perform the following:
  • Create a Vector<String> and add 6 city names.
  • Demonstrate the following Collection interface methods with output: size(), isEmpty(), contains("Mumbai"), remove("Delhi"), toArray().
  • Use an enhanced for-loop to display remaining elements.
  • Write all remaining city names into a file 'cities.txt' using FileWriter.
  • Add 3 more cities using addAll(), display the updated Vector.
  • Use clear() to empty the Vector and verify with isEmpty().
 */


/*
 * B	Swing – Quiz Application [20 Marks]
Design a Simple Quiz Application using Java Swing with 3 multiple-choice questions (Java-based):
  • JLabel to display the question number and question text.
  • 4 JRadioButton options for each question (use ButtonGroup).
  • JButton — 'Next' and 'Submit'.
  • JLabel to display the final score after Submit is clicked.
  • Logic:
      – Store questions, options, and correct answers in arrays.
      – On 'Next' → validate selection, move to next question, update question and options.
      – On 'Submit' → calculate total score out of 3 and display it.
  • Use BorderLayout: question at NORTH, options at CENTER, buttons at SOUTH.
 */

import java.util.*;
import java.io.*;
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

class Div_C_Set1_A {
    Div_C_Set1_A() {
        Vector<String> cities = new Vector<>();

        cities.add("Ahmedabad");
        cities.add("Mumbai");
        cities.add("Delhi");
        cities.add("Surat");
        cities.add("Pune");
        cities.add("Jaipur");

        System.out.println("Size: " + cities.size());
        System.out.println("Is Empty: " + cities.isEmpty());
        System.out.println("Contains Mumbai: " + cities.contains("Mumbai"));

        cities.remove("Delhi");

        System.out.println("Array: " + Arrays.toString(cities.toArray()));

        for(String c : cities) {
            System.out.println(c);
        }

        try(FileWriter fw = new FileWriter("cities.txt")) {
            for(String c : cities) fw.write(c + "\n");
        } catch(Exception e) { }

        cities.addAll(Arrays.asList("Goa","Chennai","Kolkata"));
        System.out.println("Updated: " + cities);

        cities.clear();
        System.out.println("Empty after clear: " + cities.isEmpty());
    }
}

class Div_C_Set1_B {
    int index = 0, score = 0;

    String[] questions = {
        "What is JVM?",
        "Which is not OOP concept?",
        "Java is?"
    };

    String[][] options = {
        {"Java Virtual Machine","Java Vendor Machine","Just VM","None"},
        {"Encapsulation","Inheritance","Compilation","Polymorphism"},
        {"Platform Dependent","Platform Independent","OS","None"}
    };

    int[] answers = {0,2,1};

    Div_C_Set1_B() {
        JFrame f = new JFrame("Quiz");
        f.setSize(400,300);
        f.setLayout(new BorderLayout());

        JLabel q = new JLabel(questions[0]);

        JRadioButton o1 = new JRadioButton();
        JRadioButton o2 = new JRadioButton();
        JRadioButton o3 = new JRadioButton();
        JRadioButton o4 = new JRadioButton();

        ButtonGroup bg = new ButtonGroup();
        bg.add(o1); bg.add(o2); bg.add(o3); bg.add(o4);

        JPanel center = new JPanel(new GridLayout(4,1));
        center.add(o1); center.add(o2); center.add(o3); center.add(o4);

        JButton next = new JButton("Next");
        JButton submit = new JButton("Submit");

        JLabel result = new JLabel("");

        Runnable load = () -> {
            q.setText(questions[index]);
            o1.setText(options[index][0]);
            o2.setText(options[index][1]);
            o3.setText(options[index][2]);
            o4.setText(options[index][3]);
            bg.clearSelection();
        };

        load.run();

        next.addActionListener(e -> {
            int sel = o1.isSelected()?0:o2.isSelected()?1:o3.isSelected()?2:o4.isSelected()?3:-1;
            if(sel == answers[index]) score++;
            index++;
            if(index < 3) load.run();
        });

        submit.addActionListener(e -> {
            int sel = o1.isSelected()?0:o2.isSelected()?1:o3.isSelected()?2:o4.isSelected()?3:-1;
            if(sel == answers[index]) score++;
            result.setText("Score: " + score + "/3");
        });

        JPanel south = new JPanel();
        south.add(next); south.add(submit);

        f.add(q, BorderLayout.NORTH);
        f.add(center, BorderLayout.CENTER);
        f.add(south, BorderLayout.SOUTH);
        f.add(result, BorderLayout.EAST);

        f.setVisible(true);
        f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }
}

public class Div_C_Set1_Vector_File_Swing {
    public static void main(String[] args) {
        new Div_C_Set1_A();
        // new Div_C_Set1_B();
    }
}
