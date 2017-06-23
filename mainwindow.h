#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets>

/*
place your QMainWindow code here
*/
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
  Q_OBJECT
public:
  explicit MainWindow(QWidget *parent = 0);
  ~MainWindow();
private:
  Ui::MainWindow *ui;
};


/*
this class is to add frameless window supoort and do all the stuff with titlebar and buttons
*/
class BorderlessMainWindow: public QMainWindow
{
  Q_OBJECT
public:
  explicit BorderlessMainWindow(QWidget *parent = 0);
  ~BorderlessMainWindow() {}
protected:
  void mouseMoveEvent(QMouseEvent* event);
  void mousePressEvent(QMouseEvent* event);
  void mouseReleaseEvent(QMouseEvent* event);
  void mouseDoubleClickEvent(QMouseEvent *event);
private slots:
  void slot_minimized();
  void slot_restored();
  void slot_maximized();
  void slot_closed();
private:
  MainWindow *mMainWindow;
  QWidget *mTitlebarWidget;
  QLabel *mWindowTitle;
  QPushButton *mMinimizeButton;
  QPushButton *mRestoreButton;
  QPushButton *mMaximizeButton;
  QPushButton *mCloseButton;
  QPoint mLastMousePosition;
  bool mMoving;
  bool mMaximized;
};


#endif // MAINWINDOW_H
