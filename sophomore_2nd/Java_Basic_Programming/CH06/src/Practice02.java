import java.util.InputMismatchException;
import java.util.Scanner;

public class Practice02 {

	public static void main(String[] args) {
		
		char [] day = {'일', '월', '화', '수', '목', '금', '토'};
		
		Scanner sc = new Scanner(System.in);
		
		while(true){
			System.out.print("정수를 입력 >> ");
			try{
				int n = sc.nextInt();
				n %= day.length; //day.length = 7
				System.out.println(day[n]);
			}catch(InputMismatchException e){//정수가 아닌 값을 입력했을때
				sc.next();
				System.out.println("경고! 수를 입력하지 않았다.");
				continue;
			}catch(ArrayIndexOutOfBoundsException e){//음수 입력시
				System.out.println("프로그램을 종료합니다.");
				break;
			}
		}
		
		sc.close();

	}

}
