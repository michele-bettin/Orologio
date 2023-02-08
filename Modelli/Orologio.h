#include "Orario.h"
#include "Data.h"
#include <iostream>

#ifndef OROLOGIO_H
#define OROLOGIO_H

// Rappresenta un classico orologio mettendo inseme un orario, una data e un fuso orario.
class Orologio: public Orario, public Data
{
private:
    int fusoOrario;
public:
    Orologio(int f=0, int o=0, int min=0, int sec=0, int g=0, int mes=0, int a=0);

    int getFusoOrario() const;

    void ImpostaFusoOrario(int zone);

    std::string ToString() const;

    // Aggiorna l'orologio corrente ogni secondo richiamando i metodo di aggiornamento delle classi figlie.
    void Avvia(CallBackTimer& c);

    // Aggiorna l'orologio corrente ogni secondo richiamando i metodi di singolo aggiornamento delle classi figlie.
    void Avvia();

};

#endif // OROLOGIO_H

std::ostream& operator<<(std::ostream&, const Orologio&);
