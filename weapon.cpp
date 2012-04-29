#include "weapon.h"
#include <iostream>

/*

  	Weapon(int type);
  	~Weapon();
	Bullet* bullets;
	Gun* gun;	


*/
Weapon::Weapon()
  {
  gun = new Pistol(-1,-1);
  player = NULL;
  }


Weapon::Weapon(int type, UserPlayer& play)
  {
  this->type = type;
  if (type == 0)
	{
	gun = new Pistol(-1,-1);
	}
  else if (type == 1)
	{
	gun = new LMG(-1,-1);
	}
  else if (type == 2)
	{
	gun = new Shotgun(-1,-1);
	}
  else 
	{
	gun = new Sniper(-1,-1);
	}
  player = &play;
  }

void Weapon::shoot()
  {
  if (gun->shoot())
	{
  	Bullet* newBullet = new Bullet(gun->getDamage(), gun->getSpeed());
  	newBullet->fired(player->getXpos() + player->getXdir(), player->getYpos() + player->getYdir(), player->getXdir(), player->getYdir());
  	bullets.push_back(newBullet);
	}
  for (int i = 0; i < 6; i++)
	{
	QVector<Bullet*>::iterator biter;
	int found = 0;
	for (biter = bullets.begin(); biter != bullets.end(); biter++)
		{
		if ((*biter)->getXpos() >1000 || (*biter)->getYpos() > 1000)
			{
			found = 1;
			break;
			}
		}
	if (found == 1)
	bullets.erase(biter);
	}
  

  
  }
