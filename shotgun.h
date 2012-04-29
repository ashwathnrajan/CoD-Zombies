#ifndef SHOTGUN_H
#define SHOTGUN_H

#include "gun.h"
#include <QImage>
#include <QRect>

class Shotgun : public Gun
  {
  public:
	Shotgun(int, int);
	void reload();
	bool shoot();
	

  };

#endif
