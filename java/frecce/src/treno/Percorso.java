package treno;

import java.time.LocalTime;
import java.util.Iterator;
import java.util.List;
import java.util.Map;
import java.util.TreeMap;

/**
 * ADT per un percorso ferroviario
 * Questa classe rappresenta un percorso inteso come una successione di fermate,
 *  ciascuna delle quali legata ad un tempo, previsionale o effettivo, di arrivo
 * La rappresentazione è basata su un TreeMap dove i tempi agiscono come chiavi
 *  e le stazioni sono i relativi valori
 * La classe permette di:
 *  Ottenere la stazione di partenza
 *  Ottenere l'orario di partenza
 *  Ottenere la stazione di arrivo
 *  Ottenere l'orario di arrivo
 *  Verificare se una coppia (orario, stazione) è presente nel percorso
 */
public final class Percorso {

    private final Map<LocalTime, Stazione> programmazione;

    /**
     * Ctor
     * @param orarioPartenza definisce il momento in cui il treno parte dalla prima stazione
     * @param stazionePertenza definisce la stazione da cui il treno parte
     * @param orari lista di orari delle fermate successive
     * @param fermate lista di fermate successive
     * @param orarioArrivo definisce il momento previsto per l'arrivo del treno all'ultima stazione
     * @param stazioneArrivo definisce la stazione di capolinea per il treno
     * @throws NullpointerException se l'orario o la stazione di partenza non sono definiti
     */
    public Percorso(LocalTime oraPartenza, Stazione stazionePertenza, List<LocalTime> orari, List<Stazione> fermate, LocalTime orarioArrivo, Stazione stazioneArrivo) {
        
        if(oraPartenza == null || stazionePertenza == null) {

            throw new NullPointerException();

        } else {

            this.programmazione = new TreeMap<>(); // keeps ordered

            this.programmazione.put(oraPartenza, stazionePertenza);

            Iterator<LocalTime> it = orari.listIterator();
            Iterator<Stazione> is = fermate.listIterator();

            while(is.hasNext() && it.hasNext()) {

                this.programmazione.put(it.next(), is.next());
            }

            this.programmazione.put((orarioArrivo), stazioneArrivo);
            }
    }

    /**
     * REQUIRE stazionePartenza not null
     * @return stazione di partenza
     * 
     * Il costruttore garantisce il contratto
     */
    public Stazione getStazionePartenza() {

        return this.programmazione.values().stream().findFirst().get();
    }

    /**
     * REQUIRE orarioPartenza not null
     * @return orario di partenza
     * 
     * Il costruttore garantisce il contratto
     */
    public LocalTime getOrarioPartenza() {

        return this.programmazione.keySet().stream().findFirst().get();
    }

    /**
     * Observer
     * @throws NullPointerException se stazioneArrivo è null
     * @return stazione di arrivo
     */
    public Stazione getStazioneArrivo() {

        Stazione arrival = new Stazione();

        Iterator<Stazione> is = this.programmazione.values().iterator();

        while(is.hasNext()) {

            arrival = is.next();
        }

        if(arrival == null) {

            throw new NullPointerException();

        } else {

            return arrival;
        }
    }

    /**
     * Observer
     * @throws NullPointerException se orarioArrivo è null
     * @return orario di arrivo
     */
    public LocalTime getOrarioArrivo() {

        LocalTime arrival = null;

        Iterator<LocalTime> it = this.programmazione.keySet().iterator();

        while(it.hasNext()) {

            arrival = it.next();
        }

        return arrival;
    }

    /**
     * Observer
     * @param stazione da cercare
     * @param orario di fermata a stazione
     * @return true se stazione corrisponde al valore della chiave orario
     *  e orario è una chiave valida presente nella struttra dati
     * @throws NullPointerException if stazione or orario are null
     * 
     * Valori null come parametri di questo metodo possono portare a behavior inconsistenti,
     *  essendo il costruttore della classe volutamente morbido (accetta parametri null)
     */
    public Boolean trovaFermata(Stazione stazione, LocalTime orario) {

        if(stazione == null || orario == null) {

            throw new NullPointerException();
        }

        return this.programmazione.containsKey(orario) && this.programmazione.get(orario) == stazione;
    }
    
}

