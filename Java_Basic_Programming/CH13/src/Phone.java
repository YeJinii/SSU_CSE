public interface Phone {
	final int TIME = 1000; // ������� �����ϴ� ������ ���������� �빮��
	void sendCall(); // �߻� �޼ҵ�	
	void receiveCall(); // �߻� �޼ҵ�
	default void printLogo(){ // ����Ʈ �޼ҵ�
		System.out.println("*** Phone ***");
	}
}
