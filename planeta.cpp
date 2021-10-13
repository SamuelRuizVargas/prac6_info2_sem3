#include "planeta.h"

planeta::planeta()
{
    tier=true;
    posx=0;
    posy=0;
    xo=0;
    yo=0;
    vx=0;
    vy=0;
    vxo=0;
    vyo=0;
    masa=0;
    r=20;
    setPos(posx,posy);
}

planeta::planeta(float x, float y, float _vx, float _vy, float _masa, float _radio, string textura)
{
    posx=x;
    posy=y;
    xo=posx;
    yo=posy;
    vx=_vx;
    vy=_vy;
    vxo=vx;
    vyo=vy;
    ax=0;
    ay=0;
    masa=_masa;
    r=_radio;
    setPos(posx,posy);
    if(textura=="sol")
    {
        sol=true;
    }
    else if(textura=="mercurio")
    {
        merc=true;
    }
    else if(textura=="venus")
    {
        venu=true;
    }
    else if(textura=="tierra")
    {
        tier=true;
    }
    else if(textura=="marte")
    {
        mart=true;
    }
    else if(textura=="jupiter")
    {
        jupi=true;
    }
    else if(textura=="saturno")
    {
        satu=true;
    }
    else if(textura=="urano")
    {
        uran=true;
    }
    else if(textura=="neptuno")
    {
        nept=true;
    }
    else if(textura=="NONE")
    {
        tier=true;
    }
}

QRectF planeta::boundingRect() const
{
    return QRectF(-r/2,-r/2,r,r);
}

void planeta::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPixmap pixmap;
    if(sol==true)
    {
        pixmap.load(PATH_SOL);
    }
    else if(merc==true)
    {
        pixmap.load(PATH_MERC);
    }
    else if(venu==true)
    {
        pixmap.load(PATH_VENU);
    }
    else if(tier==true)
    {
        pixmap.load(PATH_TIER);
    }
    else if(mart==true)
    {
        pixmap.load(PATH_MART);
    }
    else if(jupi==true)
    {
        pixmap.load(PATH_JUPI);
    }
    else if(satu==true)
    {
        pixmap.load(PATH_SATU);
    }
    else if(uran==true)
    {
        pixmap.load(PATH_URAN);
    }
    else if(nept==true)
    {
        pixmap.load(PATH_NEPT);
    }
    painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());
}

float planeta::getPX()
{
    return posx;
}

float planeta::getPY()
{
    return posy;
}

float planeta::getMasa()
{
    return masa;
}

void planeta::posicion_actu(float dt)
{
    //sacar pox y posy, ademas modificar cualquier variable que sea necesaria
    vx = vx + (ax*dt);
    vy = vy + (ay*dt);
    posx = posx + (vx*dt);
    posy = posy + (vy*dt);
}

void planeta::a_restart()
{
    ax=0;
    ay=0;
}

void planeta::acelera(float masa_sol)
{
    radio = sqrt(pow(0-posx,2)+pow(0-posy,2));
    ax += G*masa_sol*(0-posx)/pow(radio,3);
    ay += G*masa_sol*(0-posy)/pow(radio,3);
}

planeta::~planeta()
{

}
