/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "glass.h"
#include "nextpattern.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_newGame;
    QAction *action_exit;
    QAction *action_about;
    QAction *action_rules;
    QAction *action_settings;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    NextPattern *widget_next;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *horizontalSpacer_2;
    Glass *widget_glass;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer;
    QLabel *label_2;
    QLCDNumber *lcdNumber;
    QSpacerItem *verticalSpacer_3;
    QPushButton *button_newGame;
    QPushButton *button_exit;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menu_2;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(400, 300);
        action_newGame = new QAction(MainWindow);
        action_newGame->setObjectName(QStringLiteral("action_newGame"));
        action_exit = new QAction(MainWindow);
        action_exit->setObjectName(QStringLiteral("action_exit"));
        action_about = new QAction(MainWindow);
        action_about->setObjectName(QStringLiteral("action_about"));
        action_rules = new QAction(MainWindow);
        action_rules->setObjectName(QStringLiteral("action_rules"));
        action_settings = new QAction(MainWindow);
        action_settings->setObjectName(QStringLiteral("action_settings"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout_3 = new QHBoxLayout(centralWidget);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        widget_next = new NextPattern(centralWidget);
        widget_next->setObjectName(QStringLiteral("widget_next"));
        widget_next->setMinimumSize(QSize(60, 60));
        widget_next->setMaximumSize(QSize(60, 60));

        verticalLayout->addWidget(widget_next);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);


        horizontalLayout_3->addLayout(verticalLayout);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        widget_glass = new Glass(centralWidget);
        widget_glass->setObjectName(QStringLiteral("widget_glass"));
        widget_glass->setFocusPolicy(Qt::StrongFocus);
        widget_glass->setProperty("rows", QVariant(10u));
        widget_glass->setProperty("columns", QVariant(6u));

        horizontalLayout_3->addWidget(widget_glass);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_2);

        lcdNumber = new QLCDNumber(centralWidget);
        lcdNumber->setObjectName(QStringLiteral("lcdNumber"));

        verticalLayout_2->addWidget(lcdNumber);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_3);

        button_newGame = new QPushButton(centralWidget);
        button_newGame->setObjectName(QStringLiteral("button_newGame"));

        verticalLayout_2->addWidget(button_newGame);

        button_exit = new QPushButton(centralWidget);
        button_exit->setObjectName(QStringLiteral("button_exit"));

        verticalLayout_2->addWidget(button_exit);


        horizontalLayout_3->addLayout(verticalLayout_2);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 18));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        menu_2 = new QMenu(menuBar);
        menu_2->setObjectName(QStringLiteral("menu_2"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menu_2->menuAction());
        menu->addAction(action_newGame);
        menu->addAction(action_settings);
        menu->addAction(action_exit);
        menu_2->addAction(action_rules);
        menu_2->addAction(action_about);
        mainToolBar->addAction(action_newGame);
        mainToolBar->addAction(action_settings);
        mainToolBar->addAction(action_exit);

        retranslateUi(MainWindow);
        QObject::connect(action_newGame, SIGNAL(triggered()), widget_glass, SLOT(slotNewGame()));
        QObject::connect(action_exit, SIGNAL(triggered()), MainWindow, SLOT(close()));
        QObject::connect(button_newGame, SIGNAL(clicked()), action_newGame, SLOT(trigger()));
        QObject::connect(button_exit, SIGNAL(clicked()), action_exit, SLOT(trigger()));
        QObject::connect(widget_glass, SIGNAL(drawPattern(Figure*)), widget_next, SLOT(slotDrawPattern(Figure*)));
        QObject::connect(widget_glass, SIGNAL(signalSetScore(int)), lcdNumber, SLOT(display(int)));
        QObject::connect(action_about, SIGNAL(triggered()), widget_glass, SLOT(slotAbout()));
        QObject::connect(action_rules, SIGNAL(triggered()), widget_glass, SLOT(slotRules()));
        QObject::connect(action_settings, SIGNAL(triggered()), widget_glass, SLOT(slotSettings()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        action_newGame->setText(QApplication::translate("MainWindow", "\320\235\320\276\320\262\320\260\321\217", 0));
#ifndef QT_NO_TOOLTIP
        action_newGame->setToolTip(QApplication::translate("MainWindow", "\320\235\320\276\320\262\320\260\321\217 \320\270\320\263\321\200\320\260", 0));
#endif // QT_NO_TOOLTIP
        action_exit->setText(QApplication::translate("MainWindow", "\320\222\321\213\321\205\320\276\320\264", 0));
        action_about->setText(QApplication::translate("MainWindow", "\320\236 \320\277\321\200\320\276\320\263\321\200\320\260\320\274\320\274\320\265", 0));
        action_rules->setText(QApplication::translate("MainWindow", "\320\237\321\200\320\260\320\262\320\270\320\273\320\260", 0));
        action_settings->setText(QApplication::translate("MainWindow", "\320\237\320\260\321\200\320\260\320\274\320\265\321\202\321\200\321\213...", 0));
        label->setText(QApplication::translate("MainWindow", "\320\241\320\273\320\265\320\264\321\203\321\216\321\211\320\260\321\217", 0));
        label_2->setText(QApplication::translate("MainWindow", "\320\241\321\207\320\265\321\202", 0));
        button_newGame->setText(QApplication::translate("MainWindow", "\320\235\320\276\320\262\320\260\321\217 \320\270\320\263\321\200\320\260", 0));
        button_exit->setText(QApplication::translate("MainWindow", "\320\222\321\213\321\205\320\276\320\264", 0));
        menu->setTitle(QApplication::translate("MainWindow", "\320\230\320\263\321\200\320\260", 0));
        menu_2->setTitle(QApplication::translate("MainWindow", "\320\241\320\277\321\200\320\260\320\262\320\272\320\260", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
