#include <QtGui>

#include "gameWindow.h"
#include "gameBoard.h"
#include "player.h"

#include <iostream>

gameWindow::gameWindow()
  {
  board = new gameBoard;

  board->setGeometry(100,100,400,400);

 // all lcd initializtions and button initializations

  scoreLCD = new QLCDNumber(5);
  scoreLCD->setSegmentStyle(QLCDNumber::Filled);
  magazinesLCD = new QLCDNumber(2);
  magazinesLCD->setSegmentStyle(QLCDNumber::Filled);
  bulletsLCD = new QLCDNumber(2);
  bulletsLCD->setSegmentStyle(QLCDNumber::Filled);
  healthLCD = new QLCDNumber(1);
  healthLCD->setSegmentStyle(QLCDNumber::Filled);
  levelLCD = new QLCDNumber(2);
  levelLCD->setSegmentStyle(QLCDNumber::Filled);
  damageLCD = new QLCDNumber(2);
  damageLCD->setSegmentStyle(QLCDNumber::Filled);
 
  startButton = new QPushButton(tr("&Start"));
  startButton->setFocusPolicy(Qt::NoFocus);
  quitButton = new QPushButton(tr("&Quit"));
  quitButton->setFocusPolicy(Qt::NoFocus);
  pauseButton = new QPushButton(tr("&Pause"));
  pauseButton->setFocusPolicy(Qt::NoFocus);

  connect(startButton, SIGNAL(clicked()), board, SLOT(start()));
  connect(quitButton , SIGNAL(clicked()), qApp, SLOT(quit()));
  connect(pauseButton, SIGNAL(clicked()), board, SLOT(pause()));
  connect(board, SIGNAL(levelChanged(int)), levelLCD, SLOT(display(int)));
  connect(board, SIGNAL(scoreChanged(int)), scoreLCD, SLOT(display(int)));
  connect(board, SIGNAL(ammoChanged(int)),bulletsLCD, SLOT(display(int)));
  connect(board, SIGNAL(healthChanged(int)),healthLCD, SLOT(display(int)));
  connect(board, SIGNAL(magazinesChanged(int)),magazinesLCD, SLOT(display(int)));
  connect(board, SIGNAL(weaponChanged(int)), damageLCD, SLOT(display(int)));

  
  QGridLayout *layout = new QGridLayout;
  layout->addWidget(createLabel(tr("Weapon Damage")), 2, 0);
  layout->addWidget(damageLCD, 3, 0);
  layout->addWidget(createLabel(tr("Health")), 4, 3);
  layout->addWidget(createLabel(tr("Magazines/Ammo")),4,0);
  layout->addWidget(createLabel(tr("Level")), 6, 3);
  layout->addWidget(levelLCD, 7, 3);

  layout->addWidget(bulletsLCD, 6,0);
  layout->addWidget(magazinesLCD,5,0);
  layout->addWidget(healthLCD, 5,3);
  layout->addWidget(board, 0, 1, 8, 2);
  layout->addWidget(createLabel(tr("Score:")), 0, 0);
  layout->addWidget(scoreLCD, 1, 0);
  layout->addWidget(startButton, 0, 3);
  layout->addWidget(quitButton, 1, 3);
  layout->addWidget(pauseButton, 2, 3);
  setLayout(layout);

  setWindowTitle(tr("CoD Zombies!"));
  resize(600,400);
  }

QLabel *gameWindow::createLabel(const QString &text)
{
  QLabel *lbl = new QLabel(text);
  lbl->setAlignment(Qt::AlignHCenter | Qt::AlignBottom);
  return lbl;

}
