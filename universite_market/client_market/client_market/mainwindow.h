#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QDir>
#include <QFileInfo>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QtNetwork>
#include <QTcpSocket>
#include <QDataStream>
#include <QAbstractSocket>
#include <QMessageBox>
#include <QListWidgetItem>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QRegExp>
#include <QDialogButtonBox>
#include <QCalendarWidget>
#include <QTabWidget>

#include "database.h"
#include "societe.h"

#define DIR_CONF "/debug/conf/"
#define FILE_CONF "conf.cfg"
#define WARNING_BOX "WARNING"
#define CRITICAL_BOX "CRITICAL ERROR"
#define INFORMATION_BOX "INFORMATION"
#define QUESTION_BOX "CONFIRMATION DE SUPPRESSION"
#define LEN_USER 8
#define LEN_PASS 10
#define USER_ERR "Le nom d'utilisateur doit etre compris entre 1 et 8 caracteres"
#define PASS_ERR "Le mot de pass doit etre compris entre 1 et 10 caracteres"
#define CONNEXION_OK "Connexion réussie !"
#define DECO_MSG  "Déconnecté du serveur"
#define HOSTNOTFOUND "ERREUR : le serveur n'a pas pu être trouvé. Vérifiez l'IP et le port."
#define CONNEXIONREFUSED "ERREUR : le serveur a refusé la connexion. Vérifiez si le programme \"serveur\" a bien été lancé. Vérifiez aussi l'IP et le port"
#define REMOTEHOSTCLOSED "ERREUR : le serveur a coupé la connexion."
#define AUTHENTIFICATION_OK "AUTH#@#OK"
#define AUTHENTIFICATION_KO "AUTH#@#KO"
#define LOGON_ERR "le login ou le mot de passe ne correspondent a aucune entree."
#define LIST_EMPTY "il n'ya pas de client enregistrer pour le moment."
#define SELECTED_ERR "veuillez selectionnez un element avant de pouvoir faire cette action"
#define SEP "#@#"
#define LEN_NAME_CLI 50
#define LEN_ADDR_CLI 255
#define LEN_VILLE_CLI 25
#define LEN_CP 10
#define LEN_NUMERO 15
#define LEN_PAYS_CLI 15
#define LEN_MAIL 60
#define LEN_DATE 10
#define LEN_EFF_CLI 4
#define LEN_CA_CLI 12
#define LEN_NBPATIENT_CLI 6
#define LEN_NBOPEN_CLI 2
#define LEN_CODCLI 25
#define LEN_COM 65500
//#define LEN_COM 5
//CATEGORIE CLIENT 0:NONDEF 1:GOLD 2:ARGENT 3:BRONZE
//CLASSIFICATION CLIENT 0:NONDEF 1:HOT 2:MEDIUM 3:COLD
//STATUT SOCIETE CLIENTE 0:NONDEF 1:PRIVE 2:PUBLIC
#define NAME_ERR "Le nom de la societe doit etre compris entre 1 et 50 caracteres.\nCe champ est obligatoire."
#define VILLE_ERR "le nom de la ville fait maximum 25 caracteres."
#define ADRESSE_ERR "l'adresse fait maximum 255 caracteres."
#define CP_ERR "le code postal fait maximum 10 caracteres."
#define NUMERO_ERR "Ce champ fait maximum 15 caracteres.\nCe champ ne doit contenir que des chiffres."
#define PAYS_ERR "le nom du pays fait maximum 15 caracteres."
#define MAIL_ERR "l'adresse mail est du type jean.michel@sfri.com.\nl'adresse mail fait maximum 60 caracteres"
#define DATE_ERR "la date est du type JJ/MM/AAAA."
#define EFFECTIF_ERR "l'effectif ne doit pas exeeder les 9999 employes.\n Ce champ ne doit contenir que des chiffres."
#define CA_ERR "le chiffre d'affaire est limite a 12 caracteres.\nCe champ ne doit contenir que des chiffres."
#define COM_ERR "nombre de caractere depasser. tu t'es lacher oops!!!!!"
#define CODECLI_ERR "Ce champ contient des caracteres non valide."
#define OUVERTURE_ERR "Une structure n'a pas plus de 7 jours ouvrables dans la semaine.\nCe champ ne doit contenir que des chiffres."
#define PATIENT_ERR "Le nombre de patient ne peut pas exeder 999999.\nCe champ ne doit comporter que des chiffres"
#define VALIDATE_DEL "Êtes-vous sûr de vouloir supprimer ' "
#define FORM_ERR "Certain champs ne sont pas valide.\n Merci de les renseigner avant de poursuivre."
#define FORM_VALID "Les donnees ont ete enregistre avec succes."
#define DATA_BDD_ERR "un probleme est survenu lors de la recuperation des infos dans la BDD."
#define MODIF_ERR "un probleme est survenu lors de l'enregistrement des donnees"
#define MODIF_OK "les informations ont ete sauvegardees avec succees."
#define DEL_ERR "une erreur est survenu lors de la suppression des donneees"
#define UNDEFINED "NON DEF"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QString get_ip();
    QString get_port();
    QString    get_id_cli();
    void    get_id();
    void    get_uses();
    bool    get_listcli();
    void    init_value();
    //void    init_form();
    void    set_uses();
    void    envoi_msg(QString message);
    void    auth(int flag);
    bool    verif_conn_local();
    bool    verif_ip(QString p);
    bool    verif_fields(QString arg, int len);
    bool    recup_conf();
    bool    verif_authentification(QStringList list);
    void    list_client();
    void    gest_add_cli();
    void    gest_mod_cli();
    void    aff_F_entry();
    void    aff_F_conf();
    void    aff_F_cli();
    void    aff_F_info(int);
    void    aff_F_conn();
    void    aff_calendar();
    void    aff_F_view();
    void    gest_resume();
    void    gest_info();
    void    gest_contacts();
    void    gest_notes();
    void    gest_histo();
    void    gest_parc();
    void    gest_activite();
    void    gest_hemato();
    void    gest_bioch();


