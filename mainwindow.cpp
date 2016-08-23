/* Grundlagen der Informatik II, SS 16

    Projekt:            Idle-Game
    Autor: 				Robert Schock
    Matrikelnummer: 	4229891
    Datum: 				23.08.2016

Dies ist die Hauptdatei für das Spiel 'Infinite Coder' dass die gesammte Spiellogik
sowie das Eventhandling enthält. Eine genaue Dokumentation liegt der
Abgabe als PDF Datei bei.
*/

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QElapsedTimer>
#include <QTimer>
#include <QtGlobal>
#include <QDateTime>


MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Bestimmen des zufälligen Anfangs im Witz-Array, bei dem die Zeit als Seed verwendet wird.
    QTime time      = QTime::currentTime();
    qsrand((uint)time.msec());
    jokeCounter     = qrand() % (sizeof(jokes)/sizeof(jokes[0]));

    // Label mit aktueller Clickstärke versehen
    this->ui->labelLoCpClick->setText(QLocale(QLocale::English).toString(clpClickPercent*clpSec+clpClick, 'f', 0));

    // Die tatsächlichen Kosten in die jeweilgen Felder eintragen
    {
    this->ui->hardwareCost_0->setText(QLocale(QLocale::English).toString(hardware[0].cost, 'f', 0));
    this->ui->hardwareCost_1->setText(QLocale(QLocale::English).toString(hardware[1].cost, 'f', 0));
    this->ui->hardwareCost_2->setText(QLocale(QLocale::English).toString(hardware[2].cost, 'f', 0));
    this->ui->hardwareCost_3->setText(QLocale(QLocale::English).toString(hardware[3].cost, 'f', 0));
    this->ui->hardwareCost_4->setText(QLocale(QLocale::English).toString(hardware[4].cost, 'f', 0));
    this->ui->hardwareCost_5->setText(QLocale(QLocale::English).toString(hardware[5].cost, 'f', 0));
    this->ui->hardwareCost_6->setText(QLocale(QLocale::English).toString(hardware[6].cost, 'f', 0));
    this->ui->hardwareCost_7->setText(QLocale(QLocale::English).toString(hardware[7].cost, 'f', 0));
    this->ui->hardwareCost_8->setText(QLocale(QLocale::English).toString(hardware[8].cost, 'f', 0));
    this->ui->hardwareCost_9->setText(QLocale(QLocale::English).toString(hardware[9].cost, 'f', 0));

    this->ui->upgradeCostCoffee_1   ->setText(QLocale(QLocale::English).toString(u_coffee[0].cost, 'f', 0));
    this->ui->upgradeCostCoffee_2   ->setText(QLocale(QLocale::English).toString(u_coffee[1].cost, 'f', 0));
    this->ui->upgradeCostCoffee_3   ->setText(QLocale(QLocale::English).toString(u_coffee[2].cost, 'f', 0));
    this->ui->upgradeCostCoffee_4   ->setText(QLocale(QLocale::English).toString(u_coffee[3].cost, 'f', 0));
    this->ui->upgradeCostCoffee_5   ->setText(QLocale(QLocale::English).toString(u_coffee[4].cost, 'f', 0));

    this->ui->upgradeCostTama_1     ->setText(QLocale(QLocale::English).toString(u_tama[0].cost, 'f', 0));
    this->ui->upgradeCostTama_2     ->setText(QLocale(QLocale::English).toString(u_tama[1].cost, 'f', 0));
    this->ui->upgradeCostTama_3     ->setText(QLocale(QLocale::English).toString(u_tama[2].cost, 'f', 0));
    this->ui->upgradeCostTama_4     ->setText(QLocale(QLocale::English).toString(u_tama[3].cost, 'f', 0));
    this->ui->upgradeCostTama_5     ->setText(QLocale(QLocale::English).toString(u_tama[4].cost, 'f', 0));

    this->ui->upgradeCostCalc_1     ->setText(QLocale(QLocale::English).toString(u_calc[0].cost, 'f', 0));
    this->ui->upgradeCostCalc_2     ->setText(QLocale(QLocale::English).toString(u_calc[1].cost, 'f', 0));
    this->ui->upgradeCostCalc_3     ->setText(QLocale(QLocale::English).toString(u_calc[2].cost, 'f', 0));
    this->ui->upgradeCostCalc_4     ->setText(QLocale(QLocale::English).toString(u_calc[3].cost, 'f', 0));
    this->ui->upgradeCostCalc_5     ->setText(QLocale(QLocale::English).toString(u_calc[4].cost, 'f', 0));

    this->ui->upgradeCostArduino_1  ->setText(QLocale(QLocale::English).toString(u_arduino[0].cost, 'f', 0));
    this->ui->upgradeCostArduino_2  ->setText(QLocale(QLocale::English).toString(u_arduino[1].cost, 'f', 0));
    this->ui->upgradeCostArduino_3  ->setText(QLocale(QLocale::English).toString(u_arduino[2].cost, 'f', 0));
    this->ui->upgradeCostArduino_4  ->setText(QLocale(QLocale::English).toString(u_arduino[3].cost, 'f', 0));
    this->ui->upgradeCostArduino_5  ->setText(QLocale(QLocale::English).toString(u_arduino[4].cost, 'f', 0));

    this->ui->upgradeCostSmart_1    ->setText(QLocale(QLocale::English).toString(u_smart[0].cost, 'f', 0));
    this->ui->upgradeCostSmart_2    ->setText(QLocale(QLocale::English).toString(u_smart[1].cost, 'f', 0));
    this->ui->upgradeCostSmart_3    ->setText(QLocale(QLocale::English).toString(u_smart[2].cost, 'f', 0));
    this->ui->upgradeCostSmart_4    ->setText(QLocale(QLocale::English).toString(u_smart[3].cost, 'f', 0));
    this->ui->upgradeCostSmart_5    ->setText(QLocale(QLocale::English).toString(u_smart[4].cost, 'f', 0));

    this->ui->upgradeCostTablet_1   ->setText(QLocale(QLocale::English).toString(u_tablet[0].cost, 'f', 0));
    this->ui->upgradeCostTablet_2   ->setText(QLocale(QLocale::English).toString(u_tablet[1].cost, 'f', 0));
    this->ui->upgradeCostTablet_3   ->setText(QLocale(QLocale::English).toString(u_tablet[2].cost, 'f', 0));
    this->ui->upgradeCostTablet_4   ->setText(QLocale(QLocale::English).toString(u_tablet[3].cost, 'f', 0));
    this->ui->upgradeCostTablet_5   ->setText(QLocale(QLocale::English).toString(u_tablet[4].cost, 'f', 0));

    this->ui->upgradeCostNote_1     ->setText(QLocale(QLocale::English).toString(u_note[0].cost, 'f', 0));
    this->ui->upgradeCostNote_2     ->setText(QLocale(QLocale::English).toString(u_note[1].cost, 'f', 0));
    this->ui->upgradeCostNote_3     ->setText(QLocale(QLocale::English).toString(u_note[2].cost, 'f', 0));
    this->ui->upgradeCostNote_4     ->setText(QLocale(QLocale::English).toString(u_note[3].cost, 'f', 0));
    this->ui->upgradeCostNote_5     ->setText(QLocale(QLocale::English).toString(u_note[4].cost, 'f', 0));

    this->ui->upgradeCostPc_1       ->setText(QLocale(QLocale::English).toString(u_pc[0].cost, 'f', 0));
    this->ui->upgradeCostPc_2       ->setText(QLocale(QLocale::English).toString(u_pc[1].cost, 'f', 0));
    this->ui->upgradeCostPc_3       ->setText(QLocale(QLocale::English).toString(u_pc[2].cost, 'f', 0));
    this->ui->upgradeCostPc_4       ->setText(QLocale(QLocale::English).toString(u_pc[3].cost, 'f', 0));
    this->ui->upgradeCostPc_5       ->setText(QLocale(QLocale::English).toString(u_pc[4].cost, 'f', 0));

    this->ui->upgradeCostCodeInc_1  ->setText(QLocale(QLocale::English).toString(u_codeinc[0].cost, 'f', 0));
    this->ui->upgradeCostCodeInc_2  ->setText(QLocale(QLocale::English).toString(u_codeinc[1].cost, 'f', 0));
    this->ui->upgradeCostCodeInc_3  ->setText(QLocale(QLocale::English).toString(u_codeinc[2].cost, 'f', 0));
    this->ui->upgradeCostCodeInc_4  ->setText(QLocale(QLocale::English).toString(u_codeinc[3].cost, 'f', 0));
    this->ui->upgradeCostCodeInc_5  ->setText(QLocale(QLocale::English).toString(u_codeinc[4].cost, 'f', 0));

    this->ui->upgradeCostNeuro_1    ->setText(QLocale(QLocale::English).toString(u_neuro[0].cost, 'f', 0));
    this->ui->upgradeCostNeuro_2    ->setText(QLocale(QLocale::English).toString(u_neuro[1].cost, 'f', 0));
    this->ui->upgradeCostNeuro_3    ->setText(QLocale(QLocale::English).toString(u_neuro[2].cost, 'f', 0));
    this->ui->upgradeCostNeuro_4    ->setText(QLocale(QLocale::English).toString(u_neuro[3].cost, 'f', 0));
    this->ui->upgradeCostNeuro_5    ->setText(QLocale(QLocale::English).toString(u_neuro[4].cost, 'f', 0));
    }

    // setWordWrap(true) aktiviert den automatischen Textumbruch
    // da sonst der minimale Platz teilweise nicht ausreich um den gesamten Inhalt anzuzeigen
    {
    this->ui->labelHeadline         ->setWordWrap(true);
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
    }

    // Erstellt korrrekte ToolTips mit den festgesetzten Faktoren
    {

    updateHardwareToolTip(0);
    updateHardwareToolTip(1);
    updateHardwareToolTip(2);
    updateHardwareToolTip(3);
    updateHardwareToolTip(4);
    updateHardwareToolTip(5);
    updateHardwareToolTip(6);
    updateHardwareToolTip(7);
    updateHardwareToolTip(8);
    updateHardwareToolTip(9);

    QString *ptr_toolTip  = new QString("Erhöht die Produktion der Hardware um den Faktor ");
    QString *ptr_toolTip2 = new QString(". Außerdem erhälst du jetzt pro Klick +");
    QString *ptr_toolTip3 = new QString("% von deinen CL pro Sekunde.");

    // Abfrage ob neben der Klickstärke auch ein CL pro Sekunde -abhängiger Bonus hinzugefügt wird
    if (u_coffee[0].clpClickPercent == 0) { this->ui->upgradeFrameCoffee_1   ->setToolTip(*ptr_toolTip + QString::number(u_coffee[0].multi) + "."); }
    else { this->ui->upgradeFrameCoffee_1   ->setToolTip(*ptr_toolTip + QString::number(u_coffee[0].multi) + *ptr_toolTip2 + QLocale(QLocale::English).toString(u_coffee[0].clpClickPercent*100, 'f', 1) + *ptr_toolTip3);}

    if (u_coffee[1].clpClickPercent == 0) { this->ui->upgradeFrameCoffee_2   ->setToolTip(*ptr_toolTip + QString::number(u_coffee[1].multi) + "."); }
    else { this->ui->upgradeFrameCoffee_2   ->setToolTip(*ptr_toolTip + QString::number(u_coffee[1].multi) + *ptr_toolTip2 + QLocale(QLocale::English).toString(u_coffee[1].clpClickPercent*100, 'f', 1) + *ptr_toolTip3);}

    if (u_coffee[2].clpClickPercent == 0) { this->ui->upgradeFrameCoffee_3   ->setToolTip(*ptr_toolTip + QString::number(u_coffee[2].multi) + "."); }
    else { this->ui->upgradeFrameCoffee_3   ->setToolTip(*ptr_toolTip + QString::number(u_coffee[2].multi) + *ptr_toolTip2 + QString::number(u_coffee[2].clpClickPercent*100) + *ptr_toolTip3);}

    if (u_coffee[3].clpClickPercent == 0) { this->ui->upgradeFrameCoffee_4   ->setToolTip(*ptr_toolTip + QString::number(u_coffee[3].multi) + "."); }
    else { this->ui->upgradeFrameCoffee_4   ->setToolTip(*ptr_toolTip + QString::number(u_coffee[3].multi) + *ptr_toolTip2 + QLocale(QLocale::English).toString(u_coffee[3].clpClickPercent*100, 'f', 1) + *ptr_toolTip3);}

    if (u_coffee[4].clpClickPercent == 0) { this->ui->upgradeFrameCoffee_5   ->setToolTip(*ptr_toolTip + QString::number(u_coffee[4].multi) + "."); }
    else { this->ui->upgradeFrameCoffee_5   ->setToolTip(*ptr_toolTip + QString::number(u_coffee[4].multi) + *ptr_toolTip2 + QLocale(QLocale::English).toString(u_coffee[4].clpClickPercent*100, 'f', 1) + *ptr_toolTip3);}


    this->ui->upgradeFrameTama_1     ->setToolTip(*ptr_toolTip + QString::number(u_tama[0].multi) + ".");
    this->ui->upgradeFrameTama_2     ->setToolTip(*ptr_toolTip + QString::number(u_tama[1].multi) + ".");
    this->ui->upgradeFrameTama_3     ->setToolTip(*ptr_toolTip + QString::number(u_tama[2].multi) + ".");
    this->ui->upgradeFrameTama_4     ->setToolTip(*ptr_toolTip + QString::number(u_tama[3].multi) + ".");
    this->ui->upgradeFrameTama_5     ->setToolTip(*ptr_toolTip + QString::number(u_tama[4].multi) + ".");

    this->ui->upgradeFrameCalc_1     ->setToolTip(*ptr_toolTip + QString::number(u_calc[0].multi) + ".");
    this->ui->upgradeFrameCalc_2     ->setToolTip(*ptr_toolTip + QString::number(u_calc[1].multi) + ".");
    this->ui->upgradeFrameCalc_3     ->setToolTip(*ptr_toolTip + QString::number(u_calc[2].multi) + ".");
    this->ui->upgradeFrameCalc_4     ->setToolTip(*ptr_toolTip + QString::number(u_calc[3].multi) + ".");
    this->ui->upgradeFrameCalc_5     ->setToolTip(*ptr_toolTip + QString::number(u_calc[4].multi) + ".");

    this->ui->upgradeFrameArduino_1  ->setToolTip(*ptr_toolTip + QString::number(u_arduino[0].multi) + ".");
    this->ui->upgradeFrameArduino_2  ->setToolTip(*ptr_toolTip + QString::number(u_arduino[1].multi) + ".");
    this->ui->upgradeFrameArduino_3  ->setToolTip(*ptr_toolTip + QString::number(u_arduino[2].multi) + ".");
    this->ui->upgradeFrameArduino_4  ->setToolTip(*ptr_toolTip + QString::number(u_arduino[3].multi) + ".");
    this->ui->upgradeFrameArduino_5  ->setToolTip(*ptr_toolTip + QString::number(u_arduino[4].multi) + ".");

    this->ui->upgradeFrameSmart_1    ->setToolTip(*ptr_toolTip + QString::number(u_smart[0].multi) + ".");
    this->ui->upgradeFrameSmart_2    ->setToolTip(*ptr_toolTip + QString::number(u_smart[1].multi) + ".");
    this->ui->upgradeFrameSmart_3    ->setToolTip(*ptr_toolTip + QString::number(u_smart[2].multi) + ".");
    this->ui->upgradeFrameSmart_4    ->setToolTip(*ptr_toolTip + QString::number(u_smart[3].multi) + ".");
    this->ui->upgradeFrameSmart_5    ->setToolTip(*ptr_toolTip + QString::number(u_smart[4].multi) + ".");

    this->ui->upgradeFrameTablet_1   ->setToolTip(*ptr_toolTip + QString::number(u_tablet[0].multi) + ".");
    this->ui->upgradeFrameTablet_2   ->setToolTip(*ptr_toolTip + QString::number(u_tablet[1].multi) + ".");
    this->ui->upgradeFrameTablet_3   ->setToolTip(*ptr_toolTip + QString::number(u_tablet[2].multi) + ".");
    this->ui->upgradeFrameTablet_4   ->setToolTip(*ptr_toolTip + QString::number(u_tablet[3].multi) + ".");
    this->ui->upgradeFrameTablet_5   ->setToolTip(*ptr_toolTip + QString::number(u_tablet[4].multi) + ".");

    this->ui->upgradeFrameNote_1     ->setToolTip(*ptr_toolTip + QString::number(u_note[0].multi) + ".");
    this->ui->upgradeFrameNote_2     ->setToolTip(*ptr_toolTip + QString::number(u_note[1].multi) + ".");
    this->ui->upgradeFrameNote_3     ->setToolTip(*ptr_toolTip + QString::number(u_note[2].multi) + ".");
    this->ui->upgradeFrameNote_4     ->setToolTip(*ptr_toolTip + QString::number(u_note[3].multi) + ".");
    this->ui->upgradeFrameNote_5     ->setToolTip(*ptr_toolTip + QString::number(u_note[4].multi) + ".");

    this->ui->upgradeFramePc_1       ->setToolTip(*ptr_toolTip + QString::number(u_pc[0].multi) + ".");
    this->ui->upgradeFramePc_2       ->setToolTip(*ptr_toolTip + QString::number(u_pc[1].multi) + ".");
    this->ui->upgradeFramePc_3       ->setToolTip(*ptr_toolTip + QString::number(u_pc[2].multi) + ".");
    this->ui->upgradeFramePc_4       ->setToolTip(*ptr_toolTip + QString::number(u_pc[3].multi) + ".");
    this->ui->upgradeFramePc_5       ->setToolTip(*ptr_toolTip + QString::number(u_pc[4].multi) + ".");

    this->ui->upgradeFrameCodeInc_1  ->setToolTip(*ptr_toolTip + QString::number(u_codeinc[0].multi) + ".");
    this->ui->upgradeFrameCodeInc_2  ->setToolTip(*ptr_toolTip + QString::number(u_codeinc[1].multi) + ".");
    this->ui->upgradeFrameCodeInc_3  ->setToolTip(*ptr_toolTip + QString::number(u_codeinc[2].multi) + ".");
    this->ui->upgradeFrameCodeInc_4  ->setToolTip(*ptr_toolTip + QString::number(u_codeinc[3].multi) + ".");
    this->ui->upgradeFrameCodeInc_5  ->setToolTip(*ptr_toolTip + QString::number(u_codeinc[4].multi) + ".");

    this->ui->upgradeFrameNeuro_1    ->setToolTip(*ptr_toolTip + QString::number(u_neuro[0].multi) + ".");
    this->ui->upgradeFrameNeuro_2    ->setToolTip(*ptr_toolTip + QString::number(u_neuro[1].multi) + ".");
    this->ui->upgradeFrameNeuro_3    ->setToolTip(*ptr_toolTip + QString::number(u_neuro[2].multi) + ".");
    this->ui->upgradeFrameNeuro_4    ->setToolTip(*ptr_toolTip + QString::number(u_neuro[3].multi) + ".");
    this->ui->upgradeFrameNeuro_5    ->setToolTip(*ptr_toolTip + QString::number(u_neuro[4].multi) + ".");
    delete ptr_toolTip;
    delete ptr_toolTip2;
    delete ptr_toolTip3;
    }

    // Versteckt die Upgrades und die meisten Gebäude am Anfang des Spiels, um gewisse Freischaltmechanik zu erreichen
    {
    this->ui->hardwareFrame_1       ->hide();
    this->ui->hardwareFrame_2       ->hide();
    this->ui->hardwareFrame_3       ->hide();
    this->ui->hardwareFrame_4       ->hide();
    this->ui->hardwareFrame_5       ->hide();
    this->ui->hardwareFrame_6       ->hide();
    this->ui->hardwareFrame_7       ->hide();
    this->ui->hardwareFrame_8       ->hide();
    this->ui->hardwareFrame_9       ->hide();

    this->ui->upgradeFrameCoffee_1  ->hide();
    this->ui->upgradeFrameCoffee_2  ->hide();
    this->ui->upgradeFrameCoffee_3  ->hide();
    this->ui->upgradeFrameCoffee_4  ->hide();
    this->ui->upgradeFrameCoffee_5  ->hide();
    this->ui->upgradeFrameTama_1    ->hide();
    this->ui->upgradeFrameTama_2    ->hide();
    this->ui->upgradeFrameTama_3    ->hide();
    this->ui->upgradeFrameTama_4    ->hide();
    this->ui->upgradeFrameTama_5    ->hide();
    this->ui->upgradeFrameCalc_1    ->hide();
    this->ui->upgradeFrameCalc_2    ->hide();
    this->ui->upgradeFrameCalc_3    ->hide();
    this->ui->upgradeFrameCalc_4    ->hide();
    this->ui->upgradeFrameCalc_5    ->hide();
    this->ui->upgradeFrameArduino_1 ->hide();
    this->ui->upgradeFrameArduino_2 ->hide();
    this->ui->upgradeFrameArduino_3 ->hide();
    this->ui->upgradeFrameArduino_4 ->hide();
    this->ui->upgradeFrameArduino_5 ->hide();
    this->ui->upgradeFrameSmart_1   ->hide();
    this->ui->upgradeFrameSmart_2   ->hide();
    this->ui->upgradeFrameSmart_3   ->hide();
    this->ui->upgradeFrameSmart_4   ->hide();
    this->ui->upgradeFrameSmart_5   ->hide();
    this->ui->upgradeFrameTablet_1  ->hide();
    this->ui->upgradeFrameTablet_2  ->hide();
    this->ui->upgradeFrameTablet_3  ->hide();
    this->ui->upgradeFrameTablet_4  ->hide();
    this->ui->upgradeFrameTablet_5  ->hide();
    this->ui->upgradeFrameNote_1    ->hide();
    this->ui->upgradeFrameNote_2    ->hide();
    this->ui->upgradeFrameNote_3    ->hide();
    this->ui->upgradeFrameNote_4    ->hide();
    this->ui->upgradeFrameNote_5    ->hide();
    this->ui->upgradeFramePc_1      ->hide();
    this->ui->upgradeFramePc_2      ->hide();
    this->ui->upgradeFramePc_3      ->hide();
    this->ui->upgradeFramePc_4      ->hide();
    this->ui->upgradeFramePc_5      ->hide();
    this->ui->upgradeFrameCodeInc_1 ->hide();
    this->ui->upgradeFrameCodeInc_2 ->hide();
    this->ui->upgradeFrameCodeInc_3 ->hide();
    this->ui->upgradeFrameCodeInc_4 ->hide();
    this->ui->upgradeFrameCodeInc_5 ->hide();
    this->ui->upgradeFrameNeuro_1   ->hide();
    this->ui->upgradeFrameNeuro_2   ->hide();
    this->ui->upgradeFrameNeuro_3   ->hide();
    this->ui->upgradeFrameNeuro_4   ->hide();
    this->ui->upgradeFrameNeuro_5   ->hide();
    this->ui->upgradeFrameTemp_1    ->hide();
    this->ui->upgradeFrameTemp_2    ->hide();
    this->ui->upgradeFrameTemp_3    ->hide();
    this->ui->upgradeFrameTemp_4    ->hide();
    this->ui->upgradeFrameTemp_5    ->hide();
    this->ui->upgradeFrameTemp_6    ->hide();
    }

    // Zähltimer für das automatische Ansteigen der CL pro Sekunde
    // Indem start() keinen Parameter bekommt, läuft der Timer immer dann aus wenn das Programm im Idle ist
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    timer->start();
    elapsedTime.start();
}

