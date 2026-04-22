import javax.swing.*;

public class ViewBalanceFrame extends JFrame {
    public ViewBalanceFrame(double balance) {
        setTitle("Your Balance");
        setSize(250, 150);
        setDefaultCloseOperation(DISPOSE_ON_CLOSE);

        JLabel label = new JLabel("Current Balance: Rs." + balance);
        label.setHorizontalAlignment(SwingConstants.CENTER);

        add(label);
        setLocationRelativeTo(null);
        setVisible(true);
    }
}
