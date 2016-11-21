#ifndef SENDCOINSEXTRA_H
#define SENDCOINSEXTRA_H

#include <QFrame>

namespace Ui {
    class SendCoinsExtra;
}
class WalletModel;

class SendCoinsExtra : public QFrame
{
    Q_OBJECT

public:
    explicit SendCoinsExtra(QWidget *parent = 0);

private:
    Ui::SendCoinsExtra *ui;
    WalletModel *model;
};

#endif // SENDCOINSEXTRA_H
