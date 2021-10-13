#ifndef PLANETA_H
#define PLANETA_H

#include <QGraphicsItem>
#include <iostream>
#include <QPainter>
#include <math.h>

#define PATH_SOL "../practica6/imagenes/sol.png"
#define PATH_MERC "../practica6/imagenes/mercurio.png"
#define PATH_VENU "../practica6/imagenes/venus.png"
#define PATH_TIER "../practica6/imagenes/tierra.png"
#define PATH_MART "../practica6/imagenes/marte.png"
#define PATH_JUPI "../practica6/imagenes/jupiter.png"
#define PATH_SATU "../practica6/imagenes/saturno.png"
#define PATH_URAN "../practica6/imagenes/urano.png"
#define PATH_NEPT "../practica6/imagenes/neptuno.png"

#define PI 3.14159265

using namespace std;

class planeta : public QGraphicsItem
{
    float posx;
    float posy;
    float xo;
    float yo;
    float r;

    float vx;
    float vy;
    float vxo;
    float vyo;

    float ax;
    float ay;

    float masa;
    float radio;

    float G=1;

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
    planeta(float x,float y,float vx,float vy,float masa,float radio,string nom_planet);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);

    float getPX();
    float getPY();
    float getMasa();
    void posicion_actu(float dt);
    void a_restart();
    void acelera(float masa_sol);

    ~planeta();
};

#endif // PLANETA_H
