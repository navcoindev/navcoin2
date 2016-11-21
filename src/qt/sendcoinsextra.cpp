#include "sendcoinsextra.h"
#include "ui_sendcoinsextra.h"

#include <QtGui>
#include <QDebug>
#include <stdio.h>
#include <iostream>

using std::cout;

SendCoinsExtra::SendCoinsExtra(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::SendCoinsExtra),
    model(0)
{
    cout << "SendCoinsExtra \n";
    ui->setupUi(this);
}
