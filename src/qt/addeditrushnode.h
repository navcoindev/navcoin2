#ifndef ADDEDITRUSHNODE_H
#define ADDEDITRUSHNODE_H

#include <QDialog>

namespace Ui {
class AddEditRushNode;
}


class AddEditRushNode : public QDialog
{
    Q_OBJECT

public:
    explicit AddEditRushNode(QWidget *parent = 0);
    ~AddEditRushNode();

protected:

private slots:
    void on_okButton_clicked();
    void on_cancelButton_clicked();

signals:

private:
    Ui::AddEditRushNode *ui;
};

#endif // ADDEDITRUSHNODE_H
