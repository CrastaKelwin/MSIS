import java.util.*;
public class FindDuplicates
{
    public static void main(String []args)
    {
        Random random = new Random();
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter the Array size");
        int size = scanner.nextInt();
        if(size>0)
        {
            int[] array = new int[size];
            for (int index = 0; index < array.length; index++) {
                array[index] = random.nextInt(500);
                System.out.println("["+index+"] "+array[index]);
            }
            CheckDuplicates(array);
        }
    }

    static void CheckDuplicates(int[] array)
    {
        for (int i = 0; i < array.length-1; i++) {
            for (int j = i+1; j < array.length; j++) {
                if(array[i]==array[j])
                {
                    System.out.println("Duplicate found "+array[i]);
                    return;
                }
            }
        }
        System.out.println("No Duplicates found");
    }
}