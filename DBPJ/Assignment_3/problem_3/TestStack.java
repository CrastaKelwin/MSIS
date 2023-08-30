import java.util.Scanner;

class TestStack {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the Size of stack");
        int size = sc.nextInt();
        Stack stack = new Stack(size);
        int task = 4;
        do {
            System.out.println("Enter the following function");
            System.out.println("1. push");
            System.out.println("2. pop");
            System.out.println("3. Display");
            System.out.println("4. Exit");
            task = sc.nextInt();
            switch (task) {
                case 1:
                    System.out.println("Enter data to push");
                    int data = sc.nextInt();
                    if (stack.push(data) == true) {
                        System.out.println("Data pushed Successfully.");
                    } else {
                        System.out.println("Stack is Already Full.");
                    }
                    break;
                case 2:
                    int p = stack.pop();
                    if (p != -1) {
                        System.out.println(p);
                    }
                    break;
                case 3:
                    stack.display();
                    break;
                case 4:
                    System.out.println("Exiting Application");
                    break;
                default:

                    System.out.println("Invalid Input");
                    break;

            }
        } while (task != 4);
    }
}