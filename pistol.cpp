/*	pistol(int, int);
	void reload();
	void shoot();


	Gun(int, int);
	virtual void reload() = 0;
	virtual void shoot() = 0;
	int xpos;
	int ypos;
  protected:
	QRect gunRect;
	QImage gunImage;
	int bullets;
	int magazines;
	int damage;
	int speed;
	*/

#include "pistol.h"
#include <iostream>


Pistol::Pistol(int xpos, int ypos) : Gun(xpos, ypos)
  {
  this->bullets = 12;
  this->magazines = 4;
  this->damage = 2;
  this->speed = 3;
  this->maxMagazines = 4;
  this->maxBullets = 12;
  this->weight = 1;
  gunImage.load("pistol.png");
  gunRect = gunImage.rect();

  }

void Pistol::reload()
  {
  if (magazines > 0)
	{
	magazines--;
	bullets = maxBullets;
	}

  }

bool Pistol::shoot()
  {
  if (bullets > 0)
	{
	bullets--;
	return 1;
	}
  else return 0;

  }
