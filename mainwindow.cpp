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
  this->clpClick    = 9500000000000000000000000.0;
  this->clpSec      = 0;
  this->clpPercent  = 0;


    QString tempCost = QLocale(QLocale::English).toString(hardware[0].cost, 'f', 0);
    this->ui->hardwareCost_0->setText(QLocale(QLocale::English).toString(hardware[0].cost, 'f', 0));

    tempCost = QLocale(QLocale::English).toString(hardware[1].cost, 'f', 0);
    this->ui->hardwareCost_1->setText(QLocale(QLocale::English).toString(hardware[1].cost, 'f', 0));

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

    this->ui->upgradeNameCoffee_2   ->setWordWrap(true);
    this->ui->upgradeNameSmart_3    ->setWordWrap(true);
    this->ui->upgradeNameNote_3     ->setWordWrap(true);
    this->ui->upgradeNameNote_5     ->setWordWrap(true);
    this->ui->upgradeNameCodeInc_2  ->setWordWrap(true);
    this->ui->upgradeNameCodeInc_5  ->setWordWrap(true);

    this->ui->upgradeTextCoffee_1   ->setWordWrap(true);
    this->ui->upgradeTextCoffee_2   ->setWordWrap(true);
    this->ui->upgradeTextCoffee_3   ->setWordWrap(true);
    this->ui->upgradeTextCoffee_4   ->setWordWrap(true);
    this->ui->upgradeTextCoffee_5   ->setWordWrap(true);

    this->ui->upgradeTextTama_1     ->setWordWrap(true);
    this->ui->upgradeTextTama_2     ->setWordWrap(true);
    this->ui->upgradeTextTama_3     ->setWordWrap(true);
    this->ui->upgradeTextTama_4     ->setWordWrap(true);
    this->ui->upgradeTextTama_5     ->setWordWrap(true);

    this->ui->upgradeTextCalc_1     ->setWordWrap(true);
    this->ui->upgradeTextCalc_2     ->setWordWrap(true);
    this->ui->upgradeTextCalc_3     ->setWordWrap(true);
    this->ui->upgradeTextCalc_4     ->setWordWrap(true);
    this->ui->upgradeTextCalc_5     ->setWordWrap(true);

    this->ui->upgradeTextArduino_1  ->setWordWrap(true);
    this->ui->upgradeTextArduino_2  ->setWordWrap(true);
    this->ui->upgradeTextArduino_3  ->setWordWrap(true);
    this->ui->upgradeTextArduino_4  ->setWordWrap(true);
    this->ui->upgradeTextArduino_5  ->setWordWrap(true);

    this->ui->upgradeTextSmart_1    ->setWordWrap(true);
    this->ui->upgradeTextSmart_2    ->setWordWrap(true);
    this->ui->upgradeTextSmart_3    ->setWordWrap(true);
    this->ui->upgradeTextSmart_4    ->setWordWrap(true);
    this->ui->upgradeTextSmart_5    ->setWordWrap(true);

    this->ui->upgradeTextTablet_1   ->setWordWrap(true);
    this->ui->upgradeTextTablet_2   ->setWordWrap(true);
    this->ui->upgradeTextTablet_3   ->setWordWrap(true);
    this->ui->upgradeTextTablet_4   ->setWordWrap(true);
    this->ui->upgradeTextTablet_5   ->setWordWrap(true);

    this->ui->upgradeTextNote_1     ->setWordWrap(true);
    this->ui->upgradeTextNote_2     ->setWordWrap(true);
    this->ui->upgradeTextNote_3     ->setWordWrap(true);
    this->ui->upgradeTextNote_4     ->setWordWrap(true);
    this->ui->upgradeTextNote_5     ->setWordWrap(true);

    this->ui->upgradeTextPc_1       ->setWordWrap(true);
    this->ui->upgradeTextPc_2       ->setWordWrap(true);
    this->ui->upgradeTextPc_3       ->setWordWrap(true);
    this->ui->upgradeTextPc_4       ->setWordWrap(true);
    this->ui->upgradeTextPc_5       ->setWordWrap(true);

    this->ui->upgradeTextCodeInc_1  ->setWordWrap(true);
    this->ui->upgradeTextCodeInc_2  ->setWordWrap(true);
    this->ui->upgradeTextCodeInc_3  ->setWordWrap(true);
    this->ui->upgradeTextCodeInc_4  ->setWordWrap(true);
    this->ui->upgradeTextCodeInc_5  ->setWordWrap(true);

    this->ui->upgradeTextNeuro_1    ->setWordWrap(true);
    this->ui->upgradeTextNeuro_2    ->setWordWrap(true);
    this->ui->upgradeTextNeuro_3    ->setWordWrap(true);
    this->ui->upgradeTextNeuro_4    ->setWordWrap(true);
    this->ui->upgradeTextNeuro_5    ->setWordWrap(true);


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
    this->ui->labelHeadline->setNum(u_coffee[1].cost);
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
    //this->ui->labelLoC->;
}

void MainWindow::struct_hardware::buy(){

}