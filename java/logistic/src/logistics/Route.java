package logistics;

/**
 * ADT for a fixed route between two cities
 * Immutable
 */
public final class Route {

    private final City departure;
    private final City arrival;
    
    public Route(City departure, City arrival) {
        
        this.departure = departure;
        this.arrival = arrival;
    }

    public City getDeparture() {
        return departure;
    }

    public City getArrival() {
        return arrival;
    }

    /**
     * PRODUCER
     * @return the inverted, simmetrical route
     */
    public Route getInverted() {

        return new Route(this.arrival, this.departure);
    }
}

