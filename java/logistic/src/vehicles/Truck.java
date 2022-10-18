package vehicles;

import goods.TypeOfGoods;

/**
 * This class is an ADT for a Truck
 * Immutable
 */
public final class Truck extends Vehicle {

    private final Float loadCapacity;
    private final TypeOfGoods loadType;

    public Truck(String licensePlate, Float loadCapacity, TypeOfGoods loadType) {

        super(licensePlate);
        this.loadCapacity = loadCapacity;
        this.loadType = loadType;
    }

    public Float getLoadCapacity() {
        return loadCapacity;
    }

    public TypeOfGoods getLoadType() {
        return loadType;
    }
    
}
