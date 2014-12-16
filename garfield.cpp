#include <QWebView>
#include <QDebug>
#include "garfield.hpp"
#include "ui_garfield.h"

Garfield::Garfield(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Garfield)
{
    ui->setupUi(this);
    ui->horizontalSlider->setMinimum(QDate(1978, 6, 17).toJulianDay());
    ui->horizontalSlider->setMaximum(QDate::currentDate().toJulianDay());
    on_todayButton_clicked();
    on_showButton_clicked();
}

Garfield::~Garfield()
{
    delete ui;
}

void Garfield::on_showButton_clicked()
{
    QDateTime date = ui->dateEdit->dateTime();
    QString url = "https://garfield.com/uploads/strips/";
            url += QString(date.toString("yyyy-MM-dd"));
            url += ".jpg";
    ui->webView->load(QUrl(url));
    ui->webView->show();

    qDebug() << "DATE" << date;
    qDebug() << "URL" << url;
    qDebug() << "WEB:" << ui->webView->url();
}

void Garfield::on_todayButton_clicked()
{
    ui->dateEdit->setDateTime(QDateTime::currentDateTime());
    ui->horizontalSlider->setValue(QDate::currentDate().toJulianDay());

    qDebug() << QDateTime::currentDateTime();
}

void Garfield::on_horizontalSlider_valueChanged(int value)
{

    ui->dateEdit->setDate(QDate::fromJulianDay(value));
    if (ui->checkBox->isChecked()) on_showButton_clicked();

    qDebug() << value;
    qDebug() << QDate::fromJulianDay(value);
}


void Garfield::on_calcButton_clicked()
{

}
