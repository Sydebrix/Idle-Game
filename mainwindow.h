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

            void    buy();
        } hardware[10] =  {     { 0, 0,           15,           15, COSTMULTI,       1,       1, false},
                                { 1, 0,          100,          100, COSTMULTI,       1,       1, false},
                                { 2, 0,         1100,         1100, COSTMULTI,       8,       8, false},
                                { 3, 0,        12000,        12000, COSTMULTI,      47,      47, false},
                                { 4, 0,       130000,       130000, COSTMULTI,     260,     260, false},
                                { 5, 0,      1400000,      1400000, COSTMULTI,    1400,    1400, false},
                                { 6, 0,    330000000,    330000000, COSTMULTI,    7800,    7800, false},
                                { 7, 0,   5100000000,   5100000000, COSTMULTI,   44000,   44000, false},
                                { 8, 0,  75000000000,  75000000000, COSTMULTI,  260000,  260000, false},
                                { 9, 0, 100000000000, 100000000000, COSTMULTI, 1600000, 1600000, false}};

        struct struct_upgradeCoffee {

            int     id;

            double  cost;
            double  clpSec;
            double  clpClick;
            double  multi;
            void    buy();

        }   u_coffee[5]     = { { 1,       100, 0.5, 0, 2,},
                                { 2,       500, 0.5, 0, 2,},
                                { 3,    100000, 0.5, 0, 2,},
                                { 4,  10000000, 0.5, 0, 2,},
                                { 5, 100000000, 0.5, 0, 2,}};

        struct struct_upgrade {

            int     id;

            double  cost;
            double  clpSec;
            double  clpClick;
            double  multi;

            void    buy();
            void    setFrame();

        }   u_tama[5]       = { { 1,                    1000,     0, 0, 2},
                                { 2,                    5000,     0, 0, 2},
                                { 3,                   50000,     0, 0, 2},
                                { 4,                 5000000,     0, 0, 2},
                                { 5,              5000000000,     0, 0, 2}},

            u_calc[5]       = { { 1,                    13000,    0, 0, 2},
                                { 2,                    65000,    0, 0, 2},
                                { 3,                   650000,    0, 0, 2},
                                { 4,                 65000000,    0, 0, 2},
                                { 5,              65000000000,    0, 0, 2}},

            u_arduino[5]    = { { 1,                   150000,    0, 0, 2},
                                { 2,                   750000,    0, 0, 2},
                                { 3,                  7500000,    0, 0, 2},
                                { 4,                750000000,    0, 0, 2},
                                { 5,             750000000000,    0, 0, 2}},

            u_smart[5]      = { { 1,                  1800000,    0, 0, 2},
                                { 2,                  9000000,    0, 0, 2},
                                { 3,                 90000000,    0, 0, 2},
                                { 4,               9000000000,    0, 0, 2},
                                { 5,            9000000000000,    0, 0, 2}},

            u_tablet[5]     = { { 1,              62000000000,    0, 0, 2},
                                { 2,             310000000000,    0, 0, 2},
                                { 3,            3100000000000,    0, 0, 2},
                                { 4,          310000000000000,    0, 0, 2},
                                { 5,       310000000000000000,    0, 0, 2}},

            u_note[5]       = { { 1,             870000000000,    0, 0, 2},
                                { 2,            4350000000000,    0, 0, 2},
                                { 3,           43500000000000,    0, 0, 2},
                                { 4,         4350000000000000,    0, 0, 2},
                                { 5,      4350000000000000000,    0, 0, 2}},

            u_pc[5]         = { { 1,        12000000000000000,    0, 0, 2},
                                { 2,        60000000000000000,    0, 0, 2},
                                { 3,       600000000000000000,    0, 0, 2},
                                { 4,     60000000000000000000.0,  0, 0, 2},
                                { 5,  60000000000000000000000.0,  0, 0, 2}},

            u_codeinc[5]    = { { 1,        150000000000000000.0, 0, 0, 2},
                                { 2,        750000000000000000.0, 0, 0, 2},
                                { 3,       7500000000000000000.0, 0, 0, 2},
                                { 4,     750000000000000000000.0, 0, 0, 2},
                                { 5,  750000000000000000000000.0, 0, 0, 2}},

            u_neuro[5]      = { { 1,       1900000000000000000.0, 0, 0, 2},
                                { 2,       9500000000000000000.0, 0, 0, 2},
                                { 3,      95000000000000000000.0, 0, 0, 2},
                                { 4,    9500000000000000000000.0, 0, 0, 2},
                                { 5, 9500000000000000000000000.0, 0, 0, 2}};



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
