/* Grundlagen der Informatik II, SS 16

    Projekt:            Idle-Game
    Autor: 				Robert Schock
    Matrikelnummer: 	4229891
    Datum: 				23.08.2016

Eine genaue Dokumentation liegt der
Abgabe als PDF Datei bei.
*/

#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{





  QApplication a(argc, argv);

  MainWindow w;
  w.show();






  return a.exec();
}
