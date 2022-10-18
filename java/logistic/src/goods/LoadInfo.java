package goods;

import java.util.ListIterator;

import exceptions.InvalidLoadCompositionException;
import exceptions.InvalidPrenotationException;
import people.ClientManager;

/**
 * ADT to keep organized some Delivery data, abstraction for a travel document of the load
 */
public class LoadInfo {

    private ClientManager clients;
    private GoodsManager load;
    private Float loadWeight;
    private TypeOfGoods loadType;

    /**
     * CTOR
     * @param clients
     * @param load REQUIRE not null
     * @param loadWeight
     * @throws InvalidLoadCompositionException
     * @throws InvalidPrenotationException
     */
    public LoadInfo(ClientManager clients, GoodsManager load) throws InvalidLoadCompositionException, InvalidPrenotationException {

       this.load = load;
       this.validate();
       this.clients = clients;
       this.loadWeight = calculateLoadWeight();
       this.loadType = load.getGoods().get(0).getType();
    }

    public LoadInfo(TypeOfGoods loadType, Float loadWeight) {

        this.clients = new ClientManager();
        this.load = new GoodsManager();
        this.loadWeight = loadWeight;
        this.loadType = loadType;

    }

    public void validate() throws InvalidLoadCompositionException, InvalidPrenotationException {

        if(this.load.getGoods().isEmpty()) {

            throw new InvalidLoadCompositionException("Load is empty");

        }
        else {

            ListIterator<Goods> i = this.load.getGoods().listIterator();
            Goods temp = this.load.getGoods().get(0);

            while(i.hasNext()) {

                if(!temp.getType().toString().equals(i.next().getType().toString()) || ! temp.getType().toString().equals(this.loadType.toString())) {

                    throw new InvalidLoadCompositionException("The load is composed of incompatible goods (different kinds)");

                }

            }
        }

        if(this.clients.getClients().isEmpty()) {

            throw new InvalidPrenotationException("Clients list is empty");
        }

    }

    private Float calculateLoadWeight() {

        ListIterator<Goods> i = this.load.getGoods().listIterator();
        Float temp = 0F;

        while(i.hasNext()) {

            temp += i.next().getWeigth();

        }

        return temp;

    }

    public Float getLoadWeight() {
        return loadWeight;
    }
    
}
