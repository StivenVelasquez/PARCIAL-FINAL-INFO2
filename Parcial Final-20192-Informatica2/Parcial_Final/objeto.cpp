#include "objeto.h"

float Objeto::getPx() const
{
    return px;
}

void Objeto::setPx(float value)
{
    px = value;
}

float Objeto::getPy() const
{
    return py;
}

void Objeto::setPy(float value)
{
    py = value;
}

float Objeto::getVx() const
{
    return vx;
}

void Objeto::setVx(float value)
{
    vx = value;
}

float Objeto::getVy() const
{
    return vy;
}

void Objeto::setVy(float value)
{
    vy = value;
}

float Objeto::getR() const
{
    return r;
}

void Objeto::setR(float value)
{
    r = value;
}

float Objeto::getE() const
{
    return e;
}

void Objeto::setE(float value)
{
    e = value;
}

Objeto::Objeto()
{
   // this->setPos(-1000,-1000);

    px =59+rand()%(911-59);
    py =-(310+rand()%(440-310));
    vx=-100;
    vy=-100;
    ax=0;
    ay=0;
    e=50/100.0;
    k=11/1000;
    r=20;
    m=50;

}

QRectF Objeto::boundingRect() const
{
    return QRectF (-r/2.0,-r/2.0,r,r);
}

void Objeto::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::darkGreen);        //asigna el color
    painter->drawEllipse(boundingRect());    //dibuja una elipse encerrada en la boundingRect

    Q_UNUSED(option);
    Q_UNUSED(widget);
}

void Objeto::colisionar()
{
    if(px-(r/2.0)<=0.0)
    {
        vx = -e*vx;
        if(px-(r/2)<0.0)
        {
            px = (r/2)+1;
        }
    }
    if(px+(r/2.0)>=400.0)
    {
        vx = -e*vx;
        if(px+(r/2)>400.0)
        {
            px = 399-r/2;
        }
    }

    if(py-(r/2.0)<=-499.0)
    {
        vy = -e*vy;
        if(py-(r/2.0)<-499.0)
        {
            py = -498+(r/2);
        }
    }
    this->setPos(px,py);
}

void Objeto::advance(int phase)
{
    v=sqrt(pow(vx,2)+pow(vy,2));
    tet=atan(vy/vx);
    ax=-(k*pow(v,2)*pow(r,2)*cos(tet))/m;
    ay=((k*pow(v,2)*pow(r,2)*sin(tet))/m)+g;
    colisionar();
    vx = vx + ax*dt;
    vy = vy + ay*dt;
    px = px + vx*dt + (ax*pow(dt,2))/2;
    py = py + vy*dt + (ay*pow(dt,2))/2;
}
