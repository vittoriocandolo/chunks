public interface Manager<T> {

    /**
     * This is an interface to define minimal interactions on collections of Objects
     */

    /**
     * MODIFY add an element to the collection
     * @param element
     */
	void add(T element) throws Exception;

    /**
     * MODIFY remove an element from the collection
     * @param element
     */
	void remove(T element);
	
}