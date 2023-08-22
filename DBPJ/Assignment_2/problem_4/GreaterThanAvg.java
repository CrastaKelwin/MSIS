import java.util.*;

public class GreaterThanAvg {
    public static void main(String[] args) {
        Random random = new Random();
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter the Array size");
        int size = scanner.nextInt();
        if (size > 0) {
            int[] array = new int[size];
            for (int index = 0; index < array.length; index++) {
                array[index] = random.nextInt(500);
                System.out.println("[" + index + "] " + array[index]);
            }
            PrintGreaterThanAvg(array);
        }
    }

    static void PrintGreaterThanAvg(int[] array) {
        int sum = 0;
        for (int i = 0; i < array.length; i++) {
            sum += array[i];
        }
        int avg = sum / array.length;
        System.out.println("Elements Greater than avarage " +avg+" are");
        for (int index = 0; index < array.length; index++) {
            if (array[index] > avg) {
                System.out.println("[" + index + "] " + array[index]);
            }
        }
    }

}