import java.util.Scanner;
public class MinutesToNumYears{
	public static void main(String[] args){
	Scanner scanner = new Scanner(System.in);  // Create a Scanner object
    do {
        System.out.println("Enter the Number of minutes");
        long mins = scanner.nextLong();
        CalculateYearsDays(mins);
        System.out.println("Press 'y' to continue any other key to exit.");
    }while(scanner.next().charAt(0)=='y');
   }
   static void CalculateYearsDays(Long mins)
   {
    
    int days = (int)((mins/60)/24);
    int years = (int)(days/365);
    System.out.println("Number of Years in "+ mins+ " Minutes are "+ years );
    System.out.println("Number of Days in "+mins+" Minutes are "+ days );
   }
}