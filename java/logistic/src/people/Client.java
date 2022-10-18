package people;

public class Client extends Person {

    private String vatId;
    private String phoneNumber;
    private CCInfo ccInfo;

    public Client(String name, String vatId) {

        super(name, null);
        this.vatId = vatId;
    }

    public String getVatId() {
        return vatId;
    }

    public void setPhoneNumber(String phoneNumber) {
        this.phoneNumber = phoneNumber;
    }

    public String getPhoneNumber() {
        return phoneNumber;
    }

    public void setCcInfo(CCInfo ccInfo) {
        this.ccInfo = ccInfo;
    }

    public CCInfo getCcInfo() { // ?
        return ccInfo;
    }
    
}
