#include "planeta.h"

planeta::planeta()
{
    posx=0;
    posy=0;
    setPos(posx,posy);
}

planeta::planeta(int x, int y)
{
    posx=x;
    posy=y;
    setPos(posx,posy);
}

QRectF planeta::boundingRect() const
{
    return QRectF(0,0,20,20);
}

void planeta::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::yellow);
    painter->setPen(Qt::NoPen);
    painter->drawEllipse(boundingRect());
}

planeta::~planeta()
{

}
