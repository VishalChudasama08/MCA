class Employee{
    String employeeName = " ";
    int employeeId = 0;
    Employee(String empName, int empId){
        employeeName = empName;
        employeeId = empId;
    }
    public void displayEmployeeDetails(){
        System.out.println("Name: " + employeeName + "\nId: " + employeeId);
    }
    public static void main(String arg[]){
        Employee e = new Employee("rohal", 15);
        e.displayEmployeeDetails();
    }
}