import javax.swing.*;
import java.awt.event.*;

public class DepositFrame extends JFrame {
    public DepositFrame(BankApp app) {
        setTitle("Deposit Money");
        setSize(300, 150);
        setDefaultCloseOperation(DISPOSE_ON_CLOSE);
        setLayout(null);

        JLabel label = new JLabel("Enter Amount: ");
        JTextField amountField = new JTextField();
        JButton depositBtn = new JButton("Deposit");

        label.setBounds(30, 20, 100, 25);
        amountField.setBounds(130, 20, 120, 25);
        depositBtn.setBounds(100, 60, 100, 30);

        depositBtn.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                try {
                    double amount = Double.parseDouble(amountField.getText());
                    if (amount > 0) {
                        app.deposit(amount);
                        dispose();
                    } else {
                        JOptionPane.showMessageDialog(DepositFrame.this, "Enter a positive amount.");
                    }
                } catch (NumberFormatException ex) {
                    JOptionPane.showMessageDialog(DepositFrame.this, "Invalid input!");
                }
            }
        });

        add(label);
        add(amountField);
        add(depositBtn);
        setLocationRelativeTo(null);
        setVisible(true);
    }
}
