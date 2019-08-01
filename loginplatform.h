#ifndef LOGINPLATFORM_H
#define LOGINPLATFORM_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QSettings>

namespace Ui {
class LoginPlatform;
}

class LoginPlatform : public QMainWindow
{
    Q_OBJECT
    QTcpSocket* sock;
    quint16 _nextBlockSize;
    QSettings sysSettings;
    void settingsForUi();

public:
    explicit LoginPlatform(QWidget *parent = nullptr);
    ~LoginPlatform();

protected:
    bool eventFilter(QObject* trgt, QEvent* ev);

private:
    Ui::LoginPlatform *ui;
};

#endif // LOGINPLATFORM_H
