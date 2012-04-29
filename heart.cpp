#include "heart.h"
#include <cstdlib>

Heart::Heart()
  {
  pickedUp = 0;
  image.load("heart.png");
  rect = image.rect();
  rect.moveTo(50 + rand() % 150, 150 + rand() % 150); 
  }
