#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QShortcut>
#include <QKeyEvent>

void MainWindow::on_pass_edit_returnPressed()
{
    // appuyez sur la touche entrez a le mm effet que sur le bouton
    logon();
}

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_DeleteOnClose);
    // init_form();
    init_value();
    ui->F_conf->hide();
    ui->F_conn->hide();
    ui->F_cli->hide();
    ui->my_calendar->hide();
    ui->F_info->hide();
    ui->F_view->hide();
    // ui->F_entry->show();
    //ui->user_edit->setFocus();
    aff_F_entry();
}

MainWindow::~MainWindow()
{
    delete ui;
}

//void        MainWindow::init_form()
//{
//    ui->F_entry->setGeometry(50,100,46,13);
//}

void        MainWindow::init_value()
{
    ui->pass_edit->setEchoMode(QLineEdit::Password);
    socket = new QTcpSocket(this);
    tailleMessage = 0;
    flag_conn = 0;
    flag_auth = 0;
    //id_cli = NULL;
    my_database = new database();
    get_uses();
    QObject::connect(ui->B_log, SIGNAL(clicked()), this, SLOT(logon()));
    QObject::connect(ui->rec, SIGNAL(clicked()), this, SLOT(rec_conf()));
    QObject::connect(ui->B_modif_rec, SIGNAL(clicked()), this, SLOT(modif_conf()));
    QObject::connect(socket, SIGNAL(readyRead()), this, SLOT(donneesRecues()));
    QObject::connect(socket, SIGNAL(connected()), this, SLOT(connecte()));
    QObject::connect(socket, SIGNAL(disconnected()), this, SLOT(deconnecte()));
    QObject::connect(ui->B_connect, SIGNAL(clicked()), this, SLOT(slot_B_connect()));
    QObject::connect(socket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(erreurSocket(QAbstractSocket::SocketError)));
    QObject::connect(ui->aff_cli, SIGNAL(itemClicked(QListWidgetItem*)),this,SLOT(selected_item(QListWidgetItem*)));
    QObject::connect(ui->B_add_cli, SIGNAL(clicked()), this, SLOT(slot_add_client()));
    QObject::connect(ui->B_del_cli, SIGNAL(clicked()), this, SLOT(slot_del_client()));
    QObject::connect(ui->B_view_cli, SIGNAL(clicked()), this, SLOT(slot_view_client()));
    QObject::connect(ui->B_mod_cli, SIGNAL(clicked()), this, SLOT(slot_mod_client()));
    QObject::connect(ui->find_edit, SIGNAL(textChanged(QString)),this, SLOT(refresh_list_cli(QString)));
    QObject::connect(ui->B_reinit, SIGNAL(clicked()), this, SLOT(reinit_list_cli()));

}

// --------------------------------------------------------affichage des widgets------------------------------------------------------------

void    MainWindow::aff_F_entry()
{
    ui->F_entry->show();
    ui->F_entry->setGeometry(350,190,271,201);
    ui->user_edit->setFocus();
}

void    MainWindow::aff_F_conf()
{
    ui->F_conf->show();
    ui->F_conf->setGeometry(380,250,301,131);
}

void    MainWindow::aff_F_cli()
{
    ui->F_cli->show();
    ui->F_cli->setGeometry(390,150,331, 311);
    reinit_list_cli();
}

void    MainWindow::aff_F_info(int val)
{
    ui->F_info->show();
    ui->F_info->setGeometry(140,10,861,661);
    if (val == 1)
    {
        // on est sur de l'ajout
        ui->B_modif_infogene->hide();
        ui->B_valid_infogene->show();
        ui->nomcli_edit->clear();
        ui->addrcli_edit->clear();
        ui->villecli_edit->clear();
        ui->payscli_edit->clear();
        ui->cpcli_edit->clear();
        ui->telcli_edit->clear();
        ui->faxcli_edit->clear();
        ui->mailcli_edit->clear();
        ui->creacli_edit->clear();
        ui->dureecli_edit->clear();
        ui->effcli_edit->clear();
        ui->cacli_edit->clear();
        ui->patientcli_edit->clear();
        ui->ouverturecli_edit->clear();
        ui->codcli_edit->clear();
        ui->comcli_edit->clear();
        ui->statutcli_edit->setCurrentIndex(0);
        ui->categoriecli_edit->setCurrentIndex(0);
        ui->classificationcli_edit->setCurrentIndex(0);
        gest_add_cli();
    }
    else if (val == 2)
    {
        //on est sur de la modification
        ui->B_modif_infogene->show();
        ui->B_valid_infogene->hide();
        gest_mod_cli();
    }
}

void    MainWindow::aff_F_conn()
{
    ui->F_conn->show();
    ui->F_conn->setGeometry(330,180,361,291);
}

void    MainWindow::aff_calendar()
{
    ui->my_calendar->show();
    ui->my_calendar->setGeometry(170,240,241,161);
}

void    MainWindow::aff_F_view()
{
    ui->F_view->show();
    ui->F_view->setGeometry(40,10,951,651);
    ui->tabWidget->setTabText(0, tr("Résumé"));
    ui->tabWidget->setTabText(1, tr("Informations"));
    ui->tabWidget->setTabText(2, tr("Contacts"));
    ui->tabWidget->setTabText(3, tr("Notes"));
    ui->tabWidget->setTabText(4, tr("Historique des ventes"));
    ui->tabWidget->setTabText(5, tr("Parc machine"));
    ui->tabWidget->setTabText(6, tr("Activités"));
    ui->sous_parc_instru->setTabText(0, tr("Instruments hématologie"));
    ui->sous_parc_instru->setTabText(1, tr("Instruments biochimie"));
    ui->Client_actuel->setText(my_selected);
    QObject::connect(ui->B_return, SIGNAL(clicked()), this, SLOT(slot_return()));
    QObject::connect(ui->tabWidget, SIGNAL(currentChanged(int)), this, SLOT(slot_tabview_client(int)));
    ui->tabWidget->setCurrentIndex(0);
    //my_cli = new societe();//creation de la table pour recup les val
    gest_resume();



}

// --------------------------------------------------------Methodes de recuperation (getteurs)----------------------------------------------

QString MainWindow::get_id_cli()
{
    return id_cli;
}

void     MainWindow::get_id()
{
    QString tmp;

    tmp = "SELECT id_user FROM USER WHERE login = '" + user + "' AND password = '" + pass + "'" ;
    my_database->connexion();
    my_database->treat_query(tmp);
    my_database->close_db();
    id = my_database->get_resultat().at(0);
    qDebug() << "voila l'id: " << id;
}

bool     MainWindow::get_listcli()
{
    QString   tmp;

    tmp = "SELECT id_client, nom FROM CLIENT WHERE id_user = '" + id + "' ORDER BY nom ASC";
    my_database->connexion();
    if (my_database->treat_query(tmp) == true)
    {
        my_database->close_db();
        my_listclient = my_database->get_resultat();
        return true;
    }
    else
    {
        qDebug() << "probleme lors de la recuperation des infos dans la BDD";
        return false;
    }
}

QString  MainWindow::get_ip(){
    return ip;
}


QString  MainWindow::get_port(){
    return port;
}

void         MainWindow::get_uses(){
    QDir current_dir;
    QString conf_dir;
    QString path_file;
    QString tmp_ip;
    QString tmp_port;
    QString uses;
    QFileInfo *path;


    current_dir = QDir::currentPath();
    conf_dir += current_dir.path() + DIR_CONF;
    path = new QFileInfo(conf_dir);
    //qDebug() << conf_dir;
    if (path->exists() == true)
    {
        //chemin exists on fait des process
        if (path->isDir() == true)
        {
            if (current_dir.cd("debug/conf") == true)
            {
                // current_dir = QDir::currentPath();
                //qDebug() << current_dir.path();
                path_file = conf_dir + FILE_CONF;
                //ici on va recup la conf
                //qDebug() << path_file;
                QFile my_file(path_file);
                if (my_file.open(QIODevice::ReadOnly))
                {
                    QTextStream flux(&my_file);
                    flux >> tmp_ip;
                    flux >> tmp_port;
                    flux >> uses;
                    flag_use = (uses.remove(0,5)).toInt();
                    my_file.close();
                    qDebug() << "get_uses: " << flag_use;
                }
                else
                {
                    qDebug() << "ouverture fichier foirer so lecture  oci ";
                    flag_use = -4;
                }

            }
            else
            {
                qDebug() << "on s'est fait avoir cd ne marche pas";
                flag_use = -3;
            }
        }
        else
        {
            qDebug() << " on s'est fait avoir c pas un rep le fichier de conf n'est pas au bon endroit";
            flag_use = -2;
        }
    }
    else
    {
        qDebug() << " c pas normal c censer etre fait a la creation du log on v arenvoyer une err com koi le fichier de conf est compromis";
        flag_use = -1;
    }

}

void       MainWindow::set_uses()
{
    QDir current_dir;
    QString conf_dir;
    QString path_file;
    QFileInfo *path;


    current_dir = QDir::currentPath();
    conf_dir += current_dir.path() + DIR_CONF;
    path = new QFileInfo(conf_dir);
    if (path->exists() == true)
    {
        //chemin exists on fait des process
        if (path->isDir() == true)
        {
            if (current_dir.cd("debug/conf") == true)
            {

                path_file = conf_dir + FILE_CONF;

                QFile my_file(path_file);
                if (my_file.open(QIODevice::WriteOnly))
                {
                    flag_use = 1;
                    QTextStream flux(&my_file);
                    flux << "IPSERVEUR=" << ip << "\n";
                    flux << "PORT=" << port << "\n";
                    flux << "USES=" << flag_use << "\n";
                    my_file.close();

                }
                else
                    qDebug() << "ouverture fichier foirer so sauvegarde oci du coup set_uses oci";

            }
            else
                qDebug() << "on s'est fait avoir cd ne marche pas dans set uses";
        }
        else
        {
            qDebug() << " c pas normal fichier de conf corompu au nivo du repertoire sa pue !!!!!!!";
        }
    }
    else
    {
        qDebug() << " c pas normal fichier de conf corompu au nivo du path sa pue !!!!!!!";
    }
}

