import java.util.InputMismatchException;
import java.util.Scanner;

public class Practice01 {

	public static void main(String[] args) {
		
		System.out.print("������ �Է��ϼ��� >> ");
		Scanner sc = new Scanner(System.in);
		
		try{
			
			int n = sc.nextInt();
			if(n%2==0) System.out.println("¦��");
			else System.out.println("Ȧ��");
			
		}catch(InputMismatchException e){
			System.out.println("���� �Է����� �ʾ� ���α׷��� �����մϴ�.");
		}
		
		sc.close();
	}

}
