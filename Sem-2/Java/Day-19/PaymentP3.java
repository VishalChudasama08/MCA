interface Payment{
    public void pay(double amount);
}
abstract class Transaction{
    public abstract void transactionDetails(); 
}

class CreditCard extends Transaction implements Payment{
    String cardNumber;
    CreditCard(){}
    CreditCard(String cardNumber){
        this.cardNumber = cardNumber;
    }
    public void transactionDetails(){
        System.out.println("Payment through Credit Card ");
    }
    public void pay(double amount){
        System.out.println("CreditCard paid amount " + amount);
    }
}
class UPI extends Transaction implements Payment{
    String upiId;
    UPI(){}
    UPI(String upiId){
        this.upiId = upiId;
    }
    public void transactionDetails(){
        System.out.println("Payment through UPI ");
    }
    public void pay(double amount){
        System.out.println("UPI paid amount " + amount);
    }
}

class PaymentP3{
    public static void main(String [] args){
        CreditCard c = new CreditCard("321");
        c.transactionDetails();
        c.pay(123);

        UPI u = new UPI("654");
        u.transactionDetails();
        u.pay(456);
    }
}