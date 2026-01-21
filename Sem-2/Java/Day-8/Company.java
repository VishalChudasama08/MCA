class Company{
    String companyName = "outer";
    static class Department{
        String departmentName="inner";
        public void displayDetails(){
            System.out.println("\tDetails:-");
            System.out.println("\t\tCompany name: " + companyName);
            System.out.println("\t\tDepartment name: " + departmentName);
        }
    }
    public static void main(String arg[]){
        Company c = new Company();
        Company.Department d = new Department();
        d.displayDetails();
        System.out.println("\t\t name: " + d.departmentName);
    }
}