bool MainWindow::recup_conf()
{
    QDir current_dir;
    QString conf_dir;
    QString path_file;
    QString tmp_ip;
    QString tmp_port;
    QFileInfo *path;


    current_dir = QDir::currentPath();
    conf_dir += current_dir.path() + DIR_CONF;
    path = new QFileInfo(conf_dir);
    //qDebug() << conf_dir;
    if (path->exists() == true)
    {
        //chemin exists on fait des process
        if (path->isDir() == true)
        {
            if (current_dir.cd("debug/conf") == true)
            {
                // current_dir = QDir::currentPath();
                //qDebug() << current_dir.path();
                path_file = conf_dir + FILE_CONF;
                //ici on va recup la conf
                //qDebug() << path_file;
                QFile my_file(path_file);
                if (my_file.open(QIODevice::ReadOnly))
                {
                    QTextStream flux(&my_file);
                    flux >> tmp_ip;
                    flux >> tmp_port;
                    ip = tmp_ip.remove(0,10);
                    if (verif_ip(ip) == true)
                    {
                        port = tmp_port.remove(0,5);
                        my_file.close();
                        qDebug() << ip;
                        qDebug() << port;
                        qDebug() << "verification de ce que renvoi verif ip dans recup conf------------->" << verif_ip(ip);
                        return true;
                    }
                    else
                    {
                        my_file.close();
                        conf_err = "l'adresse IP du serveur n'est pas valide veuillez entrez une bonne valeur";
                        return false;
                    }
                }
                else
                {
                    qDebug() << "ouverture fichier foirer so lecture  oci ";
                    conf_err = "ouverture fichier de conf foirer so lecture  oci ";
                    return false;
                }
            }
            else
            {
                qDebug() << "on s'est fait avoir cd ne marche pas";
                conf_err = "le cd ne marche pas";
                return false;
            }
        }
        else
        {
            qDebug() << " on s'est fait avoir c pas un rep envoyre pour kil conf lui mm";
            conf_err = " on s'est fait avoir c pas un rep envoyre pour kil conf lui mm";
            return false;
        }
    }
    else
    {
        qDebug() << " c pas normal c censer etre fait a la creation du log on v arenvoyer une err pour quil conf lui mm";
        conf_err = " c pas normal c censer etre fait a la creation du log on v arenvoyer une err pour quil conf lui mm";
        return false;
    }
}

void    MainWindow::envoi_msg(QString message)
{

    QByteArray paquet;
    QDataStream out(&paquet, QIODevice::WriteOnly);

    out << (quint16) 0;
    out << message;
    out.device()->seek(0);
    out << (quint16) (paquet.size() - sizeof(quint16));
    socket->write(paquet); // On envoie le paquet
}

//-------------------------------------------------------------les differents slots-----------------------------------------------------

void   MainWindow::slot_activator()
{

    QObject::connect(ui->infos_nom_edit, SIGNAL(editingFinished()), this, SLOT(slot_info_name()));
    QObject::connect(ui->infos_addresse_edit, SIGNAL(textEdited(QString)), this, SLOT(slot_info_adresse()));
    QObject::connect(ui->infos_ville_edit, SIGNAL(textEdited(QString)), this, SLOT(slot_info_ville()));
    QObject::connect(ui->infos_cp_edit, SIGNAL(textEdited(QString)), this, SLOT(slot_info_cp()));
    QObject::connect(ui->infos_tel_edit, SIGNAL(textEdited(QString)), this, SLOT(slot_info_tel()));
    QObject::connect(ui->infos_telecopie_edit, SIGNAL(textEdited(QString)), this, SLOT(slot_info_fax()));
    //QObject::connect(ui->payscli_edit, SIGNAL(textEdited(QString)), this, SLOT(slot_info_pays()));
    QObject::connect(ui->infos_mail_edit, SIGNAL(editingFinished()), this, SLOT(slot_info_mail()));
    QObject::connect(ui->infos_commentaire_edit,SIGNAL(textChanged()), this, SLOT(slot_info_com()));

    ui->B_mod_info_view->disconnect();
    ui->B_mod_info_view->setText("Terminer");
    QObject::connect(ui->B_mod_info_view,SIGNAL(clicked()), this, SLOT(slot_activator_end()));


    ui->nom_info_img->setStyleSheet("background: url(:/ok-16) no-repeat;");
    ui->addr_info_img->setStyleSheet("background: url(:/ok-16) no-repeat;");
    ui->ville_info_img->setStyleSheet("background: url(:/ok-16) no-repeat;");
    ui->cp_info_img->setStyleSheet("background: url(:/ok-16) no-repeat;");
    ui->tel_info_img->setStyleSheet("background: url(:/ok-16) no-repeat;");
    ui->fax_info_img->setStyleSheet("background: url(:/ok-16) no-repeat;");
    //ui->pays_info_img->setStyleSheet("background: url(:/ok-16) no-repeat;");
    ui->mail_info_img->setStyleSheet("background: url(:/ok-16) no-repeat;");
    ui->com_info_img->setStyleSheet("background: url(:/ok-16) no-repeat;");

    ui->infos_nom_edit->setReadOnly(false);
    ui->infos_addresse_edit->setReadOnly(false);
    ui->infos_ville_edit->setReadOnly(false);
    ui->infos_cp_edit->setReadOnly(false);
    ui->infos_tel_edit->setReadOnly(false);
    ui->infos_telecopie_edit->setReadOnly(false);
    ui->infos_mail_edit->setReadOnly(false);
    ui->infos_commentaire_edit->setReadOnly(false);
}

void MainWindow::slot_activator_end()
{
    QString tmp;

    tmp = QString("UPDATE CLIENT SET nom = '") + my_cli->get_name() + QString("' , adresse = '") + my_cli->get_addr() + QString("' , ville = '") + my_cli->get_ville() + QString("' , code_postal = '") + my_cli->get_cp() + QString("' , telephone = '") + my_cli->get_tel() + QString("', fax = '") + my_cli->get_fax() + QString("' , pays = '") + my_cli->get_pays() + QString("', mail = '") + my_cli->get_mail() + QString("' , date_creation = '") + my_cli->get_crea() + QString("', statut = '") + QString::number(my_cli->get_statut()) + QString("' , duree_client = '") + my_cli->get_duree() + QString("' , effectif = '") + my_cli->get_eff() + QString("' , chiffre_affaire = '") + my_cli->get_ca() + QString("' , commentaire = '") + my_cli->get_com() + QString("' , categorie = '") + QString::number(my_cli->get_categorie()) + QString("' , classification = '") + QString::number(my_cli->get_classif()) + QString("' , nb_patient = '") + my_cli->get_patient() + QString("' , nb_ouverture = '") + my_cli->get_ouverture() + QString("' , soc_codcli = '") + my_cli->get_codcli() + QString("' , id_user = '") + id + QString("' WHERE ROWID = '") + get_id_cli() + QString("'");
    my_database->connexion();
    if (my_database->treat_query(tmp) == true)
    {
        my_database->close_db();
        QMessageBox::information(this, INFORMATION_BOX,MODIF_OK);

        ui->nom_info_img->setStyleSheet("");
        ui->addr_info_img->setStyleSheet("");
        ui->ville_info_img->setStyleSheet("");
        ui->cp_info_img->setStyleSheet("");
        ui->tel_info_img->setStyleSheet("");
        ui->fax_info_img->setStyleSheet("");
        //ui->pays_info_img->setStyleSheet("");
        ui->mail_info_img->setStyleSheet("");
        ui->com_info_img->setStyleSheet("");

        ui->B_mod_info_view->disconnect();
        ui->infos_nom_edit->disconnect();
        ui->infos_addresse_edit->disconnect();
        ui->infos_ville_edit->disconnect();
        ui->infos_cp_edit->disconnect();
        ui->infos_tel_edit->disconnect();
        ui->infos_telecopie_edit->disconnect();
        //ui->payscli_edit->disconnect();
        ui->infos_mail_edit->disconnect();
        ui->infos_commentaire_edit->disconnect();

        gest_info();
    }
    else
    {
        QMessageBox::warning(this, WARNING_BOX,MODIF_ERR);
        my_database->close_db();
    }
}

void    MainWindow::slot_machine(int val)
{
    if (val == 0)
        gest_hemato();
    else if (val == 1)
        gest_bioch();
}

void    MainWindow::slot_tabview_client(int val)
{
    qDebug() << "voila la position de mon onglet------------: " << val;
    if (val == 0)
        gest_resume();
    else if (val == 1)
        gest_info();
    else if (val == 2)
        gest_contacts();
    else if (val == 3)
        gest_notes();
    else if (val == 4)
        gest_histo();
    else if (val == 5)
        gest_parc();
    else if (val == 6)
        gest_activite();
}

void    MainWindow::slot_return()
{
    ui->Client_actuel->clear();
    ui->tabWidget->setCurrentIndex(0);
    ui->F_view->hide();
    aff_F_cli();
}

void    MainWindow::slot_name()
{
    if (my_cli->set_name(ui->nomcli_edit->text(), LEN_NAME_CLI) == false)
    {
        QMessageBox::warning(this, WARNING_BOX,NAME_ERR);
        ui->nom_img->setStyleSheet("background: url(:/del-16) no-repeat;");
    }
    else
        ui->nom_img->setStyleSheet("background: url(:/ok-16) no-repeat;");
}

void    MainWindow::slot_info_name()
{
    if (my_cli->set_name(ui->infos_nom_edit->text(), LEN_NAME_CLI) == false)
    {
        QMessageBox::warning(this, WARNING_BOX,NAME_ERR);
        ui->nom_info_img->setStyleSheet("background: url(:/del-16) no-repeat;");
    }
    else
        ui->nom_info_img->setStyleSheet("background: url(:/ok-16) no-repeat;");
}

