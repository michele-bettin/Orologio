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

    void static writeSvegliaWidgetToJson(QJsonObject& jsonObject, const SvegliaWidget* sveglia)
    {
        jsonObject["titolo"] = "Prova";
        jsonObject["ore"] = sveglia->Ore();
        jsonObject["minuti"] = sveglia->Minuti();
        jsonObject["secondi"] = sveglia->Secondi();
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
