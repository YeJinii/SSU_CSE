import java.util.Scanner;

public class Practice03 {

	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		System.out.print("학점을 입력 >> ");
		String sGrade = sc.next(); //Scanner는 문자를 입력받는 함수가 존재하지 않아 String으로 받아야함
		
		char Grade = sGrade.charAt(0); //charAt(0) -> 문자열 중 첫번째 문자를 반환
		switch(Grade){
			case 'A' : case 'B' :
				System.out.println("Excellent");
				break;
			
			case 'C' : case 'D' :
				System.out.println("Good");
				break;
				
			case 'F' :
				System.out.println("Bye");
				break;
				
			default : 
				System.out.println("잘못된 입력입니다(학점 : A, B, C, D, F).");
				break;
				
		}
		
		sc.close();
		return ;

	}

}
