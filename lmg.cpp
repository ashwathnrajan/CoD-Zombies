#include "lmg.h"
#include <iostream>

LMG::LMG(int xpos, int ypos) : Gun(xpos, ypos)
  {
  this->bullets = 50;
  this->magazines = 2;
  this->damage = 5;
  this->speed = 10;
  this->maxMagazines = 2;
  this->maxBullets = 50;
  this->weight = 4;
  gunImage.load("LMG.png");
  gunRect = gunImage.rect();

  }

void LMG::reload()
  {
  if (magazines > 0)
	{
	magazines--;
	bullets = maxBullets;
	}

  }

bool LMG::shoot()
  {
  if (bullets > 0)
	{
	bullets--;
	return 1;
	}
  else return 0;

  }
