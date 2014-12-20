/**
 * @file garfield.hpp
 * @author Zdenek Janak <janak@astronomie.cz>
 */
#ifndef GARFIELD_HPP
#define GARFIELD_HPP

#include <QWidget>
#include <QCalendarWidget>

namespace Ui {
class Garfield;
}

/**
 * @brief The Garfield class represents the main widget window
 */
class Garfield : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief Garfield constructor for the main widget window
     * @param parent do not exist
     */
    explicit Garfield(QWidget *parent = 0);

    /**
     * @brief destructor
     */
    ~Garfield();

private slots:
    /**
     * @brief on_showButton_clicked
     */
    void on_showButton_clicked();

    /**
     * @brief on_todayButton_clicked
     */
    void on_todayButton_clicked();

    /**
     * @brief on_horizontalSlider_valueChanged
     * @param value
     */
    void on_horizontalSlider_valueChanged(int value);

    /**
     * @brief on_horizontalSlider_sliderReleased
     */
    void on_horizontalSlider_sliderReleased();

    /**
     * @brief on_dateEdit_dateChanged
     * @param date
     */
    void on_dateEdit_dateChanged(const QDate &date);

    /**
     * @brief on_dateEdit_editingFinished
     */
    void on_dateEdit_editingFinished();

private:
    Ui::Garfield *ui; ///< user interface
};

#endif // GARFIELD_HPP