MainWindow::~MainWindow()
{
  delete ui;
}

// Event dass die neu gewonnen CL berechnet und das Label aktualisiert
void MainWindow::paintEvent(QPaintEvent *){

    tempTime = elapsedTime.elapsed();
    elapsedTime.restart();                  // Zwischenschritt damit die Zeit direkt weiterlaufenkann
    codeLines += tempTime * clpSec / 1000;  // Bruchteil der Sekunde mal CL pro Sekunde

    // Label-Update
    this->ui->labelLoC->setText(QLocale(QLocale::English).toString(codeLines, 'f', 0));
}

// Button für das Generieren des Codes
void MainWindow::on_pushButtonLoc_clicked()
{
    // Fügt nur die CL pro Click der Gesammtmenge hinzu
    codeLines += clpClick;
}

// Hauptfunktion für den Hardware-Kauf
void MainWindow::buyHardware(int h_id){

    // Wenn genug Geld da ist
    if (codeLines >= hardware[h_id].cost){

        // Wird der Kaufbetrag von den vorhandenen CL abgezogen
        codeLines = codeLines - hardware[h_id].cost;

        // Vorhandene Anzahl erhöhen
        hardware[h_id].counter++;

        // Neue kosten berechnen
        hardware[h_id].cost = hardware[h_id].cost * hardware[h_id].costMulti;

        switch(h_id){

                    // Erneuere die angezeigten Kosten im richtigen Feld
            case 0: this->ui->hardwareCost_0->setText(QLocale(QLocale::English).toString(hardware[h_id].cost, 'f', 0));

                    // Erneuere die Nummer schon gekaufter Einheiten
                    this->ui->hardwareCount_0->setNum(hardware[h_id].counter);

                    // Falls es der erstmalige Kauf ist
                    if (hardware[h_id].counter == 1){

                        // Wird die nächste Hardware zum Kauf freigeschaltet
                        this->ui->hardwareFrame_1->show();

                        // Die Upgrades für diese Hardware freigeschaltet
                        this->ui->upgradeFrameCoffee_1->show();

                        // Sowie eine News im Headline angezeigt
                        this->ui->labelHeadline->setText("News: Eilmeldung! Leider müssen wir unseren Bericht über den umgefallenen Sack Reis unterbrechen, da sich ein Programmierer aus Bremen scheinbar eine Tasse Kaffee aufgesetzt hat!");
                    }
            break;

            case 1: this->ui->hardwareCost_1->setText(QLocale(QLocale::English).toString(hardware[h_id].cost, 'f', 0));
                    this->ui->hardwareCount_1->setNum(hardware[h_id].counter);
                    if (hardware[h_id].counter == 1){
                        this->ui->hardwareFrame_2->show();
                        this->ui->upgradeFrameTama_1->show();
                        this->ui->labelHeadline->setText("News: Nachdem sich My-Little-Pony unter Computer-versierten Erwachsenen eine immense Fanbase aufgebaut hat, scheint der 90er Hit „Tamagochis“ das nächste Ziel der sogenannten „Bronies“ zu sein.");
                    }
            break;

            case 2: this->ui->hardwareCost_2->setText(QLocale(QLocale::English).toString(hardware[h_id].cost, 'f', 0));
                    this->ui->hardwareCount_2->setNum(hardware[h_id].counter);
                    if (hardware[h_id].counter == 1){
                        this->ui->hardwareFrame_3->show();
                        this->ui->upgradeFrameCalc_1->show();
                        this->ui->labelHeadline->setText("News: Aktien für Taschenrechner hoch im Kurs: Statistisches Bundesamt veröffentlicht Statistik, nach der der hohe Bedarf an Mathematik noch mindestens 25 Jahre anhält. Forscher suchen schon heute nach alternativen die weniger kompliziert und langweilig sind. ");
                    }
            break;

            case 3: this->ui->hardwareCost_3->setText(QLocale(QLocale::English).toString(hardware[h_id].cost, 'f', 0));
                    this->ui->hardwareCount_3->setNum(hardware[h_id].counter);
                    if (hardware[h_id].counter == 1){
                        this->ui->hardwareFrame_4->show();
                        this->ui->upgradeFrameArduino_1->show();
                        this->ui->labelHeadline->setText("News: Mann stellt einen voll funktionsfähigen PC aus Arduino-Teilen fertig, auf dem erfolgreich Windows Vista installiert werden konnte. „2007 erschien mir das eine gute Idee“, sagt der heute etwas enttäuschte Hobby-Bastler.");
                    }
            break;

            case 4: this->ui->hardwareCost_4->setText(QLocale(QLocale::English).toString(hardware[h_id].cost, 'f', 0));
                    this->ui->hardwareCount_4->setNum(hardware[h_id].counter);
                    if (hardware[h_id].counter == 1){
                        this->ui->hardwareFrame_5->show();
                        this->ui->upgradeFrameSmart_1->show();
                        this->ui->labelHeadline->setText("News: Apple gratuliert zur Neujahrsfeier: Apple CEO Cook stellte auf der Vollversammlung die letzten Finanzdaten des Jahres dar und wünschte allen Anwesenden ein erfolgreiches Jahr 2015S.");
                    }
            break;

            case 5: this->ui->hardwareCost_5->setText(QLocale(QLocale::English).toString(hardware[h_id].cost, 'f', 0));
                    this->ui->hardwareCount_5->setNum(hardware[h_id].counter);
                    if (hardware[h_id].counter == 1){
                        this->ui->hardwareFrame_6->show();
                        this->ui->upgradeFrameTablet_1->show();
                        this->ui->labelHeadline->setText("++BREAKING NEWS!! MUST SEE!!++ Studie: Digitaler Klickbait wird immer schlimmer. ++BREAKING NEWS!! MUST SEE++");
                    }
            break;

            case 6: this->ui->hardwareCost_6->setText(QLocale(QLocale::English).toString(hardware[h_id].cost, 'f', 0));
                    this->ui->hardwareCount_6->setNum(hardware[h_id].counter);
                    if (hardware[h_id].counter == 1){
                        this->ui->hardwareFrame_7->show();
                        this->ui->upgradeFrameNote_1->show();
                        this->ui->labelHeadline->setText("News: Starbucks erschließt neue Märkte: Ab Februar 2018 soll es in allen Starbucks Filialen Ray-Ben Brillen und Apple Notebooks zum Ausleihen geben, um auch niedrigere Gesellschaftsschichten anzusprechen. Trotz der etwas fragwürdigen Strategie sind sich die Experten zumindest einig, dass der absurde Preis für einen Becher Kaffee dann endlich gerechtfertigt sei.");
                    }
            break;

            case 7: this->ui->hardwareCost_7->setText(QLocale(QLocale::English).toString(hardware[h_id].cost, 'f', 0));
                    this->ui->hardwareCount_7->setNum(hardware[h_id].counter);
                    if (hardware[h_id].counter == 1){
                        this->ui->hardwareFrame_8->show();
                        this->ui->upgradeFramePc_1->show();
                        this->ui->labelHeadline->setText("News: Nutzer beendet Streit: Nach Jahren der Diskussion hat der Nutzer xXPPSlayer98Xx in einem umfangreichen Foren-Post klargestellt, dass PC und Spiel-Konsole ihre eigenen Stärken haben und daher kein System besser als das andere ist. Nutzer reagierten einsichtig und die Debatten scheinen endgültig zum Erliegen gekommen zu sein. ");
                    }
            break;

            case 8: this->ui->hardwareCost_8->setText(QLocale(QLocale::English).toString(hardware[h_id].cost, 'f', 0));
                    this->ui->hardwareCount_8->setNum(hardware[h_id].counter);
                    if (hardware[h_id].counter == 1){
                        this->ui->hardwareFrame_9->show();
                        this->ui->upgradeFrameCodeInc_1->show();
                        this->ui->labelHeadline->setText("News: Neuer globaler Player betritt den Markt: Ein unbekannter Spieler hat den hart umkämpften Markt der Rechenzentren betreten und versucht alt-eingesessene Unternehmen zu verdrängen. „Mir fällt das alles relativ leicht, da ich im Grunde nur am PC sitze und imaginären Zahlen beim größer-werden zuschaue“ kommentierte der unbekannte Spieler.");
                    }
            break;

            case 9: this->ui->hardwareCost_9->setText(QLocale(QLocale::English).toString(hardware[h_id].cost, 'f', 0));
                    this->ui->hardwareCount_9->setNum(hardware[h_id].counter);
                    if (hardware[h_id].counter == 1){
                        this->ui->upgradeFrameNeuro_1->show();
                        this->ui->labelHeadline->setText("News: Neuro-Informatik auf dem Vormarsch: Während deutsche Technologie-Konzerne damit hadern die neuen Möglichkeiten zu nutzen, wurden schon zwei pornografische Neuro-Produktionen einen Oskar nominiert. Kritiker sprechen von einer „spürbaren Tiefe“ und einem „gewissen Mitten-Drin-Gefühl“. ");
                    }
            break;
        }

    // Update aller relevanten Werte sowie Label
    updateClpSecLabel();
    updateClpClickLabel();
    updateHardwareToolTip(0);


    } else {
        // Wenn die Code-Lines nicht reichen wird die Warnung ausgegeben
        this->ui->labelHeadline->setText("Nicht genug Lines of Code!");
    }
}

