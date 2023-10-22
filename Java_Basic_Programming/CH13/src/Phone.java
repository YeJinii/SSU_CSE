public interface Phone {
	final int TIME = 1000; // 상수값을 저장하는 변수는 관례적으로 대문자
	void sendCall(); // 추상 메소드	
	void receiveCall(); // 추상 메소드
	default void printLogo(){ // 디폴트 메소드
		System.out.println("*** Phone ***");
	}
}
