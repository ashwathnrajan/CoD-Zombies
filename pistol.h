#ifndef PISTOL_H
#define PISTOL_H

#include "gun.h"
#include <QImage>
#include <QRect>

class Pistol : public Gun
  {
  public:
	Pistol(int, int);
	void reload();
	bool shoot();
	

  };

#endif
