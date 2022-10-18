public class Taxi {

    /**
     * This class is an ADT for a taxi
     * Mutable
     */
    
    private String licenseNumber;
    private Integer freeSeats;
    private Boolean isActive;
    private Location currentLocation;

    /**
     * Ctor
     * @param licenseNumber is the Taxi identifier
     * @param freeSeats is the number of seats available for the Taxi
     */
    public Taxi(String licenseNumber, Integer freeSeats) {
        
        this.licenseNumber = licenseNumber;
        this.freeSeats = freeSeats;
        this.isActive = false;
        this.currentLocation = new Location(100F, 100F);
    }

    public String getLicenseNumber() {
        return licenseNumber;
    }

    public Integer getFreeSeats() {
        return freeSeats;
    }

    public Boolean getIsActive() {
        return isActive;
    }

    public void setIsActive(Boolean isActive) {
        this.isActive = isActive;
    }

    public Location getCurrentLocation() {
        return currentLocation;
    }

    public void setCurrentLocation(Location currentLocation) {
        this.currentLocation = currentLocation;
    }
    
    public void updateLocation() {

        // code that allows the taxi to update its location
    }
}
