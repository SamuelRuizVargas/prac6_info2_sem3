#ifndef INTERFAZ_H
#define INTERFAZ_H
#include <QGraphicsScene>
#include <QMainWindow>
#include <fstream>
#include <QSlider>
#include <QTimer>

#include "planeta.h"

using namespace std;

#define PATH_PLANETS "../practica6/textos/planetas.txt"

QT_BEGIN_NAMESPACE
namespace Ui { class interfaz; }
QT_END_NAMESPACE

class interfaz : public QMainWindow
{
    Q_OBJECT

public:
    interfaz(QWidget *parent = nullptr);
    ~interfaz();

public slots:
    void zoom();
    void moverObjeto();

private:
    Ui::interfaz *ui;
    QGraphicsScene *scene;

    QTimer *timer;

    QList<planeta*> cuerpos;

    void dibujarPlanetas(string=PATH_PLANETS);
    void limpiartxt();
    void actualizartxt();
};
#endif // INTERFAZ_H
