#ifndef DATA_H
#define DATA_H

#include <string>
#include "CallBackTimer.h"
#include <iostream>
#include <ctime>
#include <string>

// Rappresenta una semplice data nel formato: giorno, mese e anno.
class Data
{
private:
    unsigned int Giorno;
    unsigned int Mese;
    unsigned int Anno;

    static const std::string NOMI_MESI[];

public:
    Data(int g = 0, int m = 0, int a = 0);

    // Imposta la data corrente sincronizzandola con quella del computer.
    void ImpostaDataCorrente();

    int GetAnno() const;

    std::string GetMese() const;

    int GetGiorno() const;

    virtual std::string ToString() const;

    // Compara l' oggetto data corrente con quella reale del computer sommata al fuso orario indicato ogni secondo.
    virtual void Avvia(CallBackTimer& c, int fuso);

    // Compara l' oggetto data corrente con quella reale del computer sommata al fuso orario indicato.
    virtual void Avvia(int fuso);
};

std::ostream& operator<<(std::ostream&, const Data&);


#endif // DATA_H
