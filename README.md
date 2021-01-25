# Qt Frameless Window with DarkStyle
simple MainWindow class implementation with frameless window and custom dark style. 

It adds also support for titlebar and buttons (minimize, maximize, close)

Look is based on the VS2013 application window (flat and frameless window)

<table>
  <tr><th colspan="2">Screenshots</th></tr>
  <tr><th>mac enabled</th><th>mac disabled</th></tr>
  <tr>
    <td><img src="https://github.com/Jorgen-VikingGod/Qt-Frameless-Window-DarkStyle/blob/master/screenshot_mac_frameless_window_qt_dark_style_enabled.png" title="screenshot mac frameless window qt dark style enabled" /></td>
    <td><img src="https://github.com/Jorgen-VikingGod/Qt-Frameless-Window-DarkStyle/blob/master/screenshot_mac_frameless_window_qt_dark_style_disabled.png" title="screenshot mac frameless window qt dark style disabled" /></td>
  </tr>
</table>


## Qt and OS
* tested with Qt5.5.0, Qt5.9.0 and Qt5.10.0
* tested on Windows 7, Windows 10,MacOSX 10.12.5 and MacOS 10.13.2

## PyQt5
Here is an [unofficial Python port](https://github.com/gmarull/qtmodern) of my implementation.

## How to use
* add additional include plath to **framelesswindow**
* add resources **framelesswindow.qrc** and **darkstyle.qrc**
* add ``#include "framelesswindow.h"`` into **main.cpp**, create window ``FramelessWindow framelessWindow;`` and assign your mainwindow object as content ``framelessWindow.setContent(mainWindow);`` and show it ``framelessWindow.show();``
* add ``#include "DarkStyle.h"`` into **main.cpp** and call ``a.setStyle(new DarkStyle);``


```qt
#include <QApplication>
#include "DarkStyle.h"
#include "framelesswindow.h"
#include "mainwindow.h"

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);

  // style our application with custom dark style
  QApplication::setStyle(new DarkStyle);
  //QApplication::setPalette(QApplication::style()->standardPalette());

  // create frameless window (and set windowState or title)
  FramelessWindow framelessWindow;
  //framelessWindow.setWindowState(Qt::WindowMaximized);
  //framelessWindow.setWindowTitle("test title");
  //framelessWindow.setWindowIcon(a.style()->standardIcon(QStyle::SP_DesktopIcon));
  
  // create our mainwindow instance
  MainWindow *mainWindow = new MainWindow;

  // add the mainwindow to our custom frameless window
  framelessWindow.setContent(mainWindow);
  framelessWindow.show();

  return a.exec();
}
```


## features
* frameless window
* custom dark style (based on **Fusion style** with dark palette and custom stylesheets)
* title bar
* buttons (minimize | restore | maximize | close)
* move window by drag the title bar
* dobule click title bar to toggle between window styte (maximize and normal)
* use of native events, like minimizing or system menu


## todo
* [ ] [resize window on each corner [#1]](https://github.com/Jorgen-VikingGod/Qt-Frameless-Window-DarkStyle/issues/1) (some work done by [notecola](https://github.com/notecola) :+1:)
* [ ] [snap on screen edges [#3]](https://github.com/Jorgen-VikingGod/Qt-Frameless-Window-DarkStyle/issues/3)


## thanks
Many thanks goes to the [Qt Forum](https://forum.qt.io/topic/80654/how-to-create-vs2013-like-frameless-window-with-dark-style) and especially to [Chris Kawa](https://forum.qt.io/user/chris-kawa) for pointing me to some usual issues and hints of great must have features. 


## Licence
> The MIT License
>
> Copyright (c) 2018, Juergen Skrotzky (https://github.com/Jorgen-VikingGod, JorgenVikingGod@gmail.com)
>
> Permission is hereby granted, free of charge, to any person obtaining a copy
> of this software and associated documentation files (the "Software"), to deal
> in the Software without restriction, including without limitation the rights
> to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
> copies of the Software, and to permit persons to whom the Software is
> furnished to do so, subject to the following conditions:
>
> The above copyright notice and this permission notice shall be included in
> all copies or substantial portions of the Software.
>
> THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
> IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
> FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
> AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
> LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
> OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
> THE SOFTWARE.
