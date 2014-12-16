#include <QWebView>
#include "garfield.hpp"
#include "ui_garfield.h"

#define MINDATE QDate(1978, 6, 19)
#define MAXDATE QDate::currentDate()

Garfield::Garfield(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Garfield)
{
    ui->setupUi(this);

    ui->horizontalSlider->setMinimum(MINDATE.toJulianDay());
    ui->horizontalSlider->setMaximum(MAXDATE.toJulianDay());

    ui->dateEdit->calendarWidget()->setMinimumDate(MINDATE);
    ui->dateEdit->calendarWidget()->setMaximumDate(MAXDATE);

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
    ui->lineEdit->setText(url);
    ui->webView->load(QUrl(url));
    ui->webView->show();
}

void Garfield::on_todayButton_clicked()
{
    ui->dateEdit->setDate(MAXDATE);
}

void Garfield::on_horizontalSlider_valueChanged(int value)
{
    ui->dateEdit->setDate(QDate::fromJulianDay(value));
}

void Garfield::on_horizontalSlider_sliderReleased()
{
    //if (ui->checkBox->isChecked()) on_showButton_clicked();
}

void Garfield::on_dateEdit_dateChanged(const QDate &date)
{
    if (date > MAXDATE) {
        ui->dateEdit->setDate(MAXDATE);
        ui->horizontalSlider->setValue(MAXDATE.toJulianDay());
    } else if (date < MINDATE) {
        ui->dateEdit->setDate(MINDATE);
        ui->horizontalSlider->setValue(MINDATE.toJulianDay());
    } else {
        ui->horizontalSlider->setValue(date.toJulianDay());
    }
    if (ui->checkBox->isChecked()) on_showButton_clicked();
}
