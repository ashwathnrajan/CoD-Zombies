#include "player.h"
#include "weapon.h"
#include <iostream>

/*
	void moveDown();
	void moveUp();
	void moveLeft();
	void moveRight();
	void fire();
	void changeWeapon();
	void loseLife();
	void addPoints(int);
	void addScore(int);
	void setXdir(int);
	void setYdir(int);
	void setXpos(int);
	void setYpos(int);
*/

UserPlayer::UserPlayer()
  {
  xpos = 150;
  ypos = 300;
  xdir = 0;
  ydir = 0;
  points = 0;
  score = 0;
  lives = 4;
  isAlive = 1;
  weaponIndex = 0;
  Weapon newWeapon(0, *this);
  weaponList.push_back(newWeapon);
  image.load("player.png");
  rect = image.rect();
  rect.moveTo(xpos, ypos);
  }

void UserPlayer::setUP()
  {
  image.load("up.png");
  }

void UserPlayer::setRIGHT()
  {
  image.load("right.png");
  }

void UserPlayer::setLEFT()
  {
  image.load("left.png");
  }

void UserPlayer::setDOWN()
  {
  image.load("down.png");
  }

void UserPlayer::moveDown()
  {
  rect.moveTo(xpos, ++ypos);
  ypos++;
  image.load("down.png");
  }

void UserPlayer::moveUp()
  {
  rect.translate(0,-1);
  ypos--;
  image.load("up.png");
  }

void UserPlayer::moveLeft()
  {
  rect.translate(-1,0);
  xpos--;
  image.load("left.png");
  }

void UserPlayer::moveRight()
  {
  rect.translate(1,0);
  xpos++;
  image.load("right.png");
  }

void UserPlayer::fire()
  {
  weaponList[weaponIndex].shoot();
  }

void UserPlayer::changeWeapon()
  {
  weaponIndex++;
  if (weaponIndex == weaponList.size())
	{
	weaponIndex = 0;
	}
  }

void UserPlayer::loseLife()
  {
  lives--;
  if (lives == 0) isAlive = 0;
  }

void UserPlayer::gainLife()
  {
  lives++;
  
  }

void UserPlayer::addPoints(int addpoints)
  {
  points += addpoints;

  }

void UserPlayer::addScore(int addscore)
  {
  score += addscore;
  }

void UserPlayer::setXdir(int dir)
  {
  xdir = dir;
  }

void UserPlayer::setYdir(int dir)
  {
  ydir = dir;
  }

void UserPlayer::setXpos(int pos)
  {
  xpos = pos;
  }

void UserPlayer::setYpos(int pos)
  {
  ypos = pos;
  }