void    MainWindow::slot_adresse()
{
    if (my_cli->set_addr(ui->addrcli_edit->text(), LEN_ADDR_CLI) == false)
    {
        QMessageBox::warning(this, WARNING_BOX,ADRESSE_ERR);
        ui->addr_img->setStyleSheet("background: url(:/del-16) no-repeat;");
        ui->addrcli_edit->backspace();
    }
    else
        ui->addr_img->setStyleSheet("background: url(:/ok-16) no-repeat;");
}

void    MainWindow::slot_info_adresse()
{
    if (my_cli->set_addr(ui->infos_addresse_edit->text(), LEN_ADDR_CLI) == false)
    {
        QMessageBox::warning(this, WARNING_BOX,ADRESSE_ERR);
        ui->addr_info_img->setStyleSheet("background: url(:/del-16) no-repeat;");
        ui->infos_addresse_edit->backspace();
    }
    else
        ui->addr_info_img->setStyleSheet("background: url(:/ok-16) no-repeat;");
}

void    MainWindow::slot_ville()
{
    if (my_cli->set_ville(ui->villecli_edit->text(), LEN_VILLE_CLI) == false)
    {
        QMessageBox::warning(this, WARNING_BOX,VILLE_ERR);
        ui->ville_img->setStyleSheet("background: url(:/del-16) no-repeat;");
        ui->villecli_edit->backspace();
    }
    else
        ui->ville_img->setStyleSheet("background: url(:/ok-16) no-repeat;");
}

void    MainWindow::slot_info_ville()
{
    if (my_cli->set_ville(ui->infos_ville_edit->text(), LEN_VILLE_CLI) == false)
    {
        QMessageBox::warning(this, WARNING_BOX,VILLE_ERR);
        ui->ville_info_img->setStyleSheet("background: url(:/del-16) no-repeat;");
        ui->infos_ville_edit->backspace();
    }
    else
        ui->ville_info_img->setStyleSheet("background: url(:/ok-16) no-repeat;");
}

void    MainWindow::slot_cp()
{
    if (my_cli->set_cp(ui->cpcli_edit->text(), LEN_CP) == false)
    {
        QMessageBox::warning(this, WARNING_BOX,CP_ERR);
        ui->cp_img->setStyleSheet("background: url(:/del-16) no-repeat;");
        ui->cpcli_edit->backspace();
    }
    else
        ui->cp_img->setStyleSheet("background: url(:/ok-16) no-repeat;");
}

void    MainWindow::slot_info_cp()
{
    if (my_cli->set_cp(ui->infos_cp_edit->text(), LEN_CP) == false)
    {
        QMessageBox::warning(this, WARNING_BOX,CP_ERR);
        ui->cp_info_img->setStyleSheet("background: url(:/del-16) no-repeat;");
        ui->infos_cp_edit->backspace();
    }
    else
        ui->cp_info_img->setStyleSheet("background: url(:/ok-16) no-repeat;");
}

void    MainWindow::slot_tel()
{
    if (my_cli->set_tel(ui->telcli_edit->text(), LEN_NUMERO) == false)
    {
        QMessageBox::warning(this, WARNING_BOX,NUMERO_ERR);
        ui->tel_img->setStyleSheet("background: url(:/del-16) no-repeat;");
        ui->telcli_edit->backspace();
    }
    else
        ui->tel_img->setStyleSheet("background: url(:/ok-16) no-repeat;");
}

void    MainWindow::slot_info_tel()
{
    if (my_cli->set_tel(ui->infos_tel_edit->text(), LEN_NUMERO) == false)
    {
        QMessageBox::warning(this, WARNING_BOX,NUMERO_ERR);
        ui->tel_info_img->setStyleSheet("background: url(:/del-16) no-repeat;");
        ui->infos_tel_edit->backspace();
    }
    else
        ui->tel_info_img->setStyleSheet("background: url(:/ok-16) no-repeat;");
}

void    MainWindow::slot_fax()
{
    if (my_cli->set_fax(ui->faxcli_edit->text(), LEN_NUMERO) == false)
    {
        QMessageBox::warning(this, WARNING_BOX,NUMERO_ERR);
        ui->fax_img->setStyleSheet("background: url(:/del-16) no-repeat;");
        ui->faxcli_edit->backspace();
    }
    else
        ui->fax_img->setStyleSheet("background: url(:/ok-16) no-repeat;");
}

void    MainWindow::slot_info_fax()
{
    if (my_cli->set_fax(ui->infos_telecopie_edit->text(), LEN_NUMERO) == false)
    {
        QMessageBox::warning(this, WARNING_BOX,NUMERO_ERR);
        ui->fax_info_img->setStyleSheet("background: url(:/del-16) no-repeat;");
        ui->infos_telecopie_edit->backspace();
    }
    else
        ui->fax_info_img->setStyleSheet("background: url(:/ok-16) no-repeat;");
}

void    MainWindow::slot_pays()
{
    if (my_cli->set_pays(ui->payscli_edit->text(), LEN_PAYS_CLI) == false)
    {
        QMessageBox::warning(this, WARNING_BOX,PAYS_ERR);
        ui->pays_img->setStyleSheet("background: url(:/del-16) no-repeat;");
        ui->payscli_edit->backspace();
    }
    else
        ui->pays_img->setStyleSheet("background: url(:/ok-16) no-repeat;");
}

//void    MainWindow::slot_info_pays()
//{
//    if (my_cli->set_pays(ui->infos_pays_edit->text(), LEN_PAYS_CLI) == false)
//    {
//        QMessageBox::warning(this, WARNING_BOX,PAYS_ERR);
//        ui->pays_info_img->setStyleSheet("background: url(:/del-16) no-repeat;");
//        ui->infos_pays_edit->backspace();
//    }
//    else
//        ui->pays_info_img->setStyleSheet("background: url(:/ok-16) no-repeat;");
//}

void    MainWindow::slot_mail()
{
    if (my_cli->set_mail(ui->mailcli_edit->text(), LEN_NUMERO) == false)
    {
        QMessageBox::warning(this, WARNING_BOX,MAIL_ERR);
        ui->mail_img->setStyleSheet("background: url(:/del-16) no-repeat;");
        ui->mailcli_edit->backspace();
    }
    else
        ui->mail_img->setStyleSheet("background: url(:/ok-16) no-repeat;");
}

void    MainWindow::slot_info_mail()
{
    if (my_cli->set_mail(ui->infos_mail_edit->text(), LEN_NUMERO) == false)
    {
        QMessageBox::warning(this, WARNING_BOX,MAIL_ERR);
        ui->mail_info_img->setStyleSheet("background: url(:/del-16) no-repeat;");
        ui->infos_mail_edit->backspace();
    }
    else
        ui->mail_info_img->setStyleSheet("background: url(:/ok-16) no-repeat;");
}

void    MainWindow::slot_eff()
{
    if (my_cli->set_eff(ui->effcli_edit->text(), LEN_EFF_CLI) == false)
    {
        QMessageBox::warning(this, WARNING_BOX,EFFECTIF_ERR);
        ui->eff_img->setStyleSheet("background: url(:/del-16) no-repeat;");
        ui->effcli_edit->backspace();
    }
    else
        ui->eff_img->setStyleSheet("background: url(:/ok-16) no-repeat;");
}

void    MainWindow::slot_ca()
{
    if (my_cli->set_ca(ui->cacli_edit->text(), LEN_CA_CLI) == false)
    {
        QMessageBox::warning(this, WARNING_BOX,CA_ERR);
        ui->ca_img->setStyleSheet("background: url(:/del-16) no-repeat;");
        ui->cacli_edit->backspace();
    }
    else
        ui->ca_img->setStyleSheet("background: url(:/ok-16) no-repeat;");
}


void    MainWindow::slot_patient()
{
    if (my_cli->set_patient(ui->patientcli_edit->text(), LEN_NBPATIENT_CLI) == false)
    {
        QMessageBox::warning(this, WARNING_BOX,PATIENT_ERR);
        ui->patient_img->setStyleSheet("background: url(:/del-16) no-repeat;");
        ui->patientcli_edit->backspace();
    }
    else
        ui->patient_img->setStyleSheet("background: url(:/ok-16) no-repeat;");
}

void    MainWindow::slot_ouverture()
{
    if (my_cli->set_ouverture(ui->ouverturecli_edit->text(), LEN_NBOPEN_CLI) == false)
    {
        QMessageBox::warning(this, WARNING_BOX,OUVERTURE_ERR);
        ui->ouverture_img->setStyleSheet("background: url(:/del-16) no-repeat;");
        ui->ouverturecli_edit->backspace();
    }
    else
        ui->ouverture_img->setStyleSheet("background: url(:/ok-16) no-repeat;");
}

void    MainWindow::slot_codcli()
{
    if (my_cli->set_codcli(ui->codcli_edit->text(), LEN_CODCLI) == false)
    {
        QMessageBox::warning(this, WARNING_BOX,CODECLI_ERR);
        ui->codcli_img->setStyleSheet("background: url(:/del-16) no-repeat;");
        ui->codcli_edit->backspace();
    }
    else
        ui->codcli_img->setStyleSheet("background: url(:/ok-16) no-repeat;");
}

void    MainWindow::slot_com()
{
    if (my_cli->set_com(ui->comcli_edit->toPlainText(), LEN_COM) == false)
    {
        QMessageBox::warning(this, WARNING_BOX,COM_ERR);
        ui->com_img->setStyleSheet("background: url(:/del-16) no-repeat;");
    }
    else
        ui->com_img->setStyleSheet("background: url(:/ok-16) no-repeat;");
}

