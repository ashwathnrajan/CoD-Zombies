#ifndef WEAPON_H
#define WEAPON_H

#include <QVector>
#include "gun.h"
#include "bullet.h"
#include "player.h"
#include "lmg.h"
#include "pistol.h"
#include "sniper.h"
#include "shotgun.h"


class UserPlayer;

class Weapon
  {
  public:
	Weapon();
  	Weapon(int type, UserPlayer& play);
	void shoot();
	QVector<Bullet*> bullets;
	Gun* gun;	
	UserPlayer* player;
	int type;
	

  };

#endif
