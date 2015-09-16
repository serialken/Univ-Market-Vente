#include "database.h"


database::database()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
}


QSqlDatabase database::get_db(){
    return db;
}

QStringList  database::get_resultat(){
    return res;
}



bool  database::connexion()
{   
    db.setDatabaseName("BDD_COMM.db");
    if (db.open() == false)
    {
        qDebug() << "connexion echoue";
        return false;
    }
    else
    {
        qDebug() << "connexion a la BDD reussie";
        return true;
    }
}

QSqlQuery database::done_query(QString arg)
{
    QSqlQuery   my_query;

    qDebug() << "affichage de la requete: " << arg;
    my_query.prepare(arg);
    if(my_query.exec())
    {
        qDebug() << "requete reussie";
        return my_query;
    }
    else
    {
        qDebug() << "requete echoue";
        return my_query;
    }
}

bool database::treat_query(QString arg)
{
    QSqlQuery myQuery;
    int       ct;
    int       i = 0;
    QString   tmp;

    if (res.isEmpty() == false)
        res.clear();
    myQuery = done_query(arg);
    if (myQuery.lastError().isValid())
    {
        qDebug() << myQuery.lastError().text();
        return false;
    }
    else
    {
        while (myQuery.next())
        {
            qDebug() << "new entry";
            for (ct = 0; ct < myQuery.record().count(); ++ct)
            {
                if (ct == (myQuery.record().count() - 1))
                    tmp += myQuery.value(ct).toString();
                else
                    tmp += myQuery.value(ct).toString() + SEP;
                qDebug() << "   " << myQuery.record().fieldName(ct) << "---" << myQuery.value(ct).toString();
            }
            res.insert(i, tmp);
            i++;
            tmp.clear();
        }
        return true;
    }
}


void database::close_db(){
    db.close();
}
