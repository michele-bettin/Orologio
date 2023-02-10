#ifndef MIOPARSERJSON_H
#define MIOPARSERJSON_H

#include <QString>
#include <QJsonObject>
#include <QJsonDocument>
#include "../Modelli/Sveglia.h"


class MioJSONParser
{
public:
    static void salva(const QString& percorso, Sveglia& s, const QString& titolo) {
        QJsonObject svegliaJSON;
        svegliaJSON.insert("titolo", titolo);
        svegliaJSON.insert( "fineSvegliaOre", s.Ore());
        svegliaJSON.insert( "fineSvegliaMinuti", s.Minuti());
        svegliaJSON.insert( "fineSvegliaSecondi", s.Secondi());

        QJsonDocument document;
        document.setObject(svegliaJSON);

        QByteArray bytes = svegliaJSON.toJson(svegliaJSON::Indented);
        QFile file(percorso);

        if( file.open( QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate ) )
        {
            QTextStream iStream( &file );
            iStream.setCodec( "utf-8" );
            iStream << bytes;
            file.close();
        }
        else
        {
            cout << "file open failed: " << path.toStdString() << endl;
        }
    }







};

#endif // MIOPARSERJSON_H
