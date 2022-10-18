package medium.broadcast;

import medium.Language;

public final class BroadcastLanguage extends Language {


    /**
     * ADT for the language of a broadcast
     * Immutable
     */
    private final boolean hasSubs;
    // audio field
    // text field

    public BroadcastLanguage(String code, boolean hasSubs) {
        
        super(code);
        this.hasSubs = hasSubs;
    }

    public boolean getHasSubs() {
        return hasSubs;
    }
    
}
