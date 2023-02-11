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

    void static scriviDaSvegliaWidgetAJSON(QJsonObject& jsonObject, SvegliaWidget* sveglia)
    {
        jsonObject["titolo"] = sveglia->getTitolo();
        jsonObject["ore"] = sveglia->getOre();
        jsonObject["minuti"] = sveglia->getMinuti();
        jsonObject["secondi"] = sveglia->getSecondi();
    }

    template <typename T>
    void static scriviArraySuFileJson(const QString& percorsoFile, ArrayList<T*> &lista)
    {
        QJsonArray jsonArray;

        for (int i = 0; i < lista.GetDimensione(); i++) {
            QJsonObject jsonObject;

            // Verifico la natura degli oggetti
            if (typeid(*lista.Get(i)) == typeid(SvegliaWidget*)) {
                writeSvegliaToJson(jsonObject, *lista.Get(i));

            }

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


    void static scriviDaJSONASvegliaWidget(QJsonObject& jsonObject, SvegliaWidget* sveglia, Orologio* oA = 0)
    {
        sveglia = new SvegliaWidget(oA, jsonObject["titolo"], jsonObject["ore"], jsonObject["minuti"], jsonObject["secondi"]);
    }


    // Passo anche l'orologio attuale perchè mi è necessario per creare oggetti di tipo sveglia widget, gli unici
        // realmente per il quale è stato creato il parser
        template <typename T>
        const ArrayList<T*> static caricaArrayDaFileJson(const QString& percorsoFile, Orologio* oA = 0)
        {
            ArrayList<T*> result;
            QFile file(percorsoFile);
            if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
            {
                qDebug() << "Impossibile aprire il file " << percorsoFile;
                return result;
            }

            QJsonDocument jsonDoc = QJsonDocument::fromJson(file.readAll());
            if (!jsonDoc.isArray())
            {
                qDebug() << "Il file " << percorsoFile << " non contiene un array JSON valido";
                return result;
            }

            QJsonArray jsonArray = jsonDoc.array();
            for (int i = 0; i < jsonArray.size(); i++)
            {
                QJsonObject jsonObject = jsonArray[i].toObject();
                scriviDaJSONAWidgetSveglia(jsonObject, *result.Get(i), oA)
                result.Aggiungi(*result.Get(i));
            }

            return result;
        }
};

#endif // MIOPARSERJSON_H
