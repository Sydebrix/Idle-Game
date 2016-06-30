#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QElapsedTimer>
#include <QTimer>
#include <QWidget>
#include <QFrame>
#define COSTMULTI 1.12

namespace Ui {
  class MainWindow;
}

class MainWindow : public QMainWindow
{
  Q_OBJECT

    public:
        explicit    MainWindow(QWidget *parent = 0);
                    ~MainWindow();

        void paintEvent(QPaintEvent *);
        QElapsedTimer   elapsedTime;

        int             tempTime;

        void            update();

        double          clpSec;
        double          clpClick;
        double          clpCollected;
        double          globalMulti;
        double          clpPercent;
        double          clpClickCoffee;


        struct struct_hardware {

            int     id;
            int     counter;

            double  baseCost;
            double  cost;
            double  costMulti;
            double  baseLOCpS;
            double  LOCpS;

            bool    access;
        } hardware[10];

        struct struct_upgradeCoffee {

            double  cost;
            double  clpSec;
            double  clpClick;
            double  multi;
            void    buy();

        };



    private slots:

        void on_buyHardware_0_clicked();

        void on_buyHardware_1_clicked();

        void on_buyHardware_2_clicked();

        void on_buyHardware_3_clicked();

        void on_buyHardware_4_clicked();

        void on_buyHardware_5_clicked();

        void on_buyHardware_6_clicked();

        void on_buyHardware_7_clicked();

        void on_buyHardware_8_clicked();

        void on_buyHardware_9_clicked();

        void on_pushButtonLoc_clicked();

private:
        Ui::MainWindow  *ui;
        double           codeLines;
};








#endif // MAINWINDOW_H
