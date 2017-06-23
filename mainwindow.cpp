#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

/*
frameless window class: it adds the MainWindow class inside the centralWidget
*/
BorderlessMainWindow::BorderlessMainWindow(QWidget *parent) : QMainWindow(parent, Qt::CustomizeWindowHint ) {
  setObjectName("borderlessMainWindow");
  setWindowFlags(Qt::FramelessWindowHint| Qt::WindowSystemMenuHint);

  mMainWindow = new MainWindow(this);
  setWindowTitle(mMainWindow->windowTitle());

  QVBoxLayout *verticalLayout = new QVBoxLayout();
  verticalLayout->setSpacing(0);
  verticalLayout->setMargin(1);

  QHBoxLayout *horizontalLayout = new QHBoxLayout();
  horizontalLayout->setSpacing(0);
  horizontalLayout->setMargin(0);

  mTitlebarWidget = new QWidget(this);
  mTitlebarWidget->setObjectName("titlebarWidget");
  mTitlebarWidget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
  mTitlebarWidget->setLayout(horizontalLayout);

  mMinimizeButton = new QPushButton(mTitlebarWidget);
  mMinimizeButton->setObjectName("minimizeButton");
  connect(mMinimizeButton, SIGNAL(clicked()), this, SLOT(slot_minimized()));

  mRestoreButton = new QPushButton(mTitlebarWidget);
  mRestoreButton->setObjectName("restoreButton");
  mRestoreButton->setVisible(false);
  connect(mRestoreButton, SIGNAL(clicked()), this, SLOT(slot_restored()));

  mMaximizeButton = new QPushButton(mTitlebarWidget);
  mMaximizeButton->setObjectName("maximizeButton");
  connect(mMaximizeButton, SIGNAL(clicked()), this, SLOT(slot_maximized()));

  mCloseButton = new QPushButton(mTitlebarWidget);
  mCloseButton->setObjectName("closeButton");
  connect(mCloseButton, SIGNAL(clicked()), this, SLOT(slot_closed()));

  mWindowTitle = new QLabel(mTitlebarWidget);
  mWindowTitle->setObjectName("windowTitle");
  mWindowTitle->setText(windowTitle());

  horizontalLayout->addWidget(mWindowTitle);
  horizontalLayout->addStretch(1);
  horizontalLayout->addWidget(mMinimizeButton);
  horizontalLayout->addWidget(mRestoreButton);
  horizontalLayout->addWidget(mMaximizeButton);
  horizontalLayout->addWidget(mCloseButton);

  verticalLayout->addWidget(mTitlebarWidget);
  verticalLayout->addWidget(mMainWindow);

  QWidget *centralWidget = new QWidget(this);
  centralWidget->setObjectName("centralWidget");
  centralWidget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
  centralWidget->setLayout(verticalLayout);

  setCentralWidget(centralWidget);
}
void BorderlessMainWindow::mousePressEvent(QMouseEvent* event) {
  if (!mTitlebarWidget->underMouse() && !mWindowTitle->underMouse())
    return;

  if(event->button() == Qt::LeftButton) {
    mMoving = true;
    mLastMousePosition = event->pos();
  }
}
void BorderlessMainWindow::mouseMoveEvent(QMouseEvent* event) {
  if (!mTitlebarWidget->underMouse() && !mWindowTitle->underMouse())
    return;

  if( event->buttons().testFlag(Qt::LeftButton) && mMoving) {
    this->move(this->pos() + (event->pos() - mLastMousePosition));
  }
}
void BorderlessMainWindow::mouseReleaseEvent(QMouseEvent* event) {
  if (!mTitlebarWidget->underMouse() && !mWindowTitle->underMouse())
    return;

  if(event->button() == Qt::LeftButton) {
    mMoving = false;
  }
}
void BorderlessMainWindow::mouseDoubleClickEvent(QMouseEvent *event) {
  Q_UNUSED(event);
  if (!mTitlebarWidget->underMouse() && !mWindowTitle->underMouse())
    return;

  mMaximized = !mMaximized;
  if (mMaximized) {
    slot_maximized();
  } else {
    slot_restored();
  }
}
void BorderlessMainWindow::slot_minimized() {
  setWindowState(Qt::WindowMinimized);
}
void BorderlessMainWindow::slot_restored() {
  mRestoreButton->setVisible(false);
  mMaximizeButton->setVisible(true);
  setWindowState(Qt::WindowNoState);
  setStyleSheet("#borderlessMainWindow{border:1px solid palette(highlight);}");
}
void BorderlessMainWindow::slot_maximized() {
  mRestoreButton->setVisible(true);
  mMaximizeButton->setVisible(false);
  setWindowState(Qt::WindowMaximized);
  setStyleSheet("#borderlessMainWindow{border:1px solid palette(base);}");
}
void BorderlessMainWindow::slot_closed() {
  close();
}

/*
MainWindow class: put all your code here
*/
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent, Qt::FramelessWindowHint), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  statusBar()->setSizeGripEnabled(true);
}

MainWindow::~MainWindow() {
  delete ui;
}
