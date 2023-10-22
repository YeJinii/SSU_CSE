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
		//Circle �迭�� ���� ���۷��� c ����
		Circle [] c;
		//5���� ���۷��� �迭 ����
		c= new Circle[5];
		
		for(int i=0; i<c.length; i++){
			//i��° ���� ��ü ����
			c[i] = new Circle(i);
		}
		
		for(int i=0; i<c.length; i++){
			System.out.println((int)(c[i].getArea()) + " ");
		}
		
	}

}
