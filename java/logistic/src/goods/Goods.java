package goods;

public class Goods {

    private String id;
    private String manufacturer;
    private String name;
    private Float price;
    private Float weigth;
    private TypeOfGoods type;

    public Goods(String id, Float weight, TypeOfGoods type) {
        
        this.id = id;
        this.weigth = weight;
        this.type = type;

    }

    public Float getWeigth() {
        return weigth;
    }

    public TypeOfGoods getType() {
        return type;
    }
    
}

