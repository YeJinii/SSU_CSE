import java.util.InputMismatchException;
import java.util.Scanner;

public class Practice02 {

	public static void main(String[] args) {
		
		char [] day = {'��', '��', 'ȭ', '��', '��', '��', '��'};
		
		Scanner sc = new Scanner(System.in);
		
		while(true){
			System.out.print("������ �Է� >> ");
			try{
				int n = sc.nextInt();
				n %= day.length; //day.length = 7
				System.out.println(day[n]);
			}catch(InputMismatchException e){//������ �ƴ� ���� �Է�������
				sc.next();
				System.out.println("���! ���� �Է����� �ʾҴ�.");
				continue;
			}catch(ArrayIndexOutOfBoundsException e){//���� �Է½�
				System.out.println("���α׷��� �����մϴ�.");
				break;
			}
		}
		
		sc.close();

	}

}
