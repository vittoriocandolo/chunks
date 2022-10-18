package logistics;

import java.time.LocalDateTime;

import goods.LoadInfo;
import goods.TypeOfGoods;
import vehicles.Fleet;

public class Delivery {

    private Route route;
    private TravelManager travelManager;
    private LoadInfo loadInfo;
    private Fleet fleet;
    private LocalDateTime DepartureTime;
    private LocalDateTime estimatedArrivalTime;
    
    /**
     * MyCtor
     * @param route
     * @param loadInfo
     * @param departureTime
     */
    public Delivery(Route route, LoadInfo loadInfo, LocalDateTime departureTime ) {
        
        this.route = route;
        this.travelManager = new TravelManager();
        this.loadInfo = loadInfo;
        this.fleet = new Fleet();
        this.DepartureTime = departureTime;
        //this.estimatedArrivalTime = someMethod();
    }

    public Delivery(City departure, City arrival, TypeOfGoods typeOfGoods, Float loadWeight, LocalDateTime departurTime) {

        this.route = new Route(departure, arrival);
        this.travelManager = new TravelManager();
        this.loadInfo = new LoadInfo(typeOfGoods, loadWeight);
        this.fleet = new Fleet();
        this.DepartureTime = departurTime;
         //this.estimatedArrivalTime = someMethod();

    }

    public Delivery(City departure, City arrival, TypeOfGoods typeOfGoods, Float loadWeight, LocalDateTime arrivalTime, Object leaveMeNull) {

        this.route = new Route(departure, arrival);
        this.travelManager = new TravelManager();
        this.loadInfo = new LoadInfo(typeOfGoods, loadWeight);
        this.fleet = new Fleet();
        //this.DepartureTime = someMethod();
        this.estimatedArrivalTime = arrivalTime;

    }

    public Route getRoute() {

        return route;

    }

    public City getDeparture() {

        return this.route.getDeparture();

    }

    public City getArrival() {

        return this.route.getArrival();
        
    }

    public LocalDateTime getDepartureTime() {
        return DepartureTime;
    }

    public LocalDateTime getEstimatedArrivalTime() {
        return estimatedArrivalTime;
    }

    public Fleet getFleet() {
        return fleet;
    }

    public LoadInfo getLoadInfo() {
        return loadInfo;
    }

    // reinstradare
}
