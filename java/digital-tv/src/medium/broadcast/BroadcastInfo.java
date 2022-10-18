package medium.broadcast;

import java.time.Duration;
import java.util.List;

public class BroadcastInfo { // TODO could be immutable

    /**
     * ADT for an info sheet
     * 
     */
    private String extendedTitle; // not mandatory
    private List<String> cast; // not mandatory
    private Duration duration;
    // country of origin

    // TODO check null / not null
    public BroadcastInfo(String extendedTitle, List<String> cast, Duration duration /* ... */) {
        
        this.extendedTitle = extendedTitle;
        this.cast = cast;
        this.duration = duration;

    }

    // TODO check getters and setters

    public String getExtendedTitle() {
        return extendedTitle;
    }

    public void setExtendedTitle(String extendedTitle) {
        this.extendedTitle = extendedTitle;
    }

    public List<String> getCast() {
        return cast;
    }

    public void setCast(List<String> cast) {
        this.cast = cast;
    }

    public Duration getDuration() {
        return duration;
    }

    public void setDuration(Duration duration) {
        this.duration = duration;
    }
    
}