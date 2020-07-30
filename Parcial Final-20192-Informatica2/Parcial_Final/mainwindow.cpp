#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle(tr("SIMULACIÓN")); //Titulo
    cronometro=new QTimer(this);    //crea el timer
    scene=new QGraphicsScene(this);   // crea la escena
    scene->setSceneRect(-200,-200,400,500);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setStyleSheet("background-color:blue");//Para color del graphicsView
    //Se crean 4 cuerpos para la simulación
    Cuerpos[0]=new Planetas(0,0,0,0,50000,15);
    Cuerpos[1]=new Planetas(-5000,0,0,-2,70,15);
    Cuerpos[2]=new Planetas(5000,0,0,2,70,15);
    Cuerpos[3]=new Planetas(0,-5000,2,0,70,15);
    Cuerpos[4]=new Planetas(0,5000,-2,0,70,15);
    //Se añaden a la escena
    scene->addItem(Cuerpos[0]);
    scene->addItem(Cuerpos[1]);
    scene->addItem(Cuerpos[2]);
    scene->addItem(Cuerpos[3]);
    scene->addItem(Cuerpos[4]);

    cronometro->start(10);

    connect(cronometro,SIGNAL(timeout()),this,SLOT(actualizar()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::actualizar()//Actualizar datos de los cuerpos
{
    for(int j=0; j<5; j++)
       {
           for(int k=0; k<5; k++)
           {
               if(j != k){
                   Cuerpos[j]->CalcularAcelx(Cuerpos[k]);
                   Cuerpos[j]->CalcularAcely(Cuerpos[k]);
                   Cuerpos[j]->getPosx();
                   Cuerpos[j]->getPosy();
                   Cuerpos[j]->CalcularVelx();
                   Cuerpos[j]->CalcularVely();
                   Cuerpos[j]->mover();
               }
           }

           Cuerpos[j]->ModValor();
       }
   }
