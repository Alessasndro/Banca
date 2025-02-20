#include "Transazione.h"

Transazione::Transazione(float importo, const string& descrizione, const string& data)
    : importo(importo), descrizione(descrizione), data(data) {}

void Transazione::salva_su_file(ofstream& file) const {
    file << importo << endl;
    file << descrizione << endl;
    file << data << endl;
}

void Transazione::leggi_da_file(ifstream& file) {
    file >> importo;
    file.ignore();
    getline(file, descrizione);
    getline(file, data);
}

float Transazione::get_importo() const { return importo; }
string Transazione::get_descrizione() const { return descrizione; }
string Transazione::get_data() const { return data; }

TransazioneIngresso::TransazioneIngresso(float importo, const string& descrizione, const string& data)
    : Transazione(importo, descrizione, data) {}

void TransazioneIngresso::salva_su_file(ofstream& file) const {
    file << "Ingresso" << endl;
    Transazione::salva_su_file(file);
}

string TransazioneIngresso::get_tipo() const { return "Ingresso"; }

TransazioneUscita::TransazioneUscita(float importo, const string& descrizione, const string& data)
    : Transazione(importo, descrizione, data) {}

void TransazioneUscita::salva_su_file(ofstream& file) const {
    file << "Uscita" << endl;
    Transazione::salva_su_file(file);
}

string TransazioneUscita::get_tipo() const { return "Uscita"; }
