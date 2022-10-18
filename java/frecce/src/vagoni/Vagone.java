package vagoni;

public class Vagone {

    /**
     * ADT per un vagone ferroviario
     * Questa classe può rappresentare una motrice oppure una carrozza
     *  ed è l'entità su cui si basa la rappresentazione dei treni
     * Lo stato concreto è basato su due enumerazioni che ne stabiliscono il tipo (motrice o carrozza)
     *  e lo stato (in uso, pronto all'uso o in manutenzione)
     * La classe mette a disposizione un getter per ottenere il tipo del vagone
     *  e getter + setter per ottenere e definire lo stato dello stesso
     */

    private TipoVagone tipo;
    private StatoVagone statoCorrente;

    /**
     * Ctor
     * @param tipo REQUIRE not null
     *  definisce se motrice o carrozza
     * I vagoni appena creati sono per default pronti
     */
    public Vagone(TipoVagone tipo) {
        
        this.tipo = tipo;
        this.statoCorrente = StatoVagone.PRONTO;
    }

    public TipoVagone getTipo() {
        return tipo;
    }

    public StatoVagone getStatoCorrente() {
        return statoCorrente;
    }

    public void setStatoCorrente(StatoVagone statoCorrente) {
        this.statoCorrente = statoCorrente;
    }
    
}

