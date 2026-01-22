class Library{
    String libraryName="LJ Library";
    class Book{
        String bookTitle="JAVA";
        String authName="Jonsh";
        public void displayDetails(){
            System.out.println(libraryName + " Book Details ");
            System.out.println("\t\tTitle: " + bookTitle);
            System.out.println("\t\tAuther: " + authName);
        }
    }
    public static void main(String arg[]){
        Library l = new Library();
        Library.Book b = l.new Book();
        b.displayDetails();
    }
}