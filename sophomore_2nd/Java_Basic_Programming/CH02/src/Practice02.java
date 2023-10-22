import java.util.Scanner;

public class Practice02 {
	public static void main(String[] args) {
		System.out.print("몇 층인지 입력>>");
		Scanner scanner = new Scanner(System.in);
		
		int floor = scanner.nextInt();
		int height = floor*5;
		
		System.out.println(height+"m 이다.");
		
		scanner.close();
	}
}
