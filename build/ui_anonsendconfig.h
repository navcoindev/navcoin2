/********************************************************************************
** Form generated from reading UI file 'anonsendconfig.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ANONSENDCONFIG_H
#define UI_ANONSENDCONFIG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_AnonsendConfig
{
public:
    QPushButton *buttonBasic;
    QPushButton *buttonHigh;
    QPushButton *buttonMax;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QFrame *line;
    QFrame *line_2;

    void setupUi(QDialog *AnonsendConfig)
    {
        if (AnonsendConfig->objectName().isEmpty())
            AnonsendConfig->setObjectName(QStringLiteral("AnonsendConfig"));
        AnonsendConfig->resize(630, 307);
        buttonBasic = new QPushButton(AnonsendConfig);
        buttonBasic->setObjectName(QStringLiteral("buttonBasic"));
        buttonBasic->setGeometry(QRect(20, 70, 151, 27));
        buttonBasic->setStyleSheet(QLatin1String("QPushButton {\n"
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
        buttonHigh = new QPushButton(AnonsendConfig);
        buttonHigh->setObjectName(QStringLiteral("buttonHigh"));
        buttonHigh->setGeometry(QRect(20, 140, 151, 27));
        buttonHigh->setStyleSheet(QLatin1String("QPushButton {\n"
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
        buttonMax = new QPushButton(AnonsendConfig);
        buttonMax->setObjectName(QStringLiteral("buttonMax"));
        buttonMax->setGeometry(QRect(20, 210, 151, 27));
        buttonMax->setStyleSheet(QLatin1String("QPushButton {\n"
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
        label = new QLabel(AnonsendConfig);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 20, 571, 31));
        label_2 = new QLabel(AnonsendConfig);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(190, 70, 421, 21));
        label_3 = new QLabel(AnonsendConfig);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(190, 140, 411, 21));
        label_4 = new QLabel(AnonsendConfig);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(190, 210, 421, 21));
        label_6 = new QLabel(AnonsendConfig);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(40, 100, 561, 21));
        label_7 = new QLabel(AnonsendConfig);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(40, 170, 561, 21));
        label_8 = new QLabel(AnonsendConfig);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(40, 240, 561, 21));
        label_9 = new QLabel(AnonsendConfig);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(40, 260, 561, 21));
        line = new QFrame(AnonsendConfig);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(10, 120, 601, 16));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        line_2 = new QFrame(AnonsendConfig);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setGeometry(QRect(10, 190, 601, 16));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        retranslateUi(AnonsendConfig);

        QMetaObject::connectSlotsByName(AnonsendConfig);
    } // setupUi

    void retranslateUi(QDialog *AnonsendConfig)
    {
        AnonsendConfig->setWindowTitle(QApplication::translate("AnonsendConfig", "Configure Anonsend", 0));
        buttonBasic->setText(QApplication::translate("AnonsendConfig", "Basic Privacy", 0));
        buttonHigh->setText(QApplication::translate("AnonsendConfig", "High Privacy", 0));
        buttonMax->setText(QApplication::translate("AnonsendConfig", "Maximum Privacy", 0));
        label->setText(QApplication::translate("AnonsendConfig", "Please select a privacy level.", 0));
        label_2->setText(QApplication::translate("AnonsendConfig", "Use 2 separate inodes to mix funds up to 1000 NAV", 0));
        label_3->setText(QApplication::translate("AnonsendConfig", "Use 8 separate inodes to mix funds up to 1000 NAV", 0));
        label_4->setText(QApplication::translate("AnonsendConfig", "Use 16 separate inodes", 0));
        label_6->setText(QApplication::translate("AnonsendConfig", "This option is the quickest and will cost about ~0.025 NAV to anonymize 1000 NAV", 0));
        label_7->setText(QApplication::translate("AnonsendConfig", "This option is moderately fast and will cost about 0.05 NAV to anonymize 1000 NAV", 0));
        label_8->setText(QApplication::translate("AnonsendConfig", "This is the slowest and most secure option. Using maximum anonymity will cost", 0));
        label_9->setText(QApplication::translate("AnonsendConfig", "0.1 NAV per 1000 NAV you anonymize.", 0));
    } // retranslateUi

};

namespace Ui {
    class AnonsendConfig: public Ui_AnonsendConfig {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ANONSENDCONFIG_H
