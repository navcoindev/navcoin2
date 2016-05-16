#ifndef RUSHNODECONFIGDIALOG_H
#define RUSHNODECONFIGDIALOG_H

#include <QDialog>

namespace Ui {
    class RushNodeConfigDialog;
}

QT_BEGIN_NAMESPACE
class QModelIndex;
QT_END_NAMESPACE

/** Dialog showing transaction details. */
class RushNodeConfigDialog : public QDialog
{
    Q_OBJECT

public:
    explicit RushNodeConfigDialog(QWidget *parent = 0, QString nodeAddress = "123.456.789.123:9999", QString privkey="INODEPRIVKEY");
    ~RushNodeConfigDialog();

private:
    Ui::RushNodeConfigDialog *ui;
};

#endif // RUSHNODECONFIGDIALOG_H
