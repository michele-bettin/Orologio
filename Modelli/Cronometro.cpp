#include "Cronometro.h"

Cronometro::Cronometro(int o, int m, int s, int c)
    : Orario(o, m, s), Centesimi(c)
{}

int Cronometro::GetCentesimi() const
{
    return Centesimi;
}

std::string Cronometro::ToString() const {
    return Orario::ToString() + " , " + std::to_string(Centesimi) + "0";
}

void Cronometro::Azzera() {
    SetSecondi(0);
    Centesimi = 0;
}

void Cronometro::Avvia(CallBackTimer &c)
{
    c.start(100, [&]()-> void {

        Avvia();

    });
}

void Cronometro::Avvia()
{
    Centesimi++;
    if (Centesimi >= 10)
    {
        Centesimi = 0;
        Orario::Avvia();
    }
}

void Cronometro::Ferma(CallBackTimer &c) {
    c.stop();
}

std::ostream& operator<<(std::ostream& os, const Cronometro& c1)
{
    return os << dynamic_cast<const Orario&>(c1) << "  " << c1.GetCentesimi();
}