// Hauptfunktion für den Upgrade-Kauf
bool MainWindow::buyUpgrade(int h_id, struct struct_upgrade *u_ptr){

    // Prüfen ob das Geld reicht
    if (u_ptr->cost <= codeLines){

        // Preis abziehen
        codeLines -= u_ptr->cost;

        // Neue Basis CL pro Sekunde der jeweiligen Hardware berechnen
        hardware[h_id].h_baseClpSec = hardware[h_id].h_baseClpSec * u_ptr->multi;

        // Neue globale CL pro Sekunde/Click berechnen
        updateClpSecLabel();
        updateClpClickLabel();
        updateHardwareToolTip(h_id);

        // Witz ausgeben
        // Immer jeweils beim 1, 3 und 4 Upgrade
        if ( (u_ptr->id == 1) || (u_ptr->id == 3) || (u_ptr->id == 4)){
            printJoke();
        }

        // Erfolgreiche Transaktion zurückgeben
        return true;

    } else {
        // Sonst angeben dass das Geld nicht reicht und false zurückgeben
        this->ui->labelHeadline->setText("Nicht genug Lines of Code!");
        return false;
    }

}

// Hauptfunktion für den Kaffee-Upgrade-Kauf
bool MainWindow::buyUpgradeCoffee(int u_id, struct struct_upgradeCoffee *u_ptr){

    // Prüfen ob das Geld reicht
    if (u_ptr->cost <= codeLines){

        // Preis abziehen
        codeLines = codeLines - u_ptr->cost;

        // Neue allgemeine Klickstärke pro Kaffee berechnen
        clpClickCoffee = clpClickCoffee * u_ptr->multi;

        // Prozente von den CL pro Sekunde, die der Klickstärke hinzugefügt werden
        clpClickPercent = clpClickPercent + u_ptr->clpClickPercent;

        // Neue globale CL pro Sekunde/Click berechnen
        updateClpSecLabel();
        updateClpClickLabel();
        updateHardwareToolTip(0);

        // Witz ausgeben
        if ( (u_ptr->id == 1) || (u_ptr->id == 3) || (u_ptr->id == 4)){
            printJoke();
        }

        // Erfolgreiche Transaktion zurückgeben
        return true;

    } else {
        // Sonst angeben dass das Geld nicht reicht und false zurückgeben
        this->ui->labelHeadline->setText("Nicht genug Lines of Code!");
        return false;
    }

}

