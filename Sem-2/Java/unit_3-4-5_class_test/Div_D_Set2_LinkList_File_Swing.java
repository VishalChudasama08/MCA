/*
 * A	 LinkedList + Random Access File [20 Marks]
Write a Java program to store and retrieve Book records using LinkedList (List Interface) and RandomAccessFile.
The program should perform the following:
  • Accept details of 4 books (Book ID: int, Title: String 20 chars, Price: double) from the user.
  • Store them in a LinkedList<Book> (create a Book class with constructor).
  • Write all records into 'books.dat' using RandomAccessFile in 'rw' mode.
      – Each record: 4 bytes (int) + 40 bytes (padded String) + 8 bytes (double) = 52 bytes.
  • Read and display a specific book record by its record number using seek().
  • Display all records by reading sequentially.
 */

/*
 * B	Swing – Temperature Converter [20 Marks]
Design a Temperature Converter application using Java Swing:
  • JTextField for entering the temperature value.
  • JComboBox for selecting conversion: Celsius to Fahrenheit, Celsius to Kelvin, Fahrenheit to Celsius, Fahrenheit to Kelvin.
  • JButton — 'Convert' and 'Clear'.
  • JLabel to display the converted result with proper unit.
  • JLabel to show error message for invalid input ('Please enter a valid number.').
  • On Convert → parse input, apply correct formula, display rounded result in result label.
  • On Clear → reset all fields.
  • Use FlowLayout with appropriate spacing.
 */

import java.util.*;
import java.io.*;
import javax.swing.*;
import java.awt.*;

class Book {
    int id;
    String title;
    double price;

    Book(int id,String t,double p){
        this.id=id; this.title=t; this.price=p;
    }
}

class Div_D_Set2_A {
    Div_D_Set2_A() throws Exception {
        Scanner sc=new Scanner(System.in);
        LinkedList<Book> list=new LinkedList<>();

        for(int i=0;i<4;i++){
            System.out.print("ID: "); int id=sc.nextInt();
            System.out.print("Title: "); String t=sc.next();
            System.out.print("Price: "); double p=sc.nextDouble();
            list.add(new Book(id,t,p));
        }

        RandomAccessFile raf=new RandomAccessFile("books.dat","rw");

        for(Book b:list){
            raf.writeInt(b.id);

            StringBuilder sb=new StringBuilder(b.title);
            while(sb.length()<20) sb.append(" ");
            raf.writeChars(sb.toString());

            raf.writeDouble(b.price);
        }

        raf.seek(0);

        while(raf.getFilePointer()<raf.length()){
            int id=raf.readInt();
            char[] t=new char[20];
            for(int i=0;i<20;i++) t[i]=raf.readChar();
            double p=raf.readDouble();

            System.out.println(id+" "+new String(t).trim()+" "+p);
        }

        raf.close();
    }
}

class Div_D_Set2_B {
    Div_D_Set2_B(){
        JFrame f=new JFrame("Temp Converter");
        f.setSize(300,200);
        f.setLayout(new FlowLayout());

        JTextField tf=new JTextField(10);

        String[] ops={
            "C to F","C to K","F to C","F to K"
        };

        JComboBox<String> cb=new JComboBox<>(ops);

        JButton convert=new JButton("Convert");
        JButton clear=new JButton("Clear");

        JLabel res=new JLabel("");
        JLabel err=new JLabel("");

        convert.addActionListener(e->{
            try{
                double v=Double.parseDouble(tf.getText());
                double r=0;

                switch(cb.getSelectedIndex()){
                    case 0: r=v*9/5+32; break;
                    case 1: r=v+273.15; break;
                    case 2: r=(v-32)*5/9; break;
                    case 3: r=(v-32)*5/9+273.15; break;
                }

                res.setText("Result: "+Math.round(r*100.0)/100.0);
                err.setText("");
            }catch(Exception ex){
                err.setText("Invalid number");
            }
        });

        clear.addActionListener(e->{
            tf.setText("");
            res.setText("");
            err.setText("");
        });

        f.add(tf); f.add(cb);
        f.add(convert); f.add(clear);
        f.add(res); f.add(err);

        f.setVisible(true);
        f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }
}

public class Div_D_Set2_LinkList_File_Swing {
    public static void main(String[] args) throws Exception {
        // new Div_D_Set2_A();
        new Div_D_Set2_B();
    }
}
