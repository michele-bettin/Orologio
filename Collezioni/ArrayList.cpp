#include "ArrayList.h"

//~ Classi di inizializzazione, distruzione e di reset ---------------------
/**
 * Costruttore di default,
 * crea una ArrayList di tipo T, con 20 elementi.
 */
template<class T>
ArrayList<T>::ArrayList()
{

    Array = new T[20];
    Capacita = 20;
    Dimensione = 0;
}

/**
 * Crea un ArrayList di size: dimensione
 *
 * @param dimensione La dimensione con la quale inizializzo l'ArrayList.
 */
template<class T>
ArrayList<T>::ArrayList(int dimensione)
{

    Array = new T[dimensione];
    Capacita = dimensione;
    Dimensione = 0;
}

/**
 * Crea un ArrayList di tipo T che è il doppio di
 * dimensione del passato ArrayList e aggiunge tutti gli elementi
 * dall'elenco ArrayList<T> passato, a questo ArrayList.
 *
 * Completamento in tempo O(n), dove n = la dimensione della lista passata.
 *
 * @param lista l'ArrayList di base per la costruzione della nuova lista.
 */
template<class T>
ArrayList<T>::ArrayList(const ArrayList<T>& lista)
{

    Array = new T[lista.GetDimensione() * 2];
    Capacita = lista.GetDimensione() * 2;
    Dimensione = lista.GetDimensione();

    for (int i = 0; i < lista.GetDimensione(); i++)
    {

        Array[i] = *lista.Get(i);
    }
}

/**
 * Crea un ArrayList di tipo T che ha una capacità uguale a quella passata
 * nel parametro Capacità. Questo ArrayList inizia con l'ArrayList passato.
 *
 * Nota: se la capacità passata è inferiore alla dimensione del passato
 * ArrayList, la capacità è impostata su due volte la dimensione del file
 * superato ArrayList.
 *
 * Viene eseguito in un tempo O(n) dove n è la dimensione dell'elenco passato.
 *
 * @param lista la lista da usare come base per la nuova lista.
 * @param capacita la capacità per la nuova lista.
 */
template<class T>
ArrayList<T>::ArrayList(const ArrayList<T>& lista, int capacita)
{

    if (capacita >= lista.getSize())
    {
        Array = new T[capacita];
        Capacita = capacita;
    }
    else
    {

        Array = new T[lista->getSize() * 2];
        Capacita = lista->getSize() * 2;
    }

    Dimensione = lista->size;

    for (int i = 0; i < Dimensione; i++)
    {

        Array[i] = lista->Get(i);
    }
}

/**
 * Distruttore generale, dealloca la lista istanziata
 */
template<class T>
ArrayList<T>::~ArrayList()
{

    delete [] Array;
}

/**
 * Raddoppia la capacità dell'ArrayList.
 *
 * Esegue in O(n), dove n è il numero degli elementi dell'ArrayList.
 */
template<class T>
void ArrayList<T>::Rialloca()
{

    Capacita *= 2;
    T * temp = new T[Capacita];

    for (int i = 0; i < Dimensione; i++)
    {

        temp[i] = Array[i];
    }

    delete [] Array;

    Array = temp;
}

/**
 * Crea un nuovo ArrayList con dimensione pari alla nuova dimensione.
 *
 * Esegue in O(n), dove n è il numero degli elementi dell'ArrayList.
 *
 * @param nuovaDimensione la nuova dimensione dell'ArrayList.
 */
template<class T>
void ArrayList<T>::Rialloca(int nuovaDimensione)
{

    Capacita = nuovaDimensione;
    T * temp = new T[nuovaDimensione];

    for (int i = 0; i < Dimensione; i++)
    {

        temp[i] = Array[i];

        delete [] Array;

        Array = temp;
    }
}

//~ Funzioni di base per aggiunta e rimozione di elementi ------------------------------------
/**
 * Aggiunge l'elemento passato all'estremità dell'ArrayList.
 *
 * Esegue in tempo O(n), nel caso peggiore: cioè la riallocazione dell'intero ArrayList.
 * O(1) in tutti gli altri casi.
 *
 * @param elemento l'elemento da aggiungere all'ArrayList.
 */
template<class T>
void ArrayList<T>::Aggiungi(T& elemento)
{

    if ((Dimensione - 1) == Capacita)
    {

        Rialloca();
    }

    Array[Dimensione] = elemento;
    Dimensione++;
}

/**
 * Aggiunge l'elemento passato all'indice specificato. Fornito
 * che l'indice è valido.
 *
 * Un indice valido è: 0 <= indice <= dimensione
 *
 * Viene eseguito in O(n) dove n è il numero di elementi che devono
 * essere spostato per adattare l'elemento all'indice o alla dimensione dell'array se
 * l'array che deve essere riallocato.
 *
 * @param elemento l'elemento da aggiungere all'ArrayList.
 * @param indice l'indice a cui aggiungere l'elemento.
*/
template<class T>
void ArrayList<T>::Aggiungi(const T& elemento, int indice) {

    if (indice >= 0 && indice <= Dimensione)
    {

        //Reallocate if necessary.
        if (indice >= Capacita || Dimensione == Capacita)
        {

            int multiplicand = (indice >= Capacita) ? indice : Dimensione;
            Rialloca(multiplicand * 2);
        }

        //Shift elements to the right.
        for (int i = Dimensione; i > indice; i--)
        {

            Array[i] = Array[i - 1];
        }

        Array[indice] = elemento;
        Dimensione++;
    }
}

