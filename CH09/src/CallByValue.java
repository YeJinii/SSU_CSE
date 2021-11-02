
public class CallByValue {
	//호출자가 건네는 값이 매개 변수에 복사되어 전달. 실인자 값은 변경되지 않음
	public static void main(String[] args) {
		int n = 10;
		
		increase(n);
		
		System.out.println(n);

	}
	
	static void increase(int m){
		m = m + 1;
	}

}
