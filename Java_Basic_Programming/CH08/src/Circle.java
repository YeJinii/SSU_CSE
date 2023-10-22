
public class Circle {
	
	int radius;
	
	void set(int r){radius = r;}
	
	double getArea() {return 3.14*radius*radius;}
	
	//다른 인자를 가지고 있는 생성자 함수가 있는 경우 생성자 함수가 default로 생성되지 않는다.
	public Circle(){}
			
	public Circle(int radius){//생성자
		this.radius=radius; //this -> 클래스 자체의 변수
	}
	
	public static void main(String[] args) {
		Circle pizza = new Circle();
		System.out.println(pizza.getArea());
		
		Circle donut = new Circle(5);
		System.out.println(donut.getArea());
	}

}
