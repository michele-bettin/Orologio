#ifndef SVEGLIA_H
#define SVEGLIA_H

#include "Orario.h"

// Rappresenta una sveglia: dato un orario (il termine della sveglia) si fa il conto alla rovescia
// per arrivare a quel determinato orario a partire dall'orario corrente
class Sveglia : public Orario
{
private:
    Orario* OraAttuale;
public:
    Sveglia(int o=0, int m=0, int s=0, Orario* oA=nullptr);

    Orario GetTempoRimanente() const;

    std::string ToString() const;

    // Questo metodo confida sul fatto che OraAttuale punti ad un oggetto orario che
    // è costantemente aggiornato da un callBack. Fatta questa premessa, il metodo fa
    // semplicemente un confronto tra i due oggetti orario e la sveglia "suonerà"
    // quando questi due oggetti segneranno lo stesso orario.
    bool HaFinito() const;
};

#endif // SVEGLIA_H

std::ostream& operator<<(std::ostream& os, const Sveglia& s);
