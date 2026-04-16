class BankAccount {
    private int balance = 100;

    // The 'synchronized' keyword ensures only one thread 
    // can execute this method at a time.
    public synchronized void withdraw(int amount) {
        String name = Thread.currentThread().getName();
        
        if (balance >= amount) {
            System.out.println(name + " is about to withdraw...");
            try {
                Thread.sleep(1000); // Simulating processing time
            } catch (InterruptedException e) {}
            
            balance -= amount;
            System.out.println(name + " finished. Remaining balance: $" + balance);
        } else {
            System.out.println(name + " - Insufficient funds! Balance: $" + balance);
        }
    }
}

public class SyncDemo {
    public static void main(String[] args) {
        BankAccount account = new BankAccount();

        // Two people (threads) using the same account
        Thread user1 = new Thread(() -> account.withdraw(70), "ATM-User");
        Thread user2 = new Thread(() -> account.withdraw(70), "Online-BillPay");

        user1.start();
        user2.start();
    }
}

/*
() -> is a Lambda Expression.

Introduced in Java 8, it is a short way to represent an anonymous function (a function without a name). It allows you to treat "code as data"—passing a block of logic directly into a method or constructor without the boilerplate of creating a whole new class.*/