class Circle {
	private int radius;
	public Circle(int radius){ this.radius = radius;}
	public int getRadius(){ return radius; }
}

public class NamedCircle extends Circle{
	
	private String name;
	
	public NamedCircle(int radius, String name){
		super(radius);//부모 class의 생성자 호출
		this.name=name;
	}
	
	public void show(){
		System.out.println(name+", 반지름 = "+getRadius());
	}
	
	public static void main(String[] args) {
		NamedCircle w = new NamedCircle(5,"Waffle");
		w.show();
	}

}
