#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <QBasicTimer>
#include <QFrame>
#include <QPointer>

#include "weapon.h"
#include "player.h"
#include "gun.h"
#include "lmg.h"
#include "pistol.h"
#include "shotgun.h"
#include "sniper.h"
#include "bullet.h"
#include "zombie.h"
#include "gameWindow.h"
#include <QVector>
#include "spittershot.h"
#include "spitter.h"
#include "devildog.h"
#include "heart.h"

class QLabel;


class gameBoard : public QFrame
  {
  Q_OBJECT

  public:
	gameBoard(QWidget * parent = 0);
	
	//void setWeaponLabel(QLabel *label);
	//QSize sizeHint() const;
	//QSize minimumSizeHint() const;

  public slots:
	void start();
	void pause();

  signals:
	void weaponChanged(int damage);
	void scoreChanged(int score);
	void ammoChanged(int bullets);
	void healthChanged(int health);
	void magazinesChanged(int magazines);
	void levelChanged(int level);

  protected:
	void paintEvent(QPaintEvent* event);
	void keyPressEvent(QKeyEvent* event);
	void timerEvent(QTimerEvent *event);

  private:
	
	void checkCollisions();
	//QBasicTimer timer;
	//QPointer<QLabel> weaponLabel;
	bool isStarted;
	bool isPaused;
	bool isDead;
	UserPlayer* player;
	QVector<Zombie*> zombieDeque;
	Weapon currWeapon;
	//QVector<Weapon*> spawnedWeaps;
	QVector<Heart*> powerups;
	
	int level;
	int score;
	int points;
	int timerId;

	
	

  };

#endif

