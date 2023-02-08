#include "Data.h"

const std::string Data::NOMI_MESI[] =
{
    "Mese non valido",
    "Gennaio",
    "Febbraio",
    "Marzo",
    "Aprile",
    "Maggio",
    "Giugno",
    "Luglio",
    "Agosto",
    "Settembre",
    "Ottobre",
    "Novembre",
    "Dicembre"
};

Data::Data(int g, int m, int a)
    : Giorno(g), Mese(m), Anno(a)
{}

void Data::ImpostaDataCorrente()
{
    const std::time_t now = std::time(nullptr);
    // convert it to (local) calendar time
    const std::tm calendar_time = *std::localtime(std::addressof(now));

    Giorno = calendar_time.tm_mday;
    Mese = calendar_time.tm_mon + 1;
    Anno = calendar_time.tm_year + 1900;
}

int Data::GetAnno() const
{
    return Anno;
}

std::string Data::GetMese() const
{
    return NOMI_MESI[Mese];
}

int Data::GetGiorno() const
{
    return Giorno;
}

std::string Data::ToString() const {
    return std::to_string(GetGiorno()) + ' ' + GetMese() + ' ' + std::to_string(GetAnno());
}

void Data::Avvia(CallBackTimer& c, int fuso)
{

    c.start(1000, [&]()-> void {

        Data::Avvia(fuso);

    });
}

void Data::Avvia(int fuso)
{
    const std::time_t now = std::time(nullptr);
    const std::tm utc_time = *std::gmtime(std::addressof(now));
    const int time_offset = fuso; // offset di "fuso" ore rispetto a UTC

    std::tm local_time = utc_time;
    local_time.tm_hour += time_offset;
    std::mktime(&local_time);

    (Giorno != (unsigned)local_time.tm_mday) && (Giorno = (unsigned)local_time.tm_mday);
    (Mese != (unsigned)local_time.tm_mon + 1) && (Mese = (unsigned)local_time.tm_mon + 1);
    (Anno != ((unsigned)local_time.tm_year + 1900)) && (Anno = ((unsigned)local_time.tm_year + 1900));

    /* CODICE UGUALE A QUELLO SOPRA MA CHE NON TIENE IN CONSIDERAZIONE IL FUSO ORARIO
    const std::time_t now = std::time(nullptr);
    const std::tm calendar_time = *std::localtime(std::addressof(now));

    (Giorno != (unsigned)calendar_time.tm_mday) && (Giorno = (unsigned)calendar_time.tm_mday);
    (Mese != (unsigned)calendar_time.tm_mon + 1) && (Mese = (unsigned)calendar_time.tm_mon + 1);
    (Anno != ((unsigned)calendar_time.tm_year + 1900)) && (Anno = ((unsigned)calendar_time.tm_year + 1900));
    */
}

std::ostream& operator<<(std::ostream& os, const Data& d)
{

    return os << d.GetGiorno() << ' ' << d.GetMese() << ' ' << d.GetAnno();

}









