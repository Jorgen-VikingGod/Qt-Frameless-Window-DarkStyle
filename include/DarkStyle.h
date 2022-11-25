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

#ifndef DARKSTYLE_HPP
#define DARKSTYLE_HPP

#include <QApplication>
#include <QFile>
#include <QFont>
#include <QProxyStyle>
#include <QStyleFactory>

#include "Qt-Frameless-Window-DarkStyle/Qt-Frameless-Window-DarkStyle_export.hpp"

class QT_FRAMELESS_WINDOW_DARKSTYLE_EXPORT DarkStyle : public QProxyStyle
{
  Q_OBJECT

public:
  DarkStyle();
  explicit DarkStyle(QStyle* style);

  QStyle* baseStyle() const;

  void polish(QPalette& palette) override;
  void polish(QApplication* app) override;

private:
  QStyle* styleBase(QStyle* style = Q_NULLPTR) const;
};

#endif  // DARKSTYLE_HPP
