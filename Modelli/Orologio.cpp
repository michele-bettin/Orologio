#include "Orologio.h"

Orologio::Orologio(int f, int o, int min, int sec, int g, int mes, int a)
    : Orario(o, min, sec), Data(g, mes, a), fusoOrario(f)
{}

int Orologio::getFusoOrario() const
{
    return fusoOrario;
}

void Orologio::ImpostaFusoOrario(int zone) {
    fusoOrario = zone;
    AvanzaOre(zone);
}

std::string Orologio::ToString() const {
    std::string f = fusoOrario >= 0 ? "+" + std::to_string(fusoOrario) : std::to_string(fusoOrario);
    return Orario::ToString() + " \n " + Data::ToString() + " \n " + "Fuso orario: " + f;
}

void Orologio::Avvia(CallBackTimer& c)
{
    Orario::ImpostaOraUTC();
    Orario::ImpostaFusoOrario(fusoOrario);
    Data::ImpostaDataCorrente();

    c.start(1000, [&]()-> void {

        Avvia();

    });
}

void Orologio::Avvia()
{

        Orario::Avvia();
        Data::Avvia();

}

std::ostream& operator<<(std::ostream& os, const Orologio& o)
{
    return os << "Fuso orario +" << o.getFusoOrario() << "  " << dynamic_cast<const Orario&>(o) << "  " << dynamic_cast<const Data&>(o);
}

