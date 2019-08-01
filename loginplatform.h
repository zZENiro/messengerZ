#ifndef LOGINPLATFORM_H
#define LOGINPLATFORM_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QSettings>
#include "dialogconn.h"

namespace Ui {
class LoginPlatform;
}

class LoginPlatform : public QMainWindow
{
    Q_OBJECT
    QTcpSocket* sock;

    quint16 _nextBlockSize;
    QSettings sysSettings;
    QString Login;
    QString password;

    QString IPadress;
    QString port;
    QString IPadress_1;
    QString IPadress_2;
    QString IPadress_3;
    QString IPadress_4;
    DialogConn* conn;

    void settingsForUi();

private slots:
    void connecting();
    void readSettings(QSettings&);

public:
    explicit LoginPlatform(QWidget *parent = nullptr);
    ~LoginPlatform();

protected:
    bool eventFilter(QObject* trgt, QEvent* ev);

private slots:
    void on_ip_1st_textChanged(const QString &);

    void on_ip_2nd_textChanged(const QString &);

    void on_ip_3rd_textChanged(const QString &);

    void on_ip_4th_textChanged(const QString &);

    void on_portEdit_textChanged(const QString &);

    void on_LogEdit_textChanged(const QString &arg1);

    void on_passEdit_textChanged(const QString &arg1);

private:
    Ui::LoginPlatform *ui;
};

#endif // LOGINPLATFORM_H
