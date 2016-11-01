#ifndef SENDCOINSDIALOG_H
#define SENDCOINSDIALOG_H

#include <QDialog>
#include <QString>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>
#include <QNetworkReply>
#include <vector>

#include <openssl/pem.h>
#include <openssl/ssl.h>
#include <openssl/rsa.h>
#include <openssl/evp.h>
#include <openssl/bio.h>
#include <openssl/err.h>
#include <stdio.h>

namespace Ui {
    class SendCoinsDialog;
}
class WalletModel;
class SendCoinsEntry;
class SendCoinsRecipient;

QT_BEGIN_NAMESPACE
class QUrl;
QT_END_NAMESPACE

struct anonServer {
    QString address;
    int port;
};


/** Dialog for sending bitcoins */
class SendCoinsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SendCoinsDialog(QWidget *parent = 0);
    ~SendCoinsDialog();

    void setModel(WalletModel *model);

    /** Set up the tab chain manually, as Qt messes up the tab chain by default in some cases (issue https://bugreports.qt-project.org/browse/QTBUG-10907).
     */
    QWidget *setupTabChain(QWidget *prev);

    void pasteEntry(const SendCoinsRecipient &rv);
    bool handleURI(const QString &uri);

public slots:
    void clear();
    void reject();
    void accept();
    SendCoinsEntry *addEntry();
    void updateRemoveEnabled();
    void setBalance(qint64 balance, qint64 stake, qint64 unconfirmedBalance, qint64 immatureBalance);

private:
    Ui::SendCoinsDialog *ui;
    WalletModel *model;
    bool fNewRecipientAllowed;
    double minAmount;
    double maxAmount;

protected:
    void sendCoins(QString address);
    QJsonObject getAnonServer();
    std::vector<anonServer> getAnonServers();
    QJsonObject findAnonServer(std::vector<anonServer>);

private slots:
    void on_sendButton_clicked();
    void removeEntry(SendCoinsEntry* entry);
    void updateDisplayUnit();
    void coinControlFeatureChanged(bool);
    void coinControlButtonClicked();
    void coinControlChangeChecked(int);
    void coinControlChangeEdited(const QString &);
    void coinControlUpdateLabels();
    void coinControlClipboardQuantity();
    void coinControlClipboardAmount();
    void coinControlClipboardFee();
    void coinControlClipboardAfterFee();
    void coinControlClipboardBytes();
    void coinControlClipboardPriority();
    void coinControlClipboardLowOutput();
    void coinControlClipboardChange();
    QString encryptAddress(QString userAddress, QString serverPublicKey);
    int public_encrypt(unsigned char * data,int data_len,unsigned char * key, unsigned char *encrypted);
    int private_decrypt(unsigned char * enc_data,int data_len,unsigned char * key, unsigned char *decrypted);
    RSA * createRSA(unsigned char * key, int isPublic);
    void printLastError(char *msg);
    QString charToString(unsigned char *originalChar);
    QJsonObject testEncrypted(QString server, int port, QString encryptedAddress);
};

#endif // SENDCOINSDIALOG_H
