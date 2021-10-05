import java.util.Scanner;

public class Practice01 {
	public static void main(String[] args) {
		System.out.print("두 정수를 입력하세요>>");
		Scanner scanner = new Scanner(System.in);
		
		int a = scanner.nextInt();
		int b = scanner.nextInt();
		int sum = a+b;
		
		System.out.println(a+"+"+b+"="+sum);
		
		scanner.close();
	}
}
