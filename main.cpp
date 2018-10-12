#include "mainwindow.h"
#include <QApplication>


int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    MainWindow w;
    if (!bcm2835_init())
        {
            QMessageBox Msgbox;
            Msgbox.setText("SPI init problem");
            Msgbox.exec();
        }
     if (!bcm2835_spi_begin())
     {
         QMessageBox Msgbox;
         Msgbox.setText("SPI begin problem");
         Msgbox.exec();
     }
     else
     {
         QMessageBox Msgbox;
         Msgbox.setText("SPI Init and begin done");
         Msgbox.exec();
         w.show();
     }


    return a.exec();
}
