
public class Song {
	
	String title;
	
	String getTitle(){return title;}
	
	public Song(String title){
		this.title=title;
	}
	
	public static void main(String[] args) {
		Song mySong = new Song ("Nessun Dorma");
		Song yourSong = new Song ("���ִ� �� �� �̷��");
		System.out.println("�� �뷡�� "+mySong.getTitle());
		System.out.println("�� �뷡�� "+yourSong.getTitle());	
	}

}
