#include "bullet.h"
/*

  	Bullet(int xpos, int ypos, int xdir, int ydir, int damage, int speed);
	void autoMove();


  	int xdir;
	int ydir;
	int xpos;
	int ypos;
	int damage;
	int speed;
	QImage bulletImage;
	QRect bulletRect;
*/

Bullet::Bullet(int damage, int speed)
  {

  this->damage = damage;
  this->speed = speed;
  bulletImage.load("bullet.png");
  hitTarget = 0;
  }

void Bullet::setHit()
  {
  hitTarget = 1;
  }

void Bullet::fired(int xpos, int ypos, int xdir, int ydir)
  {
  bulletRect = bulletImage.rect();
  this->xpos = xpos;
  this->ypos = ypos;
  this->xdir = xdir;
  this->ydir = ydir;
  bulletRect = bulletImage.rect();
  bulletRect.moveTo(xpos, ypos);
  }

void Bullet::autoMove()
  {

  bulletRect.translate(xdir, ydir);

  if (xdir == 1)
	xpos++;
  else
	xpos--;

  if (ydir == 1)
	ypos++;
  else
	ypos--;
  }
