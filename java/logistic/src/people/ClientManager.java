package people;

import java.util.ArrayList;
import java.util.List;

public class ClientManager {

    private List<Client> clients;

    public ClientManager() {
        
        this.clients = new ArrayList<>();
    }
    
    public void add(Client client) {
        
        this.clients.add(client);
        
    }

    public void remove(Client client) {
       
        this.clients.remove(client);
        
    }

    /**
     * PRODUCER
     * @return a copy of the list of clients
     */
    public List<Client> getClients() {

        return List.copyOf(clients);
    }
}

