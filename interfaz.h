#ifndef INTERFAZ_H
#define INTERFAZ_H

#include <QMainWindow>

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
};
#endif // INTERFAZ_H
