import java.util.Scanner;

public class Practice02 {

	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		int arr [] = new int [10];
		
		
		System.out.print("정수10개 입력 >> ");
		for(int i=0; i<10; i++){
			arr[i]=sc.nextInt();
		}
		
		for(int i=0; i<10; i++){
			if(arr[i]%3==0) System.out.print(arr[i]+" "); // arr[i]뒤에 ' '를 더했더니 아스키 코드 값이 나옴
		}
		
		sc.close();
		
	}

}
