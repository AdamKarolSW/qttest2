#include "mainwindow.h"
#include "ui_mainwindow.h"

using namespace std;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);



}
double freq_down=18.00; //default value of freq
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionOk_button_pushed_triggered()
{
    bcm2835_spi_setBitOrder(BCM2835_SPI_BIT_ORDER_MSBFIRST);      // The default
    bcm2835_spi_setDataMode(BCM2835_SPI_MODE0);                   // The default
    bcm2835_spi_setClockDivider(BCM2835_SPI_CLOCK_DIVIDER_65536); // The default
    bcm2835_spi_chipSelect(BCM2835_SPI_CS0);                      // The default
    bcm2835_spi_setChipSelectPolarity(BCM2835_SPI_CS0, LOW);      // the default

    // Send a byte to the slave and simultaneously read a byte back from the slave
    // If you tie MISO to MOSI, you should read back what was sent


    //uint8_t send_data = 0x11;
    uint8_t send_data = freq_down;
    uint8_t read_data = bcm2835_spi_transfer(send_data);
    printf("Sent to SPI: 0x%02X. Read back from SPI: 0x%02X.\n", send_data, read_data);
    if (send_data != read_data)
        cout << "Do you have the loopback from MOSI to MISO connected?" << endl;
}


void MainWindow::on_doubleSpinBox_valueChanged(double arg1)
{
    freq_down=arg1;
}
