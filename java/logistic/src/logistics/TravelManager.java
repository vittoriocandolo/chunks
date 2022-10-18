package logistics;

import java.util.ArrayList;
import java.util.List;

public class TravelManager {
    
    private List<City> intermediateStops;

    public TravelManager() {
        
        this.intermediateStops = new ArrayList<>();
    }

    public void addIntermediateStop(City stop) {
        
        this.intermediateStops.add(stop);
        
    }

    public void removeIntermediateStop(City stop) {
       
        this.intermediateStops.remove(stop);
        
    }

    /**
     * PRODUCER
     * @return a copy of the list of intermediate stops
     */
    public List<City> getIntermediateStops() {

        return List.copyOf(intermediateStops);
    }

}

