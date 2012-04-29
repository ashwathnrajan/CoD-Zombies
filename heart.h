#ifndef HEART_H
#define HEART_H

#include <QImage>
#include <QRect>
#include <QVector>

class Heart
  {
  public:
	Heart();
	bool pickedUp;
	QRect getRect(){return rect;}
	QImage getImage(){return image;}
	void pickUp() {pickedUp = 1;}
	bool getPickedUp() {return pickedUp;}
  private:
	QRect rect;
	QImage image;

  };

#endif
