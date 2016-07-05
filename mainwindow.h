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
        double          clpClickPercent;
        double          clpClickCoffee;
        double          codeLines;

        void            buyHardware(int h_id);
        void            updateClpClickLabel();
        void            updateClpSecLabel();
        void            updateHardwareToolTip(int h_id);



        struct struct_hardware {

            int     id;
            int     counter;

            double  baseCost;
            double  cost;
            double  costMulti;
            double  h_baseClpSec;
            double  h_clpSec;

            bool    access;

        }   hardware[10] =  {   { 0, 0,           15,           15,      1.15,       0,       1, false},
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
            double  clpClickPercent;
            double  multi;

        }   u_coffee[5]     = { { 0,       100, 0,      0, 2},
                                { 1,       500, 0,  0.005, 4},
                                { 2,    100000, 0,  0.003, 6},
                                { 3,  10000000, 0,  0.002, 8},
                                { 4, 100000000, 0,  0.001, 10}};

        struct struct_upgrade {

            int     id;

            double  cost;
            double  clpSec;
            double  clpClick;
            double  multi;


        }   u_tama[5]       = { { 0,                     1000,    0, 0, 2},
                                { 1,                     5000,    0, 0, 4},
                                { 2,                    50000,    0, 0, 6},
                                { 3,                   500000,    0, 0, 8},
                                { 4,                 50000000,    0, 0, 10}},

            u_calc[5]       = { { 0,                     13000,   0, 0, 2},
                                { 1,                     65000,   0, 0, 4},
                                { 2,                    650000,   0, 0, 6},
                                { 3,                   6500000,   0, 0, 8},
                                { 4,                 650000000,   0, 0, 10}},

            u_arduino[5]    = { { 0,                    150000,   0, 0, 2},
                                { 1,                    750000,   0, 0, 4},
                                { 2,                   7500000,   0, 0, 6},
                                { 3,                  75000000,   0, 0, 8},
                                { 4,                7500000000,   0, 0, 10}},

            u_smart[5]      = { { 0,                   1800000,   0, 0, 2},
                                { 1,                   9000000,   0, 0, 4},
                                { 2,                  90000000,   0, 0, 6},
                                { 3,                 900000000,   0, 0, 8},
                                { 4,               90000000000,   0, 0, 10}},

            u_tablet[5]     = { { 0,               62000000000,   0, 0, 2},
                                { 1,              310000000000,   0, 0, 4},
                                { 2,             3100000000000,   0, 0, 6},
                                { 3,            31000000000000,   0, 0, 8},
                                { 4,          3100000000000000,   0, 0, 10}},

            u_note[5]       = { { 0,              870000000000,   0, 0, 2},
                                { 1,             4350000000000,   0, 0, 4},
                                { 2,            43500000000000,   0, 0, 6},
                                { 3,           435000000000000,   0, 0, 8},
                                { 4,         43500000000000000,   0, 0, 10}},

            u_pc[5]         = { { 0,         12000000000000000,   0, 0, 2},
                                { 1,         60000000000000000,   0, 0, 4},
                                { 2,        600000000000000000,   0, 0, 6},
                                { 3,       6000000000000000000.0, 0, 0, 8},
                                { 4,     600000000000000000000.0, 0, 0, 10}},

            u_codeinc[5]    = { { 0,        150000000000000000.0, 0, 0, 2},
                                { 1,        750000000000000000.0, 0, 0, 4},
                                { 2,       7500000000000000000.0, 0, 0, 6},
                                { 3,      75000000000000000000.0, 0, 0, 8},
                                { 4,    7500000000000000000000.0, 0, 0, 10}},

            u_neuro[5]      = { { 0,       1900000000000000000.0, 0, 0, 2},
                                { 1,       9500000000000000000.0, 0, 0, 4},
                                { 2,      95000000000000000000.0, 0, 0, 6},
                                { 3,     950000000000000000000.0, 0, 0, 8},
                                { 4,   95000000000000000000000.0, 0, 0, 10}};

            bool            buyUpgrade(int h_id, struct struct_upgrade *u_ptr);
            bool            buyUpgradeCoffee(int u_id, struct struct_upgradeCoffee *u_ptr);

    // Slots für alle Knöpfe
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

        void on_buyUpgradeCoffee_1_clicked();

        void on_buyUpgradeCoffee_2_clicked();

        void on_buyUpgradeCoffee_3_clicked();

        void on_buyUpgradeCoffee_4_clicked();

        void on_buyUpgradeCoffee_5_clicked();

        void on_buyUpgradeTama_1_clicked();

        void on_buyUpgradeTama_2_clicked();

        void on_buyUpgradeTama_3_clicked();

        void on_buyUpgradeTama_4_clicked();

        void on_buyUpgradeTama_5_clicked();

        void on_buyUpgradeCalc_1_clicked();

        void on_buyUpgradeCalc_2_clicked();

        void on_buyUpgradeCalc_3_clicked();

        void on_buyUpgradeCalc_4_clicked();

        void on_buyUpgradeCalc_5_clicked();

        void on_buyUpgradeArduino_1_clicked();

        void on_buyUpgradeArduino_2_clicked();

        void on_buyUpgradeArduino_3_clicked();

        void on_buyUpgradeArduino_4_clicked();

        void on_buyUpgradeArduino_5_clicked();

        void on_buyUpgradeSmart_1_clicked();

        void on_buyUpgradeSmart_2_clicked();

        void on_buyUpgradeSmart_3_clicked();

        void on_buyUpgradeSmart_4_clicked();

        void on_buyUpgradeSmart_5_clicked();

        void on_buyUpgradeTablet_1_clicked();

        void on_buyUpgradeTablet_2_clicked();

        void on_buyUpgradeTablet_3_clicked();

        void on_buyUpgradeTablet_4_clicked();

        void on_buyUpgradeTablet_5_clicked();

        void on_buyUpgradeNote_1_clicked();

        void on_buyUpgradeNote_2_clicked();

        void on_buyUpgradeNote_3_clicked();

        void on_buyUpgradeNote_4_clicked();

        void on_buyUpgradeNote_5_clicked();

        void on_buyUpgradePc_1_clicked();

        void on_buyUpgradePc_2_clicked();

        void on_buyUpgradePc_3_clicked();

        void on_buyUpgradePc_4_clicked();

        void on_buyUpgradePc_5_clicked();

        void on_buyUpgradeCodeInc_1_clicked();

        void on_buyUpgradeCodeInc_2_clicked();

        void on_buyUpgradeCodeInc_3_clicked();

        void on_buyUpgradeCodeInc_4_clicked();

        void on_buyUpgradeCodeInc_5_clicked();

        void on_buyUpgradeNeuro_1_clicked();

        void on_buyUpgradeNeuro_2_clicked();

        void on_buyUpgradeNeuro_3_clicked();

        void on_buyUpgradeNeuro_4_clicked();

        void on_buyUpgradeNeuro_5_clicked();


private:
        Ui::MainWindow  *ui;
};








#endif // MAINWINDOW_H
