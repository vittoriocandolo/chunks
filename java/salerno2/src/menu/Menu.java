package menu;
import java.util.List;
import java.util.ListIterator;

import exceptions.InvalidMenuEntryExcpetion;
import manager.EntityManager;
import manager.Manager;

public class Menu {

    /**
    * ADT for a restaurant menù
    * Mutable
    * The Menu manages the menuEntries and calculates the price for every entry
    */
   private MenuCategory category;
   private Manager<MenuEntry> menuEntries;

   /**
    * Standard ctor
    */
   public Menu(MenuCategory category) {
       
       this.category = category;
       this.menuEntries = new EntityManager<>();
   }

   /**
    * Ctor importing an already existing menù
    * @param category
    * @param menuEntries
    */
   public Menu(MenuCategory category, Manager<MenuEntry> menuEntries) {
       this.category = category;
       this.menuEntries = menuEntries;
   }

   /**
    * Ctor adding immidiatly an entry to the menù
    * @param category is the menù category
    * @param newEntry is the entry immidiatly added
    */
   public Menu(MenuCategory category, MenuEntry newEntry) {
       this.category = category;
       this.menuEntries = new EntityManager<>();
       this.menuEntries.add(newEntry);
   }

   public MenuCategory getCategory() {
       return category;
   }

   public Manager<MenuEntry> getMenuEntries() {
       return menuEntries;
   }

   public void addEntry(MenuEntry newEntry) {

        this.menuEntries.add(newEntry);
   }

   /**
    * 
    * @param name
    * @param additions
    * @param removals
    * @return
    * @throws InvalidMenuEntryExcpetion
    */
   public Float calculateEntryPrice(String name, List<Ingredient> additions, List<Ingredient> removals) throws InvalidMenuEntryExcpetion {

        Float price = 0F;

        ListIterator<MenuEntry> i = this.menuEntries.getElements().listIterator();

        while(i.hasNext()) {

            MenuEntry entry = i.next();            

            if(entry.getName().equals(name)) {

                ListIterator<Ingredient> j = additions.listIterator();

                while(j.hasNext()) {

                    Ingredient ing = j.next();

                    if(! entry.getIngredients().containsElement(ing)) {

                        entry.getIngredients().add(ing);
                    }

                }

                ListIterator<Ingredient> k = removals.listIterator();
                
                while(k.hasNext()) {

                    Ingredient ing = k.next();

                    if(entry.getIngredients().containsElement(ing)) {

                        entry.getIngredients().remove(ing);
                    }
                }

                ListIterator<Ingredient> z = entry.getIngredients().getElements().listIterator();

                while(z.hasNext()) {

                    price += z.next().getPrice();
                }

            } else {

                throw new InvalidMenuEntryExcpetion();
            }
        }

        return price;

    }

}
