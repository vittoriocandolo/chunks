import java.time.LocalDateTime;

public class ReportBuilder {

    private ReservationManager reservations;
    private TaxiManager taxis;

    public ReportBuilder(ReservationManager reservations, TaxiManager taxis) {
        
        this.reservations = reservations;
        this.taxis = taxis;
    }

    @Override
    public String toString() {

        String result = "Report: " + LocalDateTime.now().toString() + " "
                            + " \n" + this.reservations.;



        return result;
    }

    
    
}
