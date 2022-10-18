public class AutonomousTaxi extends Taxi {

    /**
     * This class is an ADT for an autonomous taxi
     */
    
    private String softwareManufacturer;
    
    public AutonomousTaxi(String licenseNumber, Integer freeSeats, String softwareManufacturer) {

        super(licenseNumber, freeSeats);
        this.softwareManufacturer = softwareManufacturer;
    }

    public String getSoftwareManufacturer() {
        return softwareManufacturer;
    }
}
