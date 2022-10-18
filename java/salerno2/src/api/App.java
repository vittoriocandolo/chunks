package api;

import java.util.ArrayList;
import java.util.List;

import menu.Ingredient;
import menu.Menu;
import menu.MenuCategory;
import menu.Serving;
import restaurant.Order;

public class App {

    public static void main(String[] args) {

        Menu menu1 = new Menu(MenuCategory.FIRST_COURSES);

        List<Ingredient> ings1 = new ArrayList<>();

        Ingredient ing1 = new Ingredient("Pollo", 10F);
        Ingredient ing2 = new Ingredient("Pasta", 2F);

        ings1.add(ing1);
        ings1.add(ing2);

        Serving serv1 = new Serving("Pasta al pollo", ings1, menu1, null, null);
        
        Order order1 = new Order(serv1);
        
    }
    
}
