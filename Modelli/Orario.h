#ifndef ORARIO_H
#define ORARIO_H

#include <string>
#include <iostream>
#include <time.h>
#include "Callbacktimer.h"

// Rappresenta un semplice orario composto da: ore, minuti e secondi.
class Orario
{

// Dichiarazioni di amicizia con le funzioni di overloading dei vari operatori che hanno
// bisogno di accedere alla parte privata del mio codice
friend Orario operator+(const Orario&, const Orario&);
friend Orario operator-(const Orario&, const Orario&);
friend bool operator==(const Orario&, const Orario&);
friend bool operator>(const Orario&, const Orario&);
friend bool operator<(const Orario&, const Orario&);

private:
    // Permette al nostro orario di non sforare mai l'ora 23:59 e quindi fa ripartire l'orario dalle 00:00.
    // Va richiamata ogni volta che andiamo a modificare il nostro orario.
    void NormalizzaOrario();

protected:
    unsigned int secondi;

public:
    // Numero di secondi in un minuto
    static const unsigned int SECONDI_MINUTO;

    // Numero di secondi in un ora
    static const unsigned int SECONDI_ORA;

    // Numero di secondi in un giorno
    static const unsigned int SECONDI_GIORNO;

    // Numero di minuti in un ora
    static const unsigned int MINUTI_ORA;

    // Numero di ore in un giorno
    static const unsigned int ORE_GIORNO;

    Orario(int ore = 0, int minuti = 0, int secondi = 0);


    virtual ~Orario();

    int Ore() const;

    int Minuti() const;

    int Secondi() const;

    void SetSecondi(int s);

    void AvanzaOre(int ore);

    void AvanzaMinuti(int minuti);

    void AvanzaSecondi(int secondi);

    void ImpostaOraUTC();

    // Aumenta "artificialmente" le ore, ma non si salva in nessun modo il fuso orario passato.
    virtual void ImpostaFusoOrario(int zone);

    virtual std::string ToString() const;

    // Aggiorna l'orario di un secondo ogni secondo.
    virtual void Avvia(CallBackTimer& c);

    // Aggiorna l'orario di un secondo.
    virtual void Avvia();

};

Orario operator+(const Orario& o1, const Orario& o2);

Orario operator-(const Orario& o1, const Orario& o2);

bool operator==(const Orario& o1, const Orario& o2);

bool operator>(const Orario& o1, const Orario& o2);

bool operator<(const Orario& o1, const Orario& o2);


std::ostream& operator<<(std::ostream&, const Orario&);

#endif // ORARIO_H
