import java.util.Scanner;

public class Practice04_1 {

	public static void main(String[] args) {
		
		System.out.print("커피 주문하세요 >> ");
		Scanner sc = new Scanner(System.in);
		
		String menu = sc.next();
		int cnt = sc.nextInt();
		
		if("에스프레소".equals(menu)){
			System.out.println(2000*cnt+"원 입니다.");
		}else if("아메리카노".equals(menu)){
			System.out.println(2500*cnt+"원 입니다.");
		}else if("카푸치노".equals(menu)){
			System.out.println(3000*cnt+"원 입니다.");
		}else if("카페라떼".equals(menu)){
			System.out.println(3500*cnt+"원 입니다.");
		}else{
			System.out.println("존재하지 않는 메뉴입니다.");
		}
		
		sc.close();
		return ;

	}

}
