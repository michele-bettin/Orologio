#include "Orario.h"


bool IsInRange(int numero, int from, int to) {
    return numero >= from && numero <= to;
}

void Orario::NormalizzaOrario() {
    secondi = secondi % SECONDI_GIORNO;
}

unsigned int const Orario::SECONDI_MINUTO = 60;
unsigned int const Orario::SECONDI_ORA = 3600;
unsigned int const Orario::SECONDI_GIORNO = 86400;
unsigned int const Orario::ORE_GIORNO = 24;

Orario::Orario(int ore, int minuti, int sec) {
    if (IsInRange(ore, 0, 23) && IsInRange(minuti, 0, 60) && IsInRange(sec, 0, 60))
        secondi = ore * 3600 + minuti * 60 + sec;
    else
        secondi = 0;
    NormalizzaOrario();
}

Orario::~Orario()
{}

int Orario::Ore() const {
    return secondi / SECONDI_ORA;
}

int Orario::Minuti() const {
    return (secondi / SECONDI_MINUTO) % SECONDI_MINUTO;
}

int Orario::Secondi() const {
    return secondi % SECONDI_MINUTO;
}

void Orario::SetSecondi(int s) {
    secondi = s;
    NormalizzaOrario();
}

void Orario::AvanzaOre(int ore) {
    secondi += ore * SECONDI_ORA;
    NormalizzaOrario();
}

void Orario::AvanzaMinuti(int minuti) {
    secondi += minuti * SECONDI_MINUTO;
    NormalizzaOrario();
}

void Orario::AvanzaSecondi(int sec) {
    secondi += sec;
    NormalizzaOrario();
}


void Orario::ImpostaOraUTC() {
    time_t tmi;

    struct tm* utcTime;

    time(&tmi);
    utcTime = gmtime(&tmi);

    *this = Orario((utcTime->tm_hour) % 24, utcTime->tm_min, utcTime->tm_sec);
}

void Orario::ImpostaFusoOrario(int zone) {
    AvanzaOre(zone);
}

std::string Orario::ToString() const {
    //return std::to_string(Ore()) + " : " + std::to_string(Minuti()) + " : " + std::to_string(Secondi());
    std::string o = Ore() < 10 ? "0" + std::to_string(Ore()) : std::to_string(Ore());
    std::string m = Minuti() < 10 ? "0" + std::to_string(Minuti()) : std::to_string(Minuti());
    std::string s = Secondi() < 10 ? "0" + std::to_string(Secondi()) : std::to_string(Secondi());
    return o + " : " + m + " : " + s;
}

void Orario::Avvia(CallBackTimer& c) {
    /*MyParallelJob t1([&]()-> void {

        //this->AvanzaSecondi(1);
        std::cout << "oiuiui "<<std::endl;
    });
    t1.startThread();*/

    c.start(1000, [&]()-> void {

        Orario::Avvia();

    });
}

void Orario::Avvia() {
    secondi++;
    NormalizzaOrario();
}







Orario operator+(const Orario& o1, const Orario& o2) {
    Orario aux;
    aux.secondi = (o1.secondi + o2.secondi) % Orario::SECONDI_GIORNO;
    return aux;
}

Orario operator-(const Orario& o1, const Orario& o2)
{
    Orario aux;
    int t1 = o1.secondi;
    int t2 = o2.secondi;
    int somma = t1 - t2;
    if (somma < 0) {
        aux.secondi = Orario::SECONDI_GIORNO + somma;
    } else {
        aux.secondi = (o1.secondi - o2.secondi) % Orario::SECONDI_GIORNO;
    }

    return aux;
}

bool operator==(const Orario& o1, const Orario& o2)
{
    return o1.secondi == o2.secondi;
}

bool operator>(const Orario& o1, const Orario& o2)
{
    return o1.secondi > o2.secondi;
}

bool operator<(const Orario& o1, const Orario& o2)
{
    return o1.secondi < o2.secondi;
}

std::ostream& operator<<(std::ostream& os, const Orario& o)
{
    return os << o.Ore() << ':' << o.Minuti() << ':' << o.Secondi();
}
