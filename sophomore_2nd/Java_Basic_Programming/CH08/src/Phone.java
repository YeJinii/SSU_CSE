import java.util.Scanner;

public class Phone {
	
	private String name, tel;
	
	public Phone(String name, String tel) {
		this.name=name;
		this.tel=tel;
	}
	
	public String getName() { return name; }
	public String getTel() { return tel; }
	
	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		
		String n1,n2; String p1,p2;
		
		System.out.print("이름과 전화번호 입력 >>");
		n1=sc.next(); p1=sc.next();
		Phone info1 = new Phone(n1, p1);
		
		System.out.print("이름과 전화번호 입력 >>");
		n2=sc.next(); p2=sc.next();
		Phone info2 = new Phone(n2, p2);
		
		System.out.println(info1.getName()+"의 번호 "+info1.getTel());
		System.out.println(info2.getName()+"의 번호 "+info2.getTel());
		
		sc.close();		

	}

}
