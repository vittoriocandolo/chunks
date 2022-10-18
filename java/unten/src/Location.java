public final class Location {

    /**
     * This class is an ADT for a location
     * Immutable
     * Coordinates are represented with Floats
     */
    
    private final Float latitude;
    private final Float longitude;

    /**
     * Ctor
     * @param latitude is the first coordinate defining the Location
     * @param longitude is the second coordinate defining the Location
     */
    public Location(Float latitude, Float longitude) {
        
        this.latitude = latitude;
        this.longitude = longitude;
    }

    public Float getLatitude() {
        return latitude;
    }

    public Float getLongitude() {
        return longitude;
    }

    public Float getDistance(Location otherLocation) {

        Float distance = 0F;
        
        // code

        return distance;
    }
    
}

