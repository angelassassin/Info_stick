#include "info_stick.h"

Info_stick::Info_stick(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Info_stickClass())
{
    ui->setupUi(this);
}

Info_stick::~Info_stick()
{
    delete ui;
}

