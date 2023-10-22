import java.util.Scanner;

public class Practice03 {
	public static void main(String[] args) {
		System.out.print("x 값을 입력하세요>>");
		Scanner scanner = new Scanner(System.in);
		
		int x = scanner.nextInt();
		int y = x*x - 3*x + 7;
		
		System.out.println("x="+x+", y="+y);
		
		scanner.close();
	}
}
