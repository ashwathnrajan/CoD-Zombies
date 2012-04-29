#include <QtGui>
#include <stdlib.h>
#include "gameWindow.h"
#include <iostream>

int main(int argc, char* argv[])
  {

  QApplication app(argc, argv);
 
  gameWindow window;
  window.setGeometry(100,100,800,700);
 #if defined(Q_OS_SYMBIAN)
     window.showMaximized();
 #else
     window.show();
 #endif
 
  return app.exec();
  }

