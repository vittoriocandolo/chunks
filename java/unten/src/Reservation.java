import java.time.LocalDateTime;

public final class Reservation {

    /**
     * This class is an ADT for a taxi ride reservation
     * Immutable (~ since Integer and Client field)
     */

     private static final int IMMEDIATE_THRESHOLD = 5;

     private final Location departure;
     private final Location arrival;
     private final LocalDateTime departureTime;
     private final Integer bookedSeats;
     private final Client client;
     private final Boolean isImmediate;

     /**
      * Ctor
      * @param departure
      * @param arrival
      * @param departureTime
      * @param bookedSeats
      * @param client
      */
     public Reservation(Location departure, Location arrival, LocalDateTime departureTime, Integer bookedSeats, Client client) {

        this.departure = departure;
        this.arrival = arrival;
        this.departureTime = departureTime;
        this.bookedSeats = bookedSeats;
        this.client = client;
        this.isImmediate = LocalDateTime.now().plusMinutes(IMMEDIATE_THRESHOLD).isAfter(departureTime);
    }

    public Location getDeparture() {
        return departure;
    }

    public Location getArrival() {
        return arrival;
    }

    public LocalDateTime getDepartureTime() {
        return departureTime;
    }

    public Integer getBookedSeats() {
        return bookedSeats;
    }

    public Client getClient() {
        return client;
    }
     
    public Boolean getIsImmediate() {
        return isImmediate;
    }

}

