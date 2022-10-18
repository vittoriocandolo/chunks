package treno;

import java.time.LocalTime;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Iterator;
import java.util.List;
import java.util.Map;
import java.util.NoSuchElementException;

import vagoni.Carrozza;
import vagoni.StatoVagone;
import vagoni.TipoCarrozza;
import vagoni.Vagone;

public class Treno {

    /**
     * ADT per un treno
     * La classe rappresenta un treno tramite un campo di tipo vagone dedicato alla motrice,
     *  una lista di carrozze composta da vagoni passeggeri, ristorante o letto,
     *  un percorso che definisce l'attuale percorso del treno e di tutti i rotabili di cui è composto,
     *  un campo intero che definisce la capienza minima del treno, intesa come un valore minimo di passeggeri
     *      inserito dal client in fase di creazione dell'oggeto, valore che deve poi trovare riscontro
     *      nei componenti del treno
     * La classe permette di:
     *  Ottenere la motrice del treno
     *  Ottenere il percorso del treno
     *  Settare il percorso del treno
     *  Ottenere una struttra dati che rappresenta la struttura del treno intesa come (K1 CarrozzePassegger, k2 Carrozze...)
     *  Riconoscere se il treno è in corsa o meno
     *  
     * La classe include inoltre una serie di metodi necessari a garantire una corretta costruzione delle istanze e
     *  il supporto ad un iteratore
     */
    private Vagone motrice;
    private List<Carrozza> carrozze;
    private Percorso percorsoAttuale;
    private Integer capienzaMinima;

    /**
     * Ctor
     * @param motrice la motrice del treno
     * @param carrozze lista di carrozze che lo compongono
     * @param percorsoAttuale percorso attuale
     * @param capienzaMinima valore minimo di passeggeri trasportabili
     * @throws NullPointerException se la motrice è nulla
     */
    public Treno(Vagone motrice, List<Carrozza> carrozze, Percorso percorsoAttuale, Integer capienzaMinima) throws NullPointerException {

        this.motrice = motrice;

        if(this.motrice == null) {

            throw new NullPointerException();
        }

        this.carrozze = carrozze;

        this.validaCarrozze();

        this.percorsoAttuale = percorsoAttuale;
        this.capienzaMinima = capienzaMinima;
    }

    public Vagone getMotrice() {

        return motrice;
    }

    public Percorso getPercorso() {

        return percorsoAttuale;
    }

    public void setPercorso(Percorso percorso) {

        this.percorsoAttuale = percorso;
    }

    /**
     * Observer
     * @return struttra dati che descrive la composizione del treno (solo le carrozze, la motrice c'è sempre ed è una sola)
     */
    public Map<Integer, TipoCarrozza> getStrutturaCarrozze() {

        Map<Integer, TipoCarrozza> struttura = new HashMap<>();

        Integer nPasseggeri, nLetto, nRistorante;
        nPasseggeri = nLetto = nRistorante = 0;

        Iterator<Carrozza> i = this.carrozze.listIterator();

        while(i.hasNext()) {

            Carrozza c = i.next();

            if(c.getSottotipo() == TipoCarrozza.PASSEGGERI) {

                nPasseggeri++;
            }
            else if(c.getSottotipo() == TipoCarrozza.LETTO) {

                nLetto++;
            }
            else {

                nRistorante++;
            }

        }

        struttura.put(nPasseggeri, TipoCarrozza.PASSEGGERI);
        struttura.put(nRistorante, TipoCarrozza.RISTORANTE);
        struttura.put(nLetto, TipoCarrozza.LETTO);

        return struttura;
    }

    /**
     * Observer TODO: distinguere tra false e problemi
     * @return true se il treno è in corsa, false se non lo è o se si è verificata qualche inconsistenza:
     *  tutti i vagoni dovrebbero avere lo stesso valore di stato
     */
    public Boolean InCorsa() {

        Boolean inCorsa = false;

        Iterator<Vagone> iv = this.iterator();

        while(iv.hasNext()) {

            if(iv.next().getStatoCorrente() == StatoVagone.IN_USO) {

                inCorsa = true;
            }
        }

        return inCorsa;
    }

