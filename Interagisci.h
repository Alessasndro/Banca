#ifndef INTERAGISCI_H
#define INTERAGISCI_H

#include "ContoCorrente.h"

class Interagisci {
private:
    ContoCorrente& conto;

public:
    Interagisci(ContoCorrente& conto);
    void mostra_menu();
};

#endif
