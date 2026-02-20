interface College {

    interface Department {
        void deptName();//abstract method
    }
}

class MCA implements College.Department {

    public void deptName() {
        System.out.println("MCA Department");
    }

    
}
class NestedInterface
{
	public static void main(String[] args) {
        MCA m = new MCA();
        m.deptName();
    }
}