class Book{
    
    String title;

    Book(String title) {
        this.title = title;
    }

    @Override
    public boolean equals(Object obj){
        
        Book b = (Book) obj;
        return this.title.equals(b.title);
    }

    public static void main(String[] args) {
        Book b1 = new Book("Java");
        Book b2 = new Book("Java");

        System.out.println(b1.equals(b2)); // true
    }
}