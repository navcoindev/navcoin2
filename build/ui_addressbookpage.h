/********************************************************************************
** Form generated from reading UI file 'addressbookpage.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDRESSBOOKPAGE_H
#define UI_ADDRESSBOOKPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddressBookPage
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *labelExplanation;
    QTableView *tableView;
    QHBoxLayout *horizontalLayout;
    QPushButton *newAddressButton;
    QPushButton *copyToClipboard;
    QPushButton *showQRCode;
    QPushButton *signMessage;
    QPushButton *verifyMessage;
    QPushButton *deleteButton;
    QDialogButtonBox *buttonBox;

    void setupUi(QWidget *AddressBookPage)
    {
        if (AddressBookPage->objectName().isEmpty())
            AddressBookPage->setObjectName(QStringLiteral("AddressBookPage"));
        AddressBookPage->resize(802, 380);
        verticalLayout = new QVBoxLayout(AddressBookPage);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        labelExplanation = new QLabel(AddressBookPage);
        labelExplanation->setObjectName(QStringLiteral("labelExplanation"));
        labelExplanation->setTextFormat(Qt::PlainText);
        labelExplanation->setWordWrap(true);

        verticalLayout->addWidget(labelExplanation);

        tableView = new QTableView(AddressBookPage);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setContextMenuPolicy(Qt::CustomContextMenu);
        tableView->setTabKeyNavigation(false);
        tableView->setSelectionMode(QAbstractItemView::SingleSelection);
        tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableView->setSortingEnabled(true);
        tableView->verticalHeader()->setVisible(false);

        verticalLayout->addWidget(tableView);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        newAddressButton = new QPushButton(AddressBookPage);
        newAddressButton->setObjectName(QStringLiteral("newAddressButton"));
        newAddressButton->setStyleSheet(QLatin1String("QPushButton {\n"
"	color: #FFFFFF; \n"
"	font-weight:bold; \n"
"	margin: 1px 0; \n"
"	padding: 5px 10px; \n"
"	background-color: #43b5eb; \n"
"	border: 1px solid #1381b5; \n"
"	border-radius: 5px;\n"
"}\n"
"\n"
"QPushButton:hover { \n"
"	background-color: #71c7f0; \n"
"	border: 1px solid #43b5eb; \n"
"}\n"
"\n"
"QPushButton:checked { \n"
"	background-color: #997cc5; \n"
"	border: 1px solid #7d59b5; \n"
"} \n"
"\n"
"QPushButton:pressed { \n"
"	background-color: #997cc5; \n"
"	border: 1px solid #7d59b5; \n"
"}"));

        horizontalLayout->addWidget(newAddressButton);

        copyToClipboard = new QPushButton(AddressBookPage);
        copyToClipboard->setObjectName(QStringLiteral("copyToClipboard"));
        copyToClipboard->setStyleSheet(QLatin1String("QPushButton {\n"
"	color: #FFFFFF; \n"
"	font-weight:bold; \n"
"	margin: 1px 0; \n"
"	padding: 5px 10px; \n"
"	background-color: #43b5eb; \n"
"	border: 1px solid #1381b5; \n"
"	border-radius: 5px;\n"
"}\n"
"\n"
"QPushButton:hover { \n"
"	background-color: #71c7f0; \n"
"	border: 1px solid #43b5eb; \n"
"}\n"
"\n"
"QPushButton:checked { \n"
"	background-color: #997cc5; \n"
"	border: 1px solid #7d59b5; \n"
"} \n"
"\n"
"QPushButton:pressed { \n"
"	background-color: #997cc5; \n"
"	border: 1px solid #7d59b5; \n"
"}"));

        horizontalLayout->addWidget(copyToClipboard);

        showQRCode = new QPushButton(AddressBookPage);
        showQRCode->setObjectName(QStringLiteral("showQRCode"));
        showQRCode->setStyleSheet(QLatin1String("QPushButton {\n"
"	color: #FFFFFF; \n"
"	font-weight:bold; \n"
"	margin: 1px 0; \n"
"	padding: 5px 10px; \n"
"	background-color: #43b5eb; \n"
"	border: 1px solid #1381b5; \n"
"	border-radius: 5px;\n"
"}\n"
"\n"
"QPushButton:hover { \n"
"	background-color: #71c7f0; \n"
"	border: 1px solid #43b5eb; \n"
"}\n"
"\n"
"QPushButton:checked { \n"
"	background-color: #997cc5; \n"
"	border: 1px solid #7d59b5; \n"
"} \n"
"\n"
"QPushButton:pressed { \n"
"	background-color: #997cc5; \n"
"	border: 1px solid #7d59b5; \n"
"}"));

        horizontalLayout->addWidget(showQRCode);

        signMessage = new QPushButton(AddressBookPage);
        signMessage->setObjectName(QStringLiteral("signMessage"));
        signMessage->setStyleSheet(QLatin1String("QPushButton {\n"
"	color: #FFFFFF; \n"
"	font-weight:bold; \n"
"	margin: 1px 0; \n"
"	padding: 5px 10px; \n"
"	background-color: #43b5eb; \n"
"	border: 1px solid #1381b5; \n"
"	border-radius: 5px;\n"
"}\n"
"\n"
"QPushButton:hover { \n"
"	background-color: #71c7f0; \n"
"	border: 1px solid #43b5eb; \n"
"}\n"
"\n"
"QPushButton:checked { \n"
"	background-color: #997cc5; \n"
"	border: 1px solid #7d59b5; \n"
"} \n"
"\n"
"QPushButton:pressed { \n"
"	background-color: #997cc5; \n"
"	border: 1px solid #7d59b5; \n"
"}"));

        horizontalLayout->addWidget(signMessage);

        verifyMessage = new QPushButton(AddressBookPage);
        verifyMessage->setObjectName(QStringLiteral("verifyMessage"));
        verifyMessage->setStyleSheet(QLatin1String("QPushButton {\n"
"	color: #FFFFFF; \n"
"	font-weight:bold; \n"
"	margin: 1px 0; \n"
"	padding: 5px 10px; \n"
"	background-color: #43b5eb; \n"
"	border: 1px solid #1381b5; \n"
"	border-radius: 5px;\n"
"}\n"
"\n"
"QPushButton:hover { \n"
"	background-color: #71c7f0; \n"
"	border: 1px solid #43b5eb; \n"
"}\n"
"\n"
"QPushButton:checked { \n"
"	background-color: #997cc5; \n"
"	border: 1px solid #7d59b5; \n"
"} \n"
"\n"
"QPushButton:pressed { \n"
"	background-color: #997cc5; \n"
"	border: 1px solid #7d59b5; \n"
"}"));

        horizontalLayout->addWidget(verifyMessage);

        deleteButton = new QPushButton(AddressBookPage);
        deleteButton->setObjectName(QStringLiteral("deleteButton"));
        deleteButton->setStyleSheet(QLatin1String("QPushButton {\n"
"	color: #FFFFFF; \n"
"	font-weight:bold; \n"
"	margin: 1px 0; \n"
"	padding: 5px 10px; \n"
"	background-color: #43b5eb; \n"
"	border: 1px solid #1381b5; \n"
"	border-radius: 5px;\n"
"}\n"
"\n"
"QPushButton:hover { \n"
"	background-color: #71c7f0; \n"
"	border: 1px solid #43b5eb; \n"
"}\n"
"\n"
"QPushButton:checked { \n"
"	background-color: #997cc5; \n"
"	border: 1px solid #7d59b5; \n"
"} \n"
"\n"
"QPushButton:pressed { \n"
"	background-color: #997cc5; \n"
"	border: 1px solid #7d59b5; \n"
"}"));

        horizontalLayout->addWidget(deleteButton);

        buttonBox = new QDialogButtonBox(AddressBookPage);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(buttonBox->sizePolicy().hasHeightForWidth());
        buttonBox->setSizePolicy(sizePolicy);
        buttonBox->setStyleSheet(QLatin1String("QPushButton {\n"
"	color: #FFFFFF; \n"
"	font-weight:bold; \n"
"	margin: 1px 0; \n"
"	padding: 5px 10px; \n"
"	background-color: #43b5eb; \n"
"	border: 1px solid #1381b5; \n"
"	border-radius: 5px;\n"
"}\n"
"\n"
"QPushButton:hover { \n"
"	background-color: #71c7f0; \n"
"	border: 1px solid #43b5eb; \n"
"}\n"
"\n"
"QPushButton:checked { \n"
"	background-color: #997cc5; \n"
"	border: 1px solid #7d59b5; \n"
"} \n"
"\n"
"QPushButton:pressed { \n"
"	background-color: #997cc5; \n"
"	border: 1px solid #7d59b5; \n"
"}"));
        buttonBox->setStandardButtons(QDialogButtonBox::Ok);

        horizontalLayout->addWidget(buttonBox);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(AddressBookPage);

        QMetaObject::connectSlotsByName(AddressBookPage);
    } // setupUi

    void retranslateUi(QWidget *AddressBookPage)
    {
        AddressBookPage->setWindowTitle(QApplication::translate("AddressBookPage", "Address Book", 0));
        labelExplanation->setText(QApplication::translate("AddressBookPage", "These are your NavCoin addresses for receiving payments. You may want to give a different one to each sender so you can keep track of who is paying you.", 0));
#ifndef QT_NO_TOOLTIP
        tableView->setToolTip(QApplication::translate("AddressBookPage", "Double-click to edit address or label", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        newAddressButton->setToolTip(QApplication::translate("AddressBookPage", "Create a new address", 0));
#endif // QT_NO_TOOLTIP
        newAddressButton->setText(QApplication::translate("AddressBookPage", "&New Address", 0));
#ifndef QT_NO_TOOLTIP
        copyToClipboard->setToolTip(QApplication::translate("AddressBookPage", "Copy the currently selected address to the system clipboard", 0));
#endif // QT_NO_TOOLTIP
        copyToClipboard->setText(QApplication::translate("AddressBookPage", "&Copy Address", 0));
        showQRCode->setText(QApplication::translate("AddressBookPage", "Show &QR Code", 0));
#ifndef QT_NO_TOOLTIP
        signMessage->setToolTip(QApplication::translate("AddressBookPage", "Sign a message to prove you own a NavCoin address", 0));
#endif // QT_NO_TOOLTIP
        signMessage->setText(QApplication::translate("AddressBookPage", "Sign &Message", 0));
#ifndef QT_NO_TOOLTIP
        verifyMessage->setToolTip(QApplication::translate("AddressBookPage", "Verify a message to ensure it was signed with a specified NavCoin address", 0));
#endif // QT_NO_TOOLTIP
        verifyMessage->setText(QApplication::translate("AddressBookPage", "&Verify Message", 0));
#ifndef QT_NO_TOOLTIP
        deleteButton->setToolTip(QApplication::translate("AddressBookPage", "Delete the currently selected address from the list", 0));
#endif // QT_NO_TOOLTIP
        deleteButton->setText(QApplication::translate("AddressBookPage", "&Delete", 0));
    } // retranslateUi

};

namespace Ui {
    class AddressBookPage: public Ui_AddressBookPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDRESSBOOKPAGE_H
