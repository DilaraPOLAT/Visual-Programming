package FinalOdevi;
import java.util.ArrayList;
import java.util.List;

public class Kursiyer {
	private int kursiyerId ;
	private String kursiyerAdSoyad;
	private int kursiyerYas;
	
	public ArrayList<Kurs> alinanKurslar;
	
	public Kursiyer(int kursiyerId, String kursiyerAdSoyad, int kursiyerYas) {
			this.kursiyerId = kursiyerId;
			this.kursiyerAdSoyad = kursiyerAdSoyad;
			this.kursiyerYas = kursiyerYas;
			alinanKurslar =new ArrayList();
	}
		
	public Kursiyer() {
		// TODO Auto-generated constructor stub
	}

	public int getKursiyerId() {
		return kursiyerId;
	}
	
	public void setKursiyerId(int kursiyerId) {
		this.kursiyerId = kursiyerId;
	}
	
	public String getKursiyerAdSoyad() {
		return kursiyerAdSoyad;
	}
	
	public void setKursiyerAdSoyad(String kursiyerAdSoyad) {
		this.kursiyerAdSoyad = kursiyerAdSoyad;
	}
	
	public int getKursiyerYas() {
		return kursiyerYas;
	}
	
	public void setKursiyerYas(int kursiyerYas) {
		this.kursiyerYas = kursiyerYas;
	}
	

}
