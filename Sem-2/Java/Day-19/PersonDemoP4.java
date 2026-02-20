// Unit-3 interfacesProgram.docx program-4

interface Tax{
    public double calculateTax(double income);
}
interface Insurance{
    public double calculateInsurance();
}
abstract class Person{
    String name;
    double income; 
    Person(String name, double income){
        this.name = name;
        this.income = income;
    }
    public abstract void display();
}
class SalariedPerson extends Person implements Tax, Insurance{
    SalariedPerson(String name, double income){
        super(name, income);
    }
    public void display(){
        System.out.println("\n\tSalaried Person Details => Name: " + name + " Income: " + income);
    }
    public double calculateTax(double income){
        return ((income*10)/100);
    }
    public double calculateInsurance(){
        return ((income*5)/100);
    }
}

class BusinessPerson extends Person implements Tax, Insurance{
    BusinessPerson(String name, double income){
        super(name, income);
    }
    public void display(){
        System.out.println("\n\tBusiness Person Details => Name: " + name + " Income: " + income);
    }
    public double calculateTax(double income){
        return ((income*15)/100);
    }
    public double calculateInsurance(){
        return ((income*8)/100);
    }
}

class PersonDemoP4{
    public static void main(String [] args){
        SalariedPerson sp = new SalariedPerson("vishal", 654321);
        sp.display();
        System.out.println("\n\tcalculated tax: " + sp.calculateTax(654321));
        System.out.println("\n\tinsurance amount: " + sp.calculateInsurance());

        BusinessPerson b = new BusinessPerson("vishal2", 987654);
        b.display();
        System.out.println("\n\tcalculated tax: " + b.calculateTax(987654));
        System.out.println("\n\tinsurance amount: " + b.calculateInsurance());
    }
}