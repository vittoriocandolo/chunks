public class Client extends Person {

    /**
     * This class is an ADT for a client
     */

     private String emailAddress;

     public Client(String name, String surname, String ssc, String emailAddress) {

        super(name, surname, ssc);
        this.emailAddress = emailAddress;
    }

    public String getEmailAddress() {
        return emailAddress;
    }

    
}
