#include "gsm.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GSM w;
    w.show();
    
    return a.exec();
}
