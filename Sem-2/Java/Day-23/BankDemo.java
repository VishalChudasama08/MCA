import java.util.*;

class InvalidTransactionException extends Exception {
    InvalidTransactionException(String msg){
        super(msg);
    }
}
interface Transaction {
    public void deposit(double amount) throws InvalidTransactionException;
    public void withdraw(double amount) throws InvalidTransactionException;
}
class Account {
    private int accountNumber;
    protected double balance;
    public String bankName = "National Bank";

    Account(int accountNumber, double balance){
        this.accountNumber = accountNumber;
        this.balance = balance;
    }

    public int getAccountNumber(){
        return accountNumber;
    }
    public double getBalance(){
        return balance;
    }
    public void setBalance(double balance){
        this.balance = balance;
    }
    public void displayAccount(){
        System.out.print("\n\tAccount Number: " + accountNumber);
        System.out.print("\n\tBalance: " + balance);
    }
}
class SavingsAccount extends Account implements Transaction {
    private double interestRate;

    SavingsAccount(int accountNumber, double balance, double interestRate){
        super(accountNumber, balance);
        this.interestRate = interestRate;
    }

    public void deposit(double amount) throws InvalidTransactionException {
        if (amount < 0){
            throw new InvalidTransactionException("Amount is grater then 0");
        } else {
            int total = getBalance() + amount;
            setBalance(total); 
            System.out.println("\n\tAmount deposit successfuly");
        }
    }

    public void withdraw(double amount) throws InvalidTransactionException{
        if (amount < 0 || amount > balance) {
            throw new InvalidTransactionException("Amount is grater then 0 or less then amount");
        } else {
            int total = getBalance() - amount;
            setBalance(total); 
            System.out.println("\n\tAmount withdraw successfuly");
        }
    }
}
class BankDemo {
    public static void main() {

    }
}