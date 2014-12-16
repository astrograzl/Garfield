#include "garfield.hpp"
#include "ui_garfield.h"

Garfield::Garfield(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Garfield)
{
    ui->setupUi(this);
}

Garfield::~Garfield()
{
    delete ui;
}
