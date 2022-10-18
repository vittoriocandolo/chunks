package device;

import medium.*;

public class Setting {

    // visibility
    static final int MAXVOLUME = 50;
    static final int MAXBRIGHTNESS = 100;

    private int volume;
    private int brightness;
    private Language systemLanguage;
    private boolean showSubs;
    private boolean is2In1Active;

    //many ctors

    public Setting() {

        this.volume = 25;
        this.brightness = MAXBRIGHTNESS;
        this.systemLanguage = new Language("ENG");
        this.showSubs = false;
        this.is2In1Active = false;

    }


    // visibility

    public int getVolume() {

        return volume;
    }

    public void setVolume(int volume) {

        this.volume = volume;
    }

    public int getBrightness() {

        return brightness;
    }

    public void setBrightness(int brightness) {

        this.brightness = brightness;
    }
    
    public BroadcastLanguage getSystemLanguage() {

        return systemLanguage;
    }

    public void setSystemLanguage(BroadcastLanguage systemLanguage) {

        this.systemLanguage = systemLanguage;
    }

    public boolean getShowSubs() {

        return showSubs;
    }

    public void setShowSubs(boolean showSubs) {

        this.showSubs = showSubs;
    }

    public boolean getIs2In1Active() {

        return is2In1Active;

    }

    public void setIs2In1Active(boolean is2In1Active) {

        this.is2In1Active = is2In1Active;
    }

    // export
    
}

