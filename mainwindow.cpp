#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QElapsedTimer>
#include <QTimer>
#define COSTMULTI 1.12

MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow)
{
    ui->setupUi(this);



  this->connect(this->ui->pushButtonLoc, SIGNAL(clicked()), this,SLOT(on_pushButton_clicked()));
  this->codeLines   = 0;
  this->clpClick    = 1;
  this->clpSec      = 0;
  this->clpPercent  = 0;

    struct_hardware  hardware[10] =  {  { 0, 0,           15,           15, COSTMULTI,       1,       1, false},
                                        { 1, 0,          100,          100, COSTMULTI,       1,       1, false},
                                        { 2, 0,         1100,         1100, COSTMULTI,       8,       8, false},
                                        { 3, 0,        12000,        12000, COSTMULTI,      47,      47, false},
                                        { 4, 0,       130000,       130000, COSTMULTI,     260,     260, false},
                                        { 5, 0,      1400000,      1400000, COSTMULTI,    1400,    1400, false},
                                        { 6, 0,    330000000,    330000000, COSTMULTI,    7800,    7800, false},
                                        { 7, 0,   5100000000,   5100000000, COSTMULTI,   44000,   44000, false},
                                        { 8, 0,  75000000000,  75000000000, COSTMULTI,  260000,  260000, false},
                                        { 9, 0, 100000000000, 100000000000, COSTMULTI, 1600000, 1600000, false}};

    QString tempCost = QLocale(QLocale::English).toString(hardware[0].cost, 'f', 0);
    this->ui->hardwareCost_0->setText(tempCost);

    tempCost = QLocale(QLocale::English).toString(hardware[1].cost, 'f', 0);
    this->ui->hardwareCost_1->setText(tempCost);

    tempCost = QLocale(QLocale::English).toString(hardware[2].cost, 'f', 0);
    this->ui->hardwareCost_2->setText(tempCost);

    tempCost = QLocale(QLocale::English).toString(hardware[3].cost, 'f', 0);
    this->ui->hardwareCost_3->setText(tempCost);

    tempCost = QLocale(QLocale::English).toString(hardware[4].cost, 'f', 0);
    this->ui->hardwareCost_4->setText(tempCost);

    tempCost = QLocale(QLocale::English).toString(hardware[5].cost, 'f', 0);
    this->ui->hardwareCost_5->setText(tempCost);

    tempCost = QLocale(QLocale::English).toString(hardware[6].cost, 'f', 0);
    this->ui->hardwareCost_6->setText(tempCost);

    tempCost = QLocale(QLocale::English).toString(hardware[7].cost, 'f', 0);
    this->ui->hardwareCost_7->setText(tempCost);

    tempCost = QLocale(QLocale::English).toString(hardware[8].cost, 'f', 0);
    this->ui->hardwareCost_8->setText(tempCost);

    tempCost = QLocale(QLocale::English).toString(hardware[9].cost, 'f', 0);
    this->ui->hardwareCost_9->setText(tempCost);

    //this->ui->upgradeText->setWordWrap(true);
    /*this->ui->label_11->setWordWrap(true);
    this->ui->label_18->setWordWrap(true);
    this->ui->label_11->setText("„Coder #1“-Schriftzug auf dem Becher");
    this->ui->label_18->setText("In die tiefsten Weiten des Darknets musstest du absteigen, um diesen super-rare Sticker-Sticker zu bekommen. Du bist jetzt einer von 25 Menschen die wissen wie er aussieht, und einer von 3 der einen besitzt.");

*/
    /*this->ui->hardwareFrame_1->hide();
    this->ui->hardwareFrame_2->hide();
    this->ui->hardwareFrame_3->hide();
    this->ui->hardwareFrame_4->hide();
    this->ui->hardwareFrame_5->hide();
    this->ui->hardwareFrame_6->hide();
    this->ui->hardwareFrame_7->hide();
    this->ui->hardwareFrame_8->hide();
    this->ui->hardwareFrame_9->hide();*/

    // Autmatic increment timer
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    timer->start(0);
    elapsedTime.start();
}

MainWindow::~MainWindow()
{
  delete ui;
}

void MainWindow::paintEvent(QPaintEvent *){

    tempTime = elapsedTime.elapsed();
    elapsedTime.restart();
    codeLines += tempTime * clpSec / 1000;

    QString tempLoC = QLocale(QLocale::English).toString(codeLines, 'f', 0);

    this->ui->labelLoC->setText(tempLoC);
}

// Kaffee
// Muss gesondert behandelt werden, da er nur die Mächtigkeit des Klicks erhöht!
void MainWindow::on_buyHardware_0_clicked()
{
    // Wenn genug Geld da ist
    if (codeLines >= hardware[0].cost){

        // Wird der Kaufbetrag von den vorhandenen CL abgezogen
        codeLines = codeLines - hardware[0].cost;

        // Vorhandene Anzahl erhöhen
        hardware[0].counter++;

        // Neue kosten berechnen
        hardware[0].cost = hardware[0].cost * hardware[0].costMulti;

        // Erhöht die Mächtigkeit des klicks
        clpClick = clpClick + hardware[0].LOCpS;


    this->ui->hardwareCost_0->setText(QLocale(QLocale::English).toString(hardware[0].cost, 'f', 0));
    this->ui->labelHeadline->setNum(hardware[0].cost);
    this->ui->hardwareFrame_1->show();
    } else {
        this->ui->labelHeadline->setText("Nicht genug Geld!");
    }
}

void MainWindow::on_buyHardware_1_clicked()
{/*
    if (codeLines >= hardware[1]->h_getCost()){
        codeLines -= hardware[1]->h_getCost();
        hardware[1]->h_buy();
    }*/
}

void MainWindow::on_buyHardware_2_clicked()
{

}

void MainWindow::on_buyHardware_3_clicked()
{

}

void MainWindow::on_buyHardware_4_clicked()
{

}

void MainWindow::on_buyHardware_5_clicked()
{

}

void MainWindow::on_buyHardware_6_clicked()
{

}

void MainWindow::on_buyHardware_7_clicked()
{

}

void MainWindow::on_buyHardware_8_clicked()
{

}

void MainWindow::on_buyHardware_9_clicked()
{

}

void MainWindow::on_pushButtonLoc_clicked()
{
    codeLines+=clpClick;
    codeLines+=clpSec*clpPercent;
}
