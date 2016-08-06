/********************************************************************************
** Form generated from reading UI file 'addeditrushnode.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDEDITRUSHNODE_H
#define UI_ADDEDITRUSHNODE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_AddEditRushNode
{
public:
    QVBoxLayout *verticalLayout;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_3;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *aliasLineEdit;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *addressLineEdit;
    QHBoxLayout *horizontalLayout_3;
    QHBoxLayout *horizontalLayout_Buttons;
    QSpacerItem *horizontalSpacer_1;
    QLabel *statusLabel;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *okButton;
    QPushButton *cancelButton;

    void setupUi(QDialog *AddEditRushNode)
    {
        if (AddEditRushNode->objectName().isEmpty())
            AddEditRushNode->setObjectName(QStringLiteral("AddEditRushNode"));
        AddEditRushNode->resize(540, 241);
        AddEditRushNode->setModal(true);
        verticalLayout = new QVBoxLayout(AddEditRushNode);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(-1, 0, -1, 0);
        label_3 = new QLabel(AddEditRushNode);
        label_3->setObjectName(QStringLiteral("label_3"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);
        label_3->setWordWrap(true);

        verticalLayout_2->addWidget(label_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, -1, -1, 0);
        label = new QLabel(AddEditRushNode);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        aliasLineEdit = new QLineEdit(AddEditRushNode);
        aliasLineEdit->setObjectName(QStringLiteral("aliasLineEdit"));

        horizontalLayout->addWidget(aliasLineEdit);


        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(-1, -1, -1, 0);
        label_2 = new QLabel(AddEditRushNode);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        addressLineEdit = new QLineEdit(AddEditRushNode);
        addressLineEdit->setObjectName(QStringLiteral("addressLineEdit"));

        horizontalLayout_2->addWidget(addressLineEdit);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(-1, -1, -1, 0);

        verticalLayout_2->addLayout(horizontalLayout_3);


        verticalLayout->addLayout(verticalLayout_2);

        horizontalLayout_Buttons = new QHBoxLayout();
        horizontalLayout_Buttons->setObjectName(QStringLiteral("horizontalLayout_Buttons"));
        horizontalSpacer_1 = new QSpacerItem(40, 48, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_Buttons->addItem(horizontalSpacer_1);

        statusLabel = new QLabel(AddEditRushNode);
        statusLabel->setObjectName(QStringLiteral("statusLabel"));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        statusLabel->setFont(font);
        statusLabel->setTextFormat(Qt::PlainText);
        statusLabel->setWordWrap(true);

        horizontalLayout_Buttons->addWidget(statusLabel);

        horizontalSpacer_2 = new QSpacerItem(40, 48, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_Buttons->addItem(horizontalSpacer_2);

        okButton = new QPushButton(AddEditRushNode);
        okButton->setObjectName(QStringLiteral("okButton"));
        okButton->setStyleSheet(QLatin1String("QPushButton {\n"
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

        horizontalLayout_Buttons->addWidget(okButton);

        cancelButton = new QPushButton(AddEditRushNode);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));
        cancelButton->setStyleSheet(QLatin1String("QPushButton {\n"
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
        cancelButton->setAutoDefault(false);

        horizontalLayout_Buttons->addWidget(cancelButton);


        verticalLayout->addLayout(horizontalLayout_Buttons);


        retranslateUi(AddEditRushNode);

        QMetaObject::connectSlotsByName(AddEditRushNode);
    } // setupUi

    void retranslateUi(QDialog *AddEditRushNode)
    {
        AddEditRushNode->setWindowTitle(QApplication::translate("AddEditRushNode", "Add/Edit NavCoin Node", 0));
        label_3->setText(QApplication::translate("AddEditRushNode", "<html><head/><body><p>Enter an Alias (friendly name) for your I Node and its address (either navnet IP and port or Tor onion address and port).  The address should be in the format 123.456.789.123:9999 or akjdsafxjkhasdf.onion:9999.  A inode private key and a collateral address will both be automatically generated for you.  You must send exactly 100 000 NAV to the collateral address.</p></body></html>", 0));
        label->setText(QApplication::translate("AddEditRushNode", "Alias", 0));
        label_2->setText(QApplication::translate("AddEditRushNode", "Address", 0));
        statusLabel->setText(QString());
        okButton->setText(QApplication::translate("AddEditRushNode", "&OK", 0));
        cancelButton->setText(QApplication::translate("AddEditRushNode", "&Cancel", 0));
    } // retranslateUi

};

namespace Ui {
    class AddEditRushNode: public Ui_AddEditRushNode {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDEDITRUSHNODE_H