void    MainWindow::slot_info_com()
{
    if (my_cli->set_com(ui->infos_commentaire_edit->toPlainText(), LEN_COM) == false)
    {
        QMessageBox::warning(this, WARNING_BOX,COM_ERR);
        ui->com_info_img->setStyleSheet("background: url(:/del-16) no-repeat;");
    }
    else
        ui->com_info_img->setStyleSheet("background: url(:/ok-16) no-repeat;");
}

void  MainWindow::slot_statut(int val)
{

    my_cli->set_statut(val);
    ui->statut_img->setStyleSheet("background: url(:/ok-16) no-repeat;");
}

void  MainWindow::slot_categorie(int val)
{

    my_cli->set_categorie(val);
    ui->categorie_img->setStyleSheet("background: url(:/ok-16) no-repeat;");
}

void  MainWindow::slot_classification(int val)
{
    my_cli->set_classif(val);
    ui->classification_img->setStyleSheet("background: url(:/ok-16) no-repeat;");
}

void MainWindow::selected_item(QListWidgetItem *current)
{
    my_selected.clear();
    my_selected = current->text();
    qDebug() << "the selected item is: " << my_selected;
}

void MainWindow::get_selected_date_crea(QDate val)
{
    selected_date.clear();
    selected_date = val.toString("dd/MM/yyyy");
    qDebug() << "voici la date selectionner: " << selected_date;
    ui->my_calendar->hide();
    if (my_cli->set_crea(selected_date, LEN_DATE) == false)
    {
        QMessageBox::warning(this, WARNING_BOX,DATE_ERR);
        ui->crea_img->setStyleSheet("background: url(:/del-16) no-repeat;");
    }
    else
    {
        ui->creacli_edit->setText(selected_date);
        ui->crea_img->setStyleSheet("background: url(:/ok-16) no-repeat;");
    }
    ui->my_calendar->disconnect();

}

void MainWindow::aff_calendar_crea()
{
    aff_calendar();
    QObject::connect(ui->my_calendar,SIGNAL(clicked(QDate)), this, SLOT(get_selected_date_crea(QDate)));
}

void MainWindow::get_selected_date_duree(QDate val)
{
    selected_date.clear();
    selected_date = val.toString("dd/MM/yyyy");
    qDebug() << "voici la date selectionner: " << selected_date;
    ui->my_calendar->hide();
    if (my_cli->set_duree(selected_date, LEN_DATE) == false)
    {
        QMessageBox::warning(this, WARNING_BOX,DATE_ERR);
        ui->duree_img->setStyleSheet("background: url(:/del-16) no-repeat;");
    }
    else
    {
        ui->dureecli_edit->setText(selected_date);
        ui->duree_img->setStyleSheet("background: url(:/ok-16) no-repeat;");
    }
    ui->my_calendar->disconnect();
}

void MainWindow::aff_calendar_duree()
{
    aff_calendar();
    QObject::connect(ui->my_calendar,SIGNAL(clicked(QDate)), this, SLOT(get_selected_date_duree(QDate)));
}

void    MainWindow::slot_add_client()
{
    qDebug() << "on va ajouter un client et l'id du commercial c:" << id;
    //    ui->B_del_cli->setEnabled(false);
    //    ui->B_mod_cli->setEnabled(false);
    //    ui->B_view_cli->setEnabled(false);
    ui->F_cli->hide();
    //ui->F_info->show();
    aff_F_info(1);
    //    ui->B_modif_infogene->hide();
    //    ui->B_valid_infogene->show();

    //    gest_add_cli();
}

void    MainWindow::slot_del_client()
{
    QString tmp;

    if (my_selected.isEmpty() == true)
    {
        qDebug() << "il ya rien de selectionner !";
        QMessageBox::warning(this, WARNING_BOX,SELECTED_ERR);
    }
    else
    {
        tmp = VALIDATE_DEL + my_selected + " ' ?";
        int reponse = QMessageBox::question(this, QUESTION_BOX, tmp, QMessageBox::Yes | QMessageBox::No);
        if (reponse == QMessageBox::Yes)
        {            
            qDebug() << "on va supprimer le client" << my_selected;
            if (get_listcli() == true)
            {
                if (my_listclient.isEmpty() == true)
                    QMessageBox::critical(this, CRITICAL_BOX, DEL_ERR);
                else
                {
                    for (int i = 0; i < my_listclient.size();++i)
                    {
                        if (my_selected.compare(my_listclient.at(i).split(SEP).at(1)) == 0)
                        {
                            id_cli = my_listclient.at(i).split(SEP).at(0);
                            break;
                        }
                    }
                    if (id_cli.isNull() == true)
                    {
                        QMessageBox::critical(this, CRITICAL_BOX, DEL_ERR);
                    }
                    else
                    {
                        tmp.clear();
                        tmp = QString("DELETE FROM CLIENT WHERE ROWID = '") + id_cli + QString("'");
                        my_database->connexion();
                        if (my_database->treat_query(tmp) == false)
                        {
                            QMessageBox::critical(this, CRITICAL_BOX, DEL_ERR);
                            my_database->close_db();
                        }
                        else
                        {
                            my_database->close_db();
                            qDebug() << "on vient de supprimer le client" << my_selected;
                            reinit_list_cli();
                        }

                    }

                }
            }

        }
    }
}

void    MainWindow::slot_mod_client()
{

    if (my_selected.isEmpty() == true)
    {
        qDebug() << "il ya rien de selectionner !";
        QMessageBox::warning(this, WARNING_BOX,SELECTED_ERR);
    }
    else
    {
        qDebug() << "on va modifier les informations relatives a :" << my_selected;
        ui->F_cli->hide();
        //ui->F_info->show();
        aff_F_info(2);
        //        ui->B_modif_infogene->show();
        //        ui->B_valid_infogene->hide();
        //        gest_mod_cli();
    }
}

void    MainWindow::slot_view_client()
{

    if (my_selected.isEmpty() == true)
    {
        qDebug() << "il ya rien de selectionner !";
        QMessageBox::warning(this, WARNING_BOX,SELECTED_ERR);
    }
    else
    {
        qDebug() << "on va voir les differentes informations de: " << my_selected;
        ui->F_cli->hide();
        aff_F_view();

    }
}

void MainWindow::save_info_gene()
{
    QString tmp;

    if (my_cli->set_name(ui->nomcli_edit->text(), LEN_NAME_CLI) == false)
    {
        ui->nom_img->setStyleSheet("background: url(:/del-16) no-repeat;");
        if (my_cli->set_mail(ui->mailcli_edit->text(), LEN_MAIL) == false)
            ui->mail_img->setStyleSheet("background: url(:/del-16) no-repeat;");
        QMessageBox::warning(this, WARNING_BOX,FORM_ERR);
    }
    else if (my_cli->set_mail(ui->mailcli_edit->text(), LEN_MAIL) == false)
    {
        ui->mail_img->setStyleSheet("background: url(:/del-16) no-repeat;");
        QMessageBox::warning(this, WARNING_BOX,FORM_ERR);
    }
    else
    {
        qDebug() << "on va sauvegarder les infos suivante:";
        qDebug() << "nom: " << my_cli->get_name();
        qDebug() << "ville: " << my_cli->get_ville();
        qDebug() << "adresse: " << my_cli->get_addr();
        qDebug() << "code postal: " << my_cli->get_cp();
        qDebug() << "tel: " << my_cli->get_tel() ;
        qDebug() << "fax: " << my_cli->get_fax();
        qDebug() << "pays: " << my_cli->get_pays();
        qDebug() << "mail: " << my_cli->get_mail();
        qDebug() << "date de creation: " << my_cli->get_crea();
        qDebug() << "STATUT: " << my_cli->get_statut();
        qDebug() << "CATEGORIE: " << my_cli->get_categorie();
        qDebug() << "CLASSIFICATION: " << my_cli->get_classif();
        qDebug() << "client depuis: " << my_cli->get_duree();
        qDebug() << "effectif: " << my_cli->get_eff();
        qDebug() << "chiffre d'affaire: " << my_cli->get_ca();
        qDebug() << "nombre de patient par jour: " << my_cli->get_patient();
        qDebug() << "nombre d'ouverture /semaine: " << my_cli->get_ouverture();
        qDebug() << "code client: " << my_cli->get_codcli();
        qDebug() << "commentaire: " << my_cli->get_com();
        my_database->connexion();

        tmp = QString("INSERT INTO 'CLIENT' ( 'id_client' , 'nom' , 'adresse' , 'ville' , 'code_postal' , 'telephone' , 'fax' , 'pays' , 'mail' , 'date_creation' , 'statut' , 'duree_client' , 'effectif' , 'chiffre_affaire' , 'commentaire' , 'categorie' , 'classification' , 'nb_patient' , 'nb_ouverture' , 'soc_codcli' , 'id_user' ) VALUES ( NULL , '") + my_cli->get_name() + QString("' , '") + my_cli->get_addr() + QString("' ,'") + my_cli->get_ville() + QString("' , '") + my_cli->get_cp() + QString("' ,'") + my_cli->get_tel() + QString("' , '") + my_cli->get_fax() + QString("' , '") + my_cli->get_pays() + QString("' , '") + my_cli->get_mail() + QString("' , '") + my_cli->get_crea() + QString("' , '") + QString::number(my_cli->get_statut()) + QString("' , '") + my_cli->get_duree() + QString("' , '") + my_cli->get_eff() + QString("' , '") + my_cli->get_ca() + QString("' , '") + my_cli->get_com() + QString("' , '") + QString::number(my_cli->get_categorie()) + QString("' , '") + QString::number(my_cli->get_classif()) + QString("' , '") + my_cli->get_patient() + QString("' , '") + my_cli->get_ouverture() + QString("' , '") + my_cli->get_codcli() + QString("' , '") + id  + QString("' )");
        if (my_database->treat_query(tmp) == true)
        {
            QStringList res;
            tmp.clear();
            tmp = QString("SELECT id_client FROM CLIENT WHERE nom = '") + my_cli->get_name() + QString("' ORDER BY id_client DESC LIMIT 0, 1");
            my_database->treat_query(tmp);
            res = my_database->get_resultat();
            qDebug() << res;

            tmp.clear();
            tmp = QString("INSERT INTO CLIENT_SECTEUR ('id_client_secteur' , 'id_client' , 'id_secteur') VALUES (NULL, '") + res.at(0) + QString("' , '1')");
            my_database->treat_query(tmp);

            tmp.clear();
            tmp = QString("INSERT INTO CLIENT_SECTEUR ('id_client_secteur' , 'id_client' , 'id_secteur') VALUES (NULL, '") + res.at(0) + QString("' , '2')");
            my_database->treat_query(tmp);

            my_database->close_db();
            QMessageBox::information(this, INFORMATION_BOX,FORM_VALID);
            //            reinit_list_cli();
            cancel_info_gene();
        }
        else
        {
            QMessageBox::warning(this, WARNING_BOX,MODIF_ERR);
            my_database->close_db();
        }

    }
}

