package restaurant;

import manager.EntityManager;
import manager.Manager;

public class Restaurant {

    /**
     * ADT for a restaurant Restaurant
     * MuHall
     * The Restaurant manages the Halls exposing the data needed to get the undeliverd servings
     */
    private Manager<Hall> Halls;

    /**
     * Standard ctor
     */
    public Restaurant() {
        
        this.Halls = new EntityManager<>();
    }

    /**
     * Depending on behaviour this ctor could not be implemented
     * @param newHall is the Hall immidiatly added to the new Restaurant
     */
    public Restaurant(Hall newHall) {
        
        this.Halls = new EntityManager<>(); // and w/o this?
        this.Halls.add(newHall);

    }

    /**
     * MODIFY
     * Allows to add a Hall to the already existing Restaurant
     * @param newOrder
     */
    public void addHall(Hall newHall) {

        this.Halls.add(newHall);
    }
}