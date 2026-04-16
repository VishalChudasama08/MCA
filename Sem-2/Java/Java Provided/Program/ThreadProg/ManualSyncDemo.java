// A dedicated class that implements Runnable
class TransactionTask implements Runnable {
    private BankAccount account;
    private int amount;

    public TransactionTask(BankAccount account, int amount) {
        this.account = account;
        this.amount = amount;
    }

    @Override
    public void run() {
        account.withdraw(amount);
    }
}

public class ManualSyncDemo {
    public static void main(String[] args) {
        BankAccount sharedAccount = new BankAccount();

        // Create instances of the task class
        TransactionTask task1 = new TransactionTask(sharedAccount, 70);
        TransactionTask task2 = new TransactionTask(sharedAccount, 70);

        Thread t1 = new Thread(task1, "ATM-User");
        Thread t2 = new Thread(task2, "Online-BillPay");

        t1.start();
        t2.start();
    }
}