void MainWindow::mod_info_gene()
{
    QString tmp;

    tmp = QString("UPDATE CLIENT SET nom = '") + my_cli->get_name() + QString("' , adresse = '") + my_cli->get_addr() + QString("' , ville = '") + my_cli->get_ville() + QString("' , code_postal = '") + my_cli->get_cp() + QString("' , telephone = '") + my_cli->get_tel() + QString("', fax = '") + my_cli->get_fax() + QString("' , pays = '") + my_cli->get_pays() + QString("', mail = '") + my_cli->get_mail() + QString("' , date_creation = '") + my_cli->get_crea() + QString("', statut = '") + QString::number(my_cli->get_statut()) + QString("' , duree_client = '") + my_cli->get_duree() + QString("' , effectif = '") + my_cli->get_eff() + QString("' , chiffre_affaire = '") + my_cli->get_ca() + QString("' , commentaire = '") + my_cli->get_com() + QString("' , categorie = '") + QString::number(my_cli->get_categorie()) + QString("' , classification = '") + QString::number(my_cli->get_classif()) + QString("' , nb_patient = '") + my_cli->get_patient() + QString("' , nb_ouverture = '") + my_cli->get_ouverture() + QString("' , soc_codcli = '") + my_cli->get_codcli() + QString("' , id_user = '") + id + QString("' WHERE ROWID = '") + get_id_cli() + QString("'");
    my_database->connexion();
    if (my_database->treat_query(tmp) == true)
    {
        my_database->close_db();
        QMessageBox::information(this, INFORMATION_BOX,MODIF_OK);

        //        reinit_list_cli();
        cancel_info_gene();
        //        ui->F_info->hide();
        //        ui->F_cli->show();
        //        list_client();
        //        reinit_list_cli();
    }
    else
    {
        QMessageBox::warning(this, WARNING_BOX,MODIF_ERR);
        my_database->close_db();
    }

}

void MainWindow::cancel_info_gene()
{
    ui->nomcli_edit->clear();
    ui->addrcli_edit->clear();
    ui->addr_img->setStyleSheet("");
    ui->villecli_edit->clear();
    ui->ville_img->setStyleSheet(""); 
    ui->payscli_edit->clear();
    ui->pays_img->setStyleSheet("");
    ui->cpcli_edit->clear();
    ui->cp_img->setStyleSheet("");
    ui->telcli_edit->clear();
    ui->tel_img->setStyleSheet("");
    ui->faxcli_edit->clear();
    ui->fax_img->setStyleSheet("");
    ui->mailcli_edit->clear();
    ui->mail_img->setStyleSheet("");
    ui->creacli_edit->clear();
    ui->crea_img->setStyleSheet("");
    ui->dureecli_edit->clear();
    ui->duree_img->setStyleSheet("");
    ui->effcli_edit->clear();
    ui->eff_img->setStyleSheet("");
    ui->cacli_edit->clear();
    ui->ca_img->setStyleSheet("");
    ui->patientcli_edit->clear();
    ui->patient_img->setStyleSheet("");
    ui->ouverturecli_edit->clear();
    ui->ouverture_img->setStyleSheet("");
    ui->codcli_edit->clear();
    ui->codcli_img->setStyleSheet("");
    ui->comcli_edit->clear();
    ui->com_img->setStyleSheet("");
    ui->statutcli_edit->setCurrentIndex(0);
    ui->statut_img->setStyleSheet("");
    ui->categoriecli_edit->setCurrentIndex(0);
    ui->categorie_img->setStyleSheet("");
    ui->classificationcli_edit->setCurrentIndex(0);
    ui->classification_img->setStyleSheet("");
    ui->F_info->hide();
    //ui->F_cli->show();
    aff_F_cli();
    // list_client();
    //reinit_list_cli();
}


void MainWindow::refresh_list_cli(QString value)
{
    ui->aff_cli->clear();
    for (int i = 0; i < my_listclient.size();++i)
    {
        if (my_listclient.at(i).split(SEP).at(1).contains(value) == true)
            ui->aff_cli->addItem(my_listclient.at(i).split(SEP).at(1));
    }
}

void MainWindow::reinit_list_cli()
{
    ui->aff_cli->clear();
    ui->find_edit->clear();
    list_client();
    my_selected.clear();
}

void MainWindow::modif_conf()
{
    ui->F_conn->hide();
    //ui->F_conf->show();
    aff_F_conf();
}

void MainWindow::donneesRecues()
{
    QStringList val;

    //recuperation taille message
    //Une fois qu'on l'a, on attend d'avoir reçu le message entier (en se basant sur la taille annoncée tailleMessage)
    QDataStream in(socket);
    if (tailleMessage == 0)
    {
        if (socket->bytesAvailable() < (int)sizeof(quint16))
            return;
        in >> tailleMessage;
    }
    if (socket->bytesAvailable() < tailleMessage)
        return;
    //recuperation msg recu
    QString messageRecu;
    in >> messageRecu;
    // On affiche le message sur la zone de texte super extra ordinaire
    ui->listmsg->append(messageRecu);
    val = messageRecu.split(SEP);
    if (val.at(0).compare("AUTH") == 0)
    {
        if (verif_authentification(val) == true)
        {
            QMessageBox::information(this, INFORMATION_BOX,"authentification reussi");
            ui->F_conn->hide();
            //ui->F_cli->show();
            aff_F_cli();
            //list_client();
        }
        else
            QMessageBox::information(this, INFORMATION_BOX,"authentification failed");
    }
    else if(val.at(0).compare("REC") == 0)
    {
        //commit
    }
    else if (val.at(0).compare("UP") == 0)
    {
        //update
    }
    else
    {
        //il rakonte n'importe koi
    }

    qDebug() << "valeur du flag d'authentification a la recpetion dun msg: " << flag_auth << "\nle message recu: " << messageRecu;
}


void MainWindow::auth(int flag)
{
    QString tmp;

    if (flag == 0)
        tmp = QString("CONN") + SEP + user + SEP + pass;
    else
        tmp = QString("CONN") + SEP + user;
    envoi_msg(tmp);
    qDebug() << "message envoye: "<< tmp;
}


void MainWindow::connecte()
{
    ui->listmsg->append(tr("<em>Connexion réussie !</em>"));
    QMessageBox::information(this, INFORMATION_BOX,CONNEXION_OK);
    ui->B_connect->setEnabled(true);
    flag_conn = 1;
    // phrase d'authentification
    if (flag_use == 0)
        auth(0);
    else if(flag_use == 1)
        auth(1);
    else
        qDebug() << "caca dans la connection c partie en couille";
}


void MainWindow::deconnecte()
{
    ui->listmsg->append(tr("<em>Déconnecté du serveur</em>"));
    QMessageBox::information(this, INFORMATION_BOX,DECO_MSG);
    flag_conn = 0;
}


void        MainWindow::erreurSocket(QAbstractSocket::SocketError erreur)
{
    switch(erreur) // On affiche un message différent selon l'erreur qu'on nous indique
    {
    case QAbstractSocket::HostNotFoundError:
        ui->listmsg->append(tr("<em>ERREUR : le serveur n'a pas pu être trouvé. Vérifiez l'IP et le port.</em>"));
        QMessageBox::warning(this, WARNING_BOX,HOSTNOTFOUND);
        break;
    case QAbstractSocket::ConnectionRefusedError:
        ui->listmsg->append(tr("<em>ERREUR : le serveur a refusé la connexion. Vérifiez si le programme \"serveur\" a bien été lancé. Vérifiez aussi l'IP et le port.</em>"));
        QMessageBox::warning(this, WARNING_BOX,CONNEXIONREFUSED);
        break;
    case QAbstractSocket::RemoteHostClosedError:
        ui->listmsg->append(tr("<em>ERREUR : le serveur a coupé la connexion.</em>"));
        QMessageBox::warning(this, WARNING_BOX,REMOTEHOSTCLOSED);
        break;
    default:
        ui->listmsg->append(tr("<em>ERREUR : ") + socket->errorString() + tr("</em>"));
    }
    ui->B_connect->setEnabled(true);
}



void MainWindow::slot_B_connect()
{
    ui->listmsg->append(tr("<em>Tentative de connexion en cours...</em>"));
    ui->B_connect->setEnabled(false);
    qDebug() << ip << " " << port;
    socket->abort(); // On désactive les connexions précédentes s'il y en a
    socket->connectToHost(ip, port.toInt()); // On se connecte au serveur demandé
}

