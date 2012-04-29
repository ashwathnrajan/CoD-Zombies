#include "sniper.h"
#include <iostream>

Sniper::Sniper(int xpos, int ypos) : Gun(xpos, ypos)
  {
  this->bullets = 10;
  this->magazines = 3;
  this->damage = 20;
  this->speed = 8;
  this->maxMagazines = 3;
  this->maxBullets = 10;
  this->weight = 4;
  gunImage.load("sniper.png");
  gunRect = gunImage.rect();

  }

void Sniper::reload()
  {
  if (magazines > 0)
	{
	magazines--;
	bullets = maxBullets;
	}

  }

bool Sniper::shoot()
  {
  if (bullets > 0)
	{
	bullets--;
	return 1;
	}
  else return 0;

  }
