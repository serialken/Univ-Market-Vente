#include "mainwindow.h"

bool    MainWindow::verif_ip(QString p)
{
    QStringList res;
    QRegExp exp("^[0-9]|[1-9][0-9]|1[0-9]{2}|2[0-4][0-9]|25[0-5]$");

    res = p.split(".");
    if (res.size() == 4)
    {
        for (int i = 0; i < res.size(); ++i)
        {
            // qDebug() << res.at(i);
            if(exp.exactMatch(res.at(i)) == false)
                return false;
        }
        return true;
    }
    else
        return false;
}

bool  MainWindow::verif_fields(QString arg, int len)
{
    if ((arg.size() > len) || (arg.isEmpty() == true))
        return false;
    else
        return true;
}

bool MainWindow::verif_authentification(QStringList list)
{
    QString tmp;
    if ((list.at(1).compare("OK") == 0) && (list.size() == 4))
    {
        //on insere dans la BDD le nom et prenom requetre a changer
        // initialisation taille msg pour pouvoir recevoir de futurs messages
        tailleMessage = 0;
        tmp = "INSERT INTO USER ('id_user', 'login', 'password', 'nom', 'prenom', 'statut') VALUES (NULL ,'" + user + "', '" + pass + "', '" + list.at(2) + "', '" + list.at(3) + "', 'commercial')";
        my_database->connexion();// fodra penser a la refermer
        my_database->treat_query(tmp);
        //my_database->treat_query("SELECT * FROM USER");
        my_database->close_db();
        get_id();
        set_uses();
        flag_auth = 1;
        return true;
    }
    else if ((list.at(1).compare("OK") == 0) && (list.size() == 2))
    {
        tailleMessage = 0;
        flag_auth = 1;
        return true;
    }
    else
    {
        tailleMessage = 0;
        flag_auth = 0;
        return false;
    }
}


bool MainWindow::verif_conn_local()
{
    QString     tmp;
    QStringList myList;

    tmp = "SELECT login, password FROM USER";
    my_database->connexion();
    if (my_database->treat_query(tmp) == true)
    {
        qDebug() << "requete a marcher on va faire les test login pass";
        my_database->close_db();
        for (int i = 0; i < my_database->get_resultat().size();++i)
        {
            myList = my_database->get_resultat().at(i).split(SEP);
            if ((myList.at(0).compare(user) == 0) && (myList.at(1).compare(pass) == 0))
            {
                get_id();
                return true;
            }
        }
        return false;
    }
    else
    {
        qDebug() << "sa sent pas bon";
        my_database->close_db();
        return false;
    }
}

//-------------------------------------------------------CLIENT---------------------------------------------------------------------

