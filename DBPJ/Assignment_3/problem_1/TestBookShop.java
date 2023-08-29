import java.util.Scanner;

class TestBookShop {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the Number of Books");
        int size = sc.nextInt();
        Book books[] = new Book[size];
        for (int i = 0; i < books.length; i++) {
            System.out.println("Enter " + (i + 1) + " Book author");
            String author = sc.next();
            System.out.println("Enter " + (i + 1) + " Book title");
            String title = sc.next();
            System.out.println("Enter " + (i + 1) + " Book publisher");
            String publisher = sc.next();
            System.out.println("Enter " + (i + 1) + " Book stock");
            int stock = sc.nextInt();
            System.out.println("Enter " + (i + 1) + " Book price");
            double price = sc.nextDouble();
            books[i] = new Book(author, title, price, publisher, stock);
        }

        for (int i = 0; i < books.length; i++) {
            System.out.println("Book " + (i + 1) + " Details:");
            books[i].displayDetails();
        }

    }
}