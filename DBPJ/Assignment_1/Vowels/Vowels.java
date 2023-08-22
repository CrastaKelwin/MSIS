import java.util.Scanner;
public class Vowels{
	public static void main(String[] args){
	Scanner scanner = new Scanner(System.in);  // Create a Scanner object
	String str = scanner.next();
		char arr[] = str.toCharArray();
		int sum=0;
		for (int i = 0; i < arr.length;i++ ) {
			if(arr[i]=='a'||arr[i]=='A'||arr[i]=='e'||arr[i]=='E'||arr[i]=='i'||arr[i]=='I'||arr[i]=='o'||arr[i]=='O'||arr[i]=='u'||arr[i]=='U')
			{
				sum++;
			}
		}
	System.out.println("Number of Vowels = "+ sum );
	}
}