#ifndef ARRAYLIST_H_
#define ARRAYLIST_H_

#include <string>
#include <iostream>
#include <sstream>
#include <cstdlib>

template<class T>
class ArrayList {

    public:
        //~ Costruttori -----------------------------------------------
        ArrayList();
        ArrayList(int dimensione);
        ArrayList(const ArrayList<T>& lista);
        ArrayList(const ArrayList<T>&lista, int capacita);
        ~ArrayList();

        //~ Metodi ---------------------------------------------------
        void Aggiungi(T& elemento);
        void Aggiungi(const T & elemento, int indice);
        void Aggiungi(const ArrayList<T> & lista, int indice);
        void Aggiungi(const ArrayList<T> & lista);
        const T * Rimuovi(int indice);
        void RimuoviTutti();
        bool Sposta(int indice1, int indice2);
        T * Get(int indice) const;
        //~ Metodi Getter
        int GetDimensione() const;
        int GetCapacita() const;
        std::string toString() const;

    private:
        // L'Array che c'è alla base del nostro ArrayList.
        T * Array;
        // Il corrente numero di elementi nell'ArrayList.
        int Dimensione;
        // La capacità totale dell'Array presente alla base dell'ArrayList.
        int Capacita;

        //~Metodi -----------------------//
        void Rialloca();
        void Rialloca(int nuovaDimensione);
};

#endif /* ARRAYLIST_H_ */
