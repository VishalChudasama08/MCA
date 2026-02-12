abstract class Bank{
    int accountNumber;
    String accountHolderName;
    int balance;
    final String bankName="ABC Bank"; 

    Bank(int accountNumber, String accountHolderName, int balance){
        this.accountNumber=accountNumber;
        this.accountHolderName=accountHolderName;
        this.balance=balance;
        System.out.println("Bank Name:"+ this.bankName);
        System.out.println("Account Number:"+ this.accountNumber);
        System.out.println("Account Holder:"+ this.accountHolderName);
    }
    void deposit(int amount){
        balance += amount;
        System.out.println("Deposit: "+ balance);
    }
    final void withdraw(int amount){
        balance -= amount;
        System.out.println("Withdraw: "+ balance);
    }
    abstract void calculateInterest();
}
class SavingsAccount extends Bank{
    int interestRate=1;
    SavingsAccount(int accountNumber, String accountHolderName, int balance){
        super(accountNumber, accountHolderName, balance);
    }
    void calculateInterest(){
        System.out.println("Interest for Savings Account:"+ (interestRate*balance)/100);
    }
}
class CurrentAccount extends Bank{
    int overdraftLimit=50;
    CurrentAccount(int accountNumber, String accountHolderName, int balance){
        super(accountNumber, accountHolderName, balance);
    }
    void calculateInterest(){
        System.out.println("Interest for Current Account: "+ (balance)/500);
    }
}

class BankAccount{
    public static void main(String [] arg){
        SavingsAccount sa = new SavingsAccount(101, "John", 10000);
        sa.deposit(5000);
        System.out.println("Balance after deposit: "+sa.balance);
        sa.withdraw(2000);
        System.out.println("Balance after withdrawal: "+sa.balance);
        sa.calculateInterest();

        System.out.println("-------------------------------------");

        CurrentAccount ca = new CurrentAccount(201, "Alice", 20000);
        ca.deposit(10000);
        System.out.println("Balance after deposit: "+ca.balance);
        ca.withdraw(5000);
        System.out.println("Balance after withdrawal: "+ca.balance);
        ca.calculateInterest();
    }
}

/*
private => only that class
protected => self and inherited
default => same folder 
public => all

*/