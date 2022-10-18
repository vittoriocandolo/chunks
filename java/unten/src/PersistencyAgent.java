public interface PersistencyAgent<T> {

    public void save(T t);

    public void export(T t);
    
}

