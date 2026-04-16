import javax.swing.*;
import java.awt.*;

public class AllLayoutDemo {
    public static void main(String[] args) {

        JFrame f = new JFrame("All Layout Demo");

        // Main layout of frame
        f.setLayout(new GridLayout(3, 1)); // 3 rows

        // ================= FLOW LAYOUT =================
        JPanel flowPanel = new JPanel();
        flowPanel.setBorder(BorderFactory.createTitledBorder("FlowLayout"));
        flowPanel.setLayout(new FlowLayout());

        flowPanel.add(new JButton("Button 1"));
        flowPanel.add(new JButton("Button 2"));
        flowPanel.add(new JButton("Button 3"));

        // ================= BORDER LAYOUT =================
        JPanel borderPanel = new JPanel();
        borderPanel.setBorder(BorderFactory.createTitledBorder("BorderLayout"));
        borderPanel.setLayout(new BorderLayout());

        borderPanel.add(new JButton("North"), BorderLayout.NORTH);
        borderPanel.add(new JButton("South"), BorderLayout.SOUTH);
        borderPanel.add(new JButton("East"), BorderLayout.EAST);
        borderPanel.add(new JButton("West"), BorderLayout.WEST);
        borderPanel.add(new JButton("Center"), BorderLayout.CENTER);

        // ================= GRID LAYOUT =================
        JPanel gridPanel = new JPanel();
        gridPanel.setBorder(BorderFactory.createTitledBorder("GridLayout"));
        gridPanel.setLayout(new GridLayout(2, 3)); // 2 rows, 3 columns

        for(int i = 1; i <= 6; i++) {
            gridPanel.add(new JButton("B" + i));
        }

        // Add all panels to frame
        //f.add(flowPanel);
		//f.add(borderPanel);
        f.add(gridPanel);

        // Frame settings
        f.setSize(500, 600);
        f.setVisible(true);
        f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }
}