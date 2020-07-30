#ifndef OBJETO_H
#define OBJETO_H


#include <QPainter>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <QDebug>
#include <QTimer>
#include <QPixmap>
#include <QString>
#include <iostream>

#define dt 0.1
#define g 10

class Objeto
{
private:
    float px,py,vx,vy,ax,ay,v,tet;
    float k,m,r,e,num;

public:

    Objeto();
    QRectF boundingRect() const;
    void paint(QPainter *painter,const QStyleOptionGraphicsItem *option, QWidget *widget);
    void colisionar();
    void advance(int phase);
    float getPx() const;
    void setPx(float value);
    float getPy() const;
    void setPy(float value);
    float getVx() const;
    void setVx(float value);
    float getVy() const;
    void setVy(float value);
    float getR() const;
    void setR(float value);
    float getE() const;
    void setE(float value);
};

#endif // OBJETO_H
