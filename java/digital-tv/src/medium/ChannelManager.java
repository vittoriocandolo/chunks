package medium;

import java.util.ArrayList;
import java.util.List;

public class ChannelManager<K extends Channel> { // flex

    private List<K> channels;

    public ChannelManager() {
        
        this.channels = new ArrayList<>();

    }

    public void add(K channel) {

        this.channels.add(channel);

    }
    
}

