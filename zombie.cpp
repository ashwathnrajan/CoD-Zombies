#include "zombie.h"
#include <cstdlib>
/*
	int xpos;
	int ypos;
	QRect zombieRect;
	QImage zombieImage;
	int speed;
	int health;
	int range;
	deque<zombieMove> moveQueue;
*/



Zombie::Zombie(int xpo, int ypo)
  {
  speed = 2;
  
  this->xpos = xpo;
  this->ypos = ypo;
  zombieRect.moveTo(xpos, ypos);
  this->isDead = 0;
  this->health = 10;
  int randnum = rand() % 4;
  if (randnum == 0)
	{
	xdir = -1;
	ydir = -1;
	}
  else if (randnum == 1)
	{
	xdir = 1;
	ydir = 1;
	}
  else if (randnum == 2)
	{
	xdir = 1;
	ydir = -1;
	}
  else 
	{
	xdir = -1;
	ydir = 1;
	}
  zombieImage.load("zombie.png");
  zombieRect = zombieImage.rect();
  }

void Zombie::attack(int playerx, int playery)
	{
//do nothing
	}

void Zombie::shot(int damage)
  {
  health += -damage;
  if (health <= 0)
	isDead = 1;
  }

void Zombie::calculateDirection(int playerx, int playery)
  {
  if (xpos < playerx)
	{
	xdir = 1;
	}
  else
	{
	xdir = -1;
	}
  if (ypos < playery)
	{
	ydir = 1;
	}
  else
	{
	ydir = -1;
	}
  int randint = rand() % 10000000000000;
  if (randint == 1)
	{
	xdir = -xdir;
	ydir = -ydir;
	}
  }

void Zombie::move()
  {
  zombieRect.translate(xdir, ydir);


  xpos = zombieRect.x();
  ypos = zombieRect.y();


  }



