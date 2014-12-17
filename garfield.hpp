#ifndef GARFIELD_HPP
#define GARFIELD_HPP

#include <QWidget>
#include <QCalendarWidget>

namespace Ui {
class Garfield;
}

class Garfield : public QWidget
{
    Q_OBJECT

public:
    explicit Garfield(QWidget *parent = 0);
    ~Garfield();

private slots:
    void on_showButton_clicked();

    void on_todayButton_clicked();

    void on_horizontalSlider_valueChanged(int value);

    void on_horizontalSlider_sliderReleased();

    void on_dateEdit_dateChanged(const QDate &date);

    void on_dateEdit_editingFinished();

private:
    Ui::Garfield *ui;
};

#endif // GARFIELD_HPP
