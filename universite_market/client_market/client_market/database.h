#ifndef DATABASE_H
#define DATABASE_H

#include <QDebug>
#include <QStringList>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QtSql/QSqlRecord>
#include <QVariant>
 efine SEP "#@#"

class database
{
public:
    database();
    QSqlDatabase get_db();
    void         close_db();
    bool         treat_query(QString arg);
    QSqlQuery    done_query(QString arg);
    //QSqlQuery    get_query();
    bool         connexion();
    QStringList  get_resultat();

private:
    QSqlDatabase db;
    QStringList  res;

};

#endif // DATABASE_H
