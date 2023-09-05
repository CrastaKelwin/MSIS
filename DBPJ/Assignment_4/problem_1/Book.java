import java.lang.*;

class Book {
    private String name;
    private double price;
    private Author author;
    private int quantity;

    public Book(String name, Author author, int price, int quantity) {
        this.author = author;
        this.name = name;
        this.price = price;
        this.quantity = quantity;
    }

    public Book(String name, Author author, int price) {
        this.author = author;
        this.name = name;
        this.price = price;
    }

    public String getName() {
        return this.name;
    }

    public Author getAuthor() {
        return this.author;
    }

    public double getPrice() {
        return this.price;
    }

    public void setPrice(double price) {
        this.price = price;
    }

    public void setQty(int qty) {
        this.quantity = qty;
    }

    public int getQty() {
        return this.quantity;
    }

    @Override
    public String toString() {
        return ("Book = " + this.name + ", Author[" + author.toString() + "], price = " + this.price + ", qty = "
                + this.quantity);
    }
}