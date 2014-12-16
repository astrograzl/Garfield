#ifndef GARFIELD_HPP
#define GARFIELD_HPP

#include <QWidget>

namespace Ui {
class Garfield;
}

class Garfield : public QWidget
{
    Q_OBJECT

public:
    explicit Garfield(QWidget *parent = 0);
    ~Garfield();

private:
    Ui::Garfield *ui;
};

#endif // GARFIELD_HPP
