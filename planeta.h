#ifndef PLANETA_H
#define PLANETA_H

#include <QGraphicsItem>
#include <QPainter>

#define PATH_SOL "../practica6/imagenes/sol.png"
#define PATH_MERC "../practica6/imagenes/mercurio.png"
#define PATH_VENU "../practica6/imagenes/venus.png"
#define PATH_TIER "../practica6/imagenes/tierra.png"
#define PATH_MART "../practica6/imagenes/marte.png"
#define PATH_JUPI "../practica6/imagenes/jupiter.png"
#define PATH_SATU "../practica6/imagenes/saturno.png"
#define PATH_URAN "../practica6/imagenes/urano.png"
#define PATH_NEPT "../practica6/imagenes/neptuno.png"

using namespace std;

class planeta : public QGraphicsItem
{
//    int h=20;
//    int a=20;
    int posx;
    int posy;
    int vx;
    int vy;
    int masa;
    int radio;

    bool sol=false;
    bool merc=false;
    bool venu=false;
    bool tier=false;
    bool mart=false;
    bool jupi=false;
    bool satu=false;
    bool uran=false;
    bool nept=false;

public:
    planeta();
    planeta(int x,int y,int vx,int vy,int masa,int radio,string nom_planet);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
    ~planeta();
};

#endif // PLANETA_H
