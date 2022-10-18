package menu;
import java.util.List;

import exceptions.MenuNotFoundException;
import manager.EntityManager;
import manager.Manager;

public class MenuEntry {

    /**
     * This is an ADT for a restaurant menù entry
     * Mutable
     * 
     */

     private String name;
     private Manager<Ingredient> ingredients;

     public MenuEntry(String name, List<Ingredient> ingredients) {
         
        this.name = name;
        this.ingredients = new EntityManager<>(ingredients);
     }
    
     public String getName() {
         return name;
     }

     public Manager<Ingredient> getIngredients() {
         return ingredients;
     }

     public Menu getMenu(MenuDispatcher dispatcher) throws MenuNotFoundException {
         return dispatcher.findMenu(this);
     }
}
