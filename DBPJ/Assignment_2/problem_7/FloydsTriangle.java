import java.util.*;

public class FloydsTriangle {
    public static void main(String args[]) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter the number of rows");
        int rows = scanner.nextInt();
        int val = 1;
        for (int i = 1; i <= rows; i++) {
            int j = 0;
            for (j = 0; j < i; j++) {
                System.out.print(j + (val) + " ");
            }
            val += j;
            System.out.println();
        }

        
        int val2 = 1;
        for (int i = 1; i <= rows; i++) {
            int j = 0;
            for (j = 0; j < i; j++) {
                System.out.print(((j + val)&0x01)==0x01?0:1);
            }
            val += j;
            System.out.println();
        }
    }
}