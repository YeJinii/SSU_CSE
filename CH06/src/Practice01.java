import java.util.InputMismatchException;
import java.util.Scanner;

public class Practice01 {

	public static void main(String[] args) {
		
		System.out.print("정수를 입력하세요 >> ");
		Scanner sc = new Scanner(System.in);
		
		try{
			
			int n = sc.nextInt();
			if(n%2==0) System.out.println("짝수");
			else System.out.println("홀수");
			
		}catch(InputMismatchException e){
			System.out.println("수를 입력하지 않아 프로그램을 종료합니다.");
		}
		
		sc.close();
	}

}
