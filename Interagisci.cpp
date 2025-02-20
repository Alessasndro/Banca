#include "Interagisci.h"
#include <iostream>

Interagisci::Interagisci(ContoCorrente& conto) : conto(conto) {}

void Interagisci::mostra_menu() {
    int scelta;
    do {
        cout << "\n1. Aggiungi Transazione Ingresso";
        cout << "\n2. Aggiungi Transazione Uscita";
        cout << "\n3. Visualizza Transazioni";
        cout << "\n4. Esci\nScelta: ";
        cin >> scelta;

        if (scelta == 3) conto.visualizza_transazioni();
    } while (scelta != 4);
}
