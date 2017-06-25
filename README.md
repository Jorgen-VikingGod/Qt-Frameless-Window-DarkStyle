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

## Licence
> The MIT License
>
> Copyright (c) 2017, Juergen Skrotzky (https://github.com/Jorgen-VikingGod, JorgenVikingGod@gmail.com)
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
