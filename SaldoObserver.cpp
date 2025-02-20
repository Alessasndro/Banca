#include "SaldoObserver.h"

SaldoObserver::SaldoObserver(ContoCorrente& conto) : conto(conto) {
    conto.aggiungi_observer(this);
}

void SaldoObserver::aggiorna(float nuovo_saldo) {
    cout << "Il saldo è stato aggiornato: " << nuovo_saldo << " euro" << endl;
}
