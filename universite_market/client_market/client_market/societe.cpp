#include "societe.h"

societe::societe()
{
    statut = 0;
    categorie = 0;
    classification = 0;
}

societe::~societe()
{
    nom.clear();
    adresse.clear();
    ville.clear();
    cp.clear();
    num_tel.clear();
    num_fax.clear();
    pays.clear();
    mail.clear();
    date_crea.clear();
    duree.clear();
    eff.clear();
    ca.clear();
    com.clear();
    nb_patient.clear();
    nb_ouverture.clear();
    codcli.clear();
    statut = 0;
    categorie = 0;
    classification = 0;
}

//-------------------------------------setteurs-----------------------------------------
//il verifie set si c true et false si rien


bool societe::set_name(QString val, int len)
{
    qDebug() << "la valeur du nom recuperer est: " << val;
    if ((val.size() > len) || (val.isEmpty() == true))
        return false;
    else if (nom.compare(val) == 0)
        return true;
    else
    {
        nom = val;
        return true;
    }
}
bool societe::set_addr(QString val, int len)
{
    qDebug() << "la valeur de l'adresse recuperer est: " << val;
    if(val.size() > len)
        return false;
    else if (adresse.compare(val) == 0)
        return true;
    else
    {
        adresse = val;
        return true;
    }

}

bool societe::set_ville(QString val, int len)
{
    qDebug() << "la valeur de la ville recuperer est: " << val;
    if (val.size() > len)
        return false;
    else if (ville.compare(val) == 0)
        return true;
    else
    {
        ville = val;
        return true;
    }
}

bool societe::set_cp(QString val, int len)
{
    qDebug() << "la valeur du code postale recuperer est: " << val;
    if(val.size() > len)
        return false;
    else if (cp.compare(val) == 0)
        return true;
    else
    {
        cp = val;
        return true;
    }
}

bool societe::set_tel(QString val, int len)
{
    QRegExp exp("^[0-9]+$");
    qDebug() << "la valeur du telephone recuperer est: " << val;
    if(val.size() > len)
        return false;
    else if (num_tel.compare(val) == 0)
        return true;
    else if (exp.exactMatch(val) == false)
        return false;
    else
    {
        num_tel = val;
        return true;
    }
}

bool societe::set_fax(QString val, int len)
{
    QRegExp exp("^[0-9]+$");
    qDebug() << "la valeur du fax recuperer est: " << val;
    if(val.size() > len)
        return false;
    else if (num_fax.compare(val) == 0)
        return true;
    else if (exp.exactMatch(val) == false)
        return false;
    else
    {
        num_fax = val;
        return true;
    }
}

bool societe::set_pays(QString val, int len)
{
    qDebug() << "la valeur du pays recuperer est: " << val;
    if(val.size() > len)
        return false;
    else if (pays.compare(val) == 0)
        return true;
    else
    {
        pays = val;
        return true;
    }
}

bool societe::set_mail(QString val, int len)
{
    //le nom de domaine bloquer a 6 caractere sa peut changer
    QRegExp exp("^([a-z][A-Z][0-9])+([-_.]?[a-z][A-Z][0-9]+)*@([a-z][A-Z][0-9])+([-.]?([a-z][A-Z][0-9])+).[a-z]{2,10}$");
    qDebug() << "la valeur de l'adresse mail recuperer est: " << val;
    if(val.size() > len)
        return false;
    else if (mail.compare(val) == 0)
        return true;
    else if (exp.exactMatch(val) == false)
        return false;
    else
    {
        mail = val;
        return true;
    }

    //"^[[:alnum:]]([-_.]?[[:alnum:]_?])*@[[:alnum:]]([-.]?[[:alnum:]])+.([a-z]{2,10})$"
}

bool societe::set_crea(QString val, int len)
{
    qDebug() << "la valeur de la date de creation recuperer est: " << val;
    if(val.size() > len)
        return false;
    else if (date_crea.compare(val) == 0)
        return true;
    else
    {
        date_crea = val;
        return true;
    }
}

bool societe::set_duree(QString val, int len)
{
    qDebug() << "la valeur de la date de client depuis recuperer est: " << val;
    if(val.size() > len)
        return false;
    else if (duree.compare(val) == 0)
        return true;
    else
    {
        duree = val;
        return true;
    }
}

