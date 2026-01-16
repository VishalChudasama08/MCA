class University{
    public void displayCollege(String collegeName){
        System.out.println("College: " + collegeName);
    }

    class Dept{
        public void displayDept(String deptName){
            System.out.println("Department: " + deptName);
        }

        class Division{
            public void displayDevision(String devisionName){
                System.out.println("Division: " + devisionName);
            }
        }
    }

    public static void main(String arg[]){
        University u = new University();
        Dept dept = u.new Dept();
        Dept.Division d = dept.new Division();

        u.displayCollege("LJ");
        dept.displayDept("MCA");
        d.displayDevision("A"); 
    }
}