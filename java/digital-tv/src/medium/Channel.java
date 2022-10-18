package medium;

import java.util.ArrayList;
import java.util.List;

import medium.broadcast.Broadcast;

public class Channel {

    /**
     * This class is an ADT for a TV channel
     * Mutable, Broadcast list is unbounded (list)
     *
     */

    private String name;
    private List<Broadcast> programmation;

    /**
     * ctor
     * @param name is the channel name
     */
    public Channel(String name) {
        
        this.name = name;
        this.programmation = new ArrayList<Broadcast>();
    }

    public String getName() { 
        return this.name;
    }

    public void setName(String name) {
        this.name = name;
    }

    /**
     * MODIFY add a program to the programmation of the channel
     * @param broadcast is the program to be added MUST be not already in the programmation of another channel
     */
    public void addToProgrammation(Broadcast broadcast) {

        // validation

        this.programmation.add(broadcast);

    }

    /**
     * MODIFY remove a program from the programmation of the channel
     * @param broadcast is the program to be removed
     */
    public void removeFromProgrammation(Broadcast broadcast) {

        this.programmation.remove(broadcast);
    }
    
}