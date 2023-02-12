#ifndef MIOJSONPARSER_H
#define MIOJSONPARSER_H

#include <QtXml>
#include <QtCore>
#include <iostream>
#include <QIODevice>

#include <vector>
#include <string>
#include <type_traits>
#include <tuple>

#include <QString>
#include "../Collezioni/ArrayList.h"

class MioJSONParser
{
public:


    template <typename T>
    static std::vector<std::tuple<std::string, decltype(std::declval<T>().var)>> listaProprietaOggetto(const T& object) {
        std::vector<std::tuple<std::string, decltype(std::declval<T>().var)>> variables;

        // Use a helper function to recursively extract the member variables
        auto extractVariables = [&](auto&& arg, const std::string& name) {
            using type = std::decay_t<decltype(arg)>;
            if constexpr (std::is_class_v<type>) {
                for (auto&& [varName, varValue] : std::make_tuple(arg)) {
                    variables.push_back({ name + "." + varName, varValue });
                    extractVariables(varValue, name + "." + varName);
                }
            } else {
                variables.push_back({ name, arg });
            }
        };

        auto helper = [&](auto&& arg, const std::string& name) {
            extractVariables(arg, name);
        };

        helper(object, "");
        return variables;
    }

    template< typename T>
    static void salvaOggetto(const QString& path, const T& oggetto) {
        QJsonObject oggettoJSON;


        std::vector<std::tuple<std::string, decltype(std::declval<T>().var)>> proprietaOggetto = listaProprietaOggetto(oggetto);

        for (const auto& [name, value] : proprietaOggetto) {
          std::cout << name << ": " << value << std::endl;

        }




        QJsonObject oggettoJSON;
        oggettoJSON.insert();

        book1.insert( "name", obj1.name.c_str() );
        book1.insert( "price", obj1.price );

        Book obj2( "advanced high school mathematics", 14 );
        QJsonObject book2;
        book2.insert( "name", obj2.name.c_str() );
        book2.insert( "price", obj2.price );

        QJsonObject content;
        content.insert( "book1", book1 );
        content.insert( "book2", book2 );

        QJsonDocument document;
        document.setObject( content );
        QByteArray bytes = document.toJson( QJsonDocument::Indented );
        QFile file( path );
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

    template< typename T>
    static const ArrayList<T*> restituisciListaOggetti(const QString &path) {

    }
};

#endif // MIOJSONPARSER_H
