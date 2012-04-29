#ifndef DEVILDOG_H
#define DEVILDOG_H

#include <QImage>
#include <QRect>
#include <QVector>
#include "zombie.h"

class DevilDog : public Zombie
  {
  public:
  	DevilDog(int, int);
  	virtual void attack(int, int);
	virtual int getType() {return 3;}



  };

#endif
