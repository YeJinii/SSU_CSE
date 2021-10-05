import java.util.Scanner;

public class Practice02 {
	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		
		System.out.print("돈의 액수를 입력하세요. >> ");
		
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
		
		System.out.println("오만원"+fiftyThousand+"개, "
						 + "만원"+tenThousand+"개, "
						 + "천원"+oneThousand+"개, "
						 + "500원"+fiveHundred+"개, "
						 + "100원"+oneHundred+"개, "
						 + "10원"+ten+"개, "
						 + "1원"+one+"개");
		
		sc.close();
		return ;
		
	}
}
