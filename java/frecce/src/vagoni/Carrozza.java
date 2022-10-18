package vagoni;

public class Carrozza extends Vagone {

    /**
     * ADT per una carrozza ferroviaria
     * Questa classe può rappresentare una carrozza passeggeri, letto o ristorante
     * Lo stato concreto è basato su un'enumerazione che definisce il tipo di carrozza
     *  e un intero per rappresentare la massima capienza della carrozza
     * La classe mette a disposizione in aggiunta alla sua super solo due getter per i campi appena descritti
     */

    private TipoCarrozza sottotipo;
    private Integer capienza;

    /**
     * Ctor
     * @param sottotipo REQUIRE not null
     *  definisce il tipo di carrozza
     * @param capienza REQUIRE not null
     *  definisce la capienza massima della carrozza
     */
    public Carrozza(TipoCarrozza sottotipo, Integer capienza) {

        super(TipoVagone.CARROZZA);
        this.sottotipo = sottotipo;
        this.capienza = capienza;
    }

    public TipoCarrozza getSottotipo() {
        return sottotipo;
    }

    public Integer getCapienza() {
        return capienza;
    }
    
}

