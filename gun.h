#ifndef GUN_H
#define GUN_H

#include <QImage>
#include <QRect>

class Gun
{
  public:
	Gun(int, int);
	virtual void reload() = 0;
	virtual bool shoot() = 0;
	int getBullets();
	int getMagazines();
	int getDamage();
	int getSpeed();
	int getMaxBullets();
	int getMaxMagazines();
	int getWeight();
	QRect getRect();
	QImage &getImage();
	int xpos;
	int ypos;
  protected:
	QRect gunRect;
	QImage gunImage;
	int bullets;
	int magazines;
	int damage;
	int speed;
	int maxBullets;
	int maxMagazines;
	int weight;


};

#endif

