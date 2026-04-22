import javax.swing.*;
import java.awt.event.*;

public class BankMenu
{
    static double bal = 1000;

    public static void main(String[] args)
    {
        JFrame f = new JFrame("Bank Application");

        JMenuBar mb = new JMenuBar();
        JMenu menu = new JMenu("Transaction");

        JMenuItem deposit = new JMenuItem("Deposit");
        JMenuItem withdraw = new JMenuItem("Withdraw");
        JMenuItem balance = new JMenuItem("View Balance");
        JMenuItem exit = new JMenuItem("Exit");

        menu.add(deposit);
        menu.add(withdraw);
        menu.add(balance);
        menu.add(exit);

        mb.add(menu);
        f.setJMenuBar(mb);

        // ActionListener using inner class (no constructor)
        ActionListener al = new ActionListener()
        {
            public void actionPerformed(ActionEvent e)
            {
                if(e.getSource() == deposit)
                {
                    String amt = JOptionPane.showInputDialog("Enter deposit amount:");
                    double d = Double.parseDouble(amt);
                    bal = bal + d;
                    JOptionPane.showMessageDialog(null, "Deposited Successfully");
                }
                else if(e.getSource() == withdraw)
                {
                    String amt = JOptionPane.showInputDialog("Enter withdraw amount:");
                    double w = Double.parseDouble(amt);

                    if(w > bal)
                        JOptionPane.showMessageDialog(null, "Insufficient Balance");
                    else
                    {
                        bal = bal - w;
                        JOptionPane.showMessageDialog(null, "Withdraw Successful");
                    }
                }
                else if(e.getSource() == balance)
                {
                    JOptionPane.showMessageDialog(null, "Balance = " + bal);
                }
                else if(e.getSource() == exit)
                {
                    System.exit(0);
                }
            }
        };

        // register listener
        deposit.addActionListener(al);
        withdraw.addActionListener(al);
        balance.addActionListener(al);
        exit.addActionListener(al);

        f.setSize(400, 300);
        f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        f.setVisible(true);
    }
}