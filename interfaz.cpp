#include "interfaz.h"
#include "ui_interfaz.h"

interfaz::interfaz(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::interfaz)
{
    ui->setupUi(this);

    //Se crea la escena
    scene = new QGraphicsScene;

    //Incio de la escena
    scene->setSceneRect(0,0,741,551);

    //sol de prueba
    QPen pen;
    QBrush brush2(Qt::yellow,Qt::SolidPattern);
    scene->addRect(370,255,20,20, pen, brush2);

    //mostrar escena
    ui->graphicsView->setScene(scene);
    ui->graphicsView->show();

}

interfaz::~interfaz()
{
    delete ui;
}