void       MainWindow::logon()
{
    if (verif_fields(ui->user_edit->text(),LEN_USER) == false)
        QMessageBox::warning(this, WARNING_BOX,USER_ERR);
    else if (verif_fields(ui->pass_edit->text(), LEN_PASS) == false)
        QMessageBox::warning(this, WARNING_BOX,PASS_ERR);
    else
    {
        user = ui->user_edit->text();
        pass = ui->pass_edit->text();
        qDebug() << "dans logon------->\nuser : " << user << "\npass: " << pass;
        // suivant les cas on va voir ce kon va faire avec le login et le pass !!!!!!!!!!!!
        switch (flag_use)
        {
        case 0:
            qDebug() << "super on va pouvoir lancer la connexion au serveur et en plus c sa premiere connexion";
            if (recup_conf() == false)
            {
                QMessageBox::warning(this, WARNING_BOX,conf_err);
                ui->pass_edit->disconnect();
                ui->F_entry->hide();
                //ui->F_conf->show();
                aff_F_conf();
            }
            else
            {
                ui->pass_edit->disconnect();
                ui->F_entry->hide();
                //ui->F_conn->show();
                aff_F_conn();// a enlever plutard on le laisse pour le visu
                ui->B_connect->hide();
                slot_B_connect();// c sa ker la verite
                ui->listmsg->append(tr("<em>Bienvenue !c'est  la premiere connexion.le client est maintenant pret a se connecter au serveur.</em>"));
            }
            break;

        case 1:
            qDebug() << "la on va direct en mode connexion BDD et boulot local";
            if (recup_conf() == false)
            {
                QMessageBox::warning(this, WARNING_BOX,conf_err);
                ui->pass_edit->disconnect();
                ui->F_entry->hide();
                //ui->F_conf->show();
                aff_F_conf();

            }
            else
            {
                if (verif_conn_local() == true)
                {
                    ui->pass_edit->disconnect();
                    ui->F_entry->hide();
                    //ui->F_cli->show();
                    aff_F_cli();
                    //list_client();
                    qDebug() << my_database->get_resultat();
                }
                else
                {
                    QMessageBox::warning(this, WARNING_BOX, LOGON_ERR);
                    aff_F_entry();
                    //ui->F_entry->show();
                }
            }
            break;

        case -1:
            qDebug() << "le chemin nexiste pas encore box d'arret";
            ui->pass_edit->disconnect();
            QMessageBox::critical(this, CRITICAL_BOX,"Erreur logiciel veuillez contacter l'admin.\nCode erreur: LE CHEMIN N'EXISTE PAS.");
            break;

        case -2:
            qDebug() << "le fichier de conf n'est pas au bon endroit' box d'arret";
            ui->pass_edit->disconnect();
            QMessageBox::critical(this, CRITICAL_BOX,"Erreur logiciel veuillez contacter l'admin.\nCode erreur: LE CHEMIN EST COROMPU.");
            break;

        case -3:
            qDebug() << "cd ne marche pareil box d'arret";
            ui->pass_edit->disconnect();
            QMessageBox::critical(this, CRITICAL_BOX,"Erreur logiciel veuillez contacter l'admin.\nCode erreur: CD FAILED.");
            break;

        case -4:
            qDebug() << "ouverture fichier a foirer ici on va mettre une box d'arret";
            ui->pass_edit->disconnect();
            QMessageBox::critical(this, CRITICAL_BOX,"Erreur logiciel veuillez contacter l'admin.\nCode erreur: OPEN FAILED.");
            break;
        default:
            qDebug() << "mauvaise saisi je connai pas ce flag de connexion c la merde dans mn prog !!!!!!!!!!!!";
            ui->pass_edit->disconnect();
            QMessageBox::critical(this, CRITICAL_BOX,"Erreur logiciel veuillez contacter l'admin.\nCode erreur: LE FICHIER DE CONFIGURATION EST COROMPU.");

        }
    }
}

void MainWindow::rec_conf()
{
    QDir current_dir;
    QString conf_dir;
    QString path_file;
    QFileInfo *path;

    current_dir = QDir::currentPath();
    conf_dir += current_dir.path() + DIR_CONF;
    path = new QFileInfo(conf_dir);
    if (path->exists() == true)
    {
        //chemin exists on fait des process
        if (path->isDir() == true)
        {
            if (current_dir.cd("debug/conf") == true)
            {
                path_file = conf_dir + FILE_CONF;
                QFile my_file(path_file);
                if (my_file.open(QIODevice::WriteOnly))
                {
                    if (verif_ip(ui->ip_edit->text()) == true)
                    {
                        ip = ui->ip_edit->text();
                        port = ui->port_edit->text();
                        QTextStream flux(&my_file);
                        flux << "IPSERVEUR=" << ui->ip_edit->text() << "\n";
                        flux << "PORT=" << ui->port_edit->text() << "\n";
                        flux << "USES=" << flag_use << "\n";
                        my_file.close();
                        QMessageBox::information(this, INFORMATION_BOX,"les donnees ont ete enregistrer avec succes.");
                        ui->F_conf->hide();
                        ui->listmsg->clear();// a sup
                        ui->listmsg->append(tr("<em>Vous pouvez maintenant vous connecter.</em>"));//a sup
                        //ui->F_conn->show();// a remplacer par le slot de connexion direct
                        slot_B_connect();
                    }
                    else
                    {
                        conf_err = "l'adresse IP du serveur saisi est invalide veuillez resaisir les valeurs.";
                        my_file.close();
                        QMessageBox::warning(this,WARNING_BOX,conf_err);
                    }
                }
                else
                {
                    qDebug() << "ouverture fichier foirer so sauvegarde oci du coup on appel di la conf ";
                    QMessageBox::critical(this, CRITICAL_BOX,"le programme ne dispose pas des droits necessaire open:error.");
                }
            }
            else
            {
                qDebug() << "on s'est fait avoir cd ne marche pas";
                QMessageBox::critical(this, CRITICAL_BOX,"le programme ne dispose pas des droits necessaire cd:error.");
            }
        }
        else
        {
            qDebug() << " on s'est fait avoir c pas un rep va falloir tout se retaper";
            if (current_dir.mkdir("conf") == true)
            {
                if (current_dir.cd("/conf") == true)
                {
                    path_file = conf_dir + FILE_CONF;

                    QFile my_file(path_file);
                    if (my_file.open(QIODevice::WriteOnly))
                    {
                        if (verif_ip(ui->ip_edit->text()) == true)
                        {
                            ip = ui->ip_edit->text();
                            port = ui->port_edit->text();
                            QTextStream flux(&my_file);
                            flux << "IPSERVEUR=" << ui->ip_edit->text() << "\n";
                            flux << "PORT=" << ui->port_edit->text() << "\n";
                            flux << "USES=" << flag_use << "\n";
                            my_file.close();
                            QMessageBox::information(this, INFORMATION_BOX,"les donnees ont ete enregistree avec succes.");
                            ui->F_conf->hide();
                            ui->listmsg->clear();//a sup
                            ui->listmsg->append(tr("<em>Vous pouvez maintenant vous connecter.</em>"));// a sup
                            //ui->F_conn->show();// aremplacer par le slot de connexion direct
                            slot_B_connect();
                        }
                        else
                        {
                            conf_err = "l'adresse IP du serveur saisi est invalide veuillez resaisir les valeurs.";
                            my_file.close();
                            QMessageBox::warning(this, WARNING_BOX,conf_err);
                        }
                    }
                    else
                    {
                        qDebug() << "ouverture conf pour rec foirer";
                        QMessageBox::critical(this, CRITICAL_BOX,"le programme ne dispose pas des droits necessaire open:error.");
                    }
                }
                else
                {
                    qDebug() << "cd conf failed";
                    QMessageBox::critical(this, CRITICAL_BOX,"le programme ne dispose pas des droits necessaire cd:error.");
                }
            }
            else
            {
                qDebug() << "mkdir conf failed";
                QMessageBox::critical(this, CRITICAL_BOX,"le programme ne dispose pas des droits necessaire mkdir:error.");
            }
        }
    }
    else
    {
        qDebug() << " c pas normal c censer etre fait a la cretion du log mais on va le refaire2";
        qDebug() << current_dir.currentPath();
        if (current_dir.cd("debug") == true)
        {
            if (current_dir.mkdir("conf") == true)
            {
                qDebug() << current_dir.path();
                if (current_dir.cd("conf") == true)
                {
                    qDebug() << current_dir.path();
                    path_file = conf_dir + FILE_CONF;

                    QFile my_file(path_file);
                    if (my_file.open(QIODevice::WriteOnly))
                    {
                        if (verif_ip(ui->ip_edit->text()) == true)
                        {
                            ip = ui->ip_edit->text();
                            port = ui->port_edit->text();
                            QTextStream flux(&my_file);
                            flux << "IPSERVEUR=" << ui->ip_edit->text() << "\n";
                            flux << "PORT=" << ui->port_edit->text() << "\n";
                            flux << "USES=" << flag_use << "\n";
                            my_file.close();
                            QMessageBox::information(this, INFORMATION_BOX,"les donnees ont ete enregistrer avec succes.");
                            ui->F_conf->hide();
                            ui->listmsg->clear();// a supp
                            ui->listmsg->append(tr("<em>Vous pouvez maintenant vous connecter.</em>"));//a supp
                            // ui->F_conn->show();// a remplacer direct par le slot de connexion
                            slot_B_connect();
                        }
                        else
                        {
                            conf_err = "l'adresse IP du serveur saisi est invalide veuillez resaisir les valeurs.";
                            my_file.close();
                            QMessageBox::warning(this, WARNING_BOX,conf_err);
                        }
                    }
                    else
                    {
                        qDebug() << "ouverture conf pour rec foirer";
                        QMessageBox::critical(this, CRITICAL_BOX,"le programme ne dispose pas des droits necessaire open:error.");
                    }
                }
                else
                {
                    qDebug() << "cd conf failed";
                    QMessageBox::critical(this, CRITICAL_BOX,"le programme ne dispose pas des droits necessaire cd:error.");
                }
            }
            else
            {
                qDebug() << "mkdir conf failed";
                QMessageBox::critical(this, CRITICAL_BOX,"le programme ne dispose pas des droits necessaire mkdir:error.");
            }
        }
        else
        {
            qDebug() << "cd debug failed";
            QMessageBox::critical(this, CRITICAL_BOX,"le programme ne dispose pas des droits necessaire cd:error.");
        }

    }
    //march on bascule sur une connexion direct
    //march pas on reste sur la meme page
}


