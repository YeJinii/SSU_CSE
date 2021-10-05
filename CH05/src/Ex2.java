
public class Ex2 {
	public static void main(String[] args) {
		int intArray[] = new int[10];
		int sum=0;
		for(int i:intArray){
			intArray[i]=i;
			sum+=intArray[i];
		}
		System.out.println(sum);
	}
}
