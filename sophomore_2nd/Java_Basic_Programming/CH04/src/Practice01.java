import java.util.Scanner;

public class Practice01 {
	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		System.out.print("��(x,y)�� ��ǥ�� �Է��ϼ���. >> ");
		
		int x = sc.nextInt();
		int y = sc.nextInt();
		
		if((50<=x)&&(x<=100)&&(50<=y)&&(y<=100)) System.out.println("��("+x+','+y+")�� (50,50)�� (100,100)�� �簢�� ���� �ֽ��ϴ�.");
		else System.out.println("��("+x+','+y+")�� (50,50)�� (100,100)�� �簢�� ���� ���� �ʽ��ϴ�.");
		
		sc.close();
		return ;
	}
}
