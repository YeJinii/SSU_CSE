
public class ArrayException {

	public static void main(String[] args) {
		int [] intArray = {1,2,3,4};
		int i=0, sum=0;
		for(i=0; i<10; i++){
			try{ //프로그램 수행->문제점->문제점을 해결(예외처리 방법으로 문제점을 해결해주세요.)
				sum += intArray[i];
				System.out.println("인덱스 " + i + "까지의 합 = " +sum );
			}catch(ArrayIndexOutOfBoundsException e){
				System.out.println("배열의 요소를 다 더했으므로 프로그램을 종료합니다.");
				break;
			}
		}

	}

}
