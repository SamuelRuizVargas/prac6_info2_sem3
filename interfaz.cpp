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

    ui->verticalSlider->setTickPosition(QSlider::TicksBothSides);
    connect(ui->verticalSlider,SIGNAL(valueChanged(int)),this,SLOT(zoom()));

    //sol de prueba
    sol = new planeta(370,255);
    scene->addItem(sol);

    //mostrar escena
    ui->graphicsView->setScene(scene);
    ui->graphicsView->show();

}

interfaz::~interfaz()
{
    delete ui;
}

void interfaz::zoom()
{
    int valor_slider=ui->verticalSlider->value();
    if(valor_slider==0)
    {
        ui->graphicsView->scale(0.5,0.5);
    }
    else if(valor_slider==1)
    {
        ui->graphicsView->scale(1,1);
    }
    else
    {
        ui->graphicsView->scale(1.5,1.5);
    }
}


