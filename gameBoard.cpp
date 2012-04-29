#include <QtGui>
#include <QPainter>
#include <QApplication>
#include <cstdlib>
#include <QVector>
#include <iostream>
#include <QKeyEvent>


#include "gameBoard.h"

gameBoard::gameBoard(QWidget *parent) : QFrame(parent)
  {
  setFrameStyle(QFrame::Panel | QFrame::Sunken);
  setFocusPolicy(Qt::StrongFocus);
  isStarted = false;
  isPaused = false;
  isDead = false;

  player = new UserPlayer();
 currWeapon = (player->weaponList[0]);
  }

void gameBoard::start()
  {
  if (isPaused) return;
  isStarted = true;
  player->addScore(0);
  player->addPoints(0);
  level = 1;
  

  emit scoreChanged(player->getScore());

  timerId = startTimer(100);

  if (isDead)
	{
	isDead = false;
	player = new UserPlayer();
	currWeapon = (player->weaponList[0]);
	}
  
 
  
  }

void gameBoard::pause()
  {
  if (!isStarted) return;
  
  isPaused = !isPaused;

  if (isPaused)
	{
	killTimer(timerId);
	}
  else
	{
	timerId = startTimer(10);
	}
	update();
  }


void gameBoard::paintEvent(QPaintEvent* event)
  { 
  QFrame::paintEvent(event);
  QRect frameRect = this->frameRect();
  QPainter painter(this);
  QRect rect = contentsRect();
  setPalette(QPalette(QColor(20, 20, 100))); // colors the outside box
  painter.fillRect(frameRect, QColor(20, 10, 100));
  if (level == 2)
	{
	  painter.fillRect(frameRect, QColor(100, 10, 100));
	}
  if (level == 3)
	{
	  painter.fillRect(frameRect, QColor(50, 10, 0));
	}
  

  if (isPaused)// || !isStarted)
	{
	painter.drawText(rect, Qt::AlignCenter, tr("Paused"));
	return;
	}

  if (isDead)
	{
	painter.drawText(rect, Qt::AlignCenter, tr("Game over, you are dead"));
	return;
	}
  
  //draw UserPlayer
  painter.drawImage(player->getRect(), player->getImage());
  
  QVector<Zombie*>::iterator zit;// iteratees througthe zombie vector to draw zombies, as well as the spitters spitshot
  for (zit = zombieDeque.begin(); zit != zombieDeque.end(); zit++)
	{
	painter.drawImage((*zit)->getRect(), (*zit)->getImage());
	if ((*zit)->getType() == 2)
		{
		Spitter* dummy = dynamic_cast<Spitter*>(*zit);
		QVector<SpitterShot*>::iterator spit;
		for (spit = (dummy)->spitBullets.begin(); spit != (dummy)->spitBullets.end(); spit++)
			{
			painter.drawImage((*spit)->getRect(), (*spit)->getImage());
			}
		}
	}

  QVector<Bullet*>::iterator bit;
  QVector<Weapon>::iterator wit;
  		//iterates through the player's weapon list to draw all launched bullets
  	for (wit = player->weaponList.begin(); wit != player->weaponList.end(); wit++)
		{
  		for (bit = (*wit).bullets.begin(); bit != (*wit).bullets.end(); bit++)
			{
			painter.drawImage((*bit)->getRect(), (*bit)->getImage());
			}
		}
	
	


  }

void gameBoard::keyPressEvent(QKeyEvent *event)
  {
  if (!isStarted || isPaused)
	{
	QFrame::keyPressEvent(event);
	return;
	}
  int pxpos = player->getXpos();
  int pypos = player->getYpos();
  QRect frameRect = this->frameRect();
	switch (event->key())  //this switch statement handles individual cases of button presses
		{
		case Qt::Key_Left: // the arrow keys have the following logic: if the user is facing in that direction, move that way, otherwise, make the user look that way
			{
			int x = player->getRect().x();
			if (player->getXdir() != -1)
				{
				player->setXdir(-1);
				player->setYdir(0);
				player->setLEFT();
				break;
				} 
			else
				{
				if (pxpos > frameRect.left())
					{
					for (int i = 1; i <= (5 - player->weaponList[player->getWeapIndex()].gun->getWeight()); i++)
						{
						player->moveLeft();
						}
					break;
					}
				}
			}
		case Qt::Key_Right:
			{
			int x = player->getRect().x();
			if (player->getXdir() != 1)
				{
				player->setXdir(1);
				player->setYdir(0);
				player->setRIGHT();
				break;
				} 
			else
				{
				if (pxpos < frameRect.right())
					{
					for (int i = 1; i <= (5 - player->weaponList[player->getWeapIndex()].gun->getWeight()); i++)
						{
						player->moveRight();
						}
					break;
					}
				}
			}
		case Qt::Key_Up:
			{
			int x = player->getRect().x();
			if (player->getYdir() != -1)
				{
				player->setXdir(0);
				player->setYdir(-1);
				player->setUP();
				break;
				} 
			else
				{
				if (pypos > frameRect.top())
					{
					for (int i = 1; i <= (5 - player->weaponList[player->getWeapIndex()].gun->getWeight()); i++)
						{
						player->moveUp();
						}
					break;
					}
				}
			}
		case Qt::Key_Down:
			{
			int x = player->getRect().x();
			if (player->getYdir() != 1)
				{
				player->setXdir(0);
				player->setYdir(1);
				player->setDOWN();
				break;
				} 
			else
				{
				if (pypos < frameRect.bottom())
					{
					for (int i = 1; i <= (5 - player->weaponList[player->getWeapIndex()].gun->getWeight()); i++)
						{
						player->moveDown();
						}
					break;
					}				
				}
			}
		case Qt::Key_Space:
			{
			player->fire();
			emit ammoChanged(currWeapon.gun->getBullets());//, currWeapon.gun->getMagazines());
			break;
			}
		case Qt::Key_Q:
			{
			player->changeWeapon();
			currWeapon = (player->weaponList[player->getWeapIndex()]); 
			break;
			}
		case Qt::Key_R:
			{
			currWeapon.gun->reload();
			emit ammoChanged(currWeapon.gun->getBullets());
		 	emit magazinesChanged(currWeapon.gun->getMagazines());
			break;
			}
		default:
			{
			QFrame::keyPressEvent(event);
			break;
			}
		}

  }

