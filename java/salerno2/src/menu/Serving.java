package menu;
import java.util.List;

public class Serving extends MenuEntry {

    /**
     * This is an ADT for a restaurant serving
     * Mutable
     */

     private boolean isServed;
     private List<Ingredient> additions;
     private List<Ingredient> removals;

     //BUILDER
     public Serving(String name, List<Ingredient> ingredients, List<Ingredient> additions, List<Ingredient> removals) {

         super(name, ingredients);
         this.isServed = false;
         this.additions = additions;
         this.removals = removals;
     }

     public boolean getIsServed() {

         return this.isServed;
     }

     public List<Ingredient> getAdditions() {
         return additions;
     }

     public List<Ingredient> getRemovals() {
         return removals;
     }
}
