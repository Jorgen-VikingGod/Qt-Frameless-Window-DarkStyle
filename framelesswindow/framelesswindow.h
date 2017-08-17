/*
###############################################################################
#                                                                             #
# GNU LESSER GENERAL PUBLIC LICENSE                                           #
# Version 3, 29 June 2007                                                     #
#                                                                             #
# Copyright (C) 2017 by Juergen Skrotzky (JorgenVikingGod@gmail.com)          #
# Sources: https://github.com/Jorgen-VikingGod/Qt-Frameless-Window-DarkStyle  #
#                                                                             #
###############################################################################
*/

#ifndef FRAMELESSWINDOW_H
#define FRAMELESSWINDOW_H

#include "ui_framelesswindow.h"

class FramelessWindow: public QWidget, private Ui::FramelessWindow
{
  Q_OBJECT

public:
  explicit FramelessWindow(QWidget *parent = 0);
  void setContent(QWidget *w);

private:
  void styleWindow(bool bActive, bool bNoState);

public slots:
  void setWindowTitle(const QString &text);

private slots:
  void on_applicationStateChanged(Qt::ApplicationState state);
  void on_minimizeButton_clicked();
  void on_restoreButton_clicked();
  void on_maximizeButton_clicked();
  void on_closeButton_clicked();
  void on_windowTitlebar_doubleClicked();

protected:
  virtual void changeEvent(QEvent *event);

protected:
  QHBoxLayout contentLayout;
};

#endif // FRAMELESSWINDOW_H
