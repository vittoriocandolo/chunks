package agency;

import java.util.ArrayList;
import java.util.List;

public class PrenotationManager {

    private List<Prenotation> prenotations;

    public PrenotationManager() {
        
        this.prenotations = new ArrayList<>();
    }
    
    public void addPrenotation(Prenotation prenotation) {
        
        this.prenotations.add(prenotation);
        
    }

    public void removePrenotation(Prenotation prenotation) {
       
        this.prenotations.remove(prenotation);
        
    }

    /**
     * PRODUCER
     * @return a copy of the list of clients
     */
    public List<Prenotation> getPrenotations() {

        return List.copyOf(prenotations);
    }
}