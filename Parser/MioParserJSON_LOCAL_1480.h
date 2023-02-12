#ifndef MIOPARSERJSON_H
#define MIOPARSERJSON_H

#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <typeinfo>
#include "../Collezioni/ArrayList.h"
#include "../SvegliaWidget.h"

class MioParserJSON {
public:

    void static scriviSvegliaWidgetToJson(QJsonObject& jsonObject, const SvegliaWidget* sveglia)
    {
        jsonObject["titolo"] = sveglia -> getTitolo();
        jsonObject["ore"] = sveglia -> getOre();
        jsonObject["minuti"] = sveglia -> getMinuti();
        jsonObject["secondi"] = sveglia -> getSecondi();
    }

    template <typename T>
    void static scriviArraySuFileJson(const QString& percorsoFile, const ArrayList<T*> &lista)
    {
        QJsonArray jsonArray;

        for (int i = 0; i < lista.GetDimensione(); i++) {
            QJsonObject jsonObject;

            // Verifico la natura degli oggetti
            if (typeid(*lista.Get(i)) == typeid(Sveglia*)) {
                writeSvegliaToJson(jsonObject, *lista.Get(i));

            }
            std::cout << typeid(lista.Get(i)).name();
            std::cout << typeid(Sveglia*).name();

            jsonArray.append(jsonObject);
        }

        QFile file(percorsoFile);
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            qDebug() << "Fallito il tentativo di apertura del file: " << percorsoFile;
            return;
        }

        QTextStream stream(&file);
        stream << QJsonDocument(jsonArray).toJson(QJsonDocument::Indented);

        file.close();
    }

    template <typename T>
    const ArrayList<T*> static caricaArrayDaFileJson(const QString& percorsoFile)
    {
        QJsonArray jsonArray;

        for (int i = 0; i < lista.GetDimensione(); i++) {
            QJsonObject jsonObject;

            // Verifico la natura degli oggetti
            if (typeid(*lista.Get(i)) == typeid(Sveglia*)) {
                writeSvegliaToJson(jsonObject, *lista.Get(i));

            }
            std::cout << typeid(lista.Get(i)).name();
            std::cout << typeid(Sveglia*).name();

            jsonArray.append(jsonObject);
        }

        QFile file(percorsoFile);
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            qDebug() << "Fallito il tentativo di apertura del file: " << percorsoFile;
            return;
        }

        QTextStream stream(&file);
        stream << QJsonDocument(jsonArray).toJson(QJsonDocument::Indented);

        file.close();
    }
};

#endif // MIOPARSERJSON_H
