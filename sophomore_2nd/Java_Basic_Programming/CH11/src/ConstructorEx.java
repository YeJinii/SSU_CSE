class A {
	public A(){//������
		System.out.println("������ A ȣ��");
	}
	
	public A(int x){ // �̰� �ț��� ���� �⺻������ ���� ����
		System.out.println("�Ű������� �ִ� ������ A ȣ��");
	}
}

class B extends A{
	public B(){
		System.out.println("������ B ȣ��");
	}
	public B(int x){
		super(x);//�ݵ�� �ֻ�ܿ� �ۼ�
		System.out.println("�Ű������� �ִ� ������ B ȣ��");
	}
}

//class C extends B{
//	public C(){
//		System.out.println("������ C ȣ��");
//	}
//}

public class ConstructorEx {

	public static void main(String[] args) {
		
		//A->B->C ������ ���, �θ� ������ ������ ���� ȣ��
		//C c = new C();
		
		//B�� �Ű������� �ִ� �����ڰ� ȣ��ǰ�, A�� �⺻ �����ڰ� ȣ���(����Ŭ������ ������ ȣ��)
		B b = new B(5); 
	}

}
