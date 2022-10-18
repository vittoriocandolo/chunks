import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.ListIterator;
import java.util.Map;

public class ReservationManager implements Manager<Reservation> {

    private static final Float IMMEDIATE_LOCATION_THRESHOLD = 5000F;
    private static final Float FUTURE_FREE_TAXIS_THRESHOLD = 0.3F;

    private List<Reservation> reservations;
    private TaxiManager taxiManager;

    public ReservationManager(TaxiManager taxiManager) {
        
        this.reservations = new ArrayList<>();
        this.taxiManager = taxiManager;
    }

    @Override // could do some hierachy between exceptions
    public void add(Reservation newReservation) throws NotAcceptedImmediateReservationException, NotAcceptedFutureReservationException {
        
        if(newReservation.getIsImmediate()) {

            if(this.validateImmediateReservation(newReservation)) {

                this.reservations.add(newReservation);
            } 

            else {

                throw new NotAcceptedImmediateReservationException();
            }
        }
        
        else {

            if(this.validateFutureReservation(newReservation)) {

                this.reservations.add(newReservation);
            }

            else {

                throw new NotAcceptedFutureReservationException();
            }
        }

        this.bookTaxis(newReservation);
        
    }

    @Override
    public void remove(Reservation reservation) {
        
        this.reservations.remove(reservation);
        
    }

    private boolean validateImmediateReservation(Reservation immediateReservation) {

        Float threshold = IMMEDIATE_LOCATION_THRESHOLD;

        this.taxiManager.updateLocations();

        ListIterator<Taxi> i = this.taxiManager.getActive().listIterator();

        while(i.hasNext()) {

            Taxi t = i.next();

            if(t.getCurrentLocation().getDistance(immediateReservation.getDeparture()) < threshold) {

                return true;
            }
            
        }

        return false;
        
    }

    private boolean validateFutureReservation(Reservation futureReservation) {

        Float threshold = FUTURE_FREE_TAXIS_THRESHOLD;

        //List<Reservation> simultaneousBookings = new ArrayList<>();

        ListIterator<Reservation> i = this.reservations.listIterator();

        int counter = 0;

        while(i.hasNext()) {

            Reservation res = i.next();

            if(res.getDepartureTime().minusHours(1).isBefore(futureReservation.getDepartureTime()) &&
            res.getDepartureTime().plusHours(1).isAfter(futureReservation.getDepartureTime())) {

                //simultaneousBookings.add(res);
                counter++;

            }
        }

        return (counter < this.taxiManager.getNumberOfTaxis() * threshold);
        
    }

    private Map<Reservation, List<Taxi>> bookTaxis(Reservation reservation) {

        ListIterator<Taxi> i = this.taxiManager.getActive().listIterator();

        Map<Reservation, List<Taxi>> taxiBookingBound = new HashMap();

        while(i.hasNext()) {

            Taxi t = i.next();
            int counter = 0;
            List<Taxi> bookedTaxis = new ArrayList<>();

            if(reservation.getBookedSeats() <= counter) {

                taxiBookingBound.put(reservation, bookedTaxis);

            } else {

                counter += t.getFreeSeats();

                bookedTaxis.add(t);


            }

        }

        return taxiBookingBound;
    }
    
}

