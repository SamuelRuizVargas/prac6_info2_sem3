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
    scene->setSceneRect(-370,-275,741,551);

    ui->verticalSlider->setTickPosition(QSlider::TicksBothSides);
    connect(ui->verticalSlider,SIGNAL(valueChanged(int)),this,SLOT(zoom()));

    //se dibujan los planetas
    dibujarPlanetas();

    //Cuadrar escalamiento de scene
    ui->graphicsView->scale(0.095,0.095);

    //timer
    timer=new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(moverObjeto()));
    timer->start(0.00001);

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

void interfaz::moverObjeto()
{
    //utilizar las variables necesarias para mover el objeto
    QList<planeta*>::iterator it;

    float posicion_x, posicion_y,contador=1,masa_s=cuerpos[0]->getMasa();
    for(it=cuerpos.begin()+1;it!=cuerpos.end();it++)
    {
        cuerpos[contador]->a_restart();
        cuerpos[contador]->acelera(masa_s);
        cuerpos[contador]->posicion_actu(1);
        posicion_x=cuerpos[contador]->getPX();
        posicion_y=cuerpos[contador]->getPY();
        cuerpos[contador]->setPos(posicion_x,posicion_y);
        contador++;
    }
}

void interfaz::dibujarPlanetas(string ruta)
{
    ifstream archivo;
    string coorde,planeta_actu,numero,int1,int2,int3,int4,int5,int6;
    float len,len2,ente1,ente2,ente3,ente4,ente5,ente6,conta;
    char caracter;
    archivo.open(ruta, ios::in);
    while(!archivo.eof())
    {
        if (archivo.eof())
            break;
        getline(archivo,coorde);
        len=coorde.length();
        for (int i=0; i<=len;i++)
        {
            caracter=coorde[i];
            if (caracter!=',' and caracter!=0 )
            {
                planeta_actu+=caracter;
            }
            else if(caracter==',')
            {
                break;
            }
        }
        len2=planeta_actu.size();
        conta=0;
        for (int i=(len2)+1; i<=len;i++)
        {
            caracter=coorde[i];
            if (caracter!=',' and caracter!=0 )
            {
                numero+=caracter;
            }
            else
            {
                conta+=1;
                if(conta==1)
                    int1+=numero;
                else if(conta==2)
                    int2+=numero;
                else if(conta==3)
                    int3+=numero;
                else if(conta==4)
                    int4+=numero;
                else if(conta==5)
                    int5+=numero;
                else if(conta==6)
                    int6+=numero;
                numero.erase();
            }
        }
        ente1=atof(int1.c_str());
        ente2=atof(int2.c_str());
        ente3=atof(int3.c_str());
        ente4=atof(int4.c_str());
        ente5=atof(int5.c_str());
        ente6=atof(int6.c_str());
        int1.erase();
        int2.erase();
        int3.erase();
        int4.erase();
        int5.erase();
        int6.erase();
        cuerpos.append(new planeta(ente1,ente2,ente5,ente6,ente3,ente4,planeta_actu));
        scene->addItem(cuerpos.back());
        planeta_actu.erase();
    }
}