void gameBoard::timerEvent(QTimerEvent *event)
  {
  if (isDead)
	zombieDeque.clear();
	
  checkCollisions();

  if (player->getLives() == 0)
	{
	isDead = 1;
	}

  int pxpos = player->getXpos();
  int pypos = player->getYpos();
  QRect frameRect = this->frameRect();
//emit signals with every timer timeout
  emit weaponChanged(currWeapon.gun->getDamage());
  emit levelChanged(level);
  emit ammoChanged(currWeapon.gun->getBullets());
  emit magazinesChanged(currWeapon.gun->getMagazines());
  emit healthChanged(player->getLives());
  emit scoreChanged(player->getScore());
//advance the player level
  if (player->getScore() > 4000  && player->getScore() < 8000)
	{
	level = 2;
	}
  else if (player->getScore() > 8000)
	{
	level = 3;
	}
  if (rand() % 50-level == 1)
	{
	int randint = rand() % 4;
	Zombie* newZombie;//spawn new zombies
	std::cout << "frameRect.x(): " << frameRect.x() << "frameRect.width(): " << frameRect.width() << std::endl << "randint: " << randint << std::endl;
	if (randint == 0)  newZombie = new Zombie(frameRect.x(), frameRect.y());
	else if (randint == 1) newZombie = new Zombie(frameRect.x() + frameRect.width() -10 , frameRect.y() + frameRect.height());
	else if (randint == 2) newZombie = new Zombie(frameRect.x(), frameRect.y() + frameRect.height() - 10);
	else if (randint == 3) newZombie = new Zombie(frameRect.x() + frameRect.width(), frameRect.y());
	zombieDeque.push_back(newZombie);
	}
  if (rand()% 85 == 1  && level >= 2)
	{
	int randint = rand()%4;
	Zombie* newZombie;//spawn new spitters, only with level 2
	if (randint == 0)  newZombie = new Spitter(frameRect.x(), frameRect.y());
	else if (randint == 1) newZombie = new Spitter(frameRect.x() + frameRect.width(), frameRect.y() + frameRect.height());
	else if (randint == 2) newZombie = new Spitter(frameRect.x(), frameRect.y() + frameRect.height());
	else if (randint == 3) newZombie = new Spitter(frameRect.x() + frameRect.width(), frameRect.top());
	zombieDeque.push_back(newZombie);
	}

  if (rand()% 130 == 1 && level >= 3)
	{
	int randint = rand()%4;
	Zombie* newZombie;//spawn new devil dogs -- with level 3
	if (randint == 0)  newZombie = new DevilDog(500, 1000);
	else if (randint == 1) newZombie = new DevilDog(500, 500);
	else if (randint == 2) newZombie = new DevilDog(1000, 100);
	else if (randint == 3) newZombie = new DevilDog(frameRect.x() + frameRect.width(), frameRect.top());
	zombieDeque.push_back(newZombie);
	}
  QVector<Weapon>::iterator it;
  QVector<Zombie*>::iterator zit;
//spitter "attacks"
  for (zit = zombieDeque.begin(); zit != zombieDeque.end(); zit++)
	{
	for (int i = 0; i < (*zit)->getSpeed(); i++)
		(*zit)->move();
	if (rand() % 5 == 0)
		{
		(*zit)->calculateDirection(player->getXpos(), player->getYpos());
		}

	(*zit)->attack(player->getXpos(), player->getYpos());
		
	}
// kill "Dead" zombies
  for (int i =0; i < 5; i++)
	{
	  int found = 0;
  	for (zit = zombieDeque.begin(); zit != zombieDeque.end(); zit++)
		{
		if ((*zit)->isDead == 1)
		  {
		    found = 1;
		    break;
		  }
		}
        if (found == 1)
	zombieDeque.erase(zit);
	}

//spawn new weapon in users inventory
  if (rand() % 50 == 0)
	{
	Weapon *newWeapon = new Weapon(rand() % 4, *player);
	player->weaponList.push_back(*newWeapon);
	}
// spawn new hearts
/*
  if (rand() % 3 == 0)
	{
	Heart* newHeart = new Heart();
	powerups.push_back(newHeart);
	}*/
// kill empty weapons
for (int i = 0; i < 5; i++)
	{	
	int found = 0;
  	for (it = player->weaponList.begin(); it != player->weaponList.end(); it++)
		{
		if ((*it).gun->getBullets() == 0 && (*it).gun->getMagazines() == 0)
			found = 1;			
			break;
		}
 	if (found == 1)
   	player->weaponList.erase(it);
	}
//bullet movement
  for (it = player->weaponList.begin(); it != player->weaponList.end(); it++)
	{
	QVector<Bullet*>::iterator bit;
	for (bit = it->bullets.begin(); bit != it->bullets.end(); bit ++)
		{
		for (int i = 0; i < (*bit)->getSpeed() * 6; i++)
			{	
			(*bit)->autoMove();
			}	
		}
	}

//spitshot movement
 
  for (zit = zombieDeque.begin(); zit != zombieDeque.end(); zit++)
	{
	if ((*zit)->getType() == 2)
		{
		Spitter* dummy = dynamic_cast<Spitter*>(*zit);
		QVector<SpitterShot*>::iterator spit;
		for (spit = (dummy)->spitBullets.begin(); spit != (dummy)->spitBullets.end(); spit++)
			{
			for (int i =0; i <5; i++)
			(*spit)->autoMove();
			}
		}
	}

/*
// kill old powerups
  QVector<Heart*>::iterator hearts;
  int foundheart = 0;
  for (hearts = powerups.begin(); hearts != powerups.end(); hearts++)
	{
	if ((*hearts)->getPickedUp() == 1)
		{
		foundheart = 1;
		break;
		}
	}
  if (foundheart ==1) powerups.erase(hearts);*/
  repaint();

  }

