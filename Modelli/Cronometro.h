#ifndef CRONOMETRO_H
#define CRONOMETRO_H

#include "Orario.h"

// Rappresenta un semplice cronometro: un orario inizializzato a 00:00 che avanza di un secondo ogni secondo.
class Cronometro : public Orario
{
private:
    unsigned int Centesimi;

public:
    Cronometro(int o=0, int m=0, int s=0, int c=0);

    int GetCentesimi() const;

    std::string ToString() const;

    void Azzera();

    // Incrementa di un secondo il cronometro ogni secondo
    void Avvia(CallBackTimer& c);

    // Incrementa di un secondo il cronometro
    void Avvia();

    void Ferma(CallBackTimer &c);
};

#endif // CRONOMETRO_H

std::ostream& operator<<(std::ostream&, const Cronometro&);
