import java.util.Scanner;

public class Practice04_2 {

	public static void main(String[] args) {
		
		System.out.print("커피 주문하세요 >> ");
		Scanner sc = new Scanner(System.in);
		
		String menu = sc.next();
		int cnt = sc.nextInt();
		
		switch(menu){
			case "에스프레소" :
				System.out.println(2000*cnt+"원 입니다.");
				break;
			
			case "아메리카노" :
				System.out.println(2500*cnt+"원 입니다.");
				break;
				
			case "카푸치노" :
				System.out.println(3000*cnt+"원 입니다.");
				break;
				
			case "카페라떼" :
				System.out.println(3500*cnt+"원 입니다.");
				break;
				
			default :
				System.out.println("존재하지 않는 메뉴입니다.");
				break;
		}
		
		sc.close();
		return ;

	}

}
