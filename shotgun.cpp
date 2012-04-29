#include "shotgun.h"
#include <iostream>

Shotgun::Shotgun(int xpos, int ypos) : Gun(xpos, ypos)
  {
  this->bullets = 7;
  this->magazines = 4;
  this->damage = 7;
  this->speed = 5;
  this->maxMagazines = 4;
  this->maxBullets = 7;
  this->weight = 2;
  gunImage.load("shotgun.png");
  gunRect = gunImage.rect();

  }

void Shotgun::reload()
  {
  if (magazines > 0)
	{
	magazines--;
	bullets = maxBullets;
	}

  }

bool Shotgun::shoot()
  {
  if (bullets > 0)
	{
	bullets--;
	return 1;
	}
  else return 0;

  }
