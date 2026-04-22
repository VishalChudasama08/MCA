import javax.swing.*;
import java.awt.event.*;

public class BankMenuSimple {

    static double balance = 1000;   // ✅ simple variable

    public static void main(String[] args) {

        JFrame frame = new JFrame("Bank App");

        JMenuBar menuBar = new JMenuBar();
        JMenu menu = new JMenu("Bank");

        JMenuItem depositItem = new JMenuItem("Deposit");
        JMenuItem withdrawItem = new JMenuItem("Withdraw");
        JMenuItem balanceItem = new JMenuItem("Show Balance");
        JMenuItem exitItem = new JMenuItem("Exit");

        // Add menu items
        menu.add(depositItem);
        menu.add(withdrawItem);
        menu.add(balanceItem);
        menu.addSeparator();
        menu.add(exitItem);

        menuBar.add(menu);
        frame.setJMenuBar(menuBar);

        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        // Deposit
        depositItem.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                String input = JOptionPane.showInputDialog("Enter amount:");
                double amt = Double.parseDouble(input);
                balance += amt;
                JOptionPane.showMessageDialog(frame, "Deposited!\nBalance: " + balance);
            }
        });

        // Withdraw
        withdrawItem.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                String input = JOptionPane.showInputDialog("Enter amount:");
                double amt = Double.parseDouble(input);

                if (amt <= balance) {
                    balance -= amt;
                    JOptionPane.showMessageDialog(frame, "Withdrawn!\nBalance: " + balance);
                } else {
                    JOptionPane.showMessageDialog(frame, "Insufficient Balance!");
                }
            }
        });

        // Show Balance
        balanceItem.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                JOptionPane.showMessageDialog(frame, "Balance: " + balance);
            }
        });

        // Exit
        exitItem.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                System.exit(0);
            }
        });

        frame.setSize(400, 300);
        frame.setVisible(true);
    }
}