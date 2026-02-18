interface College {

    interface Department {
        void deptName();
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