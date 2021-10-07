#ifndef PLANETA_H
#define PLANETA_H

#include <QGraphicsItem>
#include <QPainter>

class planeta : public QGraphicsItem
{
    int h=20;
    int a=20;
    int posx;
    int posy;
    int velocidad;
    int masa;

public:
    planeta();
    planeta(int,int);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
    ~planeta();
};

#endif // PLANETA_H
