#ifndef SOCIETE_H
#define SOCIETE_H


#include <QString>
#include <QDebug>
#include <QRegExp>
#include <QCalendarWidget>


class societe
{
public:
    societe();
    ~societe();
    bool set_name(QString, int);
    bool set_addr(QString, int);
    bool set_ville(QString, int);
    bool set_cp(QString, int);
    bool set_tel(QString, int);
    bool set_fax(QString, int);
    bool set_pays(QString, int);
    bool set_mail(QString, int);
    bool set_crea(QString, int);
    bool set_duree(QString, int);
    bool set_eff(QString, int);
    bool set_ca(QString, int);
    bool set_com(QString, int);
    bool set_patient(QString, int);
    bool set_ouverture(QString, int);
    bool set_codcli(QString, int);
    bool set_statut(int);
    bool set_categorie(int);
    bool set_classif(int);
    QString get_name();
    QString get_addr();
    QString get_ville();
    QString get_cp();
    QString get_tel();
    QString get_fax();
    QString get_pays();
    QString get_mail();
    QString get_crea();
    QString get_duree();
    QString get_eff();
    QString get_ca();
    QString get_com();
    QString get_patient();
    QString get_ouverture();
    QString get_codcli();
    int get_statut();
    int get_categorie();
    int get_classif();

private:
    QString nom;
    QString adresse;
    QString ville;
    QString cp;
    QString num_tel;
    QString num_fax;
    QString pays;
    QString mail;
    QString date_crea;
    QString duree;//client depuis ....
    QString eff;
    QString ca;
    QString com;
    QString nb_patient;
    QString nb_ouverture;
    QString codcli;
    int statut;
    int categorie;
    int classification;
};

#endif // SOCIETE_H
