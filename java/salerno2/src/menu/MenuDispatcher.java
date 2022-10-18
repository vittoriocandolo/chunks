package menu;

import java.util.ListIterator;

import exceptions.MenuNotFoundException;
import manager.EntityManager;
import manager.Manager;

public class MenuDispatcher {

    private Manager<Menu> menus;

    public MenuDispatcher() {
        
        this.menus = new EntityManager<>();
    }

    public Menu findMenu(MenuEntry menuEntry) throws MenuNotFoundException {

        ListIterator<Menu> i = this.menus.getElements().listIterator();

        while(i.hasNext()) {

            Menu menu = i.next();

            if(menu.getMenuEntries().containsElement(menuEntry)) {

                return menu;
            }

            else {

                throw new MenuNotFoundException();

            } 
        }
        
        return null;

    }
    
}

