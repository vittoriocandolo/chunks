import java.util.ArrayList;
import java.util.List;

public class TaxiManager implements Manager<Taxi> { // Fleet

    /**
     * This class allows to manage the taxi fleet
     * Protocol:
     * add,
     * remove,
     * getActive,
     * updateLocations
     */
    
    private List<Taxi> taxis; // fleet

    /**
     * Ctor
     */
    public TaxiManager() {
        
        this.taxis = new ArrayList<>();
    }

    @Override
    public void add(Taxi newTaxi) {

        this.taxis.add(newTaxi);
    }

    @Override
    public void remove(Taxi taxi) {

        this.taxis.remove(taxi);
    }

    public List<Taxi> getActive() {

        List<Taxi> activeTaxis = new ArrayList<>();

        this.taxis.stream().filter(t -> t.getIsActive() == true).forEach(t -> activeTaxis.add(t));

        return activeTaxis;
    }

    public void updateLocations() {
        
        List<Taxi> activeTaxis = this.getActive();

        activeTaxis.forEach(t -> t.updateLocation());
    }

    
    public Integer getNumberOfTaxis() {

        return this.taxis.toArray().length;
    
    }
    
}
