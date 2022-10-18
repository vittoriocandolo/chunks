package device;

import medium.*;

public class Tv {

    static final int MAXVOLUME = 50;
    static final int MAXBRIGHTNESS = 100;

    private Setting currentSetting;
    private TvChannel currentChannel;
    private TvChannel secondCurrentChannel;
    private ChannelManager channelManager;

    public Tv() {

        this.currentSetting = new Setting();
        this.currentChannel = null;
        this.secondCurrentChannel = null;
        this.channelManager = new ChannelManager<>();
    }


    private void show(TvChannel channel) {

        // code that allows the TV to display the digital signal

    }

    private void show(TvChannel channel1, TvChannel channel2) {

        // code that allows the TV to display the digital signal
        // set 2-1 or validation

    }

    public void boot() {

        this.show(this.currentChannel);      

    }
 
}