    /**
     * Metodo che chiama i vari validatori
     * @throws IllegalArgumentException se il numero di carrozze è > 8
     * @throws CarrozzaRistoranteMancanteException se il treno non disponde di una carrozza ristorante
     * @throws CarrozzaLettoMancanteException se il treno viaggia dopo le 24 e non disponde di una carrozza letto
     * @throws RotabileNonDisponibileException se il treno è composto di rotabili non disponibili alla stazione di partenza
     * @throws CapienzaInsufficienteExcepion se i componenti del treno non permettono di raggiungere la capienza minima richiesta
     */
    private void validaCarrozze() throws IllegalArgumentException, CarrozzaRistoranteMancanteException, 
        CarrozzaLettoMancanteException, RotabileNonDisponibileException, CapienzaInsufficienteExcepion {

        this.validaNumeroCarrozze();

        this.validaComposizioneCarrozze();

        // validazione disponibilità vagoni va fatta a parte

        this.validaCapienzaMinima();

    }

    private void validaNumeroCarrozze() throws IllegalArgumentException {

        if(this.carrozze.size() > 8) {

            throw new IllegalArgumentException("il numero massimo di carrozze per un treno è 8");
        }
    }

    private void validaComposizioneCarrozze() throws CarrozzaRistoranteMancanteException, CarrozzaLettoMancanteException {

        // dentro questa classe scelgo di non usare l'iteratore da me definito...
        Iterator<Carrozza> ic = this.carrozze.listIterator();
        boolean guardia = true;
        boolean conLetto = false;

        while(ic.hasNext()) {

            Carrozza c = ic.next();

            if(c.getSottotipo() == TipoCarrozza.LETTO) {

                conLetto = true;

            }

            if(c.getSottotipo() == TipoCarrozza.RISTORANTE) {

                guardia = false;
            }

            if(guardia) {

                throw new CarrozzaRistoranteMancanteException();
            }
        }

        LocalTime mezzanotte = LocalTime.of(24, 00, 00); // not sure maybe (00, 00, 00);

        if(this.percorsoAttuale.getOrarioArrivo().isAfter(mezzanotte) && ! conLetto) {

                throw new CarrozzaLettoMancanteException();
        }
    }

    public void validaDisponibilitaVagoni() throws RotabileNonDisponibileException {

        Iterator<Carrozza> ic = this.carrozze.listIterator();
        Stazione partenza = this.percorsoAttuale.getStazionePartenza();

        while(ic.hasNext()) {

            Carrozza c = ic.next();

            if(! partenza.contieneVagone(c) || ! c.getStatoCorrente().equals(StatoVagone.PRONTO)) {

                throw new RotabileNonDisponibileException("Carrozze non disponibili");

            }

            if(! partenza.contieneVagone(this.motrice) || ! this.motrice.getStatoCorrente().equals(StatoVagone.PRONTO)) {

                throw new RotabileNonDisponibileException("Motrice non disponibile");
            }
        }
    }

    private void validaCapienzaMinima() throws CapienzaInsufficienteExcepion {

        Iterator<Carrozza> ic = this.carrozze.listIterator();
        Integer capienzaTreno = 0;

        while(ic.hasNext()) {

            capienzaTreno+= ic.next().getCapienza();

        }

        if(capienzaTreno < this.capienzaMinima) {

            throw new CapienzaInsufficienteExcepion();
        }
    }

    public Iterator iterator() {

        return new TrenoIterator(this);
    }

    private class TrenoIterator implements Iterator<Vagone> {

        /**
         * Inner class per implementare l'iteratore
         */
        private final List<Vagone> vagoni;
        private Vagone current;

        public TrenoIterator(Treno tr) {

            if(tr.motrice == null || tr.carrozze == null) {

                throw new NullPointerException();
            }

            this.vagoni = new ArrayList<>();
            vagoni.add(tr.motrice);
            vagoni.addAll(tr.carrozze); 
            
            this.current = this.vagoni.stream().findFirst().get();
        }

        @Override
        public boolean hasNext() {
            
            return this.vagoni.indexOf(current) < this.vagoni.size();
        }

        @Override
        public Vagone next() {

            if(this.vagoni.indexOf(current) < this.vagoni.size()) {

                Vagone v = this.vagoni.get(this.vagoni.indexOf(current) + 1);
                
                return v;

            } else {

                throw new NoSuchElementException("Superato ultimo elemento");
            }
        }
    }
    
}