// Aktualisiert die Klickstärke und das entsprechende Label
void MainWindow::updateClpClickLabel(){

    // Anzahl Kaffe * Klickstärke Kaffee, hier wurde eine Rechnung nachträglich entfernt!
    clpClick = (clpClickCoffee * hardware[0].counter); //+ (clpSec * clpClickPercent);

    // Falls prozentuale Boni zu addieren sind
    if (clpClickCoffee != 0.00){
        clpClick = clpClickPercent * clpSec * hardware[0].counter + clpClick;
    }

    // Label-Update
    this->ui->labelLoCpClick->setText(QLocale(QLocale::English).toString(clpClick, 'f', 0));
}

// Aktualisiert die CL pro Sekunde und das entsprechende Label
void MainWindow::updateClpSecLabel(){
    clpSec = 0;
    for (int i = 0; i < 10; i++){
        clpSec = hardware[i].counter * hardware[i].h_baseClpSec + clpSec;
    }
    this->ui->labelLoCpS->setText(QLocale(QLocale::English).toString(clpSec, 'f', 0));
}

// Aktualisiert den ToolTip einer angegebenen Hardware
void MainWindow::updateHardwareToolTip(int h_id){

    QString tempToolTip = "Diese Hardware erzeugt ";
    QString tempToolTip2 = "CL pro Sekunde";

    switch (h_id){
        case 0:this->ui->hardwareFrame_0->setToolTip("Ein Becher Kaffee gibt +" + QLocale(QLocale::English).toString(clpClickCoffee + (clpSec * clpClickPercent),  'f', 0) + " pro Klick.");break;
        case 1:this->ui->hardwareFrame_1->setToolTip(tempToolTip + QLocale(QLocale::English).toString(hardware[1].h_baseClpSec, 'f', 0) + tempToolTip2); break;
        case 2:this->ui->hardwareFrame_2->setToolTip(tempToolTip + QLocale(QLocale::English).toString(hardware[2].h_baseClpSec, 'f', 0) + tempToolTip2); break;
        case 3:this->ui->hardwareFrame_3->setToolTip(tempToolTip + QLocale(QLocale::English).toString(hardware[3].h_baseClpSec, 'f', 0) + tempToolTip2); break;
        case 4:this->ui->hardwareFrame_4->setToolTip(tempToolTip + QLocale(QLocale::English).toString(hardware[4].h_baseClpSec, 'f', 0) + tempToolTip2); break;
        case 5:this->ui->hardwareFrame_5->setToolTip(tempToolTip + QLocale(QLocale::English).toString(hardware[5].h_baseClpSec, 'f', 0) + tempToolTip2); break;
        case 6:this->ui->hardwareFrame_6->setToolTip(tempToolTip + QLocale(QLocale::English).toString(hardware[6].h_baseClpSec, 'f', 0) + tempToolTip2); break;
        case 7:this->ui->hardwareFrame_7->setToolTip(tempToolTip + QLocale(QLocale::English).toString(hardware[7].h_baseClpSec, 'f', 0) + tempToolTip2); break;
        case 8:this->ui->hardwareFrame_8->setToolTip(tempToolTip + QLocale(QLocale::English).toString(hardware[8].h_baseClpSec, 'f', 0) + tempToolTip2); break;
        case 9:this->ui->hardwareFrame_9->setToolTip(tempToolTip + QLocale(QLocale::English).toString(hardware[9].h_baseClpSec, 'f', 0) + tempToolTip2); break;
    }
}

