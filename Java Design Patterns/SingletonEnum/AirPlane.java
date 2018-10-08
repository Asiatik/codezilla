
import java.util.HashSet;
import java.util.Set;

public enum AirPlane {

	INSTANCE;
	
	private Set<String> seats;
	
	private AirPlane() {
		
		this.seats = new HashSet<String>();
		seats.add("1A");
		seats.add("2B");
	}
	
	private boolean reserveSeat(String seat) {
		
		return seats.remove(seat);
	}
	
	public static void scheduleFlight(String seat) {
		
		AirPlane airPlane = AirPlane.INSTANCE;
		System.out.println( airPlane.reserveSeat(seat) );
	}
}
