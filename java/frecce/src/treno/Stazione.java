package treno;

import java.util.ArrayList;
import java.util.List;
import vagoni.Vagone;

/**
 * ADT per una stazione ferroviaria
 * Questa classe rappresenta una stazione ed è l'entità su cui si basano i percorsi dei treni
 *  ed è parte necessaria per la gestione dei materiali rotabili
 * Lo stato concreto è basato su una lista di Vagoni che rappresenta i materiali rotabili
 *  presenti, in ogni momento, presso la stazione
 * La classe permette di aggiungere e rimuovere elementi dalla lista
 *  e di interrogarla per sapere se un vagone si trova, in quel momento, presso la stazione
 */
public class Stazione {

    private List<Vagone> vagoniPresenti;

    /**
     * Ctor standard per creare una stazione vuota
     */
    public Stazione() {
    
        this.vagoniPresenti = new ArrayList<>();
    }

    /**
     * Ctor per creare una stazione assegnando già dei rotabili
     * @param nuoviVagoni
     */
    public Stazione(List<Vagone> nuoviVagoni) {
        
        this.vagoniPresenti = nuoviVagoni;
    }

    public void aggiungiVagone(Vagone nuovoVagone) {

        this.vagoniPresenti.add(nuovoVagone);
    }

    public void rimuoviVagone(Vagone vagone) {

        this.vagoniPresenti.remove(vagone);
    }

    public boolean contieneVagone(Vagone vagone) {

        return this.vagoniPresenti.contains(vagone);
    }

}

