// CANDOLO VITTORIO GIORGIO - 141879
package treno;

public class RotabileNonDisponibileException extends RuntimeException {

    /**
     * Eccezione lanciata quando i componenti del treno che si vuole creare non sono disponibili alla stazione di partenza
     * @param msg
     */
    public RotabileNonDisponibileException(String msg) {
        
        super(msg);
    }

}
