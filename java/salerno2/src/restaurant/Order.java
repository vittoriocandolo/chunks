package restaurant;
import manager.EntityManager;
import manager.Manager;
import menu.Serving;

public class Order {

     /**
     * ADT for a restaurant order
     * Mutable
     * The Order manages the servings exposing the data needed to get its undeliverd servings
     * and helps the Table to calculate the check
     */
    private Manager<Serving> servings;

    /**
     * Standard ctor
     * @param newServing is the Seriving immidiatly added to the new Order
     */
    public Order(Serving newServing) {
        
        this.servings = new EntityManager<>();
        this.servings.add(newServing);
    }

    public Manager<Serving> getServings() {
        return servings;
    }


    
}
