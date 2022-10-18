package people;

/**
 * ADT for payment info (Credit Card Info)
 * Immutable
 */
public final class CCInfo {

    private String criptedCardNumber;
    private String someAuthCodeAlsoCrypted;
    // everything else
    

    public CCInfo(String ccn) {
        
        this.criptedCardNumber = ccn.hashCode() + "";
        this.someAuthCodeAlsoCrypted = this.criptedCardNumber.hashCode() + "";
        //sorry
    }
}

