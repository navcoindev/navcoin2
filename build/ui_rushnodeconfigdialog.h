/********************************************************************************
** Form generated from reading UI file 'rushnodeconfigdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RUSHNODECONFIGDIALOG_H
#define UI_RUSHNODECONFIGDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_RushNodeConfigDialog
{
public:
    QVBoxLayout *verticalLayout;
    QTextEdit *detailText;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *RushNodeConfigDialog)
    {
        if (RushNodeConfigDialog->objectName().isEmpty())
            RushNodeConfigDialog->setObjectName(QStringLiteral("RushNodeConfigDialog"));
        RushNodeConfigDialog->resize(620, 250);
        verticalLayout = new QVBoxLayout(RushNodeConfigDialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        detailText = new QTextEdit(RushNodeConfigDialog);
        detailText->setObjectName(QStringLiteral("detailText"));
        detailText->setReadOnly(true);

        verticalLayout->addWidget(detailText);

        buttonBox = new QDialogButtonBox(RushNodeConfigDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
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
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Close);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(RushNodeConfigDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), RushNodeConfigDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), RushNodeConfigDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(RushNodeConfigDialog);
    } // setupUi

    void retranslateUi(QDialog *RushNodeConfigDialog)
    {
        RushNodeConfigDialog->setWindowTitle(QApplication::translate("RushNodeConfigDialog", "I Node Configuration Template", 0));
#ifndef QT_NO_TOOLTIP
        detailText->setToolTip(QApplication::translate("RushNodeConfigDialog", "<html><head/><body><p>This pane shows an example navcoin.conf template with the necessary inode settings.</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
    } // retranslateUi

};

namespace Ui {
    class RushNodeConfigDialog: public Ui_RushNodeConfigDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RUSHNODECONFIGDIALOG_H
