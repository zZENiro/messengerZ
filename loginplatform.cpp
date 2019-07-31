#include "loginplatform.h"
#include "ui_loginplatform.h"

LoginPlatform::LoginPlatform(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LoginPlatform)
{
    ui->setupUi(this);
}

LoginPlatform::~LoginPlatform()
{
    delete ui;
}
