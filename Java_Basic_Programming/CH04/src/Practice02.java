import java.util.Scanner;

public class Practice02 {
	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		
		System.out.print("���� �׼��� �Է��ϼ���. >> ");
		
		int money = sc.nextInt();
		
		int fiftyThousand = 0, tenThousand = 0, oneThousand = 0,
			fiveHundred = 0, oneHundred = 0, ten = 0, one = 0;
		
		if(money>=50000){
			fiftyThousand = money/50000;
			money%=50000;
		}
		
		if(money>=10000){
			tenThousand = money/10000;
			money%=10000;
		}
		
		if(money>=1000){
			oneThousand = money/1000;
			money%=1000;
		}
		
		if(money>=500){
			fiveHundred = money/500;
			money%=500;
		}
		
		if(money>=100){
			oneHundred = money/100;
			money%=100;
		}
		
		if(money>=10){
			ten = money/10;
			money%=10;
		}
		
		if(money>=1){
			one = money;
		}
		
		System.out.println("������"+fiftyThousand+"��, "
						 + "����"+tenThousand+"��, "
						 + "õ��"+oneThousand+"��, "
						 + "500��"+fiveHundred+"��, "
						 + "100��"+oneHundred+"��, "
						 + "10��"+ten+"��, "
						 + "1��"+one+"��");
		
		sc.close();
		return ;
		
	}
}
