package vehicles;

import java.util.ArrayList;
import java.util.List;
import java.util.ListIterator;

public class Fleet {

    private List<Truck> fleet;

    public Fleet() {
        
        this.fleet = new ArrayList<>();
    }

    public void addTruck(Truck truck) {
        
        this.fleet.add(truck);
        
    }

    public void removeTruck(Truck truck) {
       
        this.fleet.remove(truck);
        
    }

    /**
     * PRODUCER
     * @return a copy of the list of clients
     */
    public List<Truck> getTrucks() {

        return List.copyOf(fleet);
    }

    public Float calculateCapacity() {

        ListIterator<Truck> i = this.fleet.listIterator();

        Float temp = 0F;

        while(i.hasNext()) {

            temp += i.next().getLoadCapacity();

        }

        return temp;
    }
}
