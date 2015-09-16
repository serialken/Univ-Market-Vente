/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Wed 20. Jul 13:00:20 2011
**      by: Qt User Interface Compiler version 4.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QFormLayout>
#include <QtGui/QFrame>
#include <QtGui/QGraphicsView>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QScrollArea>
#include <QtGui/QScrollBar>
#include <QtGui/QStatusBar>
#include <QtGui/QTabWidget>
#include <QtGui/QTableWidget>
#include <QtGui/QTextEdit>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLabel *Client_actuel;
    QTabWidget *tabWidget;
    QWidget *tab_4;
    QFrame *frame_resum;
    QGroupBox *groupBox;
    QTableWidget *tableWidget_2;
    QGroupBox *groupBox_2;
    QTableWidget *resum_histocomm;
    QGroupBox *groupBox_3;
    QTableWidget *resum_tab_parc;
    QGroupBox *groupBox_4;
    QTableWidget *resum_tab_reac;
    QGroupBox *groupBox_5;
    QTableWidget *tableWidget_3;
    QGroupBox *groupBox_6;
    QLineEdit *lineEdit;
    QGroupBox *groupBox_7;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QWidget *tab_5;
    QFrame *frame_infos;
    QGroupBox *groupBox_12;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *label_5;
    QLineEdit *infos_nom_edit;
    QLabel *label_7;
    QLineEdit *infos_addresse_edit;
    QLabel *label_9;
    QLineEdit *infos_ville_edit;
    QLabel *label_11;
    QLineEdit *infos_cp_edit;
    QLabel *label_13;
    QLineEdit *infos_tel_edit;
    QLabel *label_15;
    QLineEdit *infos_telecopie_edit;
    QLabel *label_17;
    QLineEdit *infos_mail_edit;
    QGroupBox *groupBox_13;
    QTableWidget *infos_tab_renseignements;
    QGroupBox *groupBox_14;
    QTextEdit *infos_commentaire_edit;
    QGroupBox *groupBox_15;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_2;
    QLabel *label_6;
    QLabel *label_8;
    QLabel *label_10;
    QWidget *tab_8;
    QFrame *frame_contacts;
    QGroupBox *groupBox_8;
    QTableWidget *contact_tab;
    QPushButton *contacts_add;
    QPushButton *contact_mod;
    QPushButton *contact_del;
    QGroupBox *groupBox_16;
    QPushButton *contact_add_position;
    QWidget *gridLayoutWidget_3;
    QGridLayout *gridLayout_3;
    QLabel *label_12;
    QLabel *label_14;
    QLineEdit *contact_prenom_edit;
    QLabel *label_16;
    QLineEdit *contact_nom_edit;
    QLabel *label_18;
    QLabel *label_19;
    QLineEdit *contact_mail_edit;
    QLabel *label_20;
    QLineEdit *contact_telephon_edit;
    QLabel *label_21;
    QLabel *label_22;
    QLineEdit *contact_assoc_edit;
    QComboBox *contact_civilite_edit;
    QComboBox *contact_position_edit;
    QComboBox *comboBox;
    QWidget *tab_9;
    QFrame *frame_notes;
    QGroupBox *groupBox_9;
    QTableWidget *notes_tab;
    QWidget *tab_10;
    QFrame *frame_histoventes;
    QGroupBox *groupBox_10;
    QTableWidget *histo_tab;
    QTableWidget *histo_total;
    QGroupBox *groupBox_11;
    QGraphicsView *histo_evo_graphique;
    QWidget *tab_11;
    QFrame *frame_parcmachine;
    QTabWidget *sous_parc_instru;
    QWidget *tab_6;
    QScrollArea *scrollArea_2;
    QWidget *scrollAreaWidgetContents_2;
    QTableWidget *parc_hema_machine;
    QTableWidget *tableWidget;
    QScrollBar *horizontalScrollBar;
    QTableWidget *tableWidget_4;
    QWidget *tab_7;
    QWidget *tab_12;
    QFrame *frame_actclient;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(832, 613);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        Client_actuel = new QLabel(centralWidget);
        Client_actuel->setObjectName(QString::fromUtf8("Client_actuel"));
        Client_actuel->setGeometry(QRect(20, 10, 131, 16));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        Client_actuel->setFont(font);
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(20, 30, 771, 521));
        tab_4 = new QWidget();
        tab_4->setObjectName(QString::fromUtf8("tab_4"));
        frame_resum = new QFrame(tab_4);
        frame_resum->setObjectName(QString::fromUtf8("frame_resum"));
        frame_resum->setGeometry(QRect(0, 0, 761, 491));
        QFont font1;
        font1.setPointSize(8);
        frame_resum->setFont(font1);
        frame_resum->setFrameShape(QFrame::StyledPanel);
        frame_resum->setFrameShadow(QFrame::Raised);
        groupBox = new QGroupBox(frame_resum);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(110, 370, 321, 111));
        tableWidget_2 = new QTableWidget(groupBox);
        if (tableWidget_2->columnCount() < 3)
            tableWidget_2->setColumnCount(3);
        QFont font2;
        font2.setPointSize(7);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setFont(font2);
        tableWidget_2->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setFont(font2);
        tableWidget_2->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        __qtablewidgetitem2->setFont(font2);
        tableWidget_2->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        tableWidget_2->setObjectName(QString::fromUtf8("tableWidget_2"));
        tableWidget_2->setGeometry(QRect(10, 20, 302, 81));
        tableWidget_2->setFont(font2);
        tableWidget_2->setCornerButtonEnabled(true);
        groupBox_2 = new QGroupBox(frame_resum);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 230, 421, 121));
        resum_histocomm = new QTableWidget(groupBox_2);
        if (resum_histocomm->columnCount() < 4)
            resum_histocomm->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        __qtablewidgetitem3->setFont(font2);
        resum_histocomm->setHorizontalHeaderItem(0, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        __qtablewidgetitem4->setFont(font2);
        resum_histocomm->setHorizontalHeaderItem(1, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        __qtablewidgetitem5->setFont(font2);
        resum_histocomm->setHorizontalHeaderItem(2, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        __qtablewidgetitem6->setFont(font2);
        __qtablewidgetitem6->setBackground(QColor(0, 0, 0));
        resum_histocomm->setHorizontalHeaderItem(3, __qtablewidgetitem6);
        resum_histocomm->setObjectName(QString::fromUtf8("resum_histocomm"));
        resum_histocomm->setGeometry(QRect(10, 18, 402, 91));
        resum_histocomm->setFont(font2);
        groupBox_3 = new QGroupBox(frame_resum);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(10, 80, 321, 131));
        resum_tab_parc = new QTableWidget(groupBox_3);
        if (resum_tab_parc->columnCount() < 3)
            resum_tab_parc->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        __qtablewidgetitem7->setFont(font2);
        resum_tab_parc->setHorizontalHeaderItem(0, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        __qtablewidgetitem8->setFont(font2);
        resum_tab_parc->setHorizontalHeaderItem(1, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        __qtablewidgetitem9->setFont(font2);
        resum_tab_parc->setHorizontalHeaderItem(2, __qtablewidgetitem9);
        resum_tab_parc->setObjectName(QString::fromUtf8("resum_tab_parc"));
        resum_tab_parc->setGeometry(QRect(9, 18, 302, 101));
        resum_tab_parc->setMaximumSize(QSize(500, 500));
        resum_tab_parc->setFont(font2);
        groupBox_4 = new QGroupBox(frame_resum);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setGeometry(QRect(340, 80, 221, 131));
        resum_tab_reac = new QTableWidget(groupBox_4);
        if (resum_tab_reac->columnCount() < 2)
            resum_tab_reac->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        __qtablewidgetitem10->setFont(font2);
        resum_tab_reac->setHorizontalHeaderItem(0, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        __qtablewidgetitem11->setFont(font2);
        resum_tab_reac->setHorizontalHeaderItem(1, __qtablewidgetitem11);
        resum_tab_reac->setObjectName(QString::fromUtf8("resum_tab_reac"));
        resum_tab_reac->setGeometry(QRect(10, 18, 202, 101));
        QFont font3;
        font3.setPointSize(7);
        font3.setBold(false);
        font3.setItalic(false);
        font3.setWeight(50);
        resum_tab_reac->setFont(font3);
        resum_tab_reac->setRowCount(0);
        groupBox_5 = new QGroupBox(frame_resum);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        groupBox_5->setGeometry(QRect(530, 230, 221, 121));
        tableWidget_3 = new QTableWidget(groupBox_5);
        if (tableWidget_3->columnCount() < 2)
            tableWidget_3->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        __qtablewidgetitem12->setFont(font2);
        tableWidget_3->setHorizontalHeaderItem(0, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        __qtablewidgetitem13->setFont(font2);
        tableWidget_3->setHorizontalHeaderItem(1, __qtablewidgetitem13);
        tableWidget_3->setObjectName(QString::fromUtf8("tableWidget_3"));
        tableWidget_3->setGeometry(QRect(10, 18, 202, 91));
        tableWidget_3->setFont(font2);
        groupBox_6 = new QGroupBox(frame_resum);
        groupBox_6->setObjectName(QString::fromUtf8("groupBox_6"));
        groupBox_6->setGeometry(QRect(40, 10, 191, 41));
        lineEdit = new QLineEdit(groupBox_6);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(39, 15, 113, 20));
        groupBox_7 = new QGroupBox(frame_resum);
        groupBox_7->setObjectName(QString::fromUtf8("groupBox_7"));
        groupBox_7->setGeometry(QRect(520, 10, 231, 61));
        formLayoutWidget = new QWidget(groupBox_7);
        formLayoutWidget->setObjectName(QString::fromUtf8("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(10, 15, 160, 41));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(formLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font2);

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        label_2 = new QLabel(formLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font2);

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        label_3 = new QLabel(formLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setStyleSheet(QString::fromUtf8("background: red; border: 1px solid black;"));
        label_3->setAlignment(Qt::AlignCenter);

        formLayout->setWidget(0, QFormLayout::FieldRole, label_3);

        label_4 = new QLabel(formLayoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setStyleSheet(QString::fromUtf8("background: green; border: 1px solid black;"));

        formLayout->setWidget(1, QFormLayout::FieldRole, label_4);

        tabWidget->addTab(tab_4, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QString::fromUtf8("tab_5"));
        frame_infos = new QFrame(tab_5);
        frame_infos->setObjectName(QString::fromUtf8("frame_infos"));
        frame_infos->setGeometry(QRect(0, 0, 761, 491));
        frame_infos->setFrameShape(QFrame::StyledPanel);
        frame_infos->setFrameShadow(QFrame::Raised);
        groupBox_12 = new QGroupBox(frame_infos);
        groupBox_12->setObjectName(QString::fromUtf8("groupBox_12"));
        groupBox_12->setGeometry(QRect(10, 10, 261, 171));
        gridLayoutWidget = new QWidget(groupBox_12);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 17, 241, 142));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(0);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(gridLayoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setStyleSheet(QString::fromUtf8("background: grey; border: 1px solid black;"));
        label_5->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_5, 0, 0, 1, 1);

        infos_nom_edit = new QLineEdit(gridLayoutWidget);
        infos_nom_edit->setObjectName(QString::fromUtf8("infos_nom_edit"));

        gridLayout->addWidget(infos_nom_edit, 0, 1, 1, 1);

        label_7 = new QLabel(gridLayoutWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setStyleSheet(QString::fromUtf8("background: grey; border: 1px solid black;"));
        label_7->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_7, 1, 0, 1, 1);

        infos_addresse_edit = new QLineEdit(gridLayoutWidget);
        infos_addresse_edit->setObjectName(QString::fromUtf8("infos_addresse_edit"));

        gridLayout->addWidget(infos_addresse_edit, 1, 1, 1, 1);

        label_9 = new QLabel(gridLayoutWidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setStyleSheet(QString::fromUtf8("background: grey; border: 1px solid black;"));
        label_9->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_9, 2, 0, 1, 1);

        infos_ville_edit = new QLineEdit(gridLayoutWidget);
        infos_ville_edit->setObjectName(QString::fromUtf8("infos_ville_edit"));

        gridLayout->addWidget(infos_ville_edit, 2, 1, 1, 1);

        label_11 = new QLabel(gridLayoutWidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setStyleSheet(QString::fromUtf8("background: grey; border: 1px solid black;"));
        label_11->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_11, 3, 0, 1, 1);

        infos_cp_edit = new QLineEdit(gridLayoutWidget);
        infos_cp_edit->setObjectName(QString::fromUtf8("infos_cp_edit"));

        gridLayout->addWidget(infos_cp_edit, 3, 1, 1, 1);

        label_13 = new QLabel(gridLayoutWidget);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setStyleSheet(QString::fromUtf8("background: grey; border: 1px solid black;"));
        label_13->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_13, 4, 0, 1, 1);

        infos_tel_edit = new QLineEdit(gridLayoutWidget);
        infos_tel_edit->setObjectName(QString::fromUtf8("infos_tel_edit"));

        gridLayout->addWidget(infos_tel_edit, 4, 1, 1, 1);

        label_15 = new QLabel(gridLayoutWidget);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setEnabled(true);
        label_15->setStyleSheet(QString::fromUtf8("background: grey; border: 1px solid black;"));
        label_15->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_15, 5, 0, 1, 1);

        infos_telecopie_edit = new QLineEdit(gridLayoutWidget);
        infos_telecopie_edit->setObjectName(QString::fromUtf8("infos_telecopie_edit"));

        gridLayout->addWidget(infos_telecopie_edit, 5, 1, 1, 1);

        label_17 = new QLabel(gridLayoutWidget);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setStyleSheet(QString::fromUtf8("background: grey; border: 1px solid black;"));
        label_17->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_17, 6, 0, 1, 1);

        infos_mail_edit = new QLineEdit(gridLayoutWidget);
        infos_mail_edit->setObjectName(QString::fromUtf8("infos_mail_edit"));

        gridLayout->addWidget(infos_mail_edit, 6, 1, 1, 1);

        groupBox_13 = new QGroupBox(frame_infos);
        groupBox_13->setObjectName(QString::fromUtf8("groupBox_13"));
        groupBox_13->setGeometry(QRect(10, 190, 531, 81));
        infos_tab_renseignements = new QTableWidget(groupBox_13);
        if (infos_tab_renseignements->columnCount() < 5)
            infos_tab_renseignements->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        __qtablewidgetitem14->setFont(font2);
        infos_tab_renseignements->setHorizontalHeaderItem(0, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        __qtablewidgetitem15->setFont(font2);
        infos_tab_renseignements->setHorizontalHeaderItem(1, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        __qtablewidgetitem16->setFont(font2);
        infos_tab_renseignements->setHorizontalHeaderItem(2, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        __qtablewidgetitem17->setFont(font2);
        infos_tab_renseignements->setHorizontalHeaderItem(3, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        __qtablewidgetitem18->setFont(font2);
        infos_tab_renseignements->setHorizontalHeaderItem(4, __qtablewidgetitem18);
        if (infos_tab_renseignements->rowCount() < 1)
            infos_tab_renseignements->setRowCount(1);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        infos_tab_renseignements->setVerticalHeaderItem(0, __qtablewidgetitem19);
        infos_tab_renseignements->setObjectName(QString::fromUtf8("infos_tab_renseignements"));
        infos_tab_renseignements->setGeometry(QRect(10, 20, 510, 51));
        infos_tab_renseignements->setFont(font2);
        groupBox_14 = new QGroupBox(frame_infos);
        groupBox_14->setObjectName(QString::fromUtf8("groupBox_14"));
        groupBox_14->setGeometry(QRect(10, 280, 681, 181));
        infos_commentaire_edit = new QTextEdit(groupBox_14);
        infos_commentaire_edit->setObjectName(QString::fromUtf8("infos_commentaire_edit"));
        infos_commentaire_edit->setGeometry(QRect(10, 19, 661, 151));
        groupBox_15 = new QGroupBox(frame_infos);
        groupBox_15->setObjectName(QString::fromUtf8("groupBox_15"));
        groupBox_15->setGeometry(QRect(430, 10, 261, 71));
        gridLayoutWidget_2 = new QWidget(groupBox_15);
        gridLayoutWidget_2->setObjectName(QString::fromUtf8("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(10, 20, 241, 41));
        gridLayout_2 = new QGridLayout(gridLayoutWidget_2);
        gridLayout_2->setSpacing(0);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        label_6 = new QLabel(gridLayoutWidget_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setStyleSheet(QString::fromUtf8("background: #999999; border: 1px solid black;"));
        label_6->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_6, 0, 0, 2, 1);

        label_8 = new QLabel(gridLayoutWidget_2);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setStyleSheet(QString::fromUtf8("background: white; border: 1px solid black;"));
        label_8->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_8, 0, 1, 1, 1);

        label_10 = new QLabel(gridLayoutWidget_2);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setStyleSheet(QString::fromUtf8("background: white; border: 1px solid black;"));
        label_10->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_10, 1, 1, 1, 1);

        tabWidget->addTab(tab_5, QString());
        tab_8 = new QWidget();
        tab_8->setObjectName(QString::fromUtf8("tab_8"));
        frame_contacts = new QFrame(tab_8);
        frame_contacts->setObjectName(QString::fromUtf8("frame_contacts"));
        frame_contacts->setGeometry(QRect(0, 0, 761, 491));
        frame_contacts->setFrameShape(QFrame::StyledPanel);
        frame_contacts->setFrameShadow(QFrame::Raised);
        groupBox_8 = new QGroupBox(frame_contacts);
        groupBox_8->setObjectName(QString::fromUtf8("groupBox_8"));
        groupBox_8->setGeometry(QRect(10, 10, 741, 251));
        groupBox_8->setCheckable(false);
        contact_tab = new QTableWidget(groupBox_8);
        if (contact_tab->columnCount() < 8)
            contact_tab->setColumnCount(8);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        __qtablewidgetitem20->setFont(font2);
        contact_tab->setHorizontalHeaderItem(0, __qtablewidgetitem20);
        QTableWidgetItem *__qtablewidgetitem21 = new QTableWidgetItem();
        __qtablewidgetitem21->setFont(font2);
        contact_tab->setHorizontalHeaderItem(1, __qtablewidgetitem21);
        QTableWidgetItem *__qtablewidgetitem22 = new QTableWidgetItem();
        __qtablewidgetitem22->setFont(font2);
        contact_tab->setHorizontalHeaderItem(2, __qtablewidgetitem22);
        QTableWidgetItem *__qtablewidgetitem23 = new QTableWidgetItem();
        __qtablewidgetitem23->setFont(font2);
        contact_tab->setHorizontalHeaderItem(3, __qtablewidgetitem23);
        QTableWidgetItem *__qtablewidgetitem24 = new QTableWidgetItem();
        __qtablewidgetitem24->setFont(font2);
        contact_tab->setHorizontalHeaderItem(4, __qtablewidgetitem24);
        QTableWidgetItem *__qtablewidgetitem25 = new QTableWidgetItem();
        __qtablewidgetitem25->setFont(font2);
        contact_tab->setHorizontalHeaderItem(5, __qtablewidgetitem25);
        QTableWidgetItem *__qtablewidgetitem26 = new QTableWidgetItem();
        __qtablewidgetitem26->setFont(font2);
        contact_tab->setHorizontalHeaderItem(6, __qtablewidgetitem26);
        QTableWidgetItem *__qtablewidgetitem27 = new QTableWidgetItem();
        __qtablewidgetitem27->setFont(font2);
        contact_tab->setHorizontalHeaderItem(7, __qtablewidgetitem27);
        contact_tab->setObjectName(QString::fromUtf8("contact_tab"));
        contact_tab->setGeometry(QRect(10, 20, 721, 221));
        contact_tab->setFont(font2);
        contact_tab->horizontalHeader()->setDefaultSectionSize(100);
        contact_tab->verticalHeader()->setDefaultSectionSize(30);
        contact_tab->verticalHeader()->setMinimumSectionSize(15);
        contacts_add = new QPushButton(frame_contacts);
        contacts_add->setObjectName(QString::fromUtf8("contacts_add"));
        contacts_add->setGeometry(QRect(510, 269, 75, 23));
        contact_mod = new QPushButton(frame_contacts);
        contact_mod->setObjectName(QString::fromUtf8("contact_mod"));
        contact_mod->setGeometry(QRect(590, 269, 75, 23));
        contact_del = new QPushButton(frame_contacts);
        contact_del->setObjectName(QString::fromUtf8("contact_del"));
        contact_del->setGeometry(QRect(670, 269, 75, 23));
        groupBox_16 = new QGroupBox(frame_contacts);
        groupBox_16->setObjectName(QString::fromUtf8("groupBox_16"));
        groupBox_16->setGeometry(QRect(10, 280, 291, 191));
        contact_add_position = new QPushButton(groupBox_16);
        contact_add_position->setObjectName(QString::fromUtf8("contact_add_position"));
        contact_add_position->setGeometry(QRect(260, 80, 21, 21));
        gridLayoutWidget_3 = new QWidget(groupBox_16);
        gridLayoutWidget_3->setObjectName(QString::fromUtf8("gridLayoutWidget_3"));
        gridLayoutWidget_3->setGeometry(QRect(10, 20, 241, 162));
        gridLayout_3 = new QGridLayout(gridLayoutWidget_3);
        gridLayout_3->setSpacing(0);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        label_12 = new QLabel(gridLayoutWidget_3);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setStyleSheet(QString::fromUtf8("background: grey; border: 1px solid black;"));
        label_12->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_12, 0, 0, 1, 1);

        label_14 = new QLabel(gridLayoutWidget_3);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setStyleSheet(QString::fromUtf8("background: grey; border: 1px solid black;"));
        label_14->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_14, 1, 0, 1, 1);

        contact_prenom_edit = new QLineEdit(gridLayoutWidget_3);
        contact_prenom_edit->setObjectName(QString::fromUtf8("contact_prenom_edit"));

        gridLayout_3->addWidget(contact_prenom_edit, 1, 1, 1, 1);

        label_16 = new QLabel(gridLayoutWidget_3);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setStyleSheet(QString::fromUtf8("background: grey; border: 1px solid black;"));
        label_16->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_16, 2, 0, 1, 1);

        contact_nom_edit = new QLineEdit(gridLayoutWidget_3);
        contact_nom_edit->setObjectName(QString::fromUtf8("contact_nom_edit"));

        gridLayout_3->addWidget(contact_nom_edit, 2, 1, 1, 1);

        label_18 = new QLabel(gridLayoutWidget_3);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setStyleSheet(QString::fromUtf8("background: grey; border: 1px solid black;"));
        label_18->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_18, 3, 0, 1, 1);

        label_19 = new QLabel(gridLayoutWidget_3);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setStyleSheet(QString::fromUtf8("background: grey; border: 1px solid black;"));
        label_19->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_19, 4, 0, 1, 1);

        contact_mail_edit = new QLineEdit(gridLayoutWidget_3);
        contact_mail_edit->setObjectName(QString::fromUtf8("contact_mail_edit"));

        gridLayout_3->addWidget(contact_mail_edit, 4, 1, 1, 1);

        label_20 = new QLabel(gridLayoutWidget_3);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setEnabled(true);
        label_20->setStyleSheet(QString::fromUtf8("background: grey; border: 1px solid black;"));
        label_20->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_20, 5, 0, 1, 1);

        contact_telephon_edit = new QLineEdit(gridLayoutWidget_3);
        contact_telephon_edit->setObjectName(QString::fromUtf8("contact_telephon_edit"));

        gridLayout_3->addWidget(contact_telephon_edit, 5, 1, 1, 1);

        label_21 = new QLabel(gridLayoutWidget_3);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setStyleSheet(QString::fromUtf8("background: grey; border: 1px solid black;"));
        label_21->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_21, 6, 0, 1, 1);

        label_22 = new QLabel(gridLayoutWidget_3);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setStyleSheet(QString::fromUtf8("background: grey; border: 1px solid black;"));
        label_22->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_22, 7, 0, 1, 1);

        contact_assoc_edit = new QLineEdit(gridLayoutWidget_3);
        contact_assoc_edit->setObjectName(QString::fromUtf8("contact_assoc_edit"));

        gridLayout_3->addWidget(contact_assoc_edit, 7, 1, 1, 1);

        contact_civilite_edit = new QComboBox(gridLayoutWidget_3);
        contact_civilite_edit->setObjectName(QString::fromUtf8("contact_civilite_edit"));

        gridLayout_3->addWidget(contact_civilite_edit, 0, 1, 1, 1);

        contact_position_edit = new QComboBox(gridLayoutWidget_3);
        contact_position_edit->setObjectName(QString::fromUtf8("contact_position_edit"));

        gridLayout_3->addWidget(contact_position_edit, 3, 1, 1, 1);

        comboBox = new QComboBox(gridLayoutWidget_3);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        gridLayout_3->addWidget(comboBox, 6, 1, 1, 1);

        tabWidget->addTab(tab_8, QString());
        tab_9 = new QWidget();
        tab_9->setObjectName(QString::fromUtf8("tab_9"));
        frame_notes = new QFrame(tab_9);
        frame_notes->setObjectName(QString::fromUtf8("frame_notes"));
        frame_notes->setGeometry(QRect(0, 0, 761, 491));
        frame_notes->setFrameShape(QFrame::StyledPanel);
        frame_notes->setFrameShadow(QFrame::Raised);
        groupBox_9 = new QGroupBox(frame_notes);
        groupBox_9->setObjectName(QString::fromUtf8("groupBox_9"));
        groupBox_9->setGeometry(QRect(10, 40, 741, 351));
        groupBox_9->setCheckable(false);
        notes_tab = new QTableWidget(groupBox_9);
        if (notes_tab->columnCount() < 8)
            notes_tab->setColumnCount(8);
        QTableWidgetItem *__qtablewidgetitem28 = new QTableWidgetItem();
        __qtablewidgetitem28->setFont(font2);
        notes_tab->setHorizontalHeaderItem(0, __qtablewidgetitem28);
        QTableWidgetItem *__qtablewidgetitem29 = new QTableWidgetItem();
        __qtablewidgetitem29->setFont(font2);
        notes_tab->setHorizontalHeaderItem(1, __qtablewidgetitem29);
        QTableWidgetItem *__qtablewidgetitem30 = new QTableWidgetItem();
        __qtablewidgetitem30->setFont(font2);
        notes_tab->setHorizontalHeaderItem(2, __qtablewidgetitem30);
        QTableWidgetItem *__qtablewidgetitem31 = new QTableWidgetItem();
        __qtablewidgetitem31->setFont(font2);
        notes_tab->setHorizontalHeaderItem(3, __qtablewidgetitem31);
        QTableWidgetItem *__qtablewidgetitem32 = new QTableWidgetItem();
        __qtablewidgetitem32->setFont(font2);
        notes_tab->setHorizontalHeaderItem(4, __qtablewidgetitem32);
        QTableWidgetItem *__qtablewidgetitem33 = new QTableWidgetItem();
        __qtablewidgetitem33->setFont(font2);
        notes_tab->setHorizontalHeaderItem(5, __qtablewidgetitem33);
        QTableWidgetItem *__qtablewidgetitem34 = new QTableWidgetItem();
        __qtablewidgetitem34->setFont(font2);
        notes_tab->setHorizontalHeaderItem(6, __qtablewidgetitem34);
        QTableWidgetItem *__qtablewidgetitem35 = new QTableWidgetItem();
        __qtablewidgetitem35->setFont(font2);
        notes_tab->setHorizontalHeaderItem(7, __qtablewidgetitem35);
        notes_tab->setObjectName(QString::fromUtf8("notes_tab"));
        notes_tab->setGeometry(QRect(10, 31, 721, 301));
        notes_tab->setFont(font2);
        notes_tab->horizontalHeader()->setDefaultSectionSize(100);
        notes_tab->verticalHeader()->setDefaultSectionSize(30);
        notes_tab->verticalHeader()->setMinimumSectionSize(15);
        tabWidget->addTab(tab_9, QString());
        tab_10 = new QWidget();
        tab_10->setObjectName(QString::fromUtf8("tab_10"));
        frame_histoventes = new QFrame(tab_10);
        frame_histoventes->setObjectName(QString::fromUtf8("frame_histoventes"));
        frame_histoventes->setGeometry(QRect(0, 0, 761, 491));
        frame_histoventes->setFrameShape(QFrame::StyledPanel);
        frame_histoventes->setFrameShadow(QFrame::Raised);
        groupBox_10 = new QGroupBox(frame_histoventes);
        groupBox_10->setObjectName(QString::fromUtf8("groupBox_10"));
        groupBox_10->setGeometry(QRect(20, 40, 711, 221));
        groupBox_10->setFont(font2);
        groupBox_10->setCheckable(false);
        histo_tab = new QTableWidget(groupBox_10);
        if (histo_tab->columnCount() < 6)
            histo_tab->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem36 = new QTableWidgetItem();
        __qtablewidgetitem36->setFont(font2);
        histo_tab->setHorizontalHeaderItem(0, __qtablewidgetitem36);
        QTableWidgetItem *__qtablewidgetitem37 = new QTableWidgetItem();
        __qtablewidgetitem37->setFont(font2);
        histo_tab->setHorizontalHeaderItem(1, __qtablewidgetitem37);
        QTableWidgetItem *__qtablewidgetitem38 = new QTableWidgetItem();
        __qtablewidgetitem38->setFont(font2);
        histo_tab->setHorizontalHeaderItem(2, __qtablewidgetitem38);
        QTableWidgetItem *__qtablewidgetitem39 = new QTableWidgetItem();
        __qtablewidgetitem39->setFont(font2);
        histo_tab->setHorizontalHeaderItem(3, __qtablewidgetitem39);
        QTableWidgetItem *__qtablewidgetitem40 = new QTableWidgetItem();
        __qtablewidgetitem40->setFont(font2);
        histo_tab->setHorizontalHeaderItem(4, __qtablewidgetitem40);
        QTableWidgetItem *__qtablewidgetitem41 = new QTableWidgetItem();
        __qtablewidgetitem41->setFont(font2);
        histo_tab->setHorizontalHeaderItem(5, __qtablewidgetitem41);
        histo_tab->setObjectName(QString::fromUtf8("histo_tab"));
        histo_tab->setGeometry(QRect(50, 18, 602, 161));
        histo_tab->setFont(font2);
        histo_tab->horizontalHeader()->setDefaultSectionSize(100);
        histo_tab->verticalHeader()->setDefaultSectionSize(30);
        histo_tab->verticalHeader()->setMinimumSectionSize(15);
        histo_total = new QTableWidget(groupBox_10);
        if (histo_total->rowCount() < 1)
            histo_total->setRowCount(1);
        QTableWidgetItem *__qtablewidgetitem42 = new QTableWidgetItem();
        __qtablewidgetitem42->setFont(font2);
        histo_total->setVerticalHeaderItem(0, __qtablewidgetitem42);
        histo_total->setObjectName(QString::fromUtf8("histo_total"));
        histo_total->setGeometry(QRect(406, 178, 246, 31));
        groupBox_11 = new QGroupBox(frame_histoventes);
        groupBox_11->setObjectName(QString::fromUtf8("groupBox_11"));
        groupBox_11->setGeometry(QRect(140, 274, 481, 201));
        histo_evo_graphique = new QGraphicsView(groupBox_11);
        histo_evo_graphique->setObjectName(QString::fromUtf8("histo_evo_graphique"));
        histo_evo_graphique->setGeometry(QRect(20, 20, 441, 171));
        tabWidget->addTab(tab_10, QString());
        tab_11 = new QWidget();
        tab_11->setObjectName(QString::fromUtf8("tab_11"));
        frame_parcmachine = new QFrame(tab_11);
        frame_parcmachine->setObjectName(QString::fromUtf8("frame_parcmachine"));
        frame_parcmachine->setGeometry(QRect(0, 0, 761, 491));
        frame_parcmachine->setFrameShape(QFrame::StyledPanel);
        frame_parcmachine->setFrameShadow(QFrame::Raised);
        sous_parc_instru = new QTabWidget(frame_parcmachine);
        sous_parc_instru->setObjectName(QString::fromUtf8("sous_parc_instru"));
        sous_parc_instru->setGeometry(QRect(8, 0, 751, 491));
        tab_6 = new QWidget();
        tab_6->setObjectName(QString::fromUtf8("tab_6"));
        scrollArea_2 = new QScrollArea(tab_6);
        scrollArea_2->setObjectName(QString::fromUtf8("scrollArea_2"));
        scrollArea_2->setGeometry(QRect(10, 10, 711, 261));
        scrollArea_2->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 709, 259));
        parc_hema_machine = new QTableWidget(scrollAreaWidgetContents_2);
        if (parc_hema_machine->columnCount() < 11)
            parc_hema_machine->setColumnCount(11);
        QTableWidgetItem *__qtablewidgetitem43 = new QTableWidgetItem();
        parc_hema_machine->setHorizontalHeaderItem(0, __qtablewidgetitem43);
        QTableWidgetItem *__qtablewidgetitem44 = new QTableWidgetItem();
        parc_hema_machine->setHorizontalHeaderItem(1, __qtablewidgetitem44);
        QTableWidgetItem *__qtablewidgetitem45 = new QTableWidgetItem();
        parc_hema_machine->setHorizontalHeaderItem(2, __qtablewidgetitem45);
        QTableWidgetItem *__qtablewidgetitem46 = new QTableWidgetItem();
        parc_hema_machine->setHorizontalHeaderItem(3, __qtablewidgetitem46);
        QTableWidgetItem *__qtablewidgetitem47 = new QTableWidgetItem();
        parc_hema_machine->setHorizontalHeaderItem(4, __qtablewidgetitem47);
        QTableWidgetItem *__qtablewidgetitem48 = new QTableWidgetItem();
        parc_hema_machine->setHorizontalHeaderItem(5, __qtablewidgetitem48);
        QTableWidgetItem *__qtablewidgetitem49 = new QTableWidgetItem();
        parc_hema_machine->setHorizontalHeaderItem(6, __qtablewidgetitem49);
        QTableWidgetItem *__qtablewidgetitem50 = new QTableWidgetItem();
        parc_hema_machine->setHorizontalHeaderItem(7, __qtablewidgetitem50);
        QTableWidgetItem *__qtablewidgetitem51 = new QTableWidgetItem();
        parc_hema_machine->setHorizontalHeaderItem(8, __qtablewidgetitem51);
        QTableWidgetItem *__qtablewidgetitem52 = new QTableWidgetItem();
        parc_hema_machine->setHorizontalHeaderItem(9, __qtablewidgetitem52);
        QTableWidgetItem *__qtablewidgetitem53 = new QTableWidgetItem();
        parc_hema_machine->setHorizontalHeaderItem(10, __qtablewidgetitem53);
        parc_hema_machine->setObjectName(QString::fromUtf8("parc_hema_machine"));
        parc_hema_machine->setGeometry(QRect(360, 30, 131, 171));
        tableWidget = new QTableWidget(scrollAreaWidgetContents_2);
        if (tableWidget->columnCount() < 3)
            tableWidget->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem54 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem54);
        QTableWidgetItem *__qtablewidgetitem55 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem55);
        QTableWidgetItem *__qtablewidgetitem56 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem56);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(180, 30, 171, 171));
        horizontalScrollBar = new QScrollBar(scrollAreaWidgetContents_2);
        horizontalScrollBar->setObjectName(QString::fromUtf8("horizontalScrollBar"));
        horizontalScrollBar->setGeometry(QRect(0, 240, 711, 20));
        horizontalScrollBar->setOrientation(Qt::Horizontal);
        tableWidget_4 = new QTableWidget(scrollAreaWidgetContents_2);
        if (tableWidget_4->columnCount() < 4)
            tableWidget_4->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem57 = new QTableWidgetItem();
        tableWidget_4->setHorizontalHeaderItem(0, __qtablewidgetitem57);
        QTableWidgetItem *__qtablewidgetitem58 = new QTableWidgetItem();
        tableWidget_4->setHorizontalHeaderItem(1, __qtablewidgetitem58);
        QTableWidgetItem *__qtablewidgetitem59 = new QTableWidgetItem();
        tableWidget_4->setHorizontalHeaderItem(2, __qtablewidgetitem59);
        QTableWidgetItem *__qtablewidgetitem60 = new QTableWidgetItem();
        tableWidget_4->setHorizontalHeaderItem(3, __qtablewidgetitem60);
        tableWidget_4->setObjectName(QString::fromUtf8("tableWidget_4"));
        tableWidget_4->setGeometry(QRect(510, 30, 171, 171));
        scrollArea_2->setWidget(scrollAreaWidgetContents_2);
        sous_parc_instru->addTab(tab_6, QString());
        tab_7 = new QWidget();
        tab_7->setObjectName(QString::fromUtf8("tab_7"));
        sous_parc_instru->addTab(tab_7, QString());
        tabWidget->addTab(tab_11, QString());
        tab_12 = new QWidget();
        tab_12->setObjectName(QString::fromUtf8("tab_12"));
        frame_actclient = new QFrame(tab_12);
        frame_actclient->setObjectName(QString::fromUtf8("frame_actclient"));
        frame_actclient->setGeometry(QRect(0, 0, 761, 491));
        frame_actclient->setFrameShape(QFrame::StyledPanel);
        frame_actclient->setFrameShadow(QFrame::Raised);
        tabWidget->addTab(tab_12, QString());
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 832, 20));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);
        sous_parc_instru->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        Client_actuel->setText(QApplication::translate("MainWindow", "NOM DE LA SOCIETE", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("MainWindow", "Chiffre d'affaire r\303\251alis\303\251", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = tableWidget_2->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "CA - 2", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget_2->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "CA - 1", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget_2->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWindow", "CA", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Historique commercial", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem3 = resum_histocomm->horizontalHeaderItem(0);
        ___qtablewidgetitem3->setText(QApplication::translate("MainWindow", "Date", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem4 = resum_histocomm->horizontalHeaderItem(1);
        ___qtablewidgetitem4->setText(QApplication::translate("MainWindow", "Type de note", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem5 = resum_histocomm->horizontalHeaderItem(2);
        ___qtablewidgetitem5->setText(QApplication::translate("MainWindow", "Interlocuteur", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem6 = resum_histocomm->horizontalHeaderItem(3);
        ___qtablewidgetitem6->setText(QApplication::translate("MainWindow", "Compte rendu", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "Parc Machines", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem7 = resum_tab_parc->horizontalHeaderItem(0);
        ___qtablewidgetitem7->setText(QApplication::translate("MainWindow", "Sp\303\251cialisation", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem8 = resum_tab_parc->horizontalHeaderItem(1);
        ___qtablewidgetitem8->setText(QApplication::translate("MainWindow", "Marque", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem9 = resum_tab_parc->horizontalHeaderItem(2);
        ___qtablewidgetitem9->setText(QApplication::translate("MainWindow", "Mod\303\250le", 0, QApplication::UnicodeUTF8));
        groupBox_4->setTitle(QApplication::translate("MainWindow", "Parc R\303\251actifs", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem10 = resum_tab_reac->horizontalHeaderItem(0);
        ___qtablewidgetitem10->setText(QApplication::translate("MainWindow", "Type", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem11 = resum_tab_reac->horizontalHeaderItem(1);
        ___qtablewidgetitem11->setText(QApplication::translate("MainWindow", "Marque", 0, QApplication::UnicodeUTF8));
        groupBox_5->setTitle(QApplication::translate("MainWindow", "Objectifs", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem12 = tableWidget_3->horizontalHeaderItem(0);
        ___qtablewidgetitem12->setText(QApplication::translate("MainWindow", "Objectif \303\251tape", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem13 = tableWidget_3->horizontalHeaderItem(1);
        ___qtablewidgetitem13->setText(QApplication::translate("MainWindow", "Objectif final", 0, QApplication::UnicodeUTF8));
        groupBox_6->setTitle(QApplication::translate("MainWindow", "Nombre de patients par jour", 0, QApplication::UnicodeUTF8));
        groupBox_7->setTitle(QApplication::translate("MainWindow", "Type du client", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "Cat\303\251gorie :", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "Classification :", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "HOT", 0, QApplication::UnicodeUTF8));
        label_4->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("MainWindow", "Tab 1", 0, QApplication::UnicodeUTF8));
        groupBox_12->setTitle(QApplication::translate("MainWindow", "Informations g\303\251n\303\251rales", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("MainWindow", "Nom:", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("MainWindow", "Adresse:", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("MainWindow", "Ville:", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("MainWindow", "Code Postal:", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("MainWindow", "N\302\260 de t\303\251l\303\251phone:", 0, QApplication::UnicodeUTF8));
        label_15->setText(QApplication::translate("MainWindow", "N\302\260 de t\303\251l\303\251copie:", 0, QApplication::UnicodeUTF8));
        label_17->setText(QApplication::translate("MainWindow", "Mail:", 0, QApplication::UnicodeUTF8));
        groupBox_13->setTitle(QApplication::translate("MainWindow", "Renseignements", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem14 = infos_tab_renseignements->horizontalHeaderItem(0);
        ___qtablewidgetitem14->setText(QApplication::translate("MainWindow", "Cr\303\251ation", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem15 = infos_tab_renseignements->horizontalHeaderItem(1);
        ___qtablewidgetitem15->setText(QApplication::translate("MainWindow", "Statut", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem16 = infos_tab_renseignements->horizontalHeaderItem(2);
        ___qtablewidgetitem16->setText(QApplication::translate("MainWindow", "Client depuis", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem17 = infos_tab_renseignements->horizontalHeaderItem(3);
        ___qtablewidgetitem17->setText(QApplication::translate("MainWindow", "Effectif", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem18 = infos_tab_renseignements->horizontalHeaderItem(4);
        ___qtablewidgetitem18->setText(QApplication::translate("MainWindow", "CA", 0, QApplication::UnicodeUTF8));
        groupBox_14->setTitle(QApplication::translate("MainWindow", "Commentaires", 0, QApplication::UnicodeUTF8));
        groupBox_15->setTitle(QApplication::translate("MainWindow", "Secteurs d'activit\303\251s", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("MainWindow", "Secteurs:", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("MainWindow", "H\303\251matologie", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("MainWindow", "Biochimie", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QApplication::translate("MainWindow", "Tab 2", 0, QApplication::UnicodeUTF8));
        groupBox_8->setTitle(QApplication::translate("MainWindow", "Contacts", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem19 = contact_tab->horizontalHeaderItem(0);
        ___qtablewidgetitem19->setText(QApplication::translate("MainWindow", "Civilit\303\251", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem20 = contact_tab->horizontalHeaderItem(1);
        ___qtablewidgetitem20->setText(QApplication::translate("MainWindow", "Pr\303\251nom", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem21 = contact_tab->horizontalHeaderItem(2);
        ___qtablewidgetitem21->setText(QApplication::translate("MainWindow", "Nom", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem22 = contact_tab->horizontalHeaderItem(3);
        ___qtablewidgetitem22->setText(QApplication::translate("MainWindow", "Position", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem23 = contact_tab->horizontalHeaderItem(4);
        ___qtablewidgetitem23->setText(QApplication::translate("MainWindow", "Mail", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem24 = contact_tab->horizontalHeaderItem(5);
        ___qtablewidgetitem24->setText(QApplication::translate("MainWindow", "T\303\251l\303\251phone", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem25 = contact_tab->horizontalHeaderItem(6);
        ___qtablewidgetitem25->setText(QApplication::translate("MainWindow", "Statut", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem26 = contact_tab->horizontalHeaderItem(7);
        ___qtablewidgetitem26->setText(QApplication::translate("MainWindow", "Association", 0, QApplication::UnicodeUTF8));
        contacts_add->setText(QApplication::translate("MainWindow", "add", 0, QApplication::UnicodeUTF8));
        contact_mod->setText(QApplication::translate("MainWindow", "mod", 0, QApplication::UnicodeUTF8));
        contact_del->setText(QApplication::translate("MainWindow", "del", 0, QApplication::UnicodeUTF8));
        groupBox_16->setTitle(QApplication::translate("MainWindow", "Contact s\303\251l\303\251ctionn\303\251", 0, QApplication::UnicodeUTF8));
        contact_add_position->setText(QApplication::translate("MainWindow", "+", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("MainWindow", "Civilit\303\251:", 0, QApplication::UnicodeUTF8));
        label_14->setText(QApplication::translate("MainWindow", "Pr\303\251nom:", 0, QApplication::UnicodeUTF8));
        label_16->setText(QApplication::translate("MainWindow", "Nom:", 0, QApplication::UnicodeUTF8));
        label_18->setText(QApplication::translate("MainWindow", "Position:", 0, QApplication::UnicodeUTF8));
        label_19->setText(QApplication::translate("MainWindow", "Mail:", 0, QApplication::UnicodeUTF8));
        label_20->setText(QApplication::translate("MainWindow", "T\303\251l\303\251phone:", 0, QApplication::UnicodeUTF8));
        label_21->setText(QApplication::translate("MainWindow", "Statut:", 0, QApplication::UnicodeUTF8));
        label_22->setText(QApplication::translate("MainWindow", "Association:", 0, QApplication::UnicodeUTF8));
        contact_civilite_edit->clear();
        contact_civilite_edit->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Monsieur", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Madame", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Mademoiselle", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Docteur", 0, QApplication::UnicodeUTF8)
        );
        contact_position_edit->clear();
        contact_position_edit->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Technicien", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Biologiste", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Acheteur", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Manager", 0, QApplication::UnicodeUTF8)
        );
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Influenceur", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "D\303\251cideur", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Freineur", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Source d'information", 0, QApplication::UnicodeUTF8)
        );
        tabWidget->setTabText(tabWidget->indexOf(tab_8), QApplication::translate("MainWindow", "Page", 0, QApplication::UnicodeUTF8));
        groupBox_9->setTitle(QApplication::translate("MainWindow", "Notes", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem27 = notes_tab->horizontalHeaderItem(0);
        ___qtablewidgetitem27->setText(QApplication::translate("MainWindow", "Date", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem28 = notes_tab->horizontalHeaderItem(1);
        ___qtablewidgetitem28->setText(QApplication::translate("MainWindow", "Type de note", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem29 = notes_tab->horizontalHeaderItem(2);
        ___qtablewidgetitem29->setText(QApplication::translate("MainWindow", "Interlocuteur", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem30 = notes_tab->horizontalHeaderItem(3);
        ___qtablewidgetitem30->setText(QApplication::translate("MainWindow", "Emetteur", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem31 = notes_tab->horizontalHeaderItem(4);
        ___qtablewidgetitem31->setText(QApplication::translate("MainWindow", "Titre", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem32 = notes_tab->horizontalHeaderItem(5);
        ___qtablewidgetitem32->setText(QApplication::translate("MainWindow", "Compte rendu", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem33 = notes_tab->horizontalHeaderItem(6);
        ___qtablewidgetitem33->setText(QApplication::translate("MainWindow", "Etat traitement", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem34 = notes_tab->horizontalHeaderItem(7);
        ___qtablewidgetitem34->setText(QApplication::translate("MainWindow", "Vente r\303\251alis\303\251e", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_9), QApplication::translate("MainWindow", "Page", 0, QApplication::UnicodeUTF8));
        groupBox_10->setTitle(QApplication::translate("MainWindow", "Historique des ventes", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem35 = histo_tab->horizontalHeaderItem(0);
        ___qtablewidgetitem35->setText(QApplication::translate("MainWindow", "Date d'achat", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem36 = histo_tab->horizontalHeaderItem(1);
        ___qtablewidgetitem36->setText(QApplication::translate("MainWindow", "Numero de facture", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem37 = histo_tab->horizontalHeaderItem(2);
        ___qtablewidgetitem37->setText(QApplication::translate("MainWindow", "Marque", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem38 = histo_tab->horizontalHeaderItem(3);
        ___qtablewidgetitem38->setText(QApplication::translate("MainWindow", "Mod\303\250le", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem39 = histo_tab->horizontalHeaderItem(4);
        ___qtablewidgetitem39->setText(QApplication::translate("MainWindow", "Quantit\303\251", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem40 = histo_tab->horizontalHeaderItem(5);
        ___qtablewidgetitem40->setText(QApplication::translate("MainWindow", "Montant", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem41 = histo_total->verticalHeaderItem(0);
        ___qtablewidgetitem41->setText(QApplication::translate("MainWindow", "TOTAL", 0, QApplication::UnicodeUTF8));
        groupBox_11->setTitle(QApplication::translate("MainWindow", "Evolution achat client", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_10), QApplication::translate("MainWindow", "Page", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem42 = parc_hema_machine->horizontalHeaderItem(0);
        ___qtablewidgetitem42->setText(QApplication::translate("MainWindow", "Marque", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem43 = parc_hema_machine->horizontalHeaderItem(1);
        ___qtablewidgetitem43->setText(QApplication::translate("MainWindow", "Mod\303\250le", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem44 = parc_hema_machine->horizontalHeaderItem(2);
        ___qtablewidgetitem44->setText(QApplication::translate("MainWindow", "Sp\303\251cificit\303\251", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem45 = parc_hema_machine->horizontalHeaderItem(3);
        ___qtablewidgetitem45->setText(QApplication::translate("MainWindow", "Caract\303\251ristique", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem46 = parc_hema_machine->horizontalHeaderItem(4);
        ___qtablewidgetitem46->setText(QApplication::translate("MainWindow", "Distibuteur", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem47 = parc_hema_machine->horizontalHeaderItem(5);
        ___qtablewidgetitem47->setText(QApplication::translate("MainWindow", "LIS", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem48 = parc_hema_machine->horizontalHeaderItem(6);
        ___qtablewidgetitem48->setText(QApplication::translate("MainWindow", "Passeur de tubes", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem49 = parc_hema_machine->horizontalHeaderItem(7);
        ___qtablewidgetitem49->setText(QApplication::translate("MainWindow", "Date achat", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem50 = parc_hema_machine->horizontalHeaderItem(8);
        ___qtablewidgetitem50->setText(QApplication::translate("MainWindow", "Mode de paiement", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem51 = parc_hema_machine->horizontalHeaderItem(9);
        ___qtablewidgetitem51->setText(QApplication::translate("MainWindow", "Nouvelle colonne", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem52 = parc_hema_machine->horizontalHeaderItem(10);
        ___qtablewidgetitem52->setText(QApplication::translate("MainWindow", "Prochain achat", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem53 = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem53->setText(QApplication::translate("MainWindow", "facilit\303\251", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem54 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem54->setText(QApplication::translate("MainWindow", "cadence", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem55 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem55->setText(QApplication::translate("MainWindow", "qualit\303\251 r\303\251sultats", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem56 = tableWidget_4->horizontalHeaderItem(0);
        ___qtablewidgetitem56->setText(QApplication::translate("MainWindow", "D\303\251lai SAV", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem57 = tableWidget_4->horizontalHeaderItem(1);
        ___qtablewidgetitem57->setText(QApplication::translate("MainWindow", "Qualit\303\251 intervention", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem58 = tableWidget_4->horizontalHeaderItem(2);
        ___qtablewidgetitem58->setText(QApplication::translate("MainWindow", "Prix", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem59 = tableWidget_4->horizontalHeaderItem(3);
        ___qtablewidgetitem59->setText(QApplication::translate("MainWindow", "Type de contrat", 0, QApplication::UnicodeUTF8));
        sous_parc_instru->setTabText(sous_parc_instru->indexOf(tab_6), QApplication::translate("MainWindow", "Tab 1", 0, QApplication::UnicodeUTF8));
        sous_parc_instru->setTabText(sous_parc_instru->indexOf(tab_7), QApplication::translate("MainWindow", "Tab 2", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_11), QApplication::translate("MainWindow", "Page", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_12), QApplication::translate("MainWindow", "Page", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
