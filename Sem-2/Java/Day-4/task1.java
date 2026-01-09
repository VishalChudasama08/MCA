class task1{
    void display_attendance(){
        System.out.println("attendance");
    }
    int dissplay_cgpa(int c){
        System.out.println("C cgpa: " + c);
        return 0;
    }
    int dissplay_cgpa(float db){
        System.out.println("DBMS cgpa: " + db);
        return 0;
    }
    void dissplay_internalmarks(int c){
        System.out.println("C: " + c);
    }
    void dissplay_internalmarks(float db){
        System.out.println("DBMS" + db);
    }
    public static void main(String arg[]){
        task1 obj = new task1();
        obj.display_attendance();
        obj.dissplay_cgpa(9);
        obj.dissplay_cgpa(8.8f);
        obj.dissplay_internalmarks(9);
        obj.dissplay_internalmarks(8.8f);
    }
}