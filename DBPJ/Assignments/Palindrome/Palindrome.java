import java.util.Scanner;
public class Palindrome{
	public static void main(String[] args){
	Scanner scanner = new Scanner(System.in);  // Create a Scanner object
	String str = scanner.next();
		char arr[] = str.toCharArray();
		char res[] = str.toCharArray();
		System.out.println("String Size is " + arr.length);
		boolean isPalindrome = true;;
		for (int i = 0; i < arr.length ;i++ ) {
			if(res[i] != arr[arr.length -1- i])
			{
				isPalindrome =false;
			}
		}
		if(isPalindrome)
		{
			System.out.println("palindrome");
		}else{
			System.out.println("not palindrome");
		}
	} 
}