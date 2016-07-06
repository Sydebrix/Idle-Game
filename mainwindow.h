#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QElapsedTimer>
#include <QTimer>
#include <QWidget>
#include <QFrame>
#include <QString>
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
        int             jokeCounter;

        double          clpSec          = 0;
        double          clpClick        = 1;
        double          clpClickPercent = 0.00;
        double          clpClickCoffee  = 1;
        double          codeLines       = 0;

        void            buyHardware(int h_id);
        void            updateClpClickLabel();
        void            updateClpSecLabel();
        void            updateHardwareToolTip(int h_id);
        void            printJoke();


        struct struct_hardware {

            int     id;
            // Anzahl gekauft
            int     counter;

            double  baseCost;
            double  cost;
            double  costMulti;
            double  h_baseClpSec;
            double  h_clpSec;

        }           hardware[10] =  {   { 0, 0,           15,           15,      1.15,        0,       1}, // Kaffee
                                        { 1, 0,          100,          100, COSTMULTI,        1,       1}, // Tamagochi
                                        { 2, 0,         1100,         1100, COSTMULTI,        8,       8}, // Taschenrechner
                                        { 3, 0,        12000,        12000, COSTMULTI,       47,      47}, // Arduino
                                        { 4, 0,       130000,       130000, COSTMULTI,      260,     260}, // Smartphone
                                        { 5, 0,      1400000,      1400000, COSTMULTI,     1400,    1400}, // Tablet
                                        { 6, 0,    330000000,    330000000, COSTMULTI,    78000,    7800}, // Notebook
                                        { 7, 0,   5100000000,   5100000000, COSTMULTI,   440000,   44000}, // PC
                                        { 8, 0,  75000000000,  75000000000, COSTMULTI,  2600000,  260000}, // CodeInc.
                                        { 9, 0, 100000000000, 100000000000, COSTMULTI, 16000000, 1600000}};// Neuro

        struct struct_upgradeCoffee {

            int     id;

            double  cost;
            double  clpSec;
            double  clpClickPercent;
            double  multi;

        }   u_coffee[5]     = { { 0,                     100, 0, 0,     2},
                                { 1,                     500, 0, 0.005, 4},
                                { 2,                  100000, 0, 0.003, 6},
                                { 3,                10000000, 0, 0.002, 8},
                                { 4,               100000000, 0, 0.001, 10}};

        struct struct_upgrade {

            int     id;

            double  cost;
            double  clpSec;
            double  clpClick;
            double  multi;


        }   u_tama[5]       = { { 0,                    1000,   0, 0, 2},
                                { 1,                    5000,   0, 0, 4},
                                { 2,                   50000,   0, 0, 6},
                                { 3,                  500000,   0, 0, 8},
                                { 4,                50000000,   0, 0, 10}},

            u_calc[5]       = { { 0,                   13000,   0, 0, 2},
                                { 1,                   65000,   0, 0, 4},
                                { 2,                  650000,   0, 0, 6},
                                { 3,                 6500000,   0, 0, 8},
                                { 4,               650000000,   0, 0, 10}},

            u_arduino[5]    = { { 0,                  150000,   0, 0, 2},
                                { 1,                  750000,   0, 0, 4},
                                { 2,                 7500000,   0, 0, 6},
                                { 3,                75000000,   0, 0, 8},
                                { 4,              7500000000,   0, 0, 10}},

            u_smart[5]      = { { 0,                 1800000,   0, 0, 2},
                                { 1,                 9000000,   0, 0, 4},
                                { 2,                90000000,   0, 0, 6},
                                { 3,               900000000,   0, 0, 8},
                                { 4,             90000000000,   0, 0, 10}},

            u_tablet[5]     = { { 0,               160000000,   0, 0, 4},
                                { 1,               780000000,   0, 0, 6},
                                { 2,              3100000000,   0, 0, 8},
                                { 3,             31000000000,   0, 0, 10},
                                { 4,           3100000000000,   0, 0, 13}},

            u_note[5]       = { { 0,              8700000000,   0, 0, 4},
                                { 1,              4350000000,   0, 0, 6},
                                { 2,             43500000000,   0, 0, 8},
                                { 3,            435000000000,   0, 0, 10},
                                { 4,          43500000000000,   0, 0, 15}},

            u_pc[5]         = { { 0,             12000000000,   0, 0, 4},
                                { 1,             60000000000,   0, 0, 6},
                                { 2,            600000000000,   0, 0, 8},
                                { 3,           6000000000000.0, 0, 0, 10},
                                { 4,         600000000000000.0, 0, 0, 20}},

            u_codeinc[5]    = { { 0,            150000000000.0, 0, 0, 4},
                                { 1,            750000000000.0, 0, 0, 6},
                                { 2,           7500000000000.0, 0, 0, 8},
                                { 3,          75000000000000.0, 0, 0, 20},
                                { 4,        7500000000000000.0, 0, 0, 50}},

            u_neuro[5]      = { { 0,           1900000000000.0, 0, 0, 4},
                                { 1,          95000000000000.0, 0, 0, 6},
                                { 2,         950000000000000.0, 0, 0, 8},
                                { 3,        9500000000000000.0, 0, 0, 30},
                                { 4,      950000000000000000.0, 0, 0, 100}};

            bool            buyUpgrade(int h_id, struct struct_upgrade *u_ptr);
            bool            buyUpgradeCoffee(int u_id, struct struct_upgradeCoffee *u_ptr);

            QString jokes[39] ={{"How many programmers do you need to change a lightbulb?\n– 0. It's a hardware problem."},
                                {"UNIX is the OS of the future. And has been for 30 years."},
                                {"What's in the water shouting F1?\nA programmer who can't swim."},
                                {"Telefonieren zwei Informatiker. Fragt der eine: „Und, wie ist das Wetter bei euch?“ „Caps Lock.“ „Häh?“ „Na, shift ohne Ende…“"},
                                {"Letzter Wunsch des Programmierers: „Bitte ein Bit.“"},
                                {"What does a programmer say after he was born? \nHello World!"},
                                {"There's no better place than 127.0.0.1!"},
                                {"6,500,000,000,000,000 Code-Lines for one upgrade?! \nBooleshit!"},
                                {"The CODEMEPOLITAN says, no other business has as much class as OOP"},
                                {"Why do programmers always mix up Halloween and Christmas?\nBecause Oct 31 == Dec 25!"},
                                {"When your hammer is C++, everything begins to look like a thumb."},
                                {"'Whats the object-oriented way to become wealthy?'\nInheritance."},
                                {"hip_hip[];"},
                                {"Two strings walk into a bar and sit down. The bartender says, 'So what'll it be?'\nThe first string says, 'I think I'll have a beer quag fulk boorg jdk^CjfdLk jk3s d#f67howe%^U r89nvy owmc63^Dz x.xvcu'\n'Please excuse my friend,' the second string says, 'He isn't null-terminated.'"},
                                {"Unix is user friendly. It's just very particular about who its friends are."},
                                {"A programmer puts two glasses on his bedside table before going to sleep. A full one, in case he gets thirsty, and an empty one, in case he doesn't."},
                                {"A programmer started to cuss\nBecause getting to sleep was a fuss\nAs she lay there in bed\nLooping 'round in her head\nwas: while(!asleep()) sheep++"},
                                {"Two bytes meet. The first byte asks, “Are you ill?”\nThe second byte replies, “No, just feeling a bit off.”"},
                                {"Two threads walk into a bar. The barkeeper looks up and yells, 'hey, I want don't any conditions race like time last!'"},
                                {"Old C programmers don't die, they're just cast into void."},
                                {"If you listen to a UNIX shell, can you hear the C?"},
                                {"Eight bytes walk into a bar. The bartender asks, “Can I get you anything?”\n“Yeah,” reply the bytes. “Make us a double.”"},
                                {"'Java programming is like teenage sex ....\nEveryone talks about it all of the time (but they don't really know what they're talking about);\nEveryone claims to be doing it;\nEveryone thinks everyone else is doing it;\nThose few who are actually doing it:\n\tAre not practicing it safely;\n\tAre doing it poorly, and\n\tAre sure it will be better next time.'\n"},
                                {"'In theory, there ought to be no difference between theory and practice. In practice, there is.'"},
                                {"A good programmer is someone who looks both ways before crossing a one-way street. ~ Doug Linder"},
                                {"99 little bugs in the code,\n99 bugs in the code,\nfix one bug, compile again,\n100 little bugs in the code.\n100 little bugs in the code, ..."},
                                {"Why did the programmer quit his job?\nBecause he didn't get arrays."},
                                {"Documentation is like sex. When it's good, it's very good. When it's bad, it's better than nothing."},
                                {"A programmer is nothing more than a machine that turns coffee into code."},
                                {"I � Unicode."},
                                {"Some people, when confronted with a problem, think, 'I know, I'll use threads' - and then two they hav erpoblesms."},
                                {"If a programmer is told to 'go to hell', he finds the worst part of that statement is the 'go to'"},
                                {"What's the best thing about UDP jokes?\nI don't care if you get them"},
                                {"1 little bug in the code\n1 little bug\npatch one down, compile it around\n0 bugs in the code\n0 little bugs in the code\n0 little bugs\npatch one downSEGMENTATION FAULT"},
                                {"In order to understand recursion you must first understand recursion."},
                                {"What do programmers do before sex?\nInitialize for()-play."},
                                {"There are 10 kinds of people in this world: Those who understand binary, those who don't, and those who weren't expecting a base 3 joke."},
                                {"Int getRandomNumber()\n{\nreturn 4;\n/* Chosen by fair dice roll, guaranteed to be random*/\n}"},
                                {"Knock, knock.\nRace condition.\nWho’s there."}};

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

        void on_actionCL_pro_Sekunde_triggered();

        void on_actionCL_pro_Klick_triggered();

        void on_actionCL_auf_0_setzen_triggered();

private:
        Ui::MainWindow  *ui;
};
#endif // MAINWINDOW_H
