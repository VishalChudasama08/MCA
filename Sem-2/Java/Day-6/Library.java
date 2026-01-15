class Library{
    static String libraryName = "LJLib";
    static String libraianName = "pravin";
    static String time = "09:30am to 5:00pm";

    Library(){
        System.out.println("Library Name: " + Library.libraryName + ", libraian name: " + Library.libraianName + ", time: " + Library.time);
    }

    public static void bookcategory(String cat){
        System.out.println("Book category: " + cat);
    }
    public static void libraryrules(int bid, String bname, String category){
        System.out.println("Book ID: " + bid + ", Name: " + bname + ", Category: " + category);
    }
    public void bookdetails(int sid, String sname, int ssem, String issuedate){
        System.out.println("Student ID: " + sid + ", Sem: " + ssem + ", book issedate: " + issuedate);
    }
    public static void main(String arg[]){
        Library lib = new Library();
        bookcategory("technical"); // technical, novel, stoty
        libraryrules(234, "Java", "technical");
        lib.bookdetails(8, "Vishal", 2, "13/1/2025 10:30am");
    }
}