public class PersisntecyHelper implements PersistencyAgent {

    @Override
    public void save(Object t) {
        
       String buffer = t.toString();

       this.export(buffer);
        
    }

    @Override
    public void export(Object t) {
        
        // salva su file
        
    }
    
}
