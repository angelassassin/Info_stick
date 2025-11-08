#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_info_stick.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Info_stickClass; };
QT_END_NAMESPACE

class Info_stick : public QMainWindow
{
    Q_OBJECT

public:
    Info_stick(QWidget *parent = nullptr);
    ~Info_stick();

private:
    Ui::Info_stickClass *ui;
};

