import java.util.Scanner;

public class Practice02 {
	public static void main(String[] args) {
		System.out.print("�� ������ �Է�>>");
		Scanner scanner = new Scanner(System.in);
		
		int floor = scanner.nextInt();
		int height = floor*5;
		
		System.out.println(height+"m �̴�.");
		
		scanner.close();
	}
}