/**
 * Aggiunge un ArrayList<T> alla fine di questo ArrayList.
 *
 * Viene eseguito in tempo O(n), dove n = la dimensione dell'elenco passato.
 *
 * @param lista l'ArrayList<T> da aggiungere a questo.
*/
template<class T>
void ArrayList<T>::Aggiungi(const ArrayList<T> & lista)
{

    for (int i = 0; i < lista.GetDimensione(); i++)
    {

        add(lista.Get(i));
    }
}

/**
  * Aggiunge un ArrayList<T> a questo ArrayList<T> in corrispondenza dell'indice specificato.
  *
  * Nota: se index è maggiore della capacità di ArrayList, the
  * ArrayList viene ingrandito a una dimensione che è due volte l'indice più
  * la dimensione dell'arrayList.
  * Se vuoi un controllo sulla dimensione dell'indice, usa getSize() per controllare.
  *
  * Viene eseguito in un tempo O(n) dove n è la dimensione dell'elenco passato o il numero
  * degli elementi che vengono spostati in questo elenco. Qualunque sia il più grande.
  *
  * @param lista l'ArrayList<T> da aggiungere a questo.
  * @param indice l'indice a cui aggiungere l'ArrayList<T> passato a.
 */
template<class T>
void ArrayList<T>::Aggiungi(const ArrayList<T> & lista, int indice)
{

    //If passed in list will overflow off of this one.
    if (indice >= Capacita || (indice + lista.GetDimensione()) >= Capacita)
    {

        reallocate((indice + lista.getDimensione()) * 2);
    }

    T* temp = new T[Capacita + lista.getDimensione()];

    //Loop through array, and passed list, adding them where they are appropriate.
    for (int i = 0, j = 0, k = 0; i < Dimensione + lista.GetDimensione(); i++)
    {

        if (i >= indice && i < indice + lista.GetDimensione())
        {

            temp[i] = *lista.Get(j);
            j++;
        }
        else
        {

            temp[i] = Array[k];
            k++;
        }
    }

    delete [] Array;
    Array = temp;
    Dimensione += lista.GetDimensione();
}

/**
  * Rimuove l'elemento all'indice passato.
  *
  * Viene eseguito in un tempo O(n) dove n è il numero di elementi che devono essere spostati.
  *
  * @param indice l'indice dell'elemento da rimuovere.
  * @return rimosso un puntatore all'elemento rimosso o NULL/0 se
  * l'indice non è valido.
*/
template<class T>
const T * ArrayList<T>::Rimuovi(int indice)
{

    T * rimosso = NULL;

    if (indice < Dimensione && indice >= 0)
    {

        for (int i = indice; i < Dimensione; i++)
        {

            Array[i] = Array[i + 1];
        }

        rimosso = Array + indice;
        Dimensione--;
    }

    return rimosso;
}

/**
  * Svuota l'ArrayList di tutti gli elementi e crea un nuovo ArrayList
  * della stessa capacità di prima.
  *
  * Funziona in tempo O(1).
*/
template<class T>
void ArrayList<T>::RimuoviTutti()
{

    delete [] Array;
    Array = new T[Capacita];

    Dimensione = 0;
}


/**
  * Sposta l'elemento da indice1 a indice2 e l'elemento
  * da indice2 a indice1. Restituisce vero se gli indici lo sono
  * valido, falso altrimenti.
  *
  * Funziona in tempo O(1).
  *
  * @param indice1 l'indice del primo elemento da spostare.
  * @param indice2 l'indice del primo elemento da spostare.
  * @return true se gli indici sono validi, false altrimenti.
*/
template<class T>
bool ArrayList<T>::Sposta(int indice1, int indice2)
{

    if (indice1 >= 0 && indice2 >= 0 &&
            indice1 < Dimensione && indice2 < Dimensione)
    {

        T temp = Array[indice1];
        Array[indice1] = Array[indice2];
        Array[indice2] = temp;


        return true;
    }

    return false;
}

/**
   * Ottiene l'elemento archiviato nell'indice passato.
   *
   * Funziona in tempo O(1).
   *
   * @param indice l'indice dell'elemento da ottenere.
   * @return un puntatore all'elemento memorizzato in index, o NULL se l'indice non è valido.
*/
template<class T>
T * ArrayList<T>::Get(int indice) const
{

    return (indice >= 0 && indice < Dimensione) ? (Array + indice) : NULL;
}

//~ Funzioni per la dimensione e la capacità----------------------------
/**
 * Ritorna la dimensione attuale dell'ArrayList.
 *
 * @return dimensione il numero degli elementi nell'ArrayList.
 */
template<class T>
int ArrayList<T>::GetDimensione() const
{

    return Dimensione;
}

/**
 * Ritorna la capacita attuale dell'ArrayList.
 *
 * @return capacita la capacita dell'ArrayList.
 */
template<class T>
int ArrayList<T>::GetCapacita() const
{

    return Capacita;
}

/**
  * Restituisce un oggetto stringa formattato di tutti
  * degli elementi in ArrayList.
  *
  *Es. (elemento1, elemento2).
  *
  * Esegue un tempo O(n) dove n è la dimensione dell'array.
  *
  * @return un oggetto stringa che rappresenta il
  * elementi nell'ArrayList.
  */
template<class T>
std::string ArrayList<T>::toString() const
{

    std::ostringstream streamOut;

    streamOut << "(";

    for (int i = 0; i < Dimensione; i++)
    {

        streamOut << Array[i];

        if (i != (Dimensione - 1))
        {

            streamOut << ", ";
        }
    }

    streamOut << ")\n";

    std::string returnString = streamOut.str();

    return returnString;
}


