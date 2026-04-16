import javax.swing.*;
import java.awt.event.*;
import java.awt.*;

public class MenuWithItemListener {
    public static void main(String[] args) {
        JFrame frame = new JFrame("Menu with ItemListener");
        frame.setSize(300, 200);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        // Create menu bar and menu
        JMenuBar menuBar = new JMenuBar();
        JMenu settingsMenu = new JMenu("Settings");

        // Create a checkbox menu item
        JCheckBoxMenuItem darkModeItem = new JCheckBoxMenuItem("Dark Mode");

        // Add checkbox item to menu
        settingsMenu.add(darkModeItem);
        menuBar.add(settingsMenu);
        frame.setJMenuBar(menuBar);

        // Label to show current mode
        JLabel label = new JLabel("Light Mode", SwingConstants.CENTER);
        label.setFont(new Font("Arial", Font.BOLD, 16));
        frame.add(label);

        // Add ItemListener
        darkModeItem.addItemListener(new ItemListener() {
            public void itemStateChanged(ItemEvent e) {
                if (darkModeItem.isSelected()) {
                    label.setText("Dark Mode");
                    frame.getContentPane().setBackground(Color.DARK_GRAY);
                    label.setForeground(Color.WHITE);
                } else {
                    label.setText("Light Mode");
                    frame.getContentPane().setBackground(Color.WHITE);
                    label.setForeground(Color.BLACK);
                }
            }
        });

        frame.setVisible(true);
    }
}
