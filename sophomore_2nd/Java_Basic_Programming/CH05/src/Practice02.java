import java.util.Scanner;

public class Practice02 {

	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		int arr [] = new int [10];
		
		
		System.out.print("����10�� �Է� >> ");
		for(int i=0; i<10; i++){
			arr[i]=sc.nextInt();
		}
		
		for(int i=0; i<10; i++){
			if(arr[i]%3==0) System.out.print(arr[i]+" "); // arr[i]�ڿ� ' '�� ���ߴ��� �ƽ�Ű �ڵ� ���� ����
		}
		
		sc.close();
		
	}

}
