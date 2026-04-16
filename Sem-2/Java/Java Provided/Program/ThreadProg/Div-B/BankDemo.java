class BankAccount {
    int balance = 1000;

     void deposit(int amount) {
        balance += amount;
        System.out.println("Deposited: " + amount);
        System.out.println("Balance: " + balance);
    }

    void withdraw(int amount) {
        if(balance >= amount) {
            balance -= amount;
            System.out.println("Withdrawn: " + amount);
            System.out.println("Balance: " + balance);
        } else {
            System.out.println("Insufficient Balance");
        }
    }
}

class DepositThread extends Thread {
    BankAccount acc;

    DepositThread(BankAccount acc) {
        this.acc = acc;
    }

    public void run() {
        acc.deposit(500);
    }
}

class WithdrawThread extends Thread {
    BankAccount acc;

    WithdrawThread(BankAccount acc) {
        this.acc = acc;
    }

    public void run() {
        acc.withdraw(700);
    }
}

public class BankDemo {
    public static void main(String[] args) {
        BankAccount account = new BankAccount();

        DepositThread t1 = new DepositThread(account);
        WithdrawThread t2 = new WithdrawThread(account);

        t1.start();
        t2.start();
    }
}