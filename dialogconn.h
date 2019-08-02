#ifndef DIALOGCONN_H
#define DIALOGCONN_H

#include <QDialog>
#include <QTcpSocket>
#include <QByteArray>
#include <QDataStream>
#include <QSettings>

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
    quint16 _nextBlockSize;

public slots:
    void getDataFromServer();
//    void getFromServerError();
    void emitQuestToServer();

signals:
    void giveSettings(Person&);

public:
    explicit DialogConn(QWidget *parent = nullptr);

    void toConnect(QString& adress, QString& port);
    void setData(QString& log, QString& pass);

    ~DialogConn();
private:
    Ui::DialogConn *ui;
};

#endif // DIALOGCONN_H
