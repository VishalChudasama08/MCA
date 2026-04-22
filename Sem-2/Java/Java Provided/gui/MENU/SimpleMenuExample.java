import javax.swing.*;
import java.awt.event.*;

public class SimpleMenuExample {
    public static void main(String[] args) {
        // Create a frame
        JFrame frame = new JFrame("JMenu Example");
        frame.setSize(400, 300);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        // Create a menu bar
        JMenuBar menuBar = new JMenuBar();

        // Create menus
        JMenu fileMenu = new JMenu("File");
        JMenu editMenu = new JMenu("Edit");

        // Create menu items
        JMenuItem newItem = new JMenuItem("New");
        JMenuItem openItem = new JMenuItem("Open");
        JMenuItem exitItem = new JMenuItem("Exit");

        JMenuItem cutItem = new JMenuItem("Cut");
        JMenuItem copyItem = new JMenuItem("Copy");
        JMenuItem pasteItem = new JMenuItem("Paste");

        // Add menu items to menus
        fileMenu.add(newItem);
        fileMenu.add(openItem);
        fileMenu.addSeparator(); // adds a separator line
        fileMenu.add(exitItem);

        editMenu.add(cutItem);
        editMenu.add(copyItem);
        editMenu.add(pasteItem);

        // Add menus to the menu bar
        menuBar.add(fileMenu);
        menuBar.add(editMenu);

        // Add menu bar to the frame
        frame.setJMenuBar(menuBar);

        // Action for Exit
        exitItem.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                System.exit(0); // exit program
            }
        });

        // Show the frame
        frame.setVisible(true);
    }
}
