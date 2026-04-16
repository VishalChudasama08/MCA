class Account {
    int balance = 1000;

    void withdraw(int amount) {
        if (balance >= amount) {
            System.out.println(Thread.currentThread().getName() + " is withdrawing...");
            balance = balance - amount;
            System.out.println("Remaining balance: " + balance);
        } else {
            System.out.println("Insufficient balance");
        }
    }
}

class MyThread extends Thread {
    Account acc;

    MyThread(Account acc) {
        this.acc = acc;
    }

    public void run() {
        acc.withdraw(700);
    }
}

public class Test {
    public static void main(String[] args) {
        Account acc = new Account();

        MyThread t1 = new MyThread(acc);
        MyThread t2 = new MyThread(acc);

        t1.start();
        t2.start();
    }
}