// Gibt einen Witz aus
void MainWindow::printJoke(){

    // Sollte der Counter die Liste abgearbeitet haben fängt er von vorne an
    if (jokeCounter == (sizeof(jokes)/sizeof(jokes[0]))) jokeCounter = 0;

    this->ui->labelHeadline->setText(jokes[jokeCounter]);

    jokeCounter++;
}

// Buttons für Hardware
void MainWindow::on_buyHardware_0_clicked()
{
    buyHardware(0);
}
void MainWindow::on_buyHardware_1_clicked()
{
    buyHardware(1);
}
void MainWindow::on_buyHardware_2_clicked()
{
    buyHardware(2);
}
void MainWindow::on_buyHardware_3_clicked()
{
    buyHardware(3);
}
void MainWindow::on_buyHardware_4_clicked()
{
    buyHardware(4);
}
void MainWindow::on_buyHardware_5_clicked()
{
    buyHardware(5);
}
void MainWindow::on_buyHardware_6_clicked()
{
    buyHardware(6);
}
void MainWindow::on_buyHardware_7_clicked()
{
    buyHardware(7);
}
void MainWindow::on_buyHardware_8_clicked()
{
    buyHardware(8);
}
void MainWindow::on_buyHardware_9_clicked()
{
    buyHardware(9);
}

