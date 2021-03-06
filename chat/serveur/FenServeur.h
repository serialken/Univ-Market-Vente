#ifndef HEADER_FENSERVEUR
#define HEADER_FENSERVEUR

#include <QtGui>
#include <QtNetwork>


cl s FenServeur : public QWidget
{
    Q_OBJECT

    public:
        FenServeur();

private slots:
        void nouvelleConnexion();
        void donneesRecues();
        void deconnexionClient();

    private:
        QLabel *etatServeur;
        QPushButton *boutonQuitter;
        QLabel *Message;

        QTcpServer *serveur;
        QList<QTcpSocket *> clients;
        quint16 tailleMessage;
};

#endif