bool societe::set_eff(QString val, int len)
{
    QRegExp exp("^[0-9]+$");
    qDebug() << "la valeur de l'effectif recuperer est: " << val;
    if(val.size() > len)
        return false;
    else if (eff.compare(val) == 0)
        return true;
    else if (exp.exactMatch(val) == false)
        return false;
    else
    {
        eff = val;
        return true;
    }
}

bool societe::set_ca(QString val, int len)
{
    QRegExp exp("^[0-9]+$");
    qDebug() << "la valeur duchiffre d affaire recuperer est: " << val;
    if(val.size() > len)
        return false;
    else if (ca.compare(val) == 0)
        return true;
    else if (exp.exactMatch(val) == false)
        return false;
    else
    {
        ca = val;
        return true;
    }
}

bool societe::set_com(QString val, int len)
{
    qDebug() << "la valeur du commentaire recuperer est: " << val;
    if(val.size() > len)
        return false;
    else if (com.compare(val) == 0)
        return true;
    else
    {
        com = val;
        return true;
    }
}

bool societe::set_patient(QString val, int len)
{
    QRegExp exp("^[0-9]+$");
    qDebug() << "la valeur du nombre de patient  recuperer est: " << val;
    if(val.size() > len)
        return false;
    else if (nb_patient.compare(val) == 0)
        return true;
    else if (exp.exactMatch(val) == false)
        return false;
    else
    {
        nb_patient = val;
        return true;
    }
}

bool societe::set_ouverture(QString val, int len)
{
    qDebug() << "la valeur du nombre d ouverture  recuperer est: " << val;
    QRegExp exp("^[0-9]+$");
    if (val.size() > len)
        return false;
    else if (val.toInt() > 7)
        return false;
    else if (nb_ouverture.compare(val) == 0)
        return true;
    else if (exp.exactMatch(val) == false)
        return false;
    else
    {
        nb_ouverture = val;
        return true;
    }
}

bool societe::set_codcli(QString val, int len)
{
    qDebug() << "la valeur du code client en interne  recuperer est: " << val;
    if (val.size() > len)
        return false;
    else if (nb_ouverture.compare(val) == 0)
        return true;
    else
    {
        nb_ouverture = val;
        return true;
    }
    //else if (exp.exactMatch(val) == false)
    //return false;
}

bool societe::set_statut(int val)
{
    qDebug() << "la valeur du statut  recuperer est: " << val;
    if ((val > 2) || (val < 0))
        return false;
    else if (val == statut)
        return true;
    else
    {
        statut = val;
        return true;
    }
}

bool societe::set_categorie(int val)
{
    qDebug() << "la valeur de la categorie  recuperer est: " << val;
    if ((val > 3) || (val < 0))
        return false;
    else if (val == categorie)
        return true;
    else
    {
        categorie = val;
        return true;
    }
}

bool societe::set_classif(int val)
{
    qDebug() << "la valeur de la classification  recuperer est: " << val;
    if ((val > 3) || (val < 0))
        return false;
    else if (val == classification)
        return true;
    else
    {
        classification = val;
        return true;
    }
}

//-----------------------------------------------------------------gettteurs------------------------------------------------------------
QString societe::get_name(){
    return nom;
}

QString societe::get_addr(){
    return adresse;
}

QString societe::get_ville(){
    return ville;
}

QString societe::get_cp(){
    return cp;
}

QString societe::get_tel(){
    return num_tel;
}

QString societe::get_fax(){
    return num_fax;
}

QString societe::get_pays(){
    return pays;
}

QString societe::get_mail(){
    return mail;
}

QString societe::get_crea(){
    return date_crea;
}

QString societe::get_duree(){
    return duree;
}

QString societe::get_eff(){
    return eff;
}

QString societe::get_ca(){
    return ca;
}

QString societe::get_com(){
    return com;
}

QString societe::get_patient(){
    return nb_patient;
}

QString societe::get_ouverture(){
    return nb_ouverture;
}

QString societe::get_codcli(){
    return codcli;
}

int societe::get_statut(){
    return statut;
}

int societe::get_categorie(){
    return categorie;
}

int societe::get_classif(){
    return classification;
}
