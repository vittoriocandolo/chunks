package logistics;

import java.awt.geom.Point2D;

public final class City {

    private final String name;
    private final Point2D.Float location;
    
    public City(String name, Point2D.Float location) {
        
        this.name = name;
        this.location = location;
    }

    public String getName() {
        return name;
    }

    public Point2D.Float getLocation() {
        return location;
    }

}

