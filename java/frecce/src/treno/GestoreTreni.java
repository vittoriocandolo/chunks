// CANDOLO VITTORIO GIORGIO - 141879
package treno;

import java.time.LocalTime;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;
import java.util.NoSuchElementException;
import java.util.stream.Collectors;

public class GestoreTreni {

    /**
     * Questa classe permette di gestire i treni svolgendo alcune operazioni di insieme
     * Lo stato concreto consiste di una lista di treni
     * La classe permette di aggiungere e rimuovere un treno,
     *  ottenere la lista dei treni in corsa in quel momento o in un momento dato
     *  e mette a disposizione un iteratore per eventuali altre richieste future di operazioni sulla struttura dati
     */
    private List<Treno> treni;

    /**
     * Ctor
     */
    public GestoreTreni() { // TODO implements interfaccia da fare
        
        this.treni = new ArrayList<>();
    }

    public List<Treno> getTreniInCorsa() {

        return this.treni.stream().filter(t -> t.InCorsa() == true).collect(Collectors.toList());

    }

    public void aggiungiTreno(Treno nuovoTreno) {

        this.treni.add(nuovoTreno);
    }

    public void rimuoviTreno(Treno trenoDaRimuovere) {

        this.treni.remove(trenoDaRimuovere);
    }

    public List<Treno> getTreniInCorsa(LocalTime time) { // TODO globalmente scegliere se LocalTime o LocalDateTime

        List<Treno> result = new ArrayList<>();

       Iterator<Treno> it = this.treni.listIterator();

       while(it.hasNext()) {

            Treno t = it.next();

            LocalTime partenza = t.getPercorso().getOrarioPartenza();
            LocalTime arrivo = t.getPercorso().getOrarioArrivo();

            if(time.isAfter(partenza) && time.isBefore(arrivo)) {

                result.add(t);
            }
       }

       return result;
    }

    public Iterator iterator() {

        return new GestoreTrenoIterator(this);
    }

    private class GestoreTrenoIterator implements Iterator<Treno> {

        private final List<Treno> treni;
        private Treno current;

        public GestoreTrenoIterator(GestoreTreni gt) {

            if(gt == null) {

                throw new NullPointerException();
            }

            this.treni = new ArrayList<>();
            treni.addAll(gt.treni); 
            
            this.current = this.treni.stream().findFirst().get();
        }

        @Override
        public boolean hasNext() {
            
            return this.treni.indexOf(current) < this.treni.size();
        }

        @Override
        public Treno next() {

            if(this.treni.indexOf(current) < this.treni.size()) {

                Treno t = this.treni.get(this.treni.indexOf(current) + 1);
                
                return t;

            } else {

                throw new NoSuchElementException("Superato ultimo elemento");
            }
        }
    }
    
}