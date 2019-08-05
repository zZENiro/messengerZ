#ifndef DIALOGCONN_H
#define DIALOGCONN_H

#include <QDialog>
#include <QTcpSocket>
#include <QByteArray>
#include <QDataStream>
#include <QSettings>
#include <QAbstractSocket>
#include "person.h"

namespace Ui {
class DialogConn;
}

class DialogConn : public QDialog
{
    Q_OBJECT
    QTcpSocket* sock;
    QString *login;
    QString *password;
    Person person;
    bool registrationNeeded = false;
    bool _badPassword = false;
    quint16 _nextBlockSize;

    void Registration(bool);
    void badPassword(bool);

public slots:
    void getDataFromServer();
    void getFromServerError(QAbstractSocket::SocketError err);
    void emitQuestToServer();

public:
    explicit DialogConn(QWidget *parent = nullptr);

    void toConnect(QString adress, quint16 port);
    void setData(QString& log, QString& pass);

    ~DialogConn();
private:
    Ui::DialogConn *ui;
};

#endif // DIALOGCONN_H
