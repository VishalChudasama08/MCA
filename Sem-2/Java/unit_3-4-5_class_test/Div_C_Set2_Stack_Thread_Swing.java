/*
 * A	Stack + Runnable Interface (Multithreading) [20 Marks]
Write a Java program to demonstrate a Shared Stack with two threads using the Runnable interface.
The program should perform the following:
  • Create a Stack<Integer> shared between two threads.
  • Thread-1 (Writer): Implements Runnable — pushes numbers 1 to 5 into the Stack with a 400ms delay between each push.
  • Thread-2 (Reader): Implements Runnable — after a 2-second initial sleep, peeks and pops all elements with a 600ms delay.
  • Start both threads using Thread constructor with Runnable object.
  • Display thread name with each push/pop using Thread.currentThread().getName().
  • After both threads complete, display 'Stack is now empty: ' with the result of isEmpty().
 */

/*
 * B	Swing – Color Theme Changer [20 Marks]
Design a Color Theme Changer application using Java Swing:
  • JLabel at the top displaying 'Select a Theme'.
  • JComboBox with 5 color themes: Default (White), Ocean Blue, Sunset Orange, Forest Green, Lavender.
  • A large JPanel (center area) that changes its background color based on the selected theme.
  • JButton — 'Apply Theme' to apply the selected color.
  • JButton — 'Reset' to restore the panel to white background.
  • JLabel at the bottom displaying the currently applied theme name.
  • On selecting from JComboBox and clicking Apply → update JPanel background and bottom JLabel.
  • Use BorderLayout for overall arrangement.
 */

import java.util.*;
import javax.swing.*;
import java.awt.*;

class Writer implements Runnable {
    Stack<Integer> s;
    Writer(Stack<Integer> s){ this.s=s; }

    public void run() {
        try {
            for(int i=1;i<=5;i++){
                s.push(i);
                System.out.println(Thread.currentThread().getName()+" push "+i);
                Thread.sleep(400);
            }
        } catch(Exception e){}
    }
}

class Reader implements Runnable {
    Stack<Integer> s;
    Reader(Stack<Integer> s){ this.s=s; }

    public void run() {
        try {
            Thread.sleep(2000);
            while(!s.isEmpty()){
                System.out.println(Thread.currentThread().getName()+" pop "+s.pop());
                Thread.sleep(600);
            }
        } catch(Exception e){}
    }
}

class Div_C_Set2_A {
    Div_C_Set2_A() throws Exception {
        Stack<Integer> s = new Stack<>();

        Thread t1 = new Thread(new Writer(s),"Writer");
        Thread t2 = new Thread(new Reader(s),"Reader");

        t1.start();
        t2.start();

        t1.join();
        t2.join();

        System.out.println("Stack empty: "+s.isEmpty());
    }
}

class Div_C_Set2_B {
    Div_C_Set2_B(){
        JFrame f = new JFrame("Theme");
        f.setSize(400,300);
        f.setLayout(new BorderLayout());

        JLabel top = new JLabel("Select Theme");
        JPanel center = new JPanel();
        JLabel bottom = new JLabel("Default");

        String[] themes = {"White","Blue","Orange","Green","Lavender"};
        JComboBox<String> cb = new JComboBox<>(themes);

        JButton apply = new JButton("Apply");
        JButton reset = new JButton("Reset");

        apply.addActionListener(e->{
            String t=(String)cb.getSelectedItem();
            switch(t){
                case "Blue": center.setBackground(Color.BLUE); break;
                case "Orange": center.setBackground(Color.ORANGE); break;
                case "Green": center.setBackground(Color.GREEN); break;
                case "Lavender": center.setBackground(new Color(230,230,250)); break;
                default: center.setBackground(Color.WHITE);
            }
            bottom.setText("Theme: "+t);
        });

        reset.addActionListener(e->{
            center.setBackground(Color.WHITE);
            bottom.setText("Default");
        });

        JPanel south = new JPanel();
        south.add(cb); south.add(apply); south.add(reset);

        f.add(top,BorderLayout.NORTH);
        f.add(center,BorderLayout.CENTER);
        f.add(south,BorderLayout.SOUTH);
        f.add(bottom,BorderLayout.WEST);

        f.setVisible(true);
        f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }
}

public class Div_C_Set2_Stack_Thread_Swing {
    public static void main(String[] args) throws Exception {
        // new Div_C_Set2_A();
        new Div_C_Set2_B();
    }
}
