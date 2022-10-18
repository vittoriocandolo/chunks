package medium;

public class TvChannel extends Channel {
    
    private String number; // it's a code

    public TvChannel(String name, String number) {

        super(name);
        this.number = number;
    }

    public String getNumber() {
        return this.number;
    }

    public void setNumber(String number) {
        this.number = number;
    }

}