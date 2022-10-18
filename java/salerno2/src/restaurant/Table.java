package restaurant;
import java.util.ListIterator;

import exceptions.InvalidMenuEntryExcpetion;
import exceptions.MenuNotFoundException;
import manager.EntityManager;
import manager.Manager;
import menu.MenuDispatcher;
import menu.Serving;

public class Table {

    /**
     * ADT for a restaurant Table
     * Mutable
     * The Table manages the orders exposing the data needed to calculate its check and to get the undeliverd servings
     */
    private Manager<Order> orders;

    /**
     * Standard ctor
     */
    public Table() {
        
        this.orders = new EntityManager<>();
    }

    /**
     * Depending on behaviour this ctor could not be implemented
     * @param newOrder is the Order immidiatly added to the new Table
     */
    public Table(Order newOrder) {
        
        this.orders = new EntityManager<>(); // and w/o this?
        this.orders.add(newOrder);

    }

    /**
     * MODIFY
     * Allows to add an Order to the already existing table
     * @param newOrder
     */
    public void addOrder(Order newOrder) {

        this.orders.add(newOrder);
    }

    public Manager<Order> getOrders() {
        return orders;
    }

    public Float getCheck(MenuDispatcher disp) {

        Float check = 0F;

        ListIterator<Order> i = this.orders.getElements().listIterator();

        while(i.hasNext()) {

            Order ord = i.next();

            ListIterator<Serving> j = ord.getServings().getElements().listIterator();

            while(j.hasNext()) {

                Serving serv = j.next();

                    try {
                        check += serv.getMenu(disp).calculateEntryPrice(serv.getName(), serv.getAdditions(), serv.getRemovals());
                    } catch (InvalidMenuEntryExcpetion | MenuNotFoundException e) {
                        e.printStackTrace();
                    }
            }
        }

        return check;

    }
    
}
