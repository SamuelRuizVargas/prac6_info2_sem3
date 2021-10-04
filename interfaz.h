#ifndef INTERFAZ_H
#define INTERFAZ_H
#include <QGraphicsScene>
#include <QMainWindow>

using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class interfaz; }
QT_END_NAMESPACE

class interfaz : public QMainWindow
{
    Q_OBJECT

public:
    interfaz(QWidget *parent = nullptr);
    ~interfaz();

private:
    Ui::interfaz *ui;
    QGraphicsScene *scene;
};
#endif // INTERFAZ_H
