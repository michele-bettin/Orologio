#include "Sveglia.h"

Sveglia::Sveglia(int o, int m, int s,  Orario* oA)
    : Orario(o, m, s), OraAttuale(oA)
{}

Orario Sveglia::GetTempoRimanente() const
{
    return *this - *OraAttuale;
}

bool Sveglia::HaFinito() const
{
    return *this == *OraAttuale;
}

std::ostream& operator<<(std::ostream& os, const Sveglia& s)
{
    return os << "La sveglia suonera' tra: " << s.GetTempoRimanente();
}
