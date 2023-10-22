import java.util.Scanner;

public class Practice01 {
	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		System.out.print("점(x,y)의 좌표를 입력하세요. >> ");
		
		int x = sc.nextInt();
		int y = sc.nextInt();
		
		if((50<=x)&&(x<=100)&&(50<=y)&&(y<=100)) System.out.println("점("+x+','+y+")은 (50,50)과 (100,100)의 사각형 내에 있습니다.");
		else System.out.println("점("+x+','+y+")은 (50,50)과 (100,100)의 사각형 내에 있지 않습니다.");
		
		sc.close();
		return ;
	}
}
