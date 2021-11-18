class A {
	public A(){//생성자
		System.out.println("생성자 A 호출");
	}
	
	public A(int x){ // 이거 안썻을 때는 기본생성자 생략 가능
		System.out.println("매개변수가 있는 생성자 A 호출");
	}
}

class B extends A{
	public B(){
		System.out.println("생성자 B 호출");
	}
	public B(int x){
		super(x);//반드시 최상단에 작성
		System.out.println("매개변수가 있는 생성자 B 호출");
	}
}

//class C extends B{
//	public C(){
//		System.out.println("생성자 C 호출");
//	}
//}

public class ConstructorEx {

	public static void main(String[] args) {
		
		//A->B->C 순으로 상속, 부모 순으로 생성자 먼저 호출
		//C c = new C();
		
		//B는 매개변수가 있는 생성자가 호출되고, A는 기본 생성자가 호출됨(슈퍼클래스의 묵시적 호출)
		B b = new B(5); 
	}

}
