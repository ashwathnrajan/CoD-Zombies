#ifndef LMG_H
#define LMG_H

#include "gun.h"
#include <QImage>
#include <QRect>

class LMG : public Gun
  {
  public:
	LMG(int, int);
	void reload();
	bool shoot();
	

  };

#endif
