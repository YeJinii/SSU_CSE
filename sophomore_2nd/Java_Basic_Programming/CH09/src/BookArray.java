import java.util.Scanner;

public class BookArray {

	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		Book [] b = new Book[2];
		for(int i=0; i<b.length; i++){
			System.out.print("���� >> ");
			String title = sc.nextLine();
			System.out.print("���� >> ");
			String author = sc.nextLine();
			b[i] = new Book(title, author);
		}
		
		for(int i=0; i<b.length; i++) System.out.println(i+1+". "+b[i].title+"_"+b[i].author);
		
		sc.close();
	
	}

}
