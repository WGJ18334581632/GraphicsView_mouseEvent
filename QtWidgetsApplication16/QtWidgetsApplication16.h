#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_QtWidgetsApplication16.h"

class QtWidgetsApplication16 : public QMainWindow
{
    Q_OBJECT

public:
    QtWidgetsApplication16(QWidget *parent = nullptr);
    ~QtWidgetsApplication16();

private:
    Ui::QtWidgetsApplication16Class ui;
};