void MainWindow::list_client()
{
    if (get_listcli() == true)
    {
        if (my_listclient.isEmpty() == true)
        {
            QMessageBox::information(this, INFORMATION_BOX,LIST_EMPTY);
            ui->B_del_cli->setEnabled(false);
            ui->B_mod_cli->setEnabled(false);
            ui->B_view_cli->setEnabled(false);
        }
        else
        {
            for (int i = 0; i < my_listclient.size();++i)
                ui->aff_cli->addItem(my_listclient.at(i).split(SEP).at(1));
        }
    }
    else
    {
        qDebug() << "probleme lors de la recuperation des infos dans la BDD";
    }
}


void MainWindow::gest_add_cli()
{
    QObject::connect(ui->B_valid_infogene, SIGNAL(clicked()), this, SLOT(save_info_gene()));
    QObject::connect(ui->B_cancel_infogene, SIGNAL(clicked()), this, SLOT(cancel_info_gene()));
    QObject::connect(ui->nomcli_edit, SIGNAL(editingFinished()), this, SLOT(slot_name()));
    QObject::connect(ui->addrcli_edit, SIGNAL(textEdited(QString)), this, SLOT(slot_adresse()));
    QObject::connect(ui->villecli_edit, SIGNAL(textEdited(QString)), this, SLOT(slot_ville()));
    QObject::connect(ui->cpcli_edit, SIGNAL(textEdited(QString)), this, SLOT(slot_cp()));
    QObject::connect(ui->telcli_edit, SIGNAL(textEdited(QString)), this, SLOT(slot_tel()));
    QObject::connect(ui->faxcli_edit, SIGNAL(textEdited(QString)), this, SLOT(slot_fax()));
    QObject::connect(ui->payscli_edit, SIGNAL(textEdited(QString)), this, SLOT(slot_pays()));
    QObject::connect(ui->mailcli_edit, SIGNAL(editingFinished()), this, SLOT(slot_mail()));
    QObject::connect(ui->dureecli_edit, SIGNAL(textEdited(QString)), this, SLOT(aff_calendar_duree()));
    QObject::connect(ui->creacli_edit, SIGNAL(textEdited(QString)), this, SLOT(aff_calendar_crea()));
    QObject::connect(ui->statutcli_edit, SIGNAL(activated(int)), this, SLOT(slot_statut(int)));
    QObject::connect(ui->categoriecli_edit, SIGNAL(activated(int)), this, SLOT(slot_categorie(int)));
    QObject::connect(ui->classificationcli_edit, SIGNAL(activated(int)), this, SLOT(slot_classification(int)));
    QObject::connect(ui->effcli_edit,SIGNAL(textEdited(QString)), this, SLOT(slot_eff()));
    QObject::connect(ui->cacli_edit,SIGNAL(textEdited(QString)), this, SLOT(slot_ca()));
    QObject::connect(ui->patientcli_edit, SIGNAL(textEdited(QString)), this, SLOT(slot_patient()));
    QObject::connect(ui->ouverturecli_edit, SIGNAL(textEdited(QString)), this, SLOT(slot_ouverture()));
    QObject::connect(ui->codcli_edit, SIGNAL(textEdited(QString)), this, SLOT(slot_codcli()));
    QObject::connect(ui->comcli_edit,SIGNAL(textChanged()), this, SLOT(slot_com()));
    ui->nom_img->setStyleSheet("background: url(:/del-16) no-repeat;");
    ui->statut_img->setStyleSheet("background: url(:/del-16) no-repeat;");
    ui->categorie_img->setStyleSheet("background: url(:/del-16) no-repeat;");
    ui->classification_img->setStyleSheet("background: url(:/del-16) no-repeat;");
    my_cli = new societe();
}

void MainWindow::gest_mod_cli()
{
    QString tmp;
    QStringList res;
    //id_cli = NULL;

    if (get_listcli() == true)
    {
        if (my_listclient.isEmpty() == true)
        {
            QMessageBox::critical(this, CRITICAL_BOX, DATA_BDD_ERR);
            cancel_info_gene();
        }
        else
        {
            for (int i = 0; i < my_listclient.size();++i)
            {
                if (my_selected.compare(my_listclient.at(i).split(SEP).at(1)) == 0)
                {
                    id_cli = my_listclient.at(i).split(SEP).at(0);
                    break;
                }
            }
            if (id_cli.isNull() == true)
            {
                QMessageBox::critical(this, CRITICAL_BOX, DATA_BDD_ERR);
                cancel_info_gene();
            }
            else
            {
                tmp = "SELECT * FROM CLIENT WHERE ROWID = '" + id_cli + "'" ;
                my_database->connexion();
                my_database->treat_query(tmp);
                my_database->close_db();
                res = my_database->get_resultat().at(0).split(SEP);
                qDebug() << res;
                QObject::connect(ui->B_modif_infogene, SIGNAL(clicked()), this, SLOT(mod_info_gene()));
                QObject::connect(ui->B_cancel_infogene, SIGNAL(clicked()), this, SLOT(cancel_info_gene()));
                QObject::connect(ui->nomcli_edit, SIGNAL(editingFinished()), this, SLOT(slot_name()));
                QObject::connect(ui->addrcli_edit, SIGNAL(textEdited(QString)), this, SLOT(slot_adresse()));
                QObject::connect(ui->villecli_edit, SIGNAL(textEdited(QString)), this, SLOT(slot_ville()));
                QObject::connect(ui->cpcli_edit, SIGNAL(textEdited(QString)), this, SLOT(slot_cp()));
                QObject::connect(ui->telcli_edit, SIGNAL(textEdited(QString)), this, SLOT(slot_tel()));
                QObject::connect(ui->faxcli_edit, SIGNAL(textEdited(QString)), this, SLOT(slot_fax()));
                QObject::connect(ui->payscli_edit, SIGNAL(textEdited(QString)), this, SLOT(slot_pays()));
                QObject::connect(ui->mailcli_edit, SIGNAL(editingFinished()), this, SLOT(slot_mail()));
                QObject::connect(ui->dureecli_edit, SIGNAL(textEdited(QString)), this, SLOT(aff_calendar_duree()));
                QObject::connect(ui->creacli_edit, SIGNAL(textEdited(QString)), this, SLOT(aff_calendar_crea()));
                QObject::connect(ui->statutcli_edit, SIGNAL(activated(int)), this, SLOT(slot_statut(int)));
                QObject::connect(ui->categoriecli_edit, SIGNAL(activated(int)), this, SLOT(slot_categorie(int)));
                QObject::connect(ui->classificationcli_edit, SIGNAL(activated(int)), this, SLOT(slot_classification(int)));
                QObject::connect(ui->effcli_edit,SIGNAL(textEdited(QString)), this, SLOT(slot_eff()));
                QObject::connect(ui->cacli_edit,SIGNAL(textEdited(QString)), this, SLOT(slot_ca()));
                QObject::connect(ui->patientcli_edit, SIGNAL(textEdited(QString)), this, SLOT(slot_patient()));
                QObject::connect(ui->ouverturecli_edit, SIGNAL(textEdited(QString)), this, SLOT(slot_ouverture()));
                QObject::connect(ui->codcli_edit, SIGNAL(textEdited(QString)), this, SLOT(slot_codcli()));
                QObject::connect(ui->comcli_edit,SIGNAL(textChanged()), this, SLOT(slot_com()));
                my_cli = new societe();//creation de la table pour recup les val
                my_cli->set_name(res.at(1), LEN_NAME_CLI);
                ui->nomcli_edit->setText(my_cli->get_name());
                my_cli->set_addr(res.at(2), LEN_ADDR_CLI);
                ui->addrcli_edit->setText(my_cli->get_addr());
                my_cli->set_ville(res.at(3), LEN_VILLE_CLI);
                ui->villecli_edit->setText(my_cli->get_ville());
                my_cli->set_cp(res.at(4), LEN_CP);
                ui->cpcli_edit->setText(my_cli->get_cp());
                my_cli->set_tel(res.at(5), LEN_NUMERO);
                ui->telcli_edit->setText(my_cli->get_tel());
                my_cli->set_fax(res.at(6), LEN_NUMERO);
                ui->faxcli_edit->setText(my_cli->get_fax());
                my_cli->set_pays(res.at(7), LEN_PAYS_CLI);
                ui->payscli_edit->setText(my_cli->get_pays());
                my_cli->set_mail(res.at(8),LEN_MAIL);
                ui->mailcli_edit->setText(my_cli->get_mail());
                my_cli->set_crea(res.at(9), LEN_DATE);
                ui->creacli_edit->setText(my_cli->get_crea());
                my_cli->set_statut(res.at(10).toInt());
                ui->statutcli_edit->setCurrentIndex(my_cli->get_statut());
                my_cli->set_duree(res.at(11), LEN_DATE);
                ui->dureecli_edit->setText(my_cli->get_duree());
                my_cli->set_eff(res.at(12), LEN_EFF_CLI);
                ui->effcli_edit->setText(my_cli->get_eff());
                my_cli->set_ca(res.at(13), LEN_CA_CLI);
                ui->cacli_edit->setText(my_cli->get_ca());
                my_cli->set_com(res.at(14), LEN_COM);
                ui->comcli_edit->setText(my_cli->get_com());
                my_cli->set_categorie(res.at(15).toInt());
                ui->categoriecli_edit->setCurrentIndex(my_cli->get_categorie());
                my_cli->set_classif(res.at(16).toInt());
                ui->classificationcli_edit->setCurrentIndex(my_cli->get_classif());
                my_cli->set_patient(res.at(17), LEN_NBPATIENT_CLI);
                ui->patientcli_edit->setText(my_cli->get_patient());
                my_cli->set_ouverture(res.at(18), LEN_NBOPEN_CLI);
                ui->ouverturecli_edit->setText(my_cli->get_ouverture());
                my_cli->set_codcli(res.at(19), LEN_CODCLI);
                ui->codcli_edit->setText(my_cli->get_codcli());

                qDebug() << "on y est presque";
            }
        }
    }
    else
    {
        QMessageBox::critical(this, CRITICAL_BOX, DATA_BDD_ERR);
        cancel_info_gene();
        qDebug() << "probleme lors de la recuperation des infos dans la BDD";
    }
}

