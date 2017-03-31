#include <QWebView>
#include "ui_garfield.h"
#include "garfield.hpp"

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
}

Garfield::~Garfield()
{
    delete ui;
}

void Garfield::keyPressEvent(QKeyEvent *e)
{
    if (e->key() == Qt::Key_Space)
        on_randomButton_clicked();
    else if (e->key() == Qt::Key_Left)
        on_prevButton_clicked();
    else if (e->key() == Qt::Key_Right)
        on_nextButton_clicked();
}

void Garfield::on_showButton_clicked()
{
    QDateTime date = ui->dateEdit->dateTime();
    QString url = "https://d1ejxu6vysztl5.cloudfront.net/comics/garfield/";
            url += QString(date.toString("yyyy")) + "/";
            url += QString(date.toString("yyyy-MM-dd"));
            url += ".gif";
    ui->lineEdit->setText(url);
    ui->webView->load(QUrl(url));
    ui->webView->show();
}

void Garfield::on_todayButton_clicked()
{
    ui->dateEdit->setDate(MAXDATE);
    on_showButton_clicked();
}

void Garfield::on_horizontalSlider_sliderReleased()
{
    on_showButton_clicked();
}

void Garfield::on_horizontalSlider_valueChanged(int value)
{
    ui->dateEdit->setDate(QDate::fromJulianDay(value));
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
}

void Garfield::on_dateEdit_editingFinished()
{
    on_showButton_clicked();
}

void Garfield::on_prevButton_clicked()
{
    QDate curdate = ui->dateEdit->date();
    if (curdate > MINDATE) {
        ui->dateEdit->setDate(curdate.addDays(-1));
        on_showButton_clicked();
    }
}

void Garfield::on_nextButton_clicked()
{
    QDate curdate = ui->dateEdit->date();
    if (curdate < MAXDATE) {
        ui->dateEdit->setDate(curdate.addDays(1));
        on_showButton_clicked();
    }
}

void Garfield::on_randomButton_clicked()
{
    int range = MAXDATE.toJulianDay() - MINDATE.toJulianDay() + 1;
    int random = MINDATE.toJulianDay() + qrand() % range;
    ui->dateEdit->setDate(QDate::fromJulianDay(random));
    on_showButton_clicked();
}
