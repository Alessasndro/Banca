#include "Interagisci.h"
#include "SaldoObserver.h"

int main() {
    ContoCorrente conto;
    SaldoObserver saldoObserver(conto);
    Interagisci interazione(conto);
    interazione.mostra_menu();
    return 0;
}