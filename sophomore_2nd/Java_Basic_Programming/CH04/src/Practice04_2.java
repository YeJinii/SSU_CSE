import java.util.Scanner;

public class Practice04_2 {

	public static void main(String[] args) {
		
		System.out.print("Ŀ�� �ֹ��ϼ��� >> ");
		Scanner sc = new Scanner(System.in);
		
		String menu = sc.next();
		int cnt = sc.nextInt();
		
		switch(menu){
			case "����������" :
				System.out.println(2000*cnt+"�� �Դϴ�.");
				break;
			
			case "�Ƹ޸�ī��" :
				System.out.println(2500*cnt+"�� �Դϴ�.");
				break;
				
			case "īǪġ��" :
				System.out.println(3000*cnt+"�� �Դϴ�.");
				break;
				
			case "ī���" :
				System.out.println(3500*cnt+"�� �Դϴ�.");
				break;
				
			default :
				System.out.println("�������� �ʴ� �޴��Դϴ�.");
				break;
		}
		
		sc.close();
		return ;

	}

}
