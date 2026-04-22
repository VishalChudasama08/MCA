import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

class MenuBarDemo {
    public static void main(String [] args){
        JFrame f = new JFrame("MenuBar Demo");
        f.setSize(600,500);
       
        JMenuBar menubar = new JMenuBar();

        JMenu mFile = new JMenu("File");
        JMenu mEdit = new JMenu("Edit");

        JMenuItem miHey = new JMenuItem("Hello");
        miHey.addActionListener(new ActionListener(){
            public void actionPerformed(ActionEvent e){
                JOptionPane.showMessageDialog(f, "Hello! I Am JOptionPane class showMessageDialog method");
            }
        });

        JMenuItem miExit = new JMenuItem("Exit");
        miExit.addActionListener(new ActionListener(){
            public void actionPerformed(ActionEvent e){
                System.exit(0);
            }
        });

        JMenuItem miCopy = new JMenuItem("Copy");
        JMenuItem miCut = new JMenuItem("Cut");
        JMenuItem miPaste = new JMenuItem("Paste");

        mFile.add(miHey);
        mFile.add(miExit);

        mEdit.add(miCopy);
        mEdit.add(miCut);
        mEdit.add(miPaste);

        menubar.add(mFile);
        menubar.add(mEdit);

        f.add(menubar);

        f.setJMenuBar(menubar);


        f.setVisible(true);
        f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }
}