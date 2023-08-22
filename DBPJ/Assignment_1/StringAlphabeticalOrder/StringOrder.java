import java.util.Scanner;
public class StringOrder{
	public static void main(String[] args){
	Scanner scanner = new Scanner(System.in);  // Create a Scanner object
	String str = scanner.next();
		char arr[] = str.toCharArray();
		System.out.println("String Size is " + arr.length);
		for (int i = 0; i < arr.length-1;i++ ) {
			for (int j = i+1; j < arr.length;j++ ) {
				if(arr[i] > arr[j])
				{
					char temp = arr[i]; 
					arr[i] = arr[j];
					arr[j] = temp;
				}
			}
		}
		System.out.println(arr);
	}
}