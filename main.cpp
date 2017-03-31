#include <QApplication>
#include "garfield.hpp"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Garfield w;
    w.show();

    return a.exec();
}
