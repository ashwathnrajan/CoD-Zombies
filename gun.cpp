#include "gun.h"
#include <iostream>

/*public:
	Gun();
	Gun(int, int);
	~Gun();
	virtual void reload() = 0;
	void shoot();
	int xpos;
	int ypos;
  protected:
	QRect gunRect;
	QImage gunImage;
*/

Gun::Gun(int xpos, int ypos)
  {
  if (!(xpos < 0 && ypos < 0))
  gunRect.moveTo(xpos, ypos);
  this->xpos = xpos; 
  this->ypos = ypos;

  }

QRect Gun::getRect()
  {
  return gunRect;
  }

QImage& Gun::getImage()
  {
  return gunImage;
  }

int Gun::getBullets()
  {
  return bullets;
  }

int Gun::getMagazines()
  {
  return magazines;
  }

int Gun::getDamage()
  {
  return damage;
  }

int Gun::getSpeed()
  {
  return speed;
  }

int Gun::getMaxBullets()
  {
  return maxBullets;
  }

int Gun::getMaxMagazines()
  {
  return maxMagazines;
  }

int Gun::getWeight()
  {
  return weight;
  }



