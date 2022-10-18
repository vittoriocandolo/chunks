import java.time.LocalDate;

public class Person {

    /**
     * This class is an ADT for a person
     * Mutable
     * partial implementation
     */

    private String name;
    private String surname;
    private String ssc; // social security number
    private LocalDate dateOfBirth; // non mandatory field
    // and more

    /**
     * Ctor
     * @param name
     * @param surname
     * @param ssc
     */
    public Person(String name, String surname, String ssc) {
        
        this.name = name;
        this.surname = surname;
        this.ssc = ssc;
    }

    public String getName() {
        return name;
    }

    public String getSurname() {
        return surname;
    }

    public String getSsc() {
        return ssc;
    }

    public LocalDate getDateOfBirth() {
        return dateOfBirth;
    }

    public void setDateOfBirth(LocalDate dateOfBirth) {
        this.dateOfBirth = dateOfBirth;
    }
    
}

