package people;

import java.time.LocalDate;

import logistics.City;

public class Person {

    /**
     * ADT for a person
     * Should use a BUILDER
     */
    private String name;
    private String surname;
    private LocalDate dateOfBirth;
    private City residence;
    private String address;
    private String ssc; //social security number

    /**
     * CTOR REQUIRE the asked parameters, use setters for missing (NO SENSE)
     * @param name
     * @param ssc
     */
    public Person(String name, String ssc) {
        
        this.name = name;
        this.dateOfBirth = calculateDateOfBirth(ssc);
        this.ssc = ssc;
    }

    public String getName() {
        return name;
    }

    public LocalDate getDateOfBirth() {
        return dateOfBirth;
    }

    public String getSsc() {
        return ssc;
    }

    public void setSurname(String surname) {
        this.surname = surname;
    }

    public String getSurname() {
        return surname;
    }

    public void setResidence(City residence) {
        this.residence = residence;
    }

    public City getResidence() {
        return residence;
    }

    public String getAddress() {
        return address;
    }

    public void setAddress(String address) {
        this.address = address;
    }
    
    private static LocalDate calculateDateOfBirth(String ssc) {

        // do calculations

        return LocalDate.now(); // fake
    }
}
