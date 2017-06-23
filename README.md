# Qt Frameless Window with DarkStyle
simple MainWindow class implementation with frameless window and custom dark style. 
It adds also support for titlebar and buttons (minimize, maximize, close)

## Qt and OS
* tested with Qt5.5.0 and Qt5.9.0
* tested on Windows7 and MacOSX 10.12.5

## How to use
* edit mainwindow.cpp/.h
* add your custom QMainWindow code into the class **MainWindow**
* the class **BorderlessMainWindow** is just to add frameless window support and styling
* to use the dark style, add ``#include "DarkStyle.h"`` insto **main.cpp** and call ``CDarkStyle::assign();``

## features
* frameless window
* custom dark style (based on **Fusion style** with dark palette and custom stylesheets)
* title bar
* buttons (minimize | restore | maximize | close)
* move window by drag the title bar
* dobule click title bar to toggle between window styte (maximize and normal)

