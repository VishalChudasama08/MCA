import java.util.*;

class BankAccount {
    private int balance = 1000;

    synchronized public void deposit(int amount) {
        balance += amount;
        System.out.println("Deposited: " + amount);
        System.out.println("Balance: " + balance);
    }

    synchronized public void withdraw(int amount){
        if(amount <= balance){
            // try {
            //     Thread.sleep(100);
            // } catch (Exception e){
            //     System.out.println(e);
            // }
            balance -= amount;
            System.out.println("Withdraw: " + amount);
            System.out.println("Balance: " + balance);
        } else {
            System.out.println("Insufficient Balance");
        }
    }
}

class DepositThread implements Runnable {
    BankAccount acc;
    int depositAmount;

    DepositThread(BankAccount acc, int amount){
        this.acc = acc;
        this.depositAmount = amount;
    }

    public void run(){
        acc.deposit(500);
    }
}

class WithdrawThread implements Runnable {
    BankAccount acc;
    int withdrawAmount;

    WithdrawThread(BankAccount acc, int withdrawAmount){
        this.acc = acc;
        this.withdrawAmount = withdrawAmount;
    }

    public void run(){
        acc.withdraw(withdrawAmount);
    }
}
class BankAccountDemo {
    public static void main(String [] args){

        Scanner scan = new Scanner(System.in);

        BankAccount account = new BankAccount();
        
        System.out.print("Enter amount for Deposit: ");
        int depositAmount = scan.nextInt();
        Thread dt = new Thread(new DepositThread(account, depositAmount));

        System.out.print("Enter amount for Withdraw: ");
        int withdrawAmount = scan.nextInt();
        Thread wt = new Thread(new WithdrawThread(account, withdrawAmount));

        dt.start();
        wt.start();
    } 
}