import javax.swing.*;
import java.awt.event.*;

public class BankApp extends JFrame {
    private static double balance = 1000.00; // Initial balance

    public BankApp() {
        setTitle("Simple Bank Application");
        setSize(400, 300);
        setDefaultCloseOperation(EXIT_ON_CLOSE);

        JMenuBar menuBar = new JMenuBar();
        JMenu menu = new JMenu("HDFC Bank");

        JMenuItem viewBalanceItem = new JMenuItem("View Balance");
        JMenuItem depositItem = new JMenuItem("Deposit");
        JMenuItem exitItem = new JMenuItem("Exit");

        // Use function instead of lambda
        viewBalanceItem.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                showBalance();
            }
        });

        // Deposit uses lambda for now, can be changed similarly
        depositItem.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                new DepositFrame(BankApp.this);
            }
        });

        exitItem.addActionListener(e -> System.exit(0));

        menu.add(viewBalanceItem);
        menu.add(depositItem);
        menu.add(exitItem);

        menuBar.add(menu);
        setJMenuBar(menuBar);
        setVisible(true);
    }

    private void showBalance() {
        new ViewBalanceFrame(balance);
    }

    public void deposit(double amount) {
        balance += amount;
        JOptionPane.showMessageDialog(this, "Amount Deposited Successfully!");
    }

    public static double getBalance() {
        return balance;
    }

    public static void main(String[] args) {
        new BankApp();
    }
}
