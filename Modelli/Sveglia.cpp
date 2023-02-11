#include "Sveglia.h"

Sveglia::Sveglia(int o, int m, int s,  Orario* oA)
    : Orario(o, m, s), OraAttuale(oA)
{}

Orario Sveglia::GetTempoRimanente() const
{
    return *this - *OraAttuale;
}

std::string Sveglia::ToString() const
{
    std::string o = Ore() < 10 ? "0" + std::to_string(Ore()) : std::to_string(Ore());
    std::string m = Minuti() < 10 ? "0" + std::to_string(Minuti()) : std::to_string(Minuti());
    return o + " : " + m;
}

bool Sveglia::HaFinito() const
{
    return *this == *OraAttuale;
}

std::ostream& operator<<(std::ostream& os, const Sveglia& s)
{
    return os << "La sveglia suonera' tra: " << s.GetTempoRimanente();
}
