#ifndef LOGINPLATFORM_H
#define LOGINPLATFORM_H

#include <QMainWindow>

namespace Ui {
class LoginPlatform;
}

class LoginPlatform : public QMainWindow
{
    Q_OBJECT

public:
    explicit LoginPlatform(QWidget *parent = nullptr);
    ~LoginPlatform();

private:
    Ui::LoginPlatform *ui;
};

#endif // LOGINPLATFORM_H
