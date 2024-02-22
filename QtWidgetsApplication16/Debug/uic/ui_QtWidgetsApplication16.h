/********************************************************************************
** Form generated from reading UI file 'QtWidgetsApplication16.ui'
**
** Created by: Qt User Interface Compiler version 5.9.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTWIDGETSAPPLICATION16_H
#define UI_QTWIDGETSAPPLICATION16_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QtWidgetsApplication16Class
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *QtWidgetsApplication16Class)
    {
        if (QtWidgetsApplication16Class->objectName().isEmpty())
            QtWidgetsApplication16Class->setObjectName(QStringLiteral("QtWidgetsApplication16Class"));
        QtWidgetsApplication16Class->resize(600, 400);
        menuBar = new QMenuBar(QtWidgetsApplication16Class);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        QtWidgetsApplication16Class->setMenuBar(menuBar);
        mainToolBar = new QToolBar(QtWidgetsApplication16Class);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        QtWidgetsApplication16Class->addToolBar(mainToolBar);
        centralWidget = new QWidget(QtWidgetsApplication16Class);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        QtWidgetsApplication16Class->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(QtWidgetsApplication16Class);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        QtWidgetsApplication16Class->setStatusBar(statusBar);

        retranslateUi(QtWidgetsApplication16Class);

        QMetaObject::connectSlotsByName(QtWidgetsApplication16Class);
    } // setupUi

    void retranslateUi(QMainWindow *QtWidgetsApplication16Class)
    {
        QtWidgetsApplication16Class->setWindowTitle(QApplication::translate("QtWidgetsApplication16Class", "QtWidgetsApplication16", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class QtWidgetsApplication16Class: public Ui_QtWidgetsApplication16Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTWIDGETSAPPLICATION16_H
