package exceptions;

/**
 * thrown when the mix of goods composing the load is incompatible
 * (mixed types of goods)
 */
public class InvalidLoadCompositionException extends Exception {

    public InvalidLoadCompositionException(String msg) {
        super(msg);
    }

}
