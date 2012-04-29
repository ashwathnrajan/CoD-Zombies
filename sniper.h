#ifndef SNIPER_H
#define SNIPER_H

#include "gun.h"
#include <QImage>
#include <QRect>

class Sniper : public Gun
  {
  public:
	Sniper(int, int);
	void reload();
	bool shoot();
	

  };

#endif
