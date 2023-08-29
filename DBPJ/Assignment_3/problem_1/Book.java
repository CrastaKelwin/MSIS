class Book {
    private String author;
    private String title;
    private double price;
    private String publisher;
    private int inStock;

    // default Constructor
    Book() {

    }

    Book(String author, String title, double price, String publisher, int inStock) {
        this.author = author;
        this.title = title;
        this.publisher = publisher;
        this.inStock = inStock;
        this.title = title;
    }

    public void setDetails(String author, String title, double price, String publisher, int inStock) {
        this.author = author;
        this.title = title;
        this.publisher = publisher;
        this.inStock = inStock;
        this.price = price;
    }

    public void displayDetails() {
        System.out.println("author\t\t:" + this.author);
        System.out.println("title\t\t:" + this.title);
        System.out.println("publisher\t:" + this.publisher);
        System.out.println("inStock\t\t:" + this.inStock);
        System.out.println("price\t\t:" + this.price);
    }

    public static int searchBookByAuthor(Book[] books, String author) {
        for (int i = 0; i < books.length; i++) {
            if (books[i].author == author) {
                return i;
            }
        }
        return -1;
    }

    public static int searchBookByTitle(Book[] books, String title) {
        for (int i = 0; i < books.length; i++) {
            if (books[i].title == title) {
                return true;
            }
        }
        return -1;
    }
}
