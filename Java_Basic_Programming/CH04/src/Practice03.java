import java.util.Scanner;

public class Practice03 {

	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		System.out.print("������ �Է� >> ");
		String sGrade = sc.next(); //Scanner�� ���ڸ� �Է¹޴� �Լ��� �������� �ʾ� String���� �޾ƾ���
		
		char Grade = sGrade.charAt(0); //charAt(0) -> ���ڿ� �� ù��° ���ڸ� ��ȯ
		switch(Grade){
			case 'A' : case 'B' :
				System.out.println("Excellent");
				break;
			
			case 'C' : case 'D' :
				System.out.println("Good");
				break;
				
			case 'F' :
				System.out.println("Bye");
				break;
				
			default : 
				System.out.println("�߸��� �Է��Դϴ�(���� : A, B, C, D, F).");
				break;
				
		}
		
		sc.close();
		return ;

	}

}
