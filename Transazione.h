
#ifndef TRANSAZIONE_H
#define TRANSAZIONE_H

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Transazione {
protected:
    float importo;
    string descrizione;
    string data;

public:
    Transazione(float importo, const string& descrizione, const string& data);
    virtual ~Transazione() = default;

    virtual void salva_su_file(ofstream& file) const;
    virtual void leggi_da_file(ifstream& file);
    virtual string get_tipo() const = 0;

    float get_importo() const;
    string get_descrizione() const;
    string get_data() const;
};

class TransazioneIngresso : public Transazione {
public:
    TransazioneIngresso(float importo, const string& descrizione, const string& data);
    void salva_su_file(ofstream& file) const override;
    string get_tipo() const override;
};

class TransazioneUscita : public Transazione {
public:
    TransazioneUscita(float importo, const string& descrizione, const string& data);
    void salva_su_file(ofstream& file) const override;
    string get_tipo() const override;
};

#endif


