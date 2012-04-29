#ifndef USERPLAYER_H
#define USERPLAYER_H

#include <QRect>
#include <QImage>
#include <QVector>
#include "weapon.h"

class Weapon;

class UserPlayer
  {
  public:
	UserPlayer();
	~UserPlayer();

 private:
	int xpos;
	int ypos;
	int xdir;
	int ydir;
	int points;
	int score;
	int lives;
	bool isAlive;
	int weaponIndex;
	QRect rect;
	QImage image;

  public:
	void moveDown();
	void moveUp();
	void moveLeft();
	void moveRight();
	void fire();
	void changeWeapon();
	void loseLife();
	void gainLife();
	void addPoints(int);
	void addScore(int);
	void setXdir(int);
	void setYdir(int);
	void setXpos(int);
	void setYpos(int);
	void setUP();
	void setDOWN();
	void setLEFT();
	void setRIGHT();

	int getXdir(){return xdir;}
	int getYdir(){return ydir;}
	int getXpos(){return xpos;}
	int getYpos(){return ypos;}

	int getPoints(){return points;}
	int getScore(){return score;}
	int getLives(){return lives;}
	int getWeapIndex(){return weaponIndex;}
 	QVector<Weapon> weaponList;
	QRect getRect(){return rect;}
	QImage getImage(){return image;}
	
 
  };

#endif