void gameBoard::checkCollisions()
  {
  for (QVector<Zombie*>::iterator zit = zombieDeque.begin(); zit != zombieDeque.end(); zit++)
	{// check zombie intersections
  	if ((player->getRect()).intersects((*zit)->getRect()))
		{
		player->loseLife();
		}
	if ((*zit)->getType() == 2)
		{
		Spitter* dummy = dynamic_cast<Spitter*>(*zit);
		QVector<SpitterShot*>::iterator spit;
		for (spit = (dummy)->spitBullets.begin(); spit != (dummy)->spitBullets.end(); spit++)
			{
			if ((player->getRect()).intersects((*spit)->getRect()))
				{
				(*spit)->setHit(); //spitshots hit target
				player->loseLife();
				}
			}
		}
	
	QVector<Bullet*>::iterator bit;
	QVector<Weapon>::iterator wit;
	//check bullet intersections
	for (wit = player->weaponList.begin(); wit != player->weaponList.end(); wit++)
		{
		for (bit = wit->bullets.begin(); bit != wit->bullets.end(); bit++)
			{
			if(((*zit)->getRect()).intersects((*bit)->getRect()))
				{
				  //std::cout << "overlap between zomb and bullet" << std::endl;
				(*zit)->shot((*bit)->getDamage());
				player->addScore(30 * (*bit)->getDamage());
				(*bit)->setHit(); //bullets hit target
				}
			}
		}
  	}
//heart intersections (but defunct)
	for (QVector<Heart*>::iterator hearts = powerups.begin(); hearts != powerups.end(); hearts++)
		{
		if ((player->getRect()).intersects((*hearts)->getRect()))
			{
			(*hearts)->pickUp();
			player->gainLife();
			}
		}
	QVector<Bullet*>::iterator bit;
	QVector<Weapon>::iterator wit;


	//spitshots intersections:
	  QVector<Zombie*>::iterator zit;
  	for (zit = zombieDeque.begin(); zit != zombieDeque.end(); zit++)
		{
		if ((*zit)->getType() == 2)
			{
			for (int i = 0; i <5; i++)
				{
				int found = 0;
				Spitter* dummy = dynamic_cast<Spitter*>(*zit);
				QVector<SpitterShot*>::iterator spit;
				for (spit = (dummy)->spitBullets.begin(); spit != (dummy)->spitBullets.end(); spit++)
					{
					if ((*spit)->getHit() == true) 
						{
						found = 1;
						break;
						}
					}
				if (found == 1) dummy->spitBullets.erase(spit);
				}
			}
		}

		
	//empty out bullets from the bullet vector
	for (wit = player->weaponList.begin(); wit != player->weaponList.end(); wit++)
		{
		for (int i = 0; i < 5; i++)
			{
			int found = 0;
			for (bit = wit->bullets.begin(); bit != wit->bullets.end(); bit++)
				{
				if ((*bit)->getHit() == true)
					{
					found = 1;
					break;
					}
				}
			if (found == 1)
			wit->bullets.erase(bit);
			}
		}
  }
