#include "objeto.h"
#include "planetas.h"

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

    int numero_aleatorio = rand() % 3; //Para que salgan de diferentes partes de la parte superior de la pantalla

    if(numero_aleatorio==1){
      px=rand() % 400;
    }

    if(numero_aleatorio==2){
      px=-400%rand();
    }

    py =-150;
    vx=100;
    vy=100;
    ax=0;
    ay=rand()%20;
    e=50/100.0;
    k=11/1000;
    r=20;
    m=50;

    setPos(px,py); //Posicion de los dementores en la pantalla

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
    if(px-(r/2.0)<=-400)
    {
        vx = -e*vx;
        if(px-(r/2)<-400)
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

    if(py-(r/2.0)<=-200.0)
    {
        vy = -e*vy;
        if(py-(r/2.0)<-200.0)
        {
            py = -199+(r/2);
        }
    }

    if(py-(r/2.0)>=400)
    {
        vy = -e*vy;
        if(py-(r/2.0)>400.0)
        {
            py = 399+(r/2);
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

