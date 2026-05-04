/*
 * A	ArrayList + Thread Synchronization [20 Marks]
Write a Java program to demonstrate Thread Synchronization using a shared ArrayList.
The program should perform the following:
  • Create a shared ArrayList<String> accessible by multiple threads.
  • Create 3 threads — each thread adds 3 items (e.g., Thread-1 adds Task-A1, Task-A2, Task-A3).
  • Use a synchronized method addItem(String item) to safely add items, avoiding race conditions.
  • Each thread displays its name before and after adding items.
  • After all threads finish (use join()), display the final ArrayList contents using an Iterator.
  • Also display the total size of the ArrayList.
 */

/*
 * B	Swing – To-Do List Manager [20 Marks]
Design a To-Do List Manager application using Java Swing:

JTextField for entering a new task.
JButton — 'Add Task' and 'Clear All'.
JTextArea (non-editable) to display all added tasks, wrapped in JScrollPane.
JLabel showing total task count (e.g., 'Total Tasks: 3').
On 'Add Task' → append the task from JTextField into JTextArea with a serial number (e.g., 1. Buy Groceries), clear the JTextField, update the count in JLabel.
On 'Clear All' → clear the JTextArea completely and reset count to 0.
Use BorderLayout: input + button at NORTH, JTextArea at CENTER, count label at SOUTH.
Expected Design:
 */

import java.util.*;
import javax.swing.*;
import java.awt.*;

class SharedList {
    ArrayList<String> list = new ArrayList<>();

    synchronized void addItem(String item){
        list.add(item);
    }
}

class Worker extends Thread {
    SharedList s;
    String prefix;

    Worker(SharedList s,String p){
        this.s=s; this.prefix=p;
    }

    public void run(){
        System.out.println(getName()+" start");
        for(int i=1;i<=3;i++){
            s.addItem(prefix+i);
        }
        System.out.println(getName()+" end");
    }
}

class Div_D_Set1_A {
    Div_D_Set1_A() throws Exception {
        SharedList s = new SharedList();

        Worker t1 = new Worker(s,"A");
        Worker t2 = new Worker(s,"B");
        Worker t3 = new Worker(s,"C");

        t1.start(); t2.start(); t3.start();

        t1.join(); t2.join(); t3.join();

        Iterator<String> it = s.list.iterator();
        while(it.hasNext()){
            System.out.println(it.next());
        }

        System.out.println("Size: "+s.list.size());
    }
}

class Div_D_Set1_B {
    int count=0;

    Div_D_Set1_B(){
        JFrame f=new JFrame("ToDo");
        f.setSize(400,400);
        f.setLayout(new BorderLayout());

        JTextField tf=new JTextField();
        JButton add=new JButton("Add");
        JButton clear=new JButton("Clear");

        JTextArea area=new JTextArea();
        area.setEditable(false);

        JLabel lbl=new JLabel("Total: 0");

        JPanel top=new JPanel(new BorderLayout());
        top.add(tf,BorderLayout.CENTER);
        top.add(add,BorderLayout.EAST);

        add.addActionListener(e->{
            count++;
            area.append(count+". "+tf.getText()+"\n");
            tf.setText("");
            lbl.setText("Total: "+count);
        });

        clear.addActionListener(e->{
            area.setText("");
            count=0;
            lbl.setText("Total: 0");
        });

        JPanel btn=new JPanel();
        btn.add(clear);

        f.add(top,BorderLayout.NORTH);
        f.add(new JScrollPane(area),BorderLayout.CENTER);
        f.add(lbl,BorderLayout.SOUTH);
        f.add(btn,BorderLayout.WEST);

        f.setVisible(true);
        f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }
}

public class Div_D_Set1_ArrayList_Thread_Swing {
    public static void main(String[] args) throws Exception {
        // new Div_D_Set1_A();
        new Div_D_Set1_B();
    }
}
