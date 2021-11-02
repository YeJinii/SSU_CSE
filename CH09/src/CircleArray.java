class Circle {
	int radius;
	public Circle(int radius) {
		this.radius = radius;
	}
	public double getArea(){
		return 3.14*radius*radius;
	}
}
public class CircleArray {

	public static void main(String[] args) {
		//Circle 배열에 대한 레퍼런스 c 선언
		Circle [] c;
		//5개의 레퍼런스 배열 생성
		c= new Circle[5];
		
		for(int i=0; i<c.length; i++){
			//i번째 원소 객체 생성
			c[i] = new Circle(i);
		}
		
		for(int i=0; i<c.length; i++){
			System.out.println((int)(c[i].getArea()) + " ");
		}
		
	}

}
