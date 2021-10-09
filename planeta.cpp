#include "planeta.h"

planeta::planeta()
{
    tier=true;
    posx=0;
    posy=0;
    vx=0;
    vy=0;
    masa=0;
    radio=20;
    setPos(posx,posy);
}

planeta::planeta(int x, int y, int _vx, int _vy, int _masa, int _radio, string textura)
{
    posx=x;
    posy=y;
    vx=_vx;
    vy=_vy;
    masa=_masa;
    radio=_radio;
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
    return QRectF(radio/2,radio/2,radio,radio);
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

planeta::~planeta()
{

}