public slots:
    void    logon();
    void    rec_conf();
    void    modif_conf();
    void    slot_B_connect();
    void    donneesRecues();
    void    connecte();
    void    deconnecte();
    void    erreurSocket(QAbstractSocket::SocketError erreur);
    void    selected_item(QListWidgetItem *);
    void    slot_add_client();
    void    slot_del_client();
    void    slot_mod_client();
    void    slot_view_client();
    void    refresh_list_cli(QString);//recherch instantanee
    void    reinit_list_cli();//reinitialise la liste des clients
    void    save_info_gene();
    void    mod_info_gene();
    void    cancel_info_gene();
    void    get_selected_date_duree(QDate);
    void    aff_calendar_duree();
    void    get_selected_date_crea(QDate);
    void    aff_calendar_crea();
    void    slot_name();
    void    slot_adresse();
    void    slot_ville();
    void    slot_cp();
    void    slot_tel();
    void    slot_fax();
    void    slot_pays();
    void    slot_mail();
    void    slot_statut(int);
    void    slot_eff();
    void    slot_ca();
    void    slot_com();
    void    slot_categorie(int);
    void    slot_classification(int);
    void    slot_patient();
    void    slot_ouverture();
    void    slot_codcli();
    void    on_pass_edit_returnPressed();
    void    slot_return();
    void    slot_tabview_client(int);
    void    slot_machine(int);
    void    slot_activator();
    void    slot_activator_end();
    void    slot_info_name();
    void    slot_info_adresse();
    void    slot_info_ville();
    void    slot_info_cp();
    void    slot_info_tel();
    void    slot_info_fax();
    //void    slot_info_pays();
    void    slot_info_mail();
    void    slot_info_com();

private:
    Ui::MainWindow *ui;
    QString              port;
    QString              ip;
    QString              user;
    QString              pass;
    QString              id;
    QString              conf_err;
    QString              id_cli;// id du client en cours de traitement
    int                  flag_conn;
    int                  flag_use;
    int                  flag_auth;// savoir si on est authentifier ou pas 0:nothing, 1:authenthifier
    quint16              tailleMessage;
    QTcpSocket           *socket; // Représente le serveur
    database::database   *my_database;
    QString              my_selected;//valeur selectionner dans la liste des clients
    QStringList          my_listclient;
    QString              selected_date;// valeur selectionner dans un calendrier
    societe::societe     *my_cli;//represente le client selectionner
};

#endif // MAINWINDOW_H
