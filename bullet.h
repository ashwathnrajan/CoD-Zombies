#ifndef BULLET_H
#define BULLET_H

#include <QImage>
#include <QRect>

class Bullet
  {
  public:
  	Bullet(int damage, int speed);
	void autoMove();
	void fired(int xpos, int ypos, int xdir, int ydir);
	void setHit();
	bool getHit() {return hitTarget;} 
	QImage getImage() {return this->bulletImage;}
	QRect getRect() {return this->bulletRect;}
	int getXdir() {return xdir;}
	int getYdir() {return ydir;}
	int getXpos() {return xpos;}
	int getYpos() {return ypos;}
	int getDamage() {return damage;}
	int getSpeed() {return speed;}
  protected:
  	int xdir;
	int ydir;
	int xpos;
	int ypos;
	int damage;
	int speed;
	bool hitTarget;
	QImage bulletImage;
	QRect bulletRect;
	


  };

#endif
