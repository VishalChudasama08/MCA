import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class MenuBarAccount {
    private static double balance = 1000;

    public static void main(String [] args){
        JFrame frame = new JFrame("Account Manage");
        frame.setSize(600,500);

        JMenuBar menuBar = new JMenuBar();

        JMenu mTrasection = new JMenu("Trasection");

        JMenuItem miDeposit = new JMenuItem("Deposit");
        miDeposit.addActionListener(new ActionListener(){
            public void actionPerformed(ActionEvent e){
                double deposit = Double.parseDouble(JOptionPane.showInputDialog(frame, "Enter Amount that you want to deposit: "));
                balance += deposit;
            }
        });
        JMenuItem miWithdrow = new JMenuItem("Withdrow");
        miWithdrow.addActionListener(new ActionListener(){
            public void actionPerformed(ActionEvent e){
                double withdraw = Double.parseDouble(JOptionPane.showInputDialog(frame, "Enter Amount that you want to withdraw: "));
                if(withdraw <= balance){
                    balance -= withdraw;
                } else {
                    JOptionPane.showMessageDialog(frame, "Insufficient Balance");
                }
            }
        });
        JMenuItem miViewBalance = new JMenuItem("View Balance");
        miViewBalance.addActionListener(new ActionListener(){
            public void actionPerformed(ActionEvent e){
                JOptionPane.showMessageDialog(frame, "Balanse: " + balance);
            }
        });
        JMenuItem miExit = new JMenuItem("Exit");
        miExit.addActionListener(new ActionListener(){
            public void actionPerformed(ActionEvent e){
                System.exit(0);
            }
        });

        mTrasection.add(miDeposit);
        mTrasection.addSeparator();
        mTrasection.add(miWithdrow);
        mTrasection.addSeparator();
        mTrasection.add(miViewBalance);
        mTrasection.addSeparator();
        mTrasection.add(miExit);

        menuBar.add(mTrasection);

        frame.add(menuBar);
        frame.setJMenuBar(menuBar);

        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setVisible(true);
    }
}