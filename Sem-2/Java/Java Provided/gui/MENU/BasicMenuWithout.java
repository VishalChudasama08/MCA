import javax.swing.*;
import java.awt.event.*;

public class BasicMenuWithout  {
    public static void main(String[] args) {
        // Create a frame
        JFrame frame = new JFrame("Simple Menu Example");
        frame.setSize(300, 200);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		// Show the frame
        frame.setVisible(true);
        // Create a menu bar
        JMenuBar menuBar = new JMenuBar();

        // Create a menu
        JMenu fileMenu = new JMenu("File");

        // Create menu items
        JMenuItem helloItem = new JMenuItem("Say Hello");
        JMenuItem aboutItem = new JMenuItem("About");
        JMenuItem exitItem = new JMenuItem("Exit");

        // Add menu items to the menu
        fileMenu.add(helloItem);
        fileMenu.add(aboutItem);
        fileMenu.addSeparator();
        fileMenu.add(exitItem);
		//helloItem.addActionListener(this);

        // Add the menu to the menu bar
        menuBar.add(fileMenu);

        // Add the menu bar to the frame
        frame.setJMenuBar(menuBar);
		
		
		
		
				

        // Action for "Say Hello"
        helloItem.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                JOptionPane.showMessageDialog(frame, "Hello, Student!");
            }
        });

        // Action for "About"
        aboutItem.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                JOptionPane.showMessageDialog(frame, "Created by Your Name");
            }
        });

        // Action for "Exit"
        exitItem.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                System.exit(0);
            }
        });

        
    }
	
	
}
