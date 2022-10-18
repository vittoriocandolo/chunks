import java.time.LocalDateTime;

public class UntenAgency {

    /**
     * This class is the main API that exposes all and only the requested features
     */
    
    private ReservationManager reservations;
    private String suggestions;

    /**
     * Ctor
     * @param fleet Taxi manager
     */
    public UntenAgency(TaxiManager fleet) {
        
        this.reservations = new ReservationManager(fleet);
    }

    /**
     * Ctor
     * @param reservations Reseravtion Manager
     */
    public UntenAgency(ReservationManager reservations) {

        this.reservations = reservations;
    }

    // copy ctor maybe

    // too many things in one shot
    public void makeReservation(Location departure, Location arrival, LocalDateTime departureTime, Integer bookedSeats, Client client) {

        Reservation res = new Reservation(departure, arrival, departureTime, bookedSeats, client);

        
            try {
                this.reservations.add(res);
            } catch (NotAcceptedImmediateReservationException | NotAcceptedFutureReservationException e) {
                
                SuggestionsHelper sh = new SuggestionsHelper(res, this.reservations);

                this.suggestions = sh.getSuggestions();
            }

    }

    public String getSuggestions() {

        return this.suggestions;
    }
}
