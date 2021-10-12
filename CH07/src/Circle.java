public class Circle { //속성 : 원의 이름, 반지름    메소드 : 원의 넓이를 구한다.
	
	int radius;
	String name;
	
	//메소드
	public void getArea() {
		System.out.println(this.name+"의 면적은 "+3.14*radius*radius);
	}

	public static void main(String[] args) {
		Circle c1 = new Circle();//인스턴스화 작업, c1,c2는 객체(인스턴스)
		c1.radius=10;
		c1.name="first_circle";
		c1.getArea();
		
		Circle c2 = new Circle();
		c2.radius=20;
		c2.name="second_circle";
		c2.getArea();
	}
}