void    MainWindow::gest_resume()
{
    qDebug() << "on va gerer le resume";
    QString tmp;
    QStringList res;
    QTableWidgetItem *my_item;

    if (get_listcli() == true)
    {
        if (my_listclient.isEmpty() == true)
        {
            QMessageBox::critical(this, CRITICAL_BOX, DATA_BDD_ERR);
            slot_return();
        }
        else
        {
            for (int i = 0; i < my_listclient.size();++i)
            {
                if (my_selected.compare(my_listclient.at(i).split(SEP).at(1)) == 0)
                {
                    id_cli = my_listclient.at(i).split(SEP).at(0);
                    break;
                }
            }
            if (id_cli.isNull() == true)
            {
                QMessageBox::critical(this, CRITICAL_BOX, DATA_BDD_ERR);
                slot_return();
            }
            else
            {
                tmp = "SELECT nb_patient, categorie, classification, chiffre_affaire FROM CLIENT WHERE ROWID = '" + id_cli + "'" ;
                my_database->connexion();
                my_database->treat_query(tmp);
                my_database->close_db();
                res = my_database->get_resultat().at(0).split(SEP);
                qDebug() << res;

                ui->lineEdit->setText(res.at(0));//nb_patient
                ui->lineEdit->setReadOnly(true);
                //categorie
                if (res.at(1).toInt() == 0)
                    ui->label_3->setText(UNDEFINED);
                else if (res.at(1).toInt() == 1)
                    ui->label_3->setText("GOLD");
                else if (res.at(1).toInt() == 2)
                    ui->label_3->setText("ARGENT");
                else if (res.at(1).toInt() == 3)
                    ui->label_3->setText("BRONZE");
                //classification
                if (res.at(2).toInt() == 0)
                    ui->label_4->setText(UNDEFINED);
                else if (res.at(2).toInt() == 1)
                    ui->label_4->setText("HOT");
                else if (res.at(2).toInt() == 2)
                    ui->label_4->setText("MEDIUM");
                else if (res.at(2).toInt() == 3)
                    ui->label_4->setText("COLD");
                //chiffre d'affaire
                my_item = new QTableWidgetItem(res.at(3));
                //ui->tableWidget_2->setRowCount(1);
                ui->tableWidget_2->setItem(0,2, my_item);
            }
        }
    }
    else
    {
        QMessageBox::critical(this, CRITICAL_BOX, DATA_BDD_ERR);
        slot_return();
        qDebug() << "probleme lors de la recuperation des infos dans la BDD";
    }
}

void    MainWindow::gest_info()
{
    qDebug() << "on va gerer les infos";
    QString tmp;
    QStringList res;
    QTableWidgetItem *item_crea;
    QTableWidgetItem *item_statut;
    QTableWidgetItem *item_duree;
    QTableWidgetItem *item_eff;
    QTableWidgetItem *item_ca;

    if (get_listcli() == true)
    {
        if (my_listclient.isEmpty() == true)
        {
            QMessageBox::critical(this, CRITICAL_BOX, DATA_BDD_ERR);
            slot_return();
        }
        else
        {
            for (int i = 0; i < my_listclient.size();++i)
            {
                if (my_selected.compare(my_listclient.at(i).split(SEP).at(1)) == 0)
                {
                    id_cli = my_listclient.at(i).split(SEP).at(0);
                    break;
                }
            }
            if (id_cli.isNull() == true)
            {
                QMessageBox::critical(this, CRITICAL_BOX, DATA_BDD_ERR);
                slot_return();
            }
            else
            {
                tmp = "SELECT * FROM CLIENT WHERE ROWID = '" + id_cli + "'" ;
                my_database->connexion();
                my_database->treat_query(tmp);
                my_database->close_db();
                res = my_database->get_resultat().at(0).split(SEP);
                qDebug() << res;
                ui->B_mod_info_view->setText("Modifier");
                QObject::connect(ui->B_mod_info_view, SIGNAL(clicked()), this, SLOT(slot_activator()));
                ui->nom_info_img->setStyleSheet("");
                ui->addr_info_img->setStyleSheet("");
                ui->ville_info_img->setStyleSheet("");
                ui->cp_info_img->setStyleSheet("");
                ui->tel_info_img->setStyleSheet("");
                ui->fax_info_img->setStyleSheet("");
                //ui->pays_info_img->setStyleSheet("");
                ui->mail_info_img->setStyleSheet("");
                ui->com_info_img->setStyleSheet("");

                my_cli = new societe();//creation de la classe pour recup les val
                my_cli->set_name(res.at(1), LEN_NAME_CLI);
                ui->infos_nom_edit->setText(my_cli->get_name());
                ui->infos_nom_edit->setReadOnly(true);

                my_cli->set_addr(res.at(2), LEN_ADDR_CLI);
                ui->infos_addresse_edit->setText(my_cli->get_addr());
                ui->infos_addresse_edit->setReadOnly(true);

                my_cli->set_ville(res.at(3), LEN_VILLE_CLI);
                ui->infos_ville_edit->setText(my_cli->get_ville());
                ui->infos_ville_edit->setReadOnly(true);

                my_cli->set_cp(res.at(4), LEN_CP);
                ui->infos_cp_edit->setText(my_cli->get_cp());
                ui->infos_cp_edit->setReadOnly(true);

                my_cli->set_tel(res.at(5), LEN_NUMERO);
                ui->infos_tel_edit->setText(my_cli->get_tel());
                ui->infos_tel_edit->setReadOnly(true);

                my_cli->set_fax(res.at(6), LEN_NUMERO);
                ui->infos_telecopie_edit->setText(my_cli->get_fax());
                ui->infos_telecopie_edit->setReadOnly(true);
                //a rajouter il a forget ce champ dans le design
                //                my_cli->set_pays(res.at(7), LEN_PAYS_CLI);
                //                ui->infos_pays_edit->setText(my_cli->get_pays());
                //                ui->infos_pays_edit->setReadOnly(true);

                my_cli->set_mail(res.at(8),LEN_MAIL);
                ui->infos_mail_edit->setText(my_cli->get_mail());
                ui->infos_mail_edit->setReadOnly(true);
                //ui->infos_tab_renseignements->setShowGrid(true);
                my_cli->set_crea(res.at(9), LEN_DATE);
                item_crea = new QTableWidgetItem(res.at(9));
                ui->infos_tab_renseignements->setItem(0,0, item_crea);

                my_cli->set_statut(res.at(10).toInt());
                if (my_cli->get_statut() == 0)
                    item_statut = new QTableWidgetItem(QString("NON-DEF"));
                else if (my_cli->get_statut() == 1)
                    item_statut = new QTableWidgetItem(QString("PRIVE"));
                else if (my_cli->get_statut() == 2)
                    item_statut = new QTableWidgetItem(QString("PUBLIC"));
                ui->infos_tab_renseignements->setItem(0,1,item_statut);

                my_cli->set_duree(res.at(11), LEN_DATE);
                item_duree = new QTableWidgetItem(res.at(11));
                ui->infos_tab_renseignements->setItem(0,2,item_duree);


                my_cli->set_eff(res.at(12), LEN_EFF_CLI);
                item_eff = new QTableWidgetItem(res.at(12));
                ui->infos_tab_renseignements->setItem(0,3,item_eff);

                my_cli->set_ca(res.at(13), LEN_CA_CLI);
                item_ca = new QTableWidgetItem(res.at(13));
                ui->infos_tab_renseignements->setItem(0,4,item_ca);

                my_cli->set_com(res.at(14), LEN_COM);
                ui->infos_commentaire_edit->setText(my_cli->get_com());
                ui->infos_commentaire_edit->setReadOnly(true);

                my_cli->set_categorie(res.at(15).toInt());
                my_cli->set_classif(res.at(16).toInt());
                my_cli->set_patient(res.at(17), LEN_NBPATIENT_CLI);
                my_cli->set_ouverture(res.at(18), LEN_NBOPEN_CLI);
                my_cli->set_codcli(res.at(19), LEN_CODCLI);
            }
        }
    }
    else
    {
        QMessageBox::critical(this, CRITICAL_BOX, DATA_BDD_ERR);
        slot_return();
        qDebug() << "probleme lors de la recuperation des infos dans la BDD";
    }
}

void    MainWindow::gest_contacts()
{
    qDebug() << "on va gerer les contacts";
    QString tmp;

    tmp = "SELECT * FROM CONTACT WHERE id_client = '" + id_cli + "'";
    my_database->connexion();

}

void    MainWindow::gest_notes()
{
    qDebug() << "on va gerer les notes";
}

void    MainWindow::gest_histo()
{
    qDebug() << "on va gerer les historiques de vente";
}

void    MainWindow::gest_parc()
{
    qDebug() << "on va gerer le parc Machines";
    QObject::connect(ui->sous_parc_instru, SIGNAL(currentChanged(int)), this, SLOT(slot_machine(int)));
}

void    MainWindow::gest_activite()
{
    qDebug() << "on va gerer les activites";
}

void MainWindow::gest_hemato()
{
    qDebug() << "on va faire la gestion des instrus hematologie";
}

void MainWindow::gest_bioch()
{
    qDebug() << "on va faire la gestion des instrus biochimique";
}
