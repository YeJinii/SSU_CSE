
public class ArrayException {

	public static void main(String[] args) {
		int [] intArray = {1,2,3,4};
		int i=0, sum=0;
		for(i=0; i<10; i++){
			try{ //���α׷� ����->������->�������� �ذ�(����ó�� ������� �������� �ذ����ּ���.)
				sum += intArray[i];
				System.out.println("�ε��� " + i + "������ �� = " +sum );
			}catch(ArrayIndexOutOfBoundsException e){
				System.out.println("�迭�� ��Ҹ� �� �������Ƿ� ���α׷��� �����մϴ�.");
				break;
			}
		}

	}

}
