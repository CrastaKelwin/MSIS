import java.util.*;

public class FindSmallest {
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
            System.out.println("enter k value");
            int k;
            k = scanner.nextInt();
            FindkthSmallestLargest(array, k);
        }
    }

    static void FindkthSmallestLargest(int[] array, int k) {
        if (array.length > k) {

            Arrays.sort(array);

            for (int index = 0; index < array.length; index++) {
                System.out.println("[" + index + "] " + array[index]);
            }
            System.out.println(k + "th smallest element is "+array[k]);
            System.out.println(k + "th largest element is "+ array[array.length - k-1]);
        }
    }
}