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

        int task = 4;
        do {
            System.out.println("Enter the following function");
            System.out.println("1. Search Book by title");
            System.out.println("2. Search Book by Author");
            System.out.println("3. Search Book by title and Author");
            System.out.println("4. Display");
            System.out.println("5. Exit");
            task = sc.nextInt();
            switch (task) {
                case 1:
                    System.out.println("Enter Book title to search");
                    String search_title = sc.next();
                    System.out.print("Book with title " + search_title);
                    int book_idx = Book.searchBookByTitle(books, search_title);
                    if (book_idx >= 0) {
                        System.out.println(" exist");
                        books[book_idx].displayDetails();
                        System.out.println("Enter the number of copies required");
                        int copies_req = sc.nextInt();
                        if (books[book_idx].getStock() < copies_req) {
                            System.out.println("Required copies not in stock");
                        } else {
                            System.out.println(
                                    "Total Cost of the Request copies = " + (books[book_idx].getPrice() * copies_req));
                        }

                    } else {
                        System.out.println(" does not exist");
                    }

                    break;
                case 2: {
                    System.out.println("Enter Book author to search");
                    String search_author = sc.next();
                    System.out.print("Book with author " + search_author);
                    int book_index = Book.searchBookByAuthor(books, search_author);
                    if (book_index >= 0) {
                        System.out.println(" exist");
                        books[book_index].displayDetails();
                        System.out.println("Enter the number of copies required");
                        int copies_req = sc.nextInt();
                        if (books[book_index].getStock() < copies_req) {
                            System.out.println("Required copies not in stock");
                        } else {
                            System.out.println("Total Cost of the Request copies = "
                                    + (books[book_index].getPrice() * copies_req));
                        }
                    } else {
                        System.out.println(" does not exist");
                    }
                }
                    break;

                case 3:
                    System.out.println("Enter Book author to search");
                    String search_author = sc.next();
                    System.out.print("Book with author " + search_author);
                    System.out.println("Enter Book title to search");
                    search_title = sc.next();
                    System.out.print("Book with title " + search_title);
                    Boolean book_not_found = true;
                    for (int i = 0; i < books.length; i++) {
                        if (books[i].isAuthorEqual(search_author) && books[i].isTitleEqual(search_title)) {
                            book_not_found = false;
                            System.out.println("Book Found");
                            books[i].displayDetails();
                            System.out.println("Enter the number of copies required");
                            int copies_req = sc.nextInt();
                            if (books[i].getStock() < copies_req) {
                                System.out.println("Required copies not in stock");
                            } else {
                                System.out.println("Total Cost of the Request copies = "
                                        + (books[i].getPrice() * copies_req));
                            }
                            break;
                        }
                    }
                    if (book_not_found) {
                        System.out.println("Book does not exist");
                    }
                    break;

                case 4:
                    for (int i = 0; i < books.length; i++) {
                        System.out.println("Book " + (i + 1) + " Details:");
                        books[i].displayDetails();
                    }
                    break;
                case 5:
                    System.out.println("Exiting Application");
                    break;
                default:

                    System.out.println("Invalid Input");
                    break;

            }
        } while (task != 5);

    }
}