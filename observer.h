#ifndef OBSERVER_H
#define OBSERVER_H

class Observer {
public:
    virtual void aggiorna(float nuovo_saldo) = 0;
};

#endif
