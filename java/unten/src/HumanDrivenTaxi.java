public class HumanDrivenTaxi extends Taxi {

    /**
     * ADT for a human driven taxi
     */
    
    private Driver taxiDriver;

    public HumanDrivenTaxi(String licenseNumber, Integer freeSeats, Driver taxiDriver) {

        super(licenseNumber, freeSeats);
        this.taxiDriver = taxiDriver;
    }

    public Driver getTaxiDriver() {
        return taxiDriver;
    }

    public void setTaxiDriver(Driver taxiDriver) {
        this.taxiDriver = taxiDriver;
    }
    
}

