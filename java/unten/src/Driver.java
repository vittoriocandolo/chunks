public class Driver extends Person {

    /**
     * This class is an ADT for a taxi driver
     */

    private String driverLicenseNumber;

    /**
     * Ctor
     * @param name
     * @param surname
     * @param ssc
     * @param driverLicenseNumber
     */
    public Driver(String name, String surname, String ssc, String driverLicenseNumber) {

        super(name, surname, ssc);
        this.driverLicenseNumber = driverLicenseNumber;
    }

    public String getDriverLicenseNumber() {
        return driverLicenseNumber;
    }
    
}