/*
 *Upgrade-Kauf
    Dabei wird das jeweils gekaufte Upgrade wieder
    entfernt und das nächste in der Reihenfolge angezeigt.
    Zudem wird das Bild der entsprechenden Hardware aktualisiert.
*/
void MainWindow::on_buyUpgradeCoffee_1_clicked()
{
    if ( buyUpgradeCoffee(0, &u_coffee[0]) ){
        this->ui->upgradeFrameCoffee_1->hide();
        this->ui->upgradeFrameCoffee_2->show();
        QPixmap image(":/images/u_coffee_1.png");
        this->ui->hardwareImg_0->setPixmap(image);
    }
}
void MainWindow::on_buyUpgradeCoffee_2_clicked()
{
    if ( buyUpgradeCoffee(0, &u_coffee[1]) ){
        this->ui->upgradeFrameCoffee_2->hide();
        this->ui->upgradeFrameCoffee_3->show();
        QPixmap image(":/images/u_coffee_2.png");
        this->ui->hardwareImg_0->setPixmap(image);
    }
}
void MainWindow::on_buyUpgradeCoffee_3_clicked()
{
    if ( buyUpgradeCoffee(0, &u_coffee[2]) ){
        this->ui->upgradeFrameCoffee_3->hide();
        this->ui->upgradeFrameCoffee_4->show();
        QPixmap image(":/images/u_coffee_3.png");
        this->ui->hardwareImg_0->setPixmap(image);
    }
}
void MainWindow::on_buyUpgradeCoffee_4_clicked()
{
    if ( buyUpgradeCoffee(0, &u_coffee[3]) ){
        this->ui->upgradeFrameCoffee_4->hide();
        this->ui->upgradeFrameCoffee_5->show();
        QPixmap image(":/images/u_coffee_4.png");
        this->ui->hardwareImg_0->setPixmap(image);
    }
}
void MainWindow::on_buyUpgradeCoffee_5_clicked()
{
    if ( buyUpgradeCoffee(0, &u_coffee[4]) ){
        this->ui->upgradeFrameCoffee_5->hide();
        QPixmap image(":/images/u_coffee_5.png");
        this->ui->hardwareImg_0->setPixmap(image);
    }
}
void MainWindow::on_buyUpgradeTama_1_clicked()
{
    if(buyUpgrade(1, &u_tama[0])){
        this->ui->upgradeFrameTama_1->hide();
        this->ui->upgradeFrameTama_2->show();
        QPixmap image(":/images/u_tama_1.png");
        this->ui->hardwareImg_1->setPixmap(image);
    }
}
void MainWindow::on_buyUpgradeTama_2_clicked()
{
    if(buyUpgrade(1, &u_tama[1])){
        this->ui->upgradeFrameTama_2->hide();
        this->ui->upgradeFrameTama_3->show();
        QPixmap image(":/images/u_tama_2.png");
        this->ui->hardwareImg_1->setPixmap(image);
    }
}
void MainWindow::on_buyUpgradeTama_3_clicked()
{
    if(buyUpgrade(1, &u_tama[2])){
        this->ui->upgradeFrameTama_3->hide();
        this->ui->upgradeFrameTama_4->show();
        QPixmap image(":/images/u_tama_3.png");
        this->ui->hardwareImg_1->setPixmap(image);
    }
}
void MainWindow::on_buyUpgradeTama_4_clicked()
{
    if(buyUpgrade(1, &u_tama[3])){
        this->ui->upgradeFrameTama_4->hide();
        this->ui->upgradeFrameTama_5->show();
        QPixmap image(":/images/u_tama_4.png");
        this->ui->hardwareImg_1->setPixmap(image);
    }
}
void MainWindow::on_buyUpgradeTama_5_clicked()
{
    if(buyUpgrade(1, &u_tama[4])){
        this->ui->upgradeFrameTama_5->hide();
        QPixmap image(":/images/u_tama_5.png");
        this->ui->hardwareImg_1->setPixmap(image);
    }
}
void MainWindow::on_buyUpgradeCalc_1_clicked()
{
    if(buyUpgrade(2, &u_calc[0])){
        this->ui->upgradeFrameCalc_1->hide();
        this->ui->upgradeFrameCalc_2->show();
        QPixmap image(":/images/u_calc_1.png");
        this->ui->hardwareImg_2->setPixmap(image);
    }
}
void MainWindow::on_buyUpgradeCalc_2_clicked()
{
    if(buyUpgrade(2, &u_calc[1])){
        this->ui->upgradeFrameCalc_2->hide();
        this->ui->upgradeFrameCalc_3->show();
        QPixmap image(":/images/u_calc_2.png");
        this->ui->hardwareImg_2->setPixmap(image);
    }
}
void MainWindow::on_buyUpgradeCalc_3_clicked()
{
    if(buyUpgrade(2, &u_calc[2])){
        this->ui->upgradeFrameCalc_3->hide();
        this->ui->upgradeFrameCalc_4->show();
        QPixmap image(":/images/u_calc_3.png");
        this->ui->hardwareImg_2->setPixmap(image);
    }
}
void MainWindow::on_buyUpgradeCalc_4_clicked()
{
    if(buyUpgrade(2, &u_calc[3])){
        this->ui->upgradeFrameCalc_4->hide();
        this->ui->upgradeFrameCalc_5->show();
        QPixmap image(":/images/u_calc_4.png");
        this->ui->hardwareImg_2->setPixmap(image);
    }
}
void MainWindow::on_buyUpgradeCalc_5_clicked()
{
    if(buyUpgrade(2, &u_calc[4])){
        this->ui->upgradeFrameCalc_5->hide();
        QPixmap image(":/images/u_calc_5.png");
        this->ui->hardwareImg_2->setPixmap(image);
    }
}
void MainWindow::on_buyUpgradeArduino_1_clicked()
{
    if(buyUpgrade(3, &u_arduino[0])){
        this->ui->upgradeFrameArduino_1->hide();
        this->ui->upgradeFrameArduino_2->show();
        QPixmap image(":/images/u_arduino_1.png");
        this->ui->hardwareImg_3->setPixmap(image);
    }
}
void MainWindow::on_buyUpgradeArduino_2_clicked()
{
    if(buyUpgrade(3, &u_arduino[1])){
        this->ui->upgradeFrameArduino_2->hide();
        this->ui->upgradeFrameArduino_3->show();
        QPixmap image(":/images/u_arduino_2.png");
        this->ui->hardwareImg_3->setPixmap(image);
    }
}
void MainWindow::on_buyUpgradeArduino_3_clicked()
{
    if(buyUpgrade(3, &u_arduino[2])){
        this->ui->upgradeFrameArduino_3->hide();
        this->ui->upgradeFrameArduino_4->show();
        QPixmap image(":/images/u_arduino_3.png");
        this->ui->hardwareImg_3->setPixmap(image);
    }
}
void MainWindow::on_buyUpgradeArduino_4_clicked()
{
    if(buyUpgrade(3, &u_arduino[3])){
        this->ui->upgradeFrameArduino_4->hide();
        this->ui->upgradeFrameArduino_5->show();
        QPixmap image(":/images/u_arduino_4.png");
        this->ui->hardwareImg_3->setPixmap(image);
    }
}
void MainWindow::on_buyUpgradeArduino_5_clicked()
{
    if(buyUpgrade(3, &u_arduino[4])){
        this->ui->upgradeFrameArduino_5->hide();
        QPixmap image(":/images/u_arduino_5.png");
        this->ui->hardwareImg_3->setPixmap(image);
    }
}
void MainWindow::on_buyUpgradeSmart_1_clicked()
{
    if(buyUpgrade(4, &u_smart[0])){
        this->ui->upgradeFrameSmart_1->hide();
        this->ui->upgradeFrameSmart_2->show();
        QPixmap image(":/images/u_smartphone_1.png");
        this->ui->hardwareImg_4->setPixmap(image);
    }
}
void MainWindow::on_buyUpgradeSmart_2_clicked()
{
    if(buyUpgrade(4, &u_smart[1])){
        this->ui->upgradeFrameSmart_2->hide();
        this->ui->upgradeFrameSmart_3->show();
        QPixmap image(":/images/u_smartphone_2.png");
        this->ui->hardwareImg_4->setPixmap(image);
    }
}
void MainWindow::on_buyUpgradeSmart_3_clicked()
{
    if(buyUpgrade(4, &u_smart[2])){
        this->ui->upgradeFrameSmart_3->hide();
        this->ui->upgradeFrameSmart_4->show();
        QPixmap image(":/images/u_smartphone_3.png");
        this->ui->hardwareImg_4->setPixmap(image);
    }
}
void MainWindow::on_buyUpgradeSmart_4_clicked()
{
    if(buyUpgrade(4, &u_smart[3])){
        this->ui->upgradeFrameSmart_4->hide();
        this->ui->upgradeFrameSmart_5->show();
        QPixmap image(":/images/u_smartphone_4.png");
        this->ui->hardwareImg_4->setPixmap(image);
    }
}
void MainWindow::on_buyUpgradeSmart_5_clicked()
{
    if(buyUpgrade(4, &u_smart[4])){
        this->ui->upgradeFrameSmart_5->hide();
        QPixmap image(":/images/u_smartphone_5.png");
        this->ui->hardwareImg_4->setPixmap(image);
    }
}
void MainWindow::on_buyUpgradeTablet_1_clicked()
{
    if(buyUpgrade(5, &u_tablet[0])){
        this->ui->upgradeFrameTablet_1->hide();
        this->ui->upgradeFrameTablet_2->show();
        QPixmap image(":/images/u_tablet_1.png");
        this->ui->hardwareImg_5->setPixmap(image);
    }
}
void MainWindow::on_buyUpgradeTablet_2_clicked()
{
    if(buyUpgrade(5, &u_tablet[1])){
        this->ui->upgradeFrameTablet_2->hide();
        this->ui->upgradeFrameTablet_3->show();
        QPixmap image(":/images/u_tablet_2.png");
        this->ui->hardwareImg_5->setPixmap(image);
    }
}
void MainWindow::on_buyUpgradeTablet_3_clicked()
{
    if(buyUpgrade(5, &u_tablet[2])){
        this->ui->upgradeFrameTablet_3->hide();
        this->ui->upgradeFrameTablet_4->show();
        QPixmap image(":/images/u_tablet_3.png");
        this->ui->hardwareImg_5->setPixmap(image);
    }
}
void MainWindow::on_buyUpgradeTablet_4_clicked()
{
    if(buyUpgrade(5, &u_tablet[3])){
        this->ui->upgradeFrameTablet_4->hide();
        this->ui->upgradeFrameTablet_5->show();
        QPixmap image(":/images/u_tablet_4.png");
        this->ui->hardwareImg_5->setPixmap(image);
    }
}
void MainWindow::on_buyUpgradeTablet_5_clicked()
{
    if(buyUpgrade(5, &u_tablet[4])){
        this->ui->upgradeFrameTablet_5->hide();
        QPixmap image(":/images/u_tablet_5.png");
        this->ui->hardwareImg_5->setPixmap(image);
    }
}
void MainWindow::on_buyUpgradeNote_1_clicked()
{
    if(buyUpgrade(6, &u_note[0])){
        this->ui->upgradeFrameNote_1->hide();
        this->ui->upgradeFrameNote_2->show();
        QPixmap image(":/images/u_notebook_1.png");
        this->ui->hardwareImg_6->setPixmap(image);
    }
}
void MainWindow::on_buyUpgradeNote_2_clicked()
{
    if(buyUpgrade(6, &u_note[1])){
        this->ui->upgradeFrameNote_2->hide();
        this->ui->upgradeFrameNote_3->show();
        QPixmap image(":/images/u_notebook_2.png");
        this->ui->hardwareImg_6->setPixmap(image);
    }
}
void MainWindow::on_buyUpgradeNote_3_clicked()
{
    if(buyUpgrade(6, &u_note[2])){
        this->ui->upgradeFrameNote_3->hide();
        this->ui->upgradeFrameNote_4->show();
        QPixmap image(":/images/u_notebook_3.png");
        this->ui->hardwareImg_6->setPixmap(image);
    }
}
void MainWindow::on_buyUpgradeNote_4_clicked()
{
    if(buyUpgrade(6, &u_note[3])){
        this->ui->upgradeFrameNote_4->hide();
        this->ui->upgradeFrameNote_5->show();
        QPixmap image(":/images/u_notebook_4.png");
        this->ui->hardwareImg_6->setPixmap(image);
    }
}
void MainWindow::on_buyUpgradeNote_5_clicked()
{
    if(buyUpgrade(6, &u_note[4])){
        this->ui->upgradeFrameNote_5->hide();
        QPixmap image(":/images/u_notebook_5.png");
        this->ui->hardwareImg_6->setPixmap(image);
    }
}
void MainWindow::on_buyUpgradePc_1_clicked()
{
    if(buyUpgrade(7, &u_pc[0])){
        this->ui->upgradeFramePc_1->hide();
        this->ui->upgradeFramePc_2->show();
        QPixmap image(":/images/u_desktop_1.png");
        this->ui->hardwareImg_7->setPixmap(image);
    }
}
void MainWindow::on_buyUpgradePc_2_clicked()
{
    if(buyUpgrade(7, &u_pc[1])){
        this->ui->upgradeFramePc_2->hide();
        this->ui->upgradeFramePc_3->show();
        QPixmap image(":/images/u_desktop_2.png");
        this->ui->hardwareImg_7->setPixmap(image);
    }
}
void MainWindow::on_buyUpgradePc_3_clicked()
{
    if(buyUpgrade(7, &u_pc[2])){
        this->ui->upgradeFramePc_3->hide();
        this->ui->upgradeFramePc_4->show();
        QPixmap image(":/images/u_desktop_3.png");
        this->ui->hardwareImg_7->setPixmap(image);
    }
}
void MainWindow::on_buyUpgradePc_4_clicked()
{
    if(buyUpgrade(7, &u_pc[3])){
        this->ui->upgradeFramePc_4->hide();
        this->ui->upgradeFramePc_5->show();
        QPixmap image(":/images/u_desktop_4.png");
        this->ui->hardwareImg_7->setPixmap(image);
    }
}
void MainWindow::on_buyUpgradePc_5_clicked()
{
    if(buyUpgrade(7, &u_pc[4])){
        this->ui->upgradeFramePc_5->hide();
        QPixmap image(":/images/u_desktop_5.png");
        this->ui->hardwareImg_7->setPixmap(image);
    }
}
void MainWindow::on_buyUpgradeCodeInc_1_clicked()
{
    if(buyUpgrade(8, &u_codeinc[0])){
        this->ui->upgradeFrameCodeInc_1->hide();
        this->ui->upgradeFrameCodeInc_2->show();
        QPixmap image(":/images/u_codeinc_1.png");
        this->ui->hardwareImg_8->setPixmap(image);
    }
}
void MainWindow::on_buyUpgradeCodeInc_2_clicked()
{
    if(buyUpgrade(8, &u_codeinc[1])){
        this->ui->upgradeFrameCodeInc_2->hide();
        this->ui->upgradeFrameCodeInc_3->show();
        QPixmap image(":/images/u_codeinc_2.png");
        this->ui->hardwareImg_8->setPixmap(image);
    }
}
void MainWindow::on_buyUpgradeCodeInc_3_clicked()
{
    if(buyUpgrade(8, &u_codeinc[2])){
        this->ui->upgradeFrameCodeInc_3->hide();
        this->ui->upgradeFrameCodeInc_4->show();
        QPixmap image(":/images/u_codeinc_3.png");
        this->ui->hardwareImg_8->setPixmap(image);
    }
}
void MainWindow::on_buyUpgradeCodeInc_4_clicked()
{
    if(buyUpgrade(8, &u_codeinc[3])){
        this->ui->upgradeFrameCodeInc_4->hide();
        this->ui->upgradeFrameCodeInc_5->show();
        QPixmap image(":/images/u_codeinc_4.png");
        this->ui->hardwareImg_8->setPixmap(image);
    }
}
void MainWindow::on_buyUpgradeCodeInc_5_clicked()
{
    if(buyUpgrade(8, &u_codeinc[4])){
        this->ui->upgradeFrameCodeInc_5->hide();
        QPixmap image(":/images/u_codeinc_5.png");
        this->ui->hardwareImg_8->setPixmap(image);
    }
}
void MainWindow::on_buyUpgradeNeuro_1_clicked()
{
    if(buyUpgrade(9, &u_neuro[0])){
        this->ui->upgradeFrameNeuro_1->hide();
        this->ui->upgradeFrameNeuro_2->show();
        QPixmap image(":/images/u_neuro_1.png");
        this->ui->hardwareImg_9->setPixmap(image);
    }
}
void MainWindow::on_buyUpgradeNeuro_2_clicked()
{
    if(buyUpgrade(9, &u_neuro[1])){
        this->ui->upgradeFrameNeuro_2->hide();
        this->ui->upgradeFrameNeuro_3->show();
        QPixmap image(":/images/u_neuro_2.png");
        this->ui->hardwareImg_9->setPixmap(image);
    }
}
void MainWindow::on_buyUpgradeNeuro_3_clicked()
{
    if(buyUpgrade(9, &u_neuro[2])){
        this->ui->upgradeFrameNeuro_3->hide();
        this->ui->upgradeFrameNeuro_4->show();
        QPixmap image(":/images/u_neuro_3.png");
        this->ui->hardwareImg_9->setPixmap(image);
    }
}
void MainWindow::on_buyUpgradeNeuro_4_clicked()
{
    if(buyUpgrade(9, &u_neuro[3])){
        this->ui->upgradeFrameNeuro_4->hide();
        this->ui->upgradeFrameNeuro_5->show();
        QPixmap image(":/images/u_neuro_4.png");
        this->ui->hardwareImg_9->setPixmap(image);
    }
}
void MainWindow::on_buyUpgradeNeuro_5_clicked()
{
    if(buyUpgrade(9, &u_neuro[4])){
        this->ui->upgradeFrameNeuro_5->hide();
        QPixmap image(":/images/u_neuro_5.png");
        this->ui->hardwareImg_9->setPixmap(image);
    }
}

// Cheats die den gewollten Wert verstärken.
// Haben keinen Einfluss auf die Anzeigen der Labels
void MainWindow::on_actionCL_pro_Sekunde_triggered()
{
    if (clpSec == 0 ) clpSec = 1000000;
    clpSec *= 1000000;
}

void MainWindow::on_actionCL_pro_Klick_triggered()
{
    clpClick *= 1000000;
}

void MainWindow::on_actionCL_auf_0_setzen_triggered()
{
    codeLines = 0;
}
