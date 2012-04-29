#ifndef SPITTER_H
#define SPITTER_H

#include <QImage>
#include <QRect>
#include <QVector>
#include "zombie.h"
#include "spittershot.h"

class Spitter : public Zombie
  {
  public:
  	Spitter(int, int);
  	virtual void attack(int, int);
	QVector<SpitterShot*> spitBullets;
	virtual int getType() {return 2;}
	virtual void move();



  };

#endif
