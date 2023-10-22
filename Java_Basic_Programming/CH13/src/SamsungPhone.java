
public class SamsungPhone implements Phone {

	@Override
	public void sendCall() {
		// TODO Auto-generated method stub
		System.out.println("전화가 울린다.");
	}

	@Override
	public void receiveCall() {
		// TODO Auto-generated method stub
		System.out.println("전화를 받는다.");
	}
	
	public static void main(String[] args) {
		Phone s = new SamsungPhone();//나를 구현할수 있도록 해준 인터페이스
		s.printLogo();
		s.sendCall();
		s.receiveCall();
	}
	
}
