
public class CallByValue {
	//ȣ���ڰ� �ǳ״� ���� �Ű� ������ ����Ǿ� ����. ������ ���� ������� ����
	public static void main(String[] args) {
		int n = 10;
		
		increase(n);
		
		System.out.println(n);

	}
	
	static void increase(int m){
		m = m + 1;
	}

}
