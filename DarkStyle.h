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

#ifndef _DarkStyle_HPP
#define _DarkStyle_HPP

/* INCLUDE FILES **************************************************************/
#include <QApplication>
#include <QProxyStyle>
#include <QStyleFactory>
#include <QFont>
#include <QFile>

/* CLASS DECLARATION **********************************************************/
/** CMainWindow class is a simple singleton to adjust style/palette/stylesheets
*******************************************************************************/
class DarkStyle : public QProxyStyle
{
  Q_OBJECT
  // PUBLIC MEMBERS *************************************************************    
  // PROTECTED MEMBERS **********************************************************
  // PRIVATE MEMBERS ************************************************************
  // CONSTRUCTOR/DESTRUCTOR *****************************************************
  // PUBLIC METHODS *************************************************************
public:
  DarkStyle();
  explicit DarkStyle(QStyle *style);

  QStyle *baseStyle() const;

  void polish(QPalette &palette) override;
  void polish(QApplication *app) override;

  // PROTECTED METHODS **********************************************************
  // PRIVATE METHODS ************************************************************
private:
  QStyle *styleBase(QStyle *style=Q_NULLPTR) const;
};

#endif  // _DarkStyle_HPP

//*****************************************************************************
// END OF FILE
//*****************************************************************************
