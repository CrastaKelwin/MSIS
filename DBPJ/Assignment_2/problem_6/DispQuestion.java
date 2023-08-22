import java.util.*;

public class DispQuestion {
    public static void main(String[] args) {
        Random random = new Random();
        Scanner scanner = new Scanner(System.in);

        int a = random.nextInt();
        int b = random.nextInt();
        int remaining_attempts = 3;
        boolean chest_unlocked=false;
        do {
            System.out.println("Enter the Sum of " + a + " and " + b);
            int result = scanner.nextInt();
            if (result == a + b) {
                chest_unlocked =true;
                break;
            } else {
                System.out.println("Incorrect Answer. Please Try again\n" + remaining_attempts + " Attempts left");
            }
            remaining_attempts--;
        } while (remaining_attempts > 0);
        if(chest_unlocked==true)
        {
            System.out.println("Good");
            System.out.println("Yay.. You Won the challenge");
        }
        else
        {
            System.out.println("Oops!. You lost the challenge");
        }
        
    }

    static void PositiveToRightNegativeToLeft(int[] array) {
        Arrays.sort(array);

        System.out.println("Modified Array");
        for (int index = 0; index < array.length; index++) {
            System.out.println("[" + index + "] " + array[index]);
        }
    }

}