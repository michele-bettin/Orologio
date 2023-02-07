#ifndef TIMER_H
#define TIMER_H

#include "Orario.h"

// Rapprenseta un semplice timer: un orario che scorre al contrario fino a che raggiunge l'ora: 00:00.
class Timer : public Orario
{
private:

public:
    Timer(int o=0, int m=0, int s=0);

    const Orario& GetTempoRimanente() const;

    bool HaFinito() const;

    // Rimuove un secondo dal timer ogni secondo che passa.
    void Avvia(CallBackTimer& c);

    // Rimuove un secondo dal timer.
    void Avvia();

    void Ferma(CallBackTimer &c);
};

#endif // TIMER_H

std::ostream& operator<<(std::ostream&, const Timer&);
