/******************************************************************************/
/**
@file          DarkStyle.h
@copyright     (c) 2017 Juergen Skrotzky (JorgenVikingGod@gmail.com)
@description   simple singleton to adjust style/palette/stylesheets
*******************************************************************************
*******************************************************************************/

#ifndef _CDarkStyle_HPP
#define _CDarkStyle_HPP

/* INCLUDE FILES **************************************************************/
#include <QtCore>
#include <QtGui>

/* CLASS DECLARATION **********************************************************/
/** CMainWindow class is a simple singleton to adjust style/palette/stylesheets
*******************************************************************************/
class CDarkStyle
{
// PUBLIC MEMBERS *************************************************************
// PROTECTED MEMBERS **********************************************************
// PRIVATE MEMBERS ************************************************************
// CONSTRUCTOR/DESTRUCTOR *****************************************************
// PUBLIC METHODS *************************************************************
public:
  static void assign()
  {
    // set style
    qApp->setStyle(QStyleFactory::create("Fusion"));
    // increase font size for better reading
    QFont defaultFont = QApplication::font();
    defaultFont.setPointSize(defaultFont.pointSize()+2);
    qApp->setFont(defaultFont);
    // modify palette to dark
    QPalette darkPalette;
    darkPalette.setColor(QPalette::Window,QColor(53,53,53));
    darkPalette.setColor(QPalette::WindowText,Qt::white);
    darkPalette.setColor(QPalette::Base,QColor(42,42,42));
    darkPalette.setColor(QPalette::AlternateBase,QColor(66,66,66));
    darkPalette.setColor(QPalette::ToolTipBase,Qt::white);
    darkPalette.setColor(QPalette::ToolTipText,Qt::white);
    darkPalette.setColor(QPalette::Text,Qt::white);
    darkPalette.setColor(QPalette::Dark,QColor(35,35,35));
    darkPalette.setColor(QPalette::Shadow,QColor(20,20,20));
    darkPalette.setColor(QPalette::Button,QColor(53,53,53));
    darkPalette.setColor(QPalette::ButtonText,Qt::white);
    darkPalette.setColor(QPalette::BrightText,Qt::red);
    darkPalette.setColor(QPalette::Link,QColor(42,130,218));
    darkPalette.setColor(QPalette::Highlight,QColor(42,130,218));
    darkPalette.setColor(QPalette::HighlightedText,Qt::white);
    darkPalette.setColor(QPalette::Disabled,QPalette::ButtonText,QColor(127,127,127));
    qApp->setPalette(darkPalette);
    // loadstylesheet
    QFile qfDarkstyle(QString(":/darkstyle/darkstyle.qss"));
    if (qfDarkstyle.open(QIODevice::ReadOnly | QIODevice::Text))
    {
      // set stylesheet
      QString qsStylesheet = QString(qfDarkstyle.readAll());
      qApp->setStyleSheet(qsStylesheet);
      qfDarkstyle.close();
    }
  }
// PROTECTED METHODS **********************************************************
// PRIVATE METHODS ************************************************************
};

#endif  // _CDarkStyle_HPP

//*****************************************************************************
// END OF FILE
//*****************************************************************************
