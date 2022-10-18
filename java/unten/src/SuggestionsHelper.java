import java.time.LocalDateTime;

public class SuggestionsHelper {

    private Reservation reservation;
    private ReservationManager reservations;

    public SuggestionsHelper(Reservation reservation, ReservationManager reservations) {
        
        this.reservation = reservation;
        this.reservations = reservations;
    }

    public String getSuggestions() {

        String answare = "";

        if(LocalDateTime.now().getNano() > 4) { // lulz

            answare = "Try again later";
        }

        else {

            answare = "Try with a different number of occupants";
        }

        return answare;
    }
}

