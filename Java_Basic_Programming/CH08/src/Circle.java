
public class Circle {
	
	int radius;
	
	void set(int r){radius = r;}
	
	double getArea() {return 3.14*radius*radius;}
	
	//�ٸ� ���ڸ� ������ �ִ� ������ �Լ��� �ִ� ��� ������ �Լ��� default�� �������� �ʴ´�.
	public Circle(){}
			
	public Circle(int radius){//������
		this.radius=radius; //this -> Ŭ���� ��ü�� ����
	}
	
	public static void main(String[] args) {
		Circle pizza = new Circle();
		System.out.println(pizza.getArea());
		
		Circle donut = new Circle(5);
		System.out.println(donut.getArea());
	}

}
