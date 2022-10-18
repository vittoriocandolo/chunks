// TODO LocalTime e Eccezioni

package test;

import java.time.LocalTime;
import java.util.ArrayList;
import java.util.List;

import api.FrecceAPI;
import treno.Percorso;
import treno.Stazione;
import treno.Treno;
import vagoni.Carrozza;
import vagoni.TipoCarrozza;
import vagoni.TipoVagone;
import vagoni.Vagone;

public class Client {

    /**
     * Classe main che simula un client
     * Viene fornito un parziale esempio di behavior al solo scopo di mostrare le chiamate ai metodi richiesti
     *
     */

    public static void main(String[] args) {

        // creo istanza api
        FrecceAPI myAPI = new FrecceAPI();

        // creo motrice
        Vagone myMotrice = new Vagone(TipoVagone.MOTRICE);

        // creo carrozze (nel numero e del tipo minimo da non causare errori)
        Carrozza myCarrozzaPasseggeri = new Carrozza(TipoCarrozza.PASSEGGERI, 80);
        Carrozza myCarrozzaRistorante = new Carrozza(TipoCarrozza.RISTORANTE, 40);

        // creo una lista di carrozze per poter usare poi il metodo creaTreno con la segnatura proposta e aggiungo le mie carrozze
        List<Carrozza> myCarrozze = new ArrayList<>();
        myCarrozze.add(myCarrozzaPasseggeri);
        myCarrozze.add(myCarrozzaRistorante);

        // imposto capacita minima
        Integer myCapacitaMinima = 100;
        
        Treno myTreno = myAPI.creaTreno(myMotrice, myCarrozze, myCapacitaMinima); // 1

        // creo lista di vagoni per aggiungerli alla stazione
        // TODO che faccia da solo il metodo associaPercorso
        List<Vagone> myVagoni = new ArrayList<>();
        myVagoni.add(myMotrice);
        myVagoni.addAll(myCarrozze);

        // creo stazione di partenza e di arrivo (vuota)
        Stazione myStazioneUD = new Stazione(myVagoni);
        Stazione myStazionePD = new Stazione();

        // assegno alcuni orari per comodità
        LocalTime myOrarioPartenza = LocalTime.now();
        LocalTime myOrarioArrivo = LocalTime.now().plusHours(2);

        // creo percorso
        Percorso myPercorso = new Percorso(myOrarioPartenza, myStazioneUD, null, null, myOrarioArrivo, myStazionePD);

        myAPI.associaPercorso(myTreno, myPercorso); // 2

        myAPI.setPartito(myTreno, myStazioneUD); // 3

        myAPI.setArrivato(myTreno, myStazionePD); // 4

        myAPI.setManutenzione(myMotrice, myStazionePD); // 5

        myAPI.setPronto(myMotrice, myStazionePD); // 6

        List<Treno> myTreniAttivi = myAPI.treniInCorsa(); // 7A

        LocalTime myTime = LocalTime.now().minusHours(1);

        List<Treno> myTreniAttiviTempo = myAPI.treniInCorsa(myTime); //7B
        
        List<Vagone> myVagoniAttivi = myAPI.vagoniInCorsa(); // 8A

        List<List<Vagone>> myVagoniAttiviBene = myAPI.vagoniInCorsaSplit(); // 8A

        List<List<Vagone>> myVagoniAttiviBeneTime = myAPI.vagoniInCorsaSplit(myTime); // 8B

        List<Vagone> myVagoniInStazione = myAPI.materialeInStazione(myStazionePD, myOrarioArrivo); // 9
    }
    
}

