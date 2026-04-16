import javax.swing.*;
import java.awt.event.*;

public class WindowListenerDemo extends JFrame implements WindowListener {

    JLabel label;

    public WindowListenerDemo() {
        setTitle("Window Listener Demo");
        setSize(400, 200);
        setLayout(null);
        setDefaultCloseOperation(JFrame.DO_NOTHING_ON_CLOSE); // So we can catch close event

        label = new JLabel("Perform a window action...", SwingConstants.CENTER);
        label.setBounds(50, 70, 300, 30);
        add(label);

        addWindowListener(this); // Attach window listener

        setVisible(true);
    }

    public void windowOpened(WindowEvent e) {
        label.setText("Window Opened");
    }

    public void windowClosing(WindowEvent e) {
        int result = JOptionPane.showConfirmDialog(this, "Are you sure to exit?", "Exit", JOptionPane.YES_NO_OPTION);
        if (result == JOptionPane.YES_OPTION) {
            dispose();
        }
    }

    public void windowClosed(WindowEvent e) {
        System.out.println("Window Closed");
    }

    public void windowIconified(WindowEvent e) {
        label.setText("Window Minimized");
    }

    public void windowDeiconified(WindowEvent e) {
        label.setText("Window Restored");
    }

    public void windowActivated(WindowEvent e) {
        label.setText("Window Activated");
    }

    public void windowDeactivated(WindowEvent e) {
        label.setText("Window Deactivated");
    }

    public static void main(String[] args) {
        new WindowListenerDemo();
    }
}
