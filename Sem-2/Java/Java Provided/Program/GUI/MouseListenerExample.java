import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class MouseListenerExample extends JFrame implements MouseListener {

    JLabel label;

    public MouseListenerExample() {
        setTitle("Mouse Listener Example");
        setSize(400, 200);
        setLayout(null);
        setDefaultCloseOperation(EXIT_ON_CLOSE);

        label = new JLabel("", SwingConstants.CENTER);
        label.setBounds(100, 50, 200, 80);
        label.setOpaque(true);
        label.setBackground(Color.LIGHT_GRAY);
        label.setFont(new Font("Arial", Font.BOLD, 16));

        label.addMouseListener(this); // Add mouse listener
        add(label);

        setVisible(true);
    }

    // MouseListener methods
    public void mouseClicked(MouseEvent e) {
        label.setBackground(Color.YELLOW);
        label.setText("Mouse Clicked!");
    }

    public void mousePressed(MouseEvent e) {
        label.setBackground(Color.ORANGE);
        label.setText("Mouse Pressed");
    }

    public void mouseReleased(MouseEvent e) {
        label.setBackground(Color.GREEN);
        label.setText("Mouse Released");
    }

    public void mouseEntered(MouseEvent e) {
        label.setBackground(Color.CYAN);
        label.setText("Mouse Entered");
    }

  public void mouseExited(MouseEvent e) {
        label.setBackground(Color.LIGHT_GRAY);
        label.setText("Mouse Exited");
    }

    public static void main(String[] args) {
        new MouseListenerExample();
    }
}
