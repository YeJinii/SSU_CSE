public class Circle { //�Ӽ� : ���� �̸�, ������    �޼ҵ� : ���� ���̸� ���Ѵ�.
	
	int radius;
	String name;
	
	//�޼ҵ�
	public void getArea() {
		System.out.println(this.name+"�� ������ "+3.14*radius*radius);
	}

	public static void main(String[] args) {
		Circle c1 = new Circle();//�ν��Ͻ�ȭ �۾�, c1,c2�� ��ü(�ν��Ͻ�)
		c1.radius=10;
		c1.name="first_circle";
		c1.getArea();
		
		Circle c2 = new Circle();
		c2.radius=20;
		c2.name="second_circle";
		c2.getArea();
	}
}
