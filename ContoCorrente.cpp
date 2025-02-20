#include "ContoCorrente.h"
#include <fstream>
#include <iostream>

ContoCorrente::ContoCorrente() : saldo(0.0f) {}

ContoCorrente::~ContoCorrente() {
    for (auto transazione : transazioni) {
        delete transazione;
    }
}

void ContoCorrente::aggiungi_transazione(Transazione* transazione) {
    transazioni.push_back(transazione);
    if (dynamic_cast<TransazioneIngresso*>(transazione)) {
        saldo += transazione->get_importo();
    } else if (dynamic_cast<TransazioneUscita*>(transazione)) {
        saldo -= transazione->get_importo();
    }
    salva_su_file();
    notifica_observer();
}

void ContoCorrente::salva_su_file() const {
    ofstream file(filename);
    if (file.is_open()) {
        file << saldo << endl;
        for (const auto& transazione : transazioni) {
            transazione->salva_su_file(file);
        }
        file.close();
    }
}

void ContoCorrente::visualizza_transazioni() const {
    cout << "Saldo attuale: " << saldo << " euro" << endl;
    for (const auto& transazione : transazioni) {
        cout << transazione->get_tipo() << " - "
             << transazione->get_importo() << " euro - "
             << transazione->get_descrizione() << " - "
             << transazione->get_data() << endl;
    }
}

void ContoCorrente::aggiungi_observer(Observer* observer) {
    observers.push_back(observer);
}

void ContoCorrente::notifica_observer() {
    for (Observer* observer : observers) {
        observer->aggiorna(saldo);
    }
}
