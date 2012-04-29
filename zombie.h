#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <QImage>
#include <QRect>
#include <QVector>

/*struct zombieMove
  {
  int xdir;
  int ydir;
  };*/

class Zombie
  {
  public:
	Zombie(int xpo, int ypo);
	
	virtual void attack(int, int);
	virtual void move();
	void calculateDirection(int playerx, int playery);
	int getXpos() {return xpos;}
	int getYpos() {return ypos;}
	QRect getRect() {return zombieRect;}
	QImage getImage() {return zombieImage;}
	int getSpeed() {return speed;}
	int getHealth() {return health;}
	int getRange() {return range;}
	//void setDeque(deque<zombieMove>);
	void shot(int damage);
	bool isDead;
	virtual int getType() {return 1;}

  protected:
	int xpos;
	int ypos;
	int xdir;
	int ydir;
	QRect zombieRect;
	QImage zombieImage;
	int speed;
	int health;
	int range;
	//deque<zombieMove> moveQueue;
	

  };

#endif
