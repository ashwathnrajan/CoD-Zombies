#include "spittershot.h"

SpitterShot::SpitterShot(int damage, int speed) : Bullet(damage, speed)
  {
  this->bulletImage.load("spittershot.png");
  }
