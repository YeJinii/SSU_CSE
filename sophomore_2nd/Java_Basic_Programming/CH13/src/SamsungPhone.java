
public class SamsungPhone implements Phone {

	@Override
	public void sendCall() {
		// TODO Auto-generated method stub
		System.out.println("��ȭ�� �︰��.");
	}

	@Override
	public void receiveCall() {
		// TODO Auto-generated method stub
		System.out.println("��ȭ�� �޴´�.");
	}
	
	public static void main(String[] args) {
		Phone s = new SamsungPhone();//���� �����Ҽ� �ֵ��� ���� �������̽�
		s.printLogo();
		s.sendCall();
		s.receiveCall();
	}
	
}
