#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QFrame>
#include <QWidget>
#include "player.h"

class QLCDNumber;
class QLabel;
class QPushButton;
class QString;

class gameBoard;

class gameWindow : public QWidget
{
	Q_OBJECT

public: 
	gameWindow();

private:
	QLabel * createLabel(const QString &text);

	

	gameBoard* board;
	
	QLCDNumber *damageLCD;
	QLCDNumber *levelLCD;
	QLCDNumber *scoreLCD;
	QLCDNumber *bulletsLCD;
	QLCDNumber *healthLCD;
	QLCDNumber *magazinesLCD;
	QPushButton *startButton;
	QPushButton *quitButton;
	QPushButton *pauseButton;

};

#endif
