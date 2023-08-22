import java.util.*;

public class Pos2RightNeg2Left {
    public static void main(String[] args) {
        Random random = new Random();
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter the Array size");
        int size = scanner.nextInt();
        if (size > 0) {
            int[] array = new int[size];
            for (int index = 0; index < array.length; index++) {
                array[index] = random.nextInt();
                System.out.println("[" + index + "] " + array[index]);
            }
            PositiveToRightNegativeToLeft(array);
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