import java.util.Scanner;

public class Practice04_1 {

	public static void main(String[] args) {
		
		System.out.print("Ŀ�� �ֹ��ϼ��� >> ");
		Scanner sc = new Scanner(System.in);
		
		String menu = sc.next();
		int cnt = sc.nextInt();
		
		if("����������".equals(menu)){
			System.out.println(2000*cnt+"�� �Դϴ�.");
		}else if("�Ƹ޸�ī��".equals(menu)){
			System.out.println(2500*cnt+"�� �Դϴ�.");
		}else if("īǪġ��".equals(menu)){
			System.out.println(3000*cnt+"�� �Դϴ�.");
		}else if("ī���".equals(menu)){
			System.out.println(3500*cnt+"�� �Դϴ�.");
		}else{
			System.out.println("�������� �ʴ� �޴��Դϴ�.");
		}
		
		sc.close();
		return ;

	}

}
