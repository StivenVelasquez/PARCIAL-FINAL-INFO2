#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QGraphicsScene>
#include <QTimer>
#include <planetas.h>
#include <objeto.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void colision();

private slots:
    void actualizar(); //Actualizacion
    void spawn();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    QTimer *cronometro;
    Planetas *Cuerpos[5];
    QTimer *timer;
};

#endif // MAINWINDOW_H
