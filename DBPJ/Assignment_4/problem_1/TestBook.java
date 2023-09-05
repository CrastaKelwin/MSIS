import java.util.*;
import java.lang.*;

class TestBook {
    public static void main(String[] args) {
        Author author = new Author("kpc", "kpc@abc.com", 'M');
        Book book = new Book("textbook", author, 10, 10);
        System.out.println(book);
        assert (book.getName().equals("textbook"));
        assert (book.getAuthor() == author);
        assert (book.getPrice() == 10);
        book.setPrice(100);
        assert (book.getPrice() == 100);
        assert (book.getQty() == 10);
        book.setQty(200);
        assert (book.getQty() == 200);
        System.out.println(book);
    }
}