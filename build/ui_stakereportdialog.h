/********************************************************************************
** Form generated from reading UI file 'stakereportdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STAKEREPORTDIALOG_H
#define UI_STAKEREPORTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StakeReportDialog
{
public:
    QLabel *label;
    QFrame *line;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QFrame *line_4;
    QLabel *label_3;
    QLabel *L1_24h;
    QLabel *Stake_7D;
    QFrame *line_2;
    QLabel *Amount_7D;
    QLabel *L3_30D_2;
    QLabel *Amount_30D;
    QFrame *line_3;
    QLabel *Stake_365D;
    QLabel *Stake_24H;
    QLabel *Stake_30D;
    QLabel *L3_30D;
    QLabel *Amount_365D;
    QLabel *Amount_24H;
    QLabel *L_Coin;
    QLabel *L2_7D;
    QLabel *L_LastStakeTime;
    QLabel *Amount_Last;
    QLabel *Stake_Counted;
    QLabel *L_Last;
    QLabel *TimeTook_2;
    QLabel *TimeTook;
    QTableWidget *StakeReportTable;
    QLabel *L_CurrentBlock;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *button_Refresh;
    QPushButton *CopytoClipboard;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *StakeReportDialog)
    {
        if (StakeReportDialog->objectName().isEmpty())
            StakeReportDialog->setObjectName(QStringLiteral("StakeReportDialog"));
        StakeReportDialog->resize(432, 554);
        StakeReportDialog->setMinimumSize(QSize(432, 554));
        StakeReportDialog->setMaximumSize(QSize(432, 554));
        StakeReportDialog->setModal(false);
        label = new QLabel(StakeReportDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(116, 10, 200, 19));
        label->setMinimumSize(QSize(200, 0));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label->setFrameShape(QFrame::NoFrame);
        label->setFrameShadow(QFrame::Sunken);
        label->setLineWidth(2);
        label->setMidLineWidth(3);
        label->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        line = new QFrame(StakeReportDialog);
        line->setObjectName(QStringLiteral("line"));
        line->setEnabled(false);
        line->setGeometry(QRect(116, 25, 200, 16));
        line->setMinimumSize(QSize(200, 0));
#ifndef QT_NO_TOOLTIP
        line->setToolTip(QStringLiteral("Original coding by Remy5"));
#endif // QT_NO_TOOLTIP
        line->setFrameShadow(QFrame::Raised);
        line->setMidLineWidth(1);
        line->setFrameShape(QFrame::HLine);
        gridLayoutWidget = new QWidget(StakeReportDialog);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 40, 411, 203));
        QFont font1;
        font1.setPointSize(9);
        gridLayoutWidget->setFont(font1);
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setVerticalSpacing(5);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        line_4 = new QFrame(gridLayoutWidget);
        line_4->setObjectName(QStringLiteral("line_4"));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_4, 5, 0, 1, 1);

        label_3 = new QLabel(gridLayoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        QFont font2;
        font2.setPointSize(9);
        font2.setBold(true);
        font2.setWeight(75);
        label_3->setFont(font2);
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_3->setMargin(4);

        gridLayout->addWidget(label_3, 0, 2, 1, 1);

        L1_24h = new QLabel(gridLayoutWidget);
        L1_24h->setObjectName(QStringLiteral("L1_24h"));
        L1_24h->setFont(font2);
        L1_24h->setMargin(4);

        gridLayout->addWidget(L1_24h, 1, 0, 1, 1);

        Stake_7D = new QLabel(gridLayoutWidget);
        Stake_7D->setObjectName(QStringLiteral("Stake_7D"));
        QFont font3;
        font3.setPointSize(9);
        font3.setBold(true);
        font3.setWeight(75);
        font3.setKerning(false);
        Stake_7D->setFont(font3);
        Stake_7D->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        Stake_7D->setMargin(4);

        gridLayout->addWidget(Stake_7D, 2, 2, 1, 1);

        line_2 = new QFrame(gridLayoutWidget);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_2, 5, 1, 1, 1);

        Amount_7D = new QLabel(gridLayoutWidget);
        Amount_7D->setObjectName(QStringLiteral("Amount_7D"));
        Amount_7D->setFont(font3);
        Amount_7D->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        Amount_7D->setMargin(4);

        gridLayout->addWidget(Amount_7D, 2, 1, 1, 1);

        L3_30D_2 = new QLabel(gridLayoutWidget);
        L3_30D_2->setObjectName(QStringLiteral("L3_30D_2"));
        L3_30D_2->setFont(font2);
        L3_30D_2->setMargin(4);

        gridLayout->addWidget(L3_30D_2, 4, 0, 1, 1);

        Amount_30D = new QLabel(gridLayoutWidget);
        Amount_30D->setObjectName(QStringLiteral("Amount_30D"));
        Amount_30D->setFont(font3);
        Amount_30D->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        Amount_30D->setMargin(4);

        gridLayout->addWidget(Amount_30D, 3, 1, 1, 1);

        line_3 = new QFrame(gridLayoutWidget);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_3, 5, 2, 1, 1);

        Stake_365D = new QLabel(gridLayoutWidget);
        Stake_365D->setObjectName(QStringLiteral("Stake_365D"));
        Stake_365D->setFont(font3);
        Stake_365D->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        Stake_365D->setMargin(4);

        gridLayout->addWidget(Stake_365D, 4, 2, 1, 1);

        Stake_24H = new QLabel(gridLayoutWidget);
        Stake_24H->setObjectName(QStringLiteral("Stake_24H"));
        Stake_24H->setFont(font3);
        Stake_24H->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        Stake_24H->setMargin(4);

        gridLayout->addWidget(Stake_24H, 1, 2, 1, 1);

        Stake_30D = new QLabel(gridLayoutWidget);
        Stake_30D->setObjectName(QStringLiteral("Stake_30D"));
        Stake_30D->setFont(font3);
        Stake_30D->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        Stake_30D->setMargin(4);

        gridLayout->addWidget(Stake_30D, 3, 2, 1, 1);

        L3_30D = new QLabel(gridLayoutWidget);
        L3_30D->setObjectName(QStringLiteral("L3_30D"));
        L3_30D->setFont(font2);
        L3_30D->setMargin(4);

        gridLayout->addWidget(L3_30D, 3, 0, 1, 1);

        Amount_365D = new QLabel(gridLayoutWidget);
        Amount_365D->setObjectName(QStringLiteral("Amount_365D"));
        Amount_365D->setFont(font3);
        Amount_365D->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        Amount_365D->setMargin(4);

        gridLayout->addWidget(Amount_365D, 4, 1, 1, 1);

        Amount_24H = new QLabel(gridLayoutWidget);
        Amount_24H->setObjectName(QStringLiteral("Amount_24H"));
        Amount_24H->setFont(font3);
        Amount_24H->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        Amount_24H->setMargin(4);

        gridLayout->addWidget(Amount_24H, 1, 1, 1, 1);

        L_Coin = new QLabel(gridLayoutWidget);
        L_Coin->setObjectName(QStringLiteral("L_Coin"));
        L_Coin->setFont(font2);
        L_Coin->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        L_Coin->setMargin(4);

        gridLayout->addWidget(L_Coin, 0, 1, 1, 1);

        L2_7D = new QLabel(gridLayoutWidget);
        L2_7D->setObjectName(QStringLiteral("L2_7D"));
        L2_7D->setFont(font2);
        L2_7D->setMargin(4);

        gridLayout->addWidget(L2_7D, 2, 0, 1, 1);

        L_LastStakeTime = new QLabel(gridLayoutWidget);
        L_LastStakeTime->setObjectName(QStringLiteral("L_LastStakeTime"));
        QFont font4;
        font4.setBold(true);
        font4.setWeight(75);
        L_LastStakeTime->setFont(font4);
        L_LastStakeTime->setAlignment(Qt::AlignCenter);
        L_LastStakeTime->setMargin(5);

        gridLayout->addWidget(L_LastStakeTime, 6, 0, 1, 1);

        Amount_Last = new QLabel(gridLayoutWidget);
        Amount_Last->setObjectName(QStringLiteral("Amount_Last"));
        Amount_Last->setFont(font3);
        Amount_Last->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        Amount_Last->setMargin(4);

        gridLayout->addWidget(Amount_Last, 6, 1, 1, 1);

        Stake_Counted = new QLabel(gridLayoutWidget);
        Stake_Counted->setObjectName(QStringLiteral("Stake_Counted"));
        QFont font5;
        font5.setPointSize(9);
        font5.setBold(false);
        font5.setWeight(50);
        Stake_Counted->setFont(font5);
        Stake_Counted->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        Stake_Counted->setMargin(4);

        gridLayout->addWidget(Stake_Counted, 7, 2, 1, 1);

        L_Last = new QLabel(gridLayoutWidget);
        L_Last->setObjectName(QStringLiteral("L_Last"));
        L_Last->setFont(font4);
        L_Last->setAlignment(Qt::AlignCenter);
        L_Last->setMargin(4);

        gridLayout->addWidget(L_Last, 6, 2, 1, 1);

        TimeTook_2 = new QLabel(gridLayoutWidget);
        TimeTook_2->setObjectName(QStringLiteral("TimeTook_2"));
        TimeTook_2->setFont(font5);
        TimeTook_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        TimeTook_2->setMargin(4);

        gridLayout->addWidget(TimeTook_2, 7, 1, 1, 1);

        TimeTook = new QLabel(gridLayoutWidget);
        TimeTook->setObjectName(QStringLiteral("TimeTook"));
        TimeTook->setFont(font5);
        TimeTook->setMargin(4);

        gridLayout->addWidget(TimeTook, 7, 0, 1, 1);

        gridLayout->setColumnStretch(0, 3);
        gridLayout->setColumnStretch(1, 3);
        StakeReportTable = new QTableWidget(StakeReportDialog);
        if (StakeReportTable->columnCount() < 3)
            StakeReportTable->setColumnCount(3);
        QFont font6;
        font6.setPointSize(10);
        font6.setBold(true);
        font6.setWeight(75);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setTextAlignment(Qt::AlignLeft|Qt::AlignVCenter);
        __qtablewidgetitem->setFont(font6);
        StakeReportTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setTextAlignment(Qt::AlignRight|Qt::AlignVCenter);
        __qtablewidgetitem1->setFont(font6);
        StakeReportTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        __qtablewidgetitem2->setTextAlignment(Qt::AlignRight|Qt::AlignVCenter);
        __qtablewidgetitem2->setFont(font6);
        StakeReportTable->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        if (StakeReportTable->rowCount() < 30)
            StakeReportTable->setRowCount(30);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        __qtablewidgetitem3->setFont(font1);
        __qtablewidgetitem3->setFlags(Qt::ItemIsSelectable|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        StakeReportTable->setItem(0, 0, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        __qtablewidgetitem4->setText(QStringLiteral("0"));
        __qtablewidgetitem4->setTextAlignment(Qt::AlignRight|Qt::AlignVCenter);
        __qtablewidgetitem4->setFont(font1);
        __qtablewidgetitem4->setFlags(Qt::ItemIsSelectable|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        StakeReportTable->setItem(0, 1, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        __qtablewidgetitem5->setText(QStringLiteral("0"));
        __qtablewidgetitem5->setTextAlignment(Qt::AlignRight|Qt::AlignVCenter);
        __qtablewidgetitem5->setFont(font1);
        __qtablewidgetitem5->setFlags(Qt::ItemIsSelectable|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        StakeReportTable->setItem(0, 2, __qtablewidgetitem5);
        StakeReportTable->setObjectName(QStringLiteral("StakeReportTable"));
        StakeReportTable->setGeometry(QRect(10, 240, 411, 231));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(1);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(StakeReportTable->sizePolicy().hasHeightForWidth());
        StakeReportTable->setSizePolicy(sizePolicy);
        StakeReportTable->setFont(font4);
        StakeReportTable->setAlternatingRowColors(true);
        StakeReportTable->setSortingEnabled(true);
        StakeReportTable->setRowCount(30);
        StakeReportTable->setColumnCount(3);
        StakeReportTable->horizontalHeader()->setStretchLastSection(true);
        L_CurrentBlock = new QLabel(StakeReportDialog);
        L_CurrentBlock->setObjectName(QStringLiteral("L_CurrentBlock"));
        L_CurrentBlock->setGeometry(QRect(5, 470, 422, 51));
        L_CurrentBlock->setFont(font5);
        L_CurrentBlock->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        L_CurrentBlock->setMargin(2);
        horizontalLayoutWidget = new QWidget(StakeReportDialog);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(0, 520, 431, 33));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        button_Refresh = new QPushButton(horizontalLayoutWidget);
        button_Refresh->setObjectName(QStringLiteral("button_Refresh"));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(button_Refresh->sizePolicy().hasHeightForWidth());
        button_Refresh->setSizePolicy(sizePolicy1);
        button_Refresh->setStyleSheet(QLatin1String("QPushButton {\n"
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

        horizontalLayout->addWidget(button_Refresh);

        CopytoClipboard = new QPushButton(horizontalLayoutWidget);
        CopytoClipboard->setObjectName(QStringLiteral("CopytoClipboard"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(CopytoClipboard->sizePolicy().hasHeightForWidth());
        CopytoClipboard->setSizePolicy(sizePolicy2);
        CopytoClipboard->setMinimumSize(QSize(100, 0));
        CopytoClipboard->setStyleSheet(QLatin1String("QPushButton {\n"
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

        horizontalLayout->addWidget(CopytoClipboard);

        buttonBox = new QDialogButtonBox(horizontalLayoutWidget);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        sizePolicy1.setHeightForWidth(buttonBox->sizePolicy().hasHeightForWidth());
        buttonBox->setSizePolicy(sizePolicy1);
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
        buttonBox->setCenterButtons(true);

        horizontalLayout->addWidget(buttonBox);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 2);
        horizontalLayout->setStretch(2, 1);

        retranslateUi(StakeReportDialog);
        QObject::connect(buttonBox, SIGNAL(clicked(QAbstractButton*)), StakeReportDialog, SLOT(close()));

        QMetaObject::connectSlotsByName(StakeReportDialog);
    } // setupUi

    void retranslateUi(QDialog *StakeReportDialog)
    {
        StakeReportDialog->setWindowTitle(QApplication::translate("StakeReportDialog", "Stake Report", 0));
#ifndef QT_NO_TOOLTIP
        label->setToolTip(QApplication::translate("StakeReportDialog", "Dialog which report the earning made with stake over time", 0));
#endif // QT_NO_TOOLTIP
        label->setText(QApplication::translate("StakeReportDialog", "Stake Report", 0));
#ifndef QT_NO_TOOLTIP
        label_3->setToolTip(QApplication::translate("StakeReportDialog", "POS Block Made", 0));
#endif // QT_NO_TOOLTIP
        label_3->setText(QApplication::translate("StakeReportDialog", "Stake Made", 0));
#ifndef QT_NO_TOOLTIP
        L1_24h->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        L1_24h->setText(QApplication::translate("StakeReportDialog", "Last 24 Hours", 0));
#ifndef QT_NO_TOOLTIP
        Stake_7D->setToolTip(QApplication::translate("StakeReportDialog", "Stake Made in last 7 Days", 0));
#endif // QT_NO_TOOLTIP
        Stake_7D->setText(QApplication::translate("StakeReportDialog", "0", 0));
#ifndef QT_NO_TOOLTIP
        Amount_7D->setToolTip(QApplication::translate("StakeReportDialog", "Coin Earned in last 7 Days", 0));
#endif // QT_NO_TOOLTIP
        Amount_7D->setText(QApplication::translate("StakeReportDialog", "0.00", 0));
#ifndef QT_NO_TOOLTIP
        L3_30D_2->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        L3_30D_2->setText(QApplication::translate("StakeReportDialog", "Last 365 Days", 0));
#ifndef QT_NO_TOOLTIP
        Amount_30D->setToolTip(QApplication::translate("StakeReportDialog", "Coin Earned in last 30 Days", 0));
#endif // QT_NO_TOOLTIP
        Amount_30D->setText(QApplication::translate("StakeReportDialog", "0.00", 0));
#ifndef QT_NO_TOOLTIP
        Stake_365D->setToolTip(QApplication::translate("StakeReportDialog", "Stake Made in last 365 Days", 0));
#endif // QT_NO_TOOLTIP
        Stake_365D->setText(QApplication::translate("StakeReportDialog", "0", 0));
#ifndef QT_NO_TOOLTIP
        Stake_24H->setToolTip(QApplication::translate("StakeReportDialog", "Stake Made in last 24H", 0));
#endif // QT_NO_TOOLTIP
        Stake_24H->setText(QApplication::translate("StakeReportDialog", "0", 0));
#ifndef QT_NO_TOOLTIP
        Stake_30D->setToolTip(QApplication::translate("StakeReportDialog", "Stake Made in last 30 Days", 0));
#endif // QT_NO_TOOLTIP
        Stake_30D->setText(QApplication::translate("StakeReportDialog", "0", 0));
#ifndef QT_NO_TOOLTIP
        L3_30D->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        L3_30D->setText(QApplication::translate("StakeReportDialog", "Last 30 Days", 0));
#ifndef QT_NO_TOOLTIP
        Amount_365D->setToolTip(QApplication::translate("StakeReportDialog", "Coin Earned in last 365 Days", 0));
#endif // QT_NO_TOOLTIP
        Amount_365D->setText(QApplication::translate("StakeReportDialog", "0.00", 0));
#ifndef QT_NO_TOOLTIP
        Amount_24H->setToolTip(QApplication::translate("StakeReportDialog", "Coin Earned in last 24H", 0));
#endif // QT_NO_TOOLTIP
        Amount_24H->setText(QApplication::translate("StakeReportDialog", "0.00", 0));
        L_Coin->setText(QApplication::translate("StakeReportDialog", "Coin SubTotal", 0));
#ifndef QT_NO_TOOLTIP
        L2_7D->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        L2_7D->setText(QApplication::translate("StakeReportDialog", "Last 7 Days", 0));
#ifndef QT_NO_TOOLTIP
        L_LastStakeTime->setToolTip(QApplication::translate("StakeReportDialog", "Date of the last mature Stake", 0));
#endif // QT_NO_TOOLTIP
        L_LastStakeTime->setText(QApplication::translate("StakeReportDialog", "Never", 0));
#ifndef QT_NO_TOOLTIP
        Amount_Last->setToolTip(QApplication::translate("StakeReportDialog", "Coin Earned in last mature Stake", 0));
#endif // QT_NO_TOOLTIP
        Amount_Last->setText(QApplication::translate("StakeReportDialog", "0.00", 0));
#ifndef QT_NO_TOOLTIP
        Stake_Counted->setToolTip(QApplication::translate("StakeReportDialog", "Total Stake Analized", 0));
#endif // QT_NO_TOOLTIP
        Stake_Counted->setText(QApplication::translate("StakeReportDialog", "0", 0));
        L_Last->setText(QApplication::translate("StakeReportDialog", "Last Stake", 0));
#ifndef QT_NO_TOOLTIP
        TimeTook_2->setToolTip(QApplication::translate("StakeReportDialog", "Time took to refresh dialog", 0));
#endif // QT_NO_TOOLTIP
        TimeTook_2->setText(QApplication::translate("StakeReportDialog", "Wait please...", 0));
#ifndef QT_NO_TOOLTIP
        TimeTook->setToolTip(QApplication::translate("StakeReportDialog", "Time took to retrieve the data", 0));
#endif // QT_NO_TOOLTIP
        TimeTook->setText(QApplication::translate("StakeReportDialog", "Wait please...", 0));
        QTableWidgetItem *___qtablewidgetitem = StakeReportTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("StakeReportDialog", "Date", 0));
        QTableWidgetItem *___qtablewidgetitem1 = StakeReportTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("StakeReportDialog", "Amount", 0));
        QTableWidgetItem *___qtablewidgetitem2 = StakeReportTable->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("StakeReportDialog", "Stake", 0));

        const bool __sortingEnabled = StakeReportTable->isSortingEnabled();
        StakeReportTable->setSortingEnabled(false);
        StakeReportTable->setSortingEnabled(__sortingEnabled);

#ifndef QT_NO_TOOLTIP
        L_CurrentBlock->setToolTip(QApplication::translate("StakeReportDialog", "Data of the current block.", 0));
#endif // QT_NO_TOOLTIP
        L_CurrentBlock->setText(QApplication::translate("StakeReportDialog", "Current Chain Block :", 0));
#ifndef QT_NO_TOOLTIP
        button_Refresh->setToolTip(QApplication::translate("StakeReportDialog", "Refresh the data", 0));
#endif // QT_NO_TOOLTIP
        button_Refresh->setText(QApplication::translate("StakeReportDialog", "Refresh", 0));
#ifndef QT_NO_TOOLTIP
        CopytoClipboard->setToolTip(QApplication::translate("StakeReportDialog", "Copy Report to ClipBoard", 0));
#endif // QT_NO_TOOLTIP
        CopytoClipboard->setText(QApplication::translate("StakeReportDialog", "Copy to clipboard", 0));
#ifndef QT_NO_TOOLTIP
        buttonBox->setToolTip(QApplication::translate("StakeReportDialog", "Close the dialog", 0));
#endif // QT_NO_TOOLTIP
    } // retranslateUi

};

namespace Ui {
    class StakeReportDialog: public Ui_StakeReportDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STAKEREPORTDIALOG_H
