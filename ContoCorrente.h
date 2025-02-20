#ifndef CONTOCORRENTE_H
#define CONTOCORRENTE_H

#include "Transazione.h"
#include "Observer.h"
#include <vector>

class ContoCorrente {
private:
    float saldo;
    vector<Transazione*> transazioni;
    vector<Observer*> observers;
    const string filename = "conto.txt";

public:
    ContoCorrente();
    ~ContoCorrente();

    void aggiungi_transazione(Transazione* transazione);
    void salva_su_file() const;
    void visualizza_transazioni() const;

    void aggiungi_observer(Observer* observer);
    void notifica_observer();
};

#endif
