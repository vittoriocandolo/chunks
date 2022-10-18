package api;
import java.time.LocalTime;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;

import treno.GestoreTreni;
import treno.Percorso;
import treno.Stazione;
import treno.Treno;
import vagoni.Carrozza;
import vagoni.StatoVagone;
import vagoni.Vagone;

/**
 * Classe principale che gestisce il sistema di trasporto ferroviario
 * Espone solo i metodi richiesti
 * Nello stato concreto si serve di un gestore treni per alcune operazioni di collegamento fra le entità
 */
public class FrecceAPI {

    private GestoreTreni treni;

    /**
     * Ctor
     */
    public FrecceAPI() {
        
        this.treni = new GestoreTreni();
    }

    /**
     * Producer permette al client di creare un treno secondo alcuni parametri richiesti dall'esercizio
     *  il treno viene subito aggiunto al gestore (MODIFY)
     * @param motrice la motrice del treno
     * @param carrozze le carrozze che compongono il treno
     * @param capienzaMinima numero minimo di passeggeri trasportabili
     * @return nuovo Treno
     */
    public Treno creaTreno(Vagone motrice, List<Carrozza> carrozze, Integer capienzaMinima) {

        Treno nuovoTreno = new Treno(motrice, carrozze, null, capienzaMinima);
        nuovoTreno.validaDisponibilitaVagoni();

        this.treni.aggiungiTreno(nuovoTreno);

        return new Treno(motrice, carrozze, null, capienzaMinima);
    }

    /**
     * MODIFY permette di associare un percorso ad un treno (tipicamente appena creato)
     * @param treno
     * @param percorso
     * 
     * 
     */
    public void associaPercorso(Treno treno, Percorso percorso) {

        treno.setPercorso(percorso);
        treno.validaDisponibilitaVagoni();
    }

    /**
     * MODIFY permette di cambiare lo stato di tutti i componenti del treno una volta che questo parte
     * @param treno
     * @param stazione di partenza
     */
    public void setPartito(Treno treno, Stazione stazione) {

        Iterator<Vagone> iv = treno.iterator();

        while(iv.hasNext()) {

            Vagone v = iv.next();
            v.setStatoCorrente(StatoVagone.IN_USO);
            stazione.rimuoviVagone(v);
            
        }

    }

    /**
     * MODIFY permette di cambiare lo stato di tutti i componenti del treno una volta che questo arriva ad una stazione
     *  (non solo al capolinea, lo stato dei vagoni deve essere sempre coerente)
     * @param treno
     * @param stazione
     */
    public void setArrivato(Treno treno, Stazione stazione) {

        Iterator<Vagone> iv = treno.iterator();

        while(iv.hasNext()) {

            Vagone v = iv.next();
            v.setStatoCorrente(StatoVagone.IN_USO);
            stazione.aggiungiVagone(v);
            
        }

    }

    /**
     * MODIFY permette di cambiare lo stato di un vagone, mettendolo in manutenzione presso una stazione
     * @param vagone da manutenere
     * @param stazione dove si trova il vagone
     */
    public void setManutenzione(Vagone vagone, Stazione stazione) {

            vagone.setStatoCorrente(StatoVagone.IN_MANUTENZIONE);
            stazione.aggiungiVagone(vagone);
            
    }


    /**
     * MODIFY permette di cambiare lo stato di un vagone, mettendolo in "ready" presso una stazione
     * @param vagone pronto
     * @param stazione dove si trova
     *
     */
    public void setPronto(Vagone vagone, Stazione stazione) {

        vagone.setStatoCorrente(StatoVagone.PRONTO);
        stazione.aggiungiVagone(vagone); // ?
        
    }

    /**
     * Observer
     * @return lista dei treni in corsa
     */
    public List<Treno> treniInCorsa() {

        return this.treni.getTreniInCorsa();
    }

    /**
     * Observer
     * @param orario momento in cui cercare
     * @return lista dei treni in corsa in quel momento
     */
    public List<Treno> treniInCorsa(LocalTime orario) {

        return this.treni.getTreniInCorsa(orario);
    }

    /**
     * Observer
     * @return lista dei vagoni che compongono i treni in corsa (tutti assieme, non divisi per treno)
     */
    public List<Vagone> vagoniInCorsa() {

        List<Vagone> vagoni = new ArrayList<>();

        List<Treno> treniInCorsa = this.treniInCorsa();

        Iterator<Treno> it = treniInCorsa.listIterator();
        
        while(it.hasNext()) {

            Treno t = it.next();
            Iterator<Vagone> iv = t.iterator();

            vagoni.add(t.getMotrice());
            
            while(iv.hasNext()) {

                vagoni.add(iv.next());
            }

        }

        return vagoni;
    }

    /**
     * Observer
     * @return lista dei vagoni che compongono i treni in corsa, suddivisi in liste, per treno
     */
    public List<List<Vagone>> vagoniInCorsaSplit() {

        List<List<Vagone>> result = new ArrayList<>();

        List<Treno> treniAttivi = this.treniInCorsa();

        Iterator<Treno> it = treniAttivi.listIterator();

        while(it.hasNext()) {

            Treno t = it.next();

            List<Vagone> vagoni = new ArrayList<>();
            vagoni.add(t.getMotrice());

            Iterator<Vagone> iv = t.iterator();

            while(iv.hasNext()) {

                vagoni.add(iv.next());
            }

            result.add(vagoni);
        }

        return result;
    }

    /**
     * Observer
     * @param orario momento in cui cercare
     * @return lista dei vagoni che compongono i treni in corsa all'orario dato, suddivisi in liste, per treno
     */
    public List<List<Vagone>> vagoniInCorsaSplit(LocalTime orario) {

        List<List<Vagone>> result = new ArrayList<>();

        List<Treno> treniAttivi = this.treniInCorsa(orario);

        Iterator<Treno> it = treniAttivi.listIterator();

        while(it.hasNext()) {

            Treno t = it.next();

            List<Vagone> vagoni = new ArrayList<>();
            vagoni.add(t.getMotrice());

            Iterator<Vagone> iv = t.iterator();

            while(iv.hasNext()) {

                vagoni.add(iv.next());
            }

            result.add(vagoni);
        }

        return result;
    }

    /**
     * Observer
     * @param stazione dove si trovano i rotabili
     * @param orario istante in cui cercare
     * @return lista dei vagoni che si trovano presso una stazione nel momento dato
     */
    public List<Vagone> materialeInStazione(Stazione stazione, LocalTime orario) {

        List<Vagone> result = new ArrayList<>();

        Iterator<Treno> it = this.treni.iterator();

        while(it.hasNext()) {

            Treno t = it.next();

            if(t.getPercorso().trovaFermata(stazione, orario)) {

                Iterator<Vagone> iv = t.iterator();

                while(iv.hasNext()) {

                    result.add(iv.next());
                }
            }
        }

        return result;
    }

}

