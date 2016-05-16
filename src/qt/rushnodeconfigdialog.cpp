#include "rushnodeconfigdialog.h"
#include "ui_rushnodeconfigdialog.h"

#include <QModelIndex>

RushNodeConfigDialog::RushNodeConfigDialog(QWidget *parent, QString nodeAddress, QString privkey) :
    QDialog(parent),
    ui(new Ui::RushNodeConfigDialog)
{
    ui->setupUi(this);
    QString desc = "rpcallowip=127.0.0.1<br>rpcuser=REPLACEME<br>rpcpassword=REPLACEME<br>server=1<br>listen=1<br>port=REPLACEMEWITHYOURPORT<br>inode=1<br>inodeaddr=" + nodeAddress + "<br>inodeprivkey=" + privkey + "<br>";
    ui->detailText->setHtml(desc);
}

RushNodeConfigDialog::~RushNodeConfigDialog()
{
    delete ui;
}
