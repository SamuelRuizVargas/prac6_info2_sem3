#ifndef INTERFAZ_H
#define INTERFAZ_H
#include <QGraphicsScene>
#include <QMainWindow>
#include <QSlider>

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

private:
    Ui::interfaz *ui;
    QGraphicsScene *scene;
    planeta *sol;
};
#endif // INTERFAZ_H
