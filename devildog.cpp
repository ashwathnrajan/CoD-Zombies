#include "devildog.h"
#include <cstdlib>

DevilDog::DevilDog(int xpos, int ypos) : Zombie(xpos, ypos)
  {
  health = 3;
  speed = 5;
  zombieImage.load("devildog.png");
  zombieRect = zombieImage.rect();
  if (rand() % 2 == 0)
  	zombieRect.moveTo(1000, 1000);
 else  zombieRect.moveTo(xpos, ypos);
  }

void DevilDog::attack(int playerx, int playery)
  {
//do nothing

  }
