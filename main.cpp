#include "mainwindow.h"
#include <QApplication>
#include <QPalette>

#include "DarkStyle.h"

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);

  // apply dark style
  CDarkStyle::assign();

  // create and show frameless window
  BorderlessMainWindow w;
  w.show();

  return a.exec();
}
