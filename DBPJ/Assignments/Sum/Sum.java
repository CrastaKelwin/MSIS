/* Third Program Sum of three inpt arguements*/

public class Sum{
	public static void main(String[] args){
		int sum=0;
		for (int i = 0; i < args.length;i++ ) {
			sum +=Integer.parseInt(args[i]);
		}
	System.out.println("Sum = "+ sum );
	}
}