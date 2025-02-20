#ifndef SALDOOBSERVER_H
#define SALDOOBSERVER_H

#include "Observer.h"
#include "ContoCorrente.h"
#include <iostream>

class SaldoObserver : public Observer {
private:
    ContoCorrente& conto;

public:
    SaldoObserver(ContoCorrente& conto);
    void aggiorna(float nuovo_saldo) override;
};

#endif
