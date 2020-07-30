#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QGraphicsScene>
#include <QTimer>
#include <planetas.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
  //  void on_pushButton_clicked(); //Para cuando se pulse el boton
    void actualizar(); //Actualizacion

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    QTimer *cronometro;
    Planetas *Cuerpos[5];
};

#endif // MAINWINDOW_H
