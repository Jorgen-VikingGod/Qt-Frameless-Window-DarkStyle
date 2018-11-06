/*
###############################################################################
#                                                                             #
# The MIT License                                                             #
#                                                                             #
# Copyright (C) 2017 by Juergen Skrotzky (JorgenVikingGod@gmail.com)          #
#               >> https://github.com/Jorgen-VikingGod                        #
#                                                                             #
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
  virtual void	mouseDoubleClickEvent(QMouseEvent *event);
  virtual void	checkBorderDragging(QMouseEvent *event);
  virtual void	mousePressEvent(QMouseEvent *event);
  virtual void	mouseReleaseEvent(QMouseEvent *event);
  virtual bool eventFilter(QObject *obj, QEvent *event);

private:
	bool LeftBorderHit(const QPoint & pos);
	bool RightBorderHit(const QPoint & pos);
	bool TopBorderHit(const QPoint & pos);
	bool BottomBorderHit(const QPoint & pos);

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

  bool m_bMousePressed;
  bool m_bDragTop;
  bool m_bDragLeft;
  bool m_bDragRight;
  bool m_bDragBottom;

  QRect m_StartGeometry;

  const int CONST_DRAG_BORDER_SIZE = 15;
};

#endif // FRAMELESSWINDOW_H
