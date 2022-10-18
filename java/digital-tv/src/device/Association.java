package device;

public final class Association<T, K> {

    private final T first;
    private final K second;

    public Association(T first, K second) {
        
        this.first = first;
        this.second = second;

    }

    public T getFirst() {
        return first;
    }

    public K getSecond() {
        return second;
    }
    
}
