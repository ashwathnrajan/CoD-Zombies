#include "spitter.h"
#include <cstdlib>

Spitter::Spitter(int xpos, int ypos) : Zombie(xpos, ypos)
  {
  health = 12;
  speed = 2;
  zombieImage.load("spitter.png");
  zombieRect = zombieImage.rect();
  if (rand() % 2 == 1)  zombieRect.moveTo(500, 500);
  else zombieRect.moveTo(xpos, ypos);
  }

void Spitter::attack(int playerx, int playery)
  {//the spitter attackes when aligned with the player
  if (xpos == playerx )
	{
	SpitterShot* newShot = new SpitterShot(1, 5);
	spitBullets.push_back(newShot);
	newShot->fired(xpos, ypos, 0, ydir);
	}
  else if ( ypos == playery)
	{
	SpitterShot* newShot = new SpitterShot(1, 5);
	spitBullets.push_back(newShot);
	newShot->fired(xpos, ypos, xdir, 0);
	}

  }

void Spitter::move()
  {
  zombieRect.translate(xdir, ydir);

  if (rand() % 100000000 == 1)
	zombieRect.moveTo(xpos + (xdir*30), ypos + (ydir*30)); // the random jumps of the spitter
  xpos = zombieRect.x();
  ypos = zombieRect.y();


  }
