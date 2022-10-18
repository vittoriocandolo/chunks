package restaurant;
import java.util.ArrayList;
import java.util.List;
import java.util.ListIterator;

import manager.EntityManager;
import manager.Manager;
import menu.Serving;

public class Hall {

    /**
     * ADT for a restaurant Hall
     * Mutable
     * The Hall manages the tables exposing the data needed to get the undeliverd servings
     */
    private Manager<Table> tables;

    /**
     * Standard ctor
     */
    public Hall() {
        
        this.tables = new EntityManager<>();
    }

    /**
     * Depending on behaviour this ctor could not be implemented
     * @param newTable is the Table immidiatly added to the new Hall
     */
    public Hall(Table newTable) {
        
        this.tables = new EntityManager<>(); // and w/o this?
        this.tables.add(newTable);

    }

    /**
     * MODIFY
     * Allows to add a Table to the already existing Hall
     * @param newOrder
     */
    public void addTable(Table newTable) {

        this.tables.add(newTable);
    }

    /**
     * 
     * @return
     */
    public List<Serving> getNotServed() {

        List<Serving> notServed = new ArrayList<>();

        ListIterator<Table> i = this.tables.getElements().listIterator();

        while(i.hasNext()) {

            Table tab = i.next();

            ListIterator<Order> j = tab.getOrders().getElements().listIterator();

            while(j.hasNext()) {

                Order ord = j.next();

                ListIterator<Serving> k = ord.getServings().getElements().listIterator();

                while(k.hasNext()) {

                    Serving serv = k.next();

                    if(! serv.getIsServed()) {

                        notServed.add(serv);
                    }
                }
            }


        }

        return notServed;

    }
    
}

