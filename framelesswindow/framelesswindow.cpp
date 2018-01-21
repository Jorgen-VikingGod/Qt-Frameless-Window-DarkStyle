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

#include <QGraphicsDropShadowEffect>
#include "framelesswindow.h"

FramelessWindow::FramelessWindow(QWidget *parent): QWidget(parent)
{
  setWindowFlags(Qt::FramelessWindowHint | Qt::WindowSystemMenuHint);
  // append minimize button flag in case of windows,
  // for correct windows native handling of minimize function
#if defined(Q_OS_WIN)
  setWindowFlags(windowFlags() | Qt::WindowMinimizeButtonHint);
#endif
  setAttribute(Qt::WA_TranslucentBackground);

  setupUi(this);

  restoreButton->setVisible(false);

  //shadow under window title text
  QGraphicsDropShadowEffect *textShadow = new QGraphicsDropShadowEffect;
  textShadow->setBlurRadius(4.0);
  textShadow->setColor(QColor(0,0,0));
  textShadow->setOffset(0.0);
  titleText->setGraphicsEffect(textShadow);

  //window shadow
  QGraphicsDropShadowEffect *windowShadow = new QGraphicsDropShadowEffect;
  windowShadow->setBlurRadius(9.0);
  windowShadow->setColor(palette().color(QPalette::Highlight));
  windowShadow->setOffset(0.0);
  windowFrame->setGraphicsEffect(windowShadow);

  QObject::connect(qApp, &QGuiApplication::applicationStateChanged, this, &FramelessWindow::on_applicationStateChanged);
}

void FramelessWindow::changeEvent(QEvent *event)
{
  if (event->type() == QEvent::WindowStateChange) {
    if (windowState().testFlag(Qt::WindowNoState)) {
      on_restoreButton_clicked();
      event->ignore();
    } else if (windowState().testFlag(Qt::WindowMaximized)) {
      on_maximizeButton_clicked();
      event->ignore();
    }
  }
  event->accept();
}

void FramelessWindow::setContent(QWidget *w)
{
  contentLayout.setMargin(0);
  contentLayout.addWidget(w);
  windowContent->setLayout(&contentLayout);
}

void FramelessWindow::setWindowTitle(const QString &text)
{
  titleText->setText(text);
}

void FramelessWindow::styleWindow(bool bActive, bool bNoState)
{
  if (bActive) {
    if (bNoState) {
      layout()->setMargin(15);
      windowTitlebar->setStyleSheet(QStringLiteral("#windowTitlebar{border: 0px none palette(shadow); border-top-left-radius:5px; border-top-right-radius:5px; background-color:palette(shadow); height:20px;}"));
      windowFrame->setStyleSheet(QStringLiteral("#windowFrame{border:1px solid palette(highlight); border-radius:5px 5px 5px 5px; background-color:palette(Window);}"));
      QGraphicsEffect *oldShadow = windowFrame->graphicsEffect();
      if (oldShadow)
        delete oldShadow;
      QGraphicsDropShadowEffect *windowShadow = new QGraphicsDropShadowEffect;
      windowShadow->setBlurRadius(9.0);
      windowShadow->setColor(palette().color(QPalette::Highlight));
      windowShadow->setOffset(0.0);
      windowFrame->setGraphicsEffect(windowShadow);
    } else {
      layout()->setMargin(0);
      windowTitlebar->setStyleSheet(QStringLiteral("#windowTitlebar{border: 0px none palette(shadow); border-top-left-radius:0px; border-top-right-radius:0px; background-color:palette(shadow); height:20px;}"));
      windowFrame->setStyleSheet(QStringLiteral("#windowFrame{border:1px solid palette(dark); border-radius:0px 0px 0px 0px; background-color:palette(Window);}"));
      QGraphicsEffect *oldShadow = windowFrame->graphicsEffect();
      if (oldShadow)
        delete oldShadow;
      windowFrame->setGraphicsEffect(nullptr);
    } // if (bNoState) else maximize
  } else {
    if (bNoState) {
      layout()->setMargin(15);
      windowTitlebar->setStyleSheet(QStringLiteral("#windowTitlebar{border: 0px none palette(shadow); border-top-left-radius:5px; border-top-right-radius:5px; background-color:palette(dark); height:20px;}"));
      windowFrame->setStyleSheet(QStringLiteral("#windowFrame{border:1px solid #000000; border-radius:5px 5px 5px 5px; background-color:palette(Window);}"));
      QGraphicsEffect *oldShadow = windowFrame->graphicsEffect();
      if (oldShadow)
        delete oldShadow;
      QGraphicsDropShadowEffect *windowShadow = new QGraphicsDropShadowEffect;
      windowShadow->setBlurRadius(9.0);
      windowShadow->setColor(palette().color(QPalette::Shadow));
      windowShadow->setOffset(0.0);
      windowFrame->setGraphicsEffect(windowShadow);
    } else {
      layout()->setMargin(0);
      windowTitlebar->setStyleSheet(QStringLiteral("#titlebarWidget{border: 0px none palette(shadow); border-top-left-radius:0px; border-top-right-radius:0px; background-color:palette(dark); height:20px;}"));
      windowFrame->setStyleSheet(QStringLiteral("#windowFrame{border:1px solid palette(shadow); border-radius:0px 0px 0px 0px; background-color:palette(Window);}"));
      QGraphicsEffect *oldShadow = windowFrame->graphicsEffect();
      if (oldShadow)
        delete oldShadow;
      windowFrame->setGraphicsEffect(nullptr);
    } // if (bNoState) { else maximize
  } // if (bActive) { else no focus
}

void FramelessWindow::on_applicationStateChanged(Qt::ApplicationState state)
{
  if (windowState().testFlag(Qt::WindowNoState)) {
    if (state == Qt::ApplicationActive) {
      styleWindow(true, true);
    } else {
      styleWindow(false, true);
    }
  } else if (windowState().testFlag(Qt::WindowMaximized)) {
    if (state == Qt::ApplicationActive) {
      styleWindow(true, false);
    } else {
      styleWindow(false, false);
    }
  }
}

void FramelessWindow::on_minimizeButton_clicked()
{
  setWindowState(Qt::WindowMinimized);
}

void FramelessWindow::on_restoreButton_clicked() {
  restoreButton->setVisible(false);
  maximizeButton->setVisible(true);
  setWindowState(Qt::WindowNoState);
  styleWindow(true, true);
}
void FramelessWindow::on_maximizeButton_clicked()
{
  restoreButton->setVisible(true);
  maximizeButton->setVisible(false);
  setWindowState(Qt::WindowMaximized);
  styleWindow(true, false);
}
void FramelessWindow::on_closeButton_clicked()
{
  close();
}

void FramelessWindow::on_windowTitlebar_doubleClicked()
{
  if (windowState().testFlag(Qt::WindowNoState)) {
    on_maximizeButton_clicked();
  } else if (windowState().testFlag(Qt::WindowMaximized)) {
    on_restoreButton_clicked();
  }
}
