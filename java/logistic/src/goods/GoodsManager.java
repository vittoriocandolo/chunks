package goods;

import java.util.ArrayList;
import java.util.List;

public class GoodsManager {

    private List<Goods> goods;

    public GoodsManager() {
        
        this.goods = new ArrayList<>();
    }
    
    public void addGoods(Goods goods) {
        
        this.goods.add(goods);
        
    }

    public void removeGoods(Goods goods) {
       
        this.goods.remove(goods);
        
    }

    /**
     * PRODUCER
     * @return a copy of the list of clients
     */
    public List<Goods> getGoods() {

        return List.copyOf(goods);
    }